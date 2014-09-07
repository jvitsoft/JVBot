#include "JVANN.h"
#include <QFile>
#include <QJsonArray>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
//#include "JVInputGeneratorPixelValue.h"
//#include "JVInputGeneratorHuMoments.h"
#include "JVInputGeneratorHOG.h"
#include "JVImage.h"

JVANN::JVANN()
{
    m_bInputsInitialized = false;
}

JVANN::~JVANN()
{

}

void JVANN::clearConfiguration()
{
    m_setClasses.clear();
    m_strSetName.clear();
    m_numImagesTraining = 0;
    m_numImagesTest = 0;
}

void JVANN::setConfiguration(QJsonObject joConfigANN)
{
    clearConfiguration();
    
    m_strSetName = joConfigANN.value("setName").toString();

    QJsonArray jaClasses = joConfigANN.value("classes").toArray();
    for (qint32 nIndex = 0; nIndex < jaClasses.size(); ++nIndex)
    {
        QJsonObject joClass = jaClasses[nIndex].toObject();
        //QString strId = joClass.value("id").toString();
        QString strLabel = joClass.value("label").toString();
        m_setClasses.append(strLabel);
    }

    m_numImagesTraining = joConfigANN.value("numImagesTraining").toVariant().toInt();
    m_numImagesTest = joConfigANN.value("numImagesTest").toVariant().toInt();

    qDebug() << "setName:" << m_strSetName;
    qDebug() << "numImagesTraining:" << m_numImagesTraining;
    qDebug() << "numImagesTest:" << m_numImagesTest;

    QJsonObject joInputsGenerator = joConfigANN.value("inputsGenerator").toObject();
    QString strInputsGeneratorId = joInputsGenerator.value("id").toString();

    qDebug() << "InputsGeneratorId:" << strInputsGeneratorId;

    
    if(strInputsGeneratorId == "HOG")
    {
        m_pJVInputGenerator.reset(new JVInputGeneratorHOG());

    }
    /*
    else if(strInputsGeneratorId == "HuMoments")
    {
        m_pJVInputGenerator.reset(new JVInputGeneratorHuMoments());
    }
    else if(strInputsGeneratorId == "Histograms")
    {
        m_pJVInputGenerator.reset(new JVInputGeneratorHistograms());
    }
     */
    m_matOutputs = cv::Mat(m_numImagesTraining,m_setClasses.size(),CV_32F,cv::Scalar::all(0));
}

cv::Mat JVANN::generateInputs(JVImage* pJVImage)
{
    return m_pJVInputGenerator->generateInputs(pJVImage);
}

void JVANN::addInput(qint32 numImage,JVImage* pJVImage)
{

    cv::Mat mapInputs = generateInputs(pJVImage);

    if(m_bInputsInitialized == false)
    {
        m_bInputsInitialized = true;
        m_matInputs = cv::Mat(m_numImagesTraining,mapInputs.cols,CV_32F,cv::Scalar::all(0));
    }

    for(qint32 nColumn=0; nColumn<mapInputs.cols; nColumn++)
    {
        m_matInputs.at<float>(numImage,nColumn) = mapInputs.at<float>(0,nColumn);
    }
}

void JVANN::train()
{
    cv::Mat layers(3,1,CV_32S);
    layers.at<int>(0,0) = m_matInputs.cols;//input layer
    layers.at<int>(1,0)= 50;//hidden layer
    layers.at<int>(2,0) = m_setClasses.size();//output layer

    m_nnetwork = new CvANN_MLP(layers,CvANN_MLP::SIGMOID_SYM,0.6,1);
    //create the neural network.
    //for more details check http://docs.opencv.org/modules/ml/doc/neural_networks.html

    CvANN_MLP_TrainParams params(
       // terminate the training after either 1000
       // iterations or a very small change in the
       // network wieghts below the specified value
       cvTermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS, 1000, 0.000001),
       // use backpropogation for training
       CvANN_MLP_TrainParams::BACKPROP,
       // co-efficents for backpropogation training
       // recommended values taken from http://docs.opencv.org/modules/ml/doc/neural_networks.html#cvann-mlp-trainparams
       0.1,
       0.1);

    int iterations = m_nnetwork->train(m_matInputs, m_matOutputs,cv::Mat(),cv::Mat(),params);
    qDebug() << "Iterations: " << iterations;
}
/*
bool JVANN::lessThan( QPair<QString,qreal> pair1, QPair<QString,qreal> pair2 )
{
    return pair1.second < pair2.second;
}*/

QString JVANN::predict(const cv::Mat& matImage)
{
    qint32 numClasses = m_setClasses.size();

    cv::Mat classificationResult(1, numClasses, CV_32F);

    m_nnetwork->predict(matImage, classificationResult);

    QList<QPair<QString,qreal> > lClassifications;
    for(int index=0;index<numClasses;index++)
    {
        float value = classificationResult.at<float>(0,index);
        QPair<QString,qreal> pair;
        pair.first = m_setClasses.at(index);
        pair.second = value;
        lClassifications.append(pair);
    }

    // Order
    qSort(lClassifications.begin(),lClassifications.end(),QPairSecondComparer());


  
    QString strClass = "Unknown";
    // Get the max value
    if(lClassifications.size() > 0)
    {
        QPair<QString,qreal> pairBestMatch = lClassifications.at(0);
        strClass = pairBestMatch.first;
        //if(pairBestMatch.second < 0.9)
        //{
            // Check other matches
            if(lClassifications.size() > 1)
            {
                // Check the difference between the second best match
                QPair<QString,qreal> pairSecondMatch = lClassifications.at(1);
                qreal nDifference = fabs(pairBestMatch.second - pairSecondMatch.second);
                if(nDifference < 0.3)
                {
                    // error, it is very similar to other class, so we are not sure
                    strClass = "?";
                    qDebug() << "Predict:" << strClass;
                    QList<QPair<QString,qreal> >::const_iterator itClassifications;
                    for(itClassifications = lClassifications.begin(); itClassifications != lClassifications.end();
                        itClassifications++)
                    {
                        QPair<QString,qreal> pair = *itClassifications;
                        qDebug() << pair.first << " -> " << pair.second;
                    }

                }
            }
        //}
    }
    
    return strClass;

    //qDebug() << "MaxValue: " << maxValue << ", maxIndex:" << maxIndex;
    /*
    // find the class with maximum weightage.
    int maxIndex = 0;
    float value=-1;
    float maxValue=0;
    for(int index=0;index<numClasses;index++)
    {   value = classificationResult.at<float>(0,index);
        qDebug() << "Label " << index << ":" << value;
        float difference = fabs(value-maxValue);
        if(value>maxValue && difference > 0.5)
        {
            maxValue = value;
            maxIndex=index;
        }
    }*/

    //qDebug() << "MaxValue: " << maxValue << ", maxIndex:" << maxIndex;

    //if(maxValue < 0.1)
    //    return "error";

    //return m_setClasses.at(maxIndex);
}

void JVANN::addOutput(qint32 numImage,qint32 nClassId, qint32 nValue)
{
    m_matOutputs.at<float>(numImage,nClassId) = nValue;
}

QList<QString> JVANN::getClasses()
{
    return m_setClasses;
}

QString JVANN::getSetName()
{
    return m_strSetName;
}

qint32 JVANN::getNumImagesTraining()
{
    return m_numImagesTraining;
}

qint32 JVANN::getNumImagesTest()
{
    return m_numImagesTest;
}
