#include "JVImageProcessor.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include "JVAlgorithmBinarize.h"
#include "JVAlgorithmGrayscale.h"
#include "JVAlgorithmBlobs.h"
#include <QtAlgorithms>
//#include "JVAlgorithmCanny.h"
#include "JVAlgorithmResize.h"
//#include "JVAlgorithmContours.h"

JVImageProcessor::JVImageProcessor()
{

}

JVImageProcessor::~JVImageProcessor()
{

}

void JVImageProcessor::process(JVImage* pJVImage)
{
    // Display original image
    //cv::imshow("src", pJVImage->getSrcImage());

    QList<JVAlgorithm*>::const_iterator itAlgorithms;
    for(itAlgorithms = m_lAlgoritms.begin(); itAlgorithms != m_lAlgoritms.end(); ++itAlgorithms)
    {
        JVAlgorithm* pJVAlgorithm = *itAlgorithms;
        if(pJVAlgorithm != NULL)
        {
            pJVAlgorithm->process(pJVImage);

            // Display processed image
            //cv::imshow(pJVAlgorithm->getId().toStdString(), pJVImage->getProcessedImage());
        }
    }
}

void JVImageProcessor::clearConfiguration()
{
    qDeleteAll(m_lAlgoritms);
    m_lAlgoritms.clear();
}

void JVImageProcessor::setConfiguration(QJsonObject jsonObjectProcesing)
{
    clearConfiguration();
    
    QJsonArray jsonProcesingAlgorithms = jsonObjectProcesing.value("algorithms").toArray();

    for (qint32 nIndex = 0; nIndex < jsonProcesingAlgorithms.size(); ++nIndex)
    {
        QJsonObject jsonObjectAlgorithm = jsonProcesingAlgorithms[nIndex].toObject();
        QString strId = jsonObjectAlgorithm.value("id").toString();
        QJsonObject joConfigAlgorithm = jsonObjectAlgorithm.value("configuration").toObject();
        if(strId == "Binarize")
        {
            // Create algorithm object
            JVAlgorithmBinarize* pJVAlgorithmBinarize = new JVAlgorithmBinarize();
            pJVAlgorithmBinarize->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmBinarize);
        }
        else if(strId == "Grayscale")
        {
            // Create algorithm object
            JVAlgorithmGrayscale* pJVAlgorithmGrayscale = new JVAlgorithmGrayscale();
            pJVAlgorithmGrayscale->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmGrayscale);
        }
        else if(strId == "Blobs")
        {
            // Create algorithm object
            JVAlgorithmBlobs* pJVAlgorithmBlobs = new JVAlgorithmBlobs();
            pJVAlgorithmBlobs->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmBlobs);
        }
        else if(strId == "Resize")
        {
            // Create algorithm object
            JVAlgorithmResize* pJVAlgorithmResize = new JVAlgorithmResize();
            pJVAlgorithmResize->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmResize);
        }    
        
        /*
        else if(strId == "Canny")
        {
            // Create algorithm object
            JVAlgorithmCanny* pJVAlgorithmCanny = new JVAlgorithmCanny();
            pJVAlgorithmCanny->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmCanny);
        }
        else if(strId == "Resize")
        {
            // Create algorithm object
            JVAlgorithmResize* pJVAlgorithmResize = new JVAlgorithmResize();
            pJVAlgorithmResize->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmResize);
        }
        else if(strId == "Contours")
        {
            // Create algorithm object
            JVAlgorithmContours* pJVAlgorithmContours = new JVAlgorithmContours();
            pJVAlgorithmContours->onInit(strId,joConfigAlgorithm);
            qDebug() << "Added Algorithm Id:" << strId;
            m_lAlgoritms.append(pJVAlgorithmContours);
        }*/

        //m_hashSet.insert(strClassId,strPathImage);
    }
}
