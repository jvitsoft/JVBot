#include "JVBot.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>
#include <QJsonDocument>
#include "JVImage.h"
#include "JVTrainingSetGenerator.h"
#include "JVImageManager.h"
#include "JVScreenCapturer.h"
#include "JVBotServer.h"
#include "JVDataDetected.h"
#include "JVTrainerCombination.h"
JVBot::JVBot(QString strId)
{
    m_strId = strId;
    m_nCount = 0;
    
    m_pJVScreenCapturer = new JVScreenCapturer();
        
      m_pFileSystemWatcher.reset(new QFileSystemWatcher(this));

      m_pJVImageProcessor.reset(new JVImageProcessor);
      m_pJVImagePreProcessor.reset(new JVImageProcessor);
      
      
      m_pJVImageManager.reset(new JVImageManager);
      
      m_pJVANN.reset(new JVANN);
      
     QString strPath = QString("%1/%2/%3.json")
             .arg(JVBotServer::DATA_PATH)
             .arg("Bots")
             .arg(m_strId);
     qDebug() << "Path:" << strPath;
     
     m_pFileSystemWatcher->addPath(strPath);
   
     QObject::connect(m_pFileSystemWatcher.data(), 
        SIGNAL(fileChanged(const QString&)),
        this,
        SLOT(onUpdate(const QString&)));

    connect(&m_timerFileChanged, SIGNAL(timeout()), this, SLOT(onBotChanged()));

    ros::NodeHandle nodeHandle;
    image_transport::ImageTransport imageTransport(nodeHandle);
    QString strNameTopic = QString("/%1/images/%2").arg(m_strId).arg("source");
    m_ImagePublisher = imageTransport.advertise(strNameTopic.toStdString(), 1);
    
  /*  m_pJVImageProcessor.reset(new JVImageProcessor);
    m_pJVANN.reset(new JVANN);
    m_pJVImageManager.reset(new JVImageManager);*/
}

void JVBot::onBotChanged()
{
    qDebug() << "onBotChanged";
    m_timerFileChanged.stop();
    loadConfig();
}

qint32 JVBot::trainAutomatic()
{
     qDebug() << "JVBot::trainAutomatic";
     
     qint32 nErrorPt = 100;
     while(nErrorPt > 0)
     {
        JVTrainingSetData* pJVTrainingSetData = m_pJVTrainer->generateRandomTrainingSetData();
        QMultiHash<QString,QString> hashTrainingSet = pJVTrainingSetData->getTrainingSet();
           QMultiHash<QString,QString>::const_iterator itTrainingSet;
           qint32 nNumImage = 0;
           for(itTrainingSet = hashTrainingSet.begin(); itTrainingSet != hashTrainingSet.end(); ++itTrainingSet)
           {
               QString strClassId = itTrainingSet.key();
               QString strImagePath = itTrainingSet.value();
               qDebug() << "ClassId:" << strClassId;
               qDebug() << "ImagePath:" << strImagePath;

               JVImage* pJVImage = m_pJVImageManager->getInstanceImage(strImagePath);
               if(pJVImage != NULL)
               {
                   //qDebug() << "before";
                   //cv::imshow("before", pJVImage->getProcessedImage());
                   m_pJVImageProcessor->process(pJVImage);
               }

               // Obtener la imagen resultado
               cv::Mat result = pJVImage->getProcessedImage();

              cv::imshow("result", result);
              qDebug() << "Rows:" << result.rows;
              qDebug() << "Columns:" << result.cols;
               //QString strPixels = JVImage::getPixelsString(result);
               //qDebug() << strPixels;

               m_pJVANN->addInput(nNumImage,pJVImage);

               // Important: we need to specify the index of the classId in the list
               qint32 nIndexClassId = m_pJVANN->getClasses().indexOf(strClassId);

               m_pJVANN->addOutput(nNumImage,nIndexClassId,1);

               ++nNumImage;
           }

           m_pJVANN->train();

           //predict
          nErrorPt = predict(pJVTrainingSetData);       
     }
     
     qDebug() << "FOund!";
     
     //m_pJVTrainer->train();
     //JVTrainerCombination* pJVTrainerCombination = m_pJVTrainer->generateValidCombination();
     return -1;
}

qint32 JVBot::train()
{
    QString strSetName = m_pJVANN->getSetName();

        JVTrainingSetGenerator* pJVTrainingSetGenerator = new JVTrainingSetGenerator();
        
        QString strPathDir = QString("%1/%2/%3")
             .arg(JVBotServer::DATA_PATH)
             .arg("Images")
             .arg(strSetName);

        qDebug() << "Train: DirPath:" << strPathDir;
        JVTrainingSetData* pJVTrainingSetData = NULL; //pJVTrainingSetGenerator->getTrainingSet(strSetName);
        if(pJVTrainingSetData == NULL)
        {
            pJVTrainingSetData = pJVTrainingSetGenerator->generateTrainingSet(strSetName,
                                                                             strPathDir,
                                                                             m_pJVANN->getClasses(),
                                                                             m_pJVANN->getNumImagesTraining(),
                                                                             m_pJVANN->getNumImagesTest());
            qDebug() << "Generated";
            //pJVTrainingSetData->save();
        }
        else
        {
            qDebug() << "Exists";
        }
        
        
    QMultiHash<QString,QString> hashTrainingSet = pJVTrainingSetData->getTrainingSet();
    QMultiHash<QString,QString>::const_iterator itTrainingSet;
    qint32 nNumImage = 0;
    for(itTrainingSet = hashTrainingSet.begin(); itTrainingSet != hashTrainingSet.end(); ++itTrainingSet)
    {
        QString strClassId = itTrainingSet.key();
        QString strImagePath = itTrainingSet.value();
        qDebug() << "ClassId:" << strClassId;
        qDebug() << "ImagePath:" << strImagePath;

        JVImage* pJVImage = m_pJVImageManager->getInstanceImage(strImagePath);
        if(pJVImage != NULL)
        {
            //qDebug() << "before";
            //cv::imshow("before", pJVImage->getProcessedImage());
            m_pJVImageProcessor->process(pJVImage);
        }

        // Obtener la imagen resultado
        cv::Mat result = pJVImage->getProcessedImage();

       cv::imshow("result", result);
       qDebug() << "Rows:" << result.rows;
       qDebug() << "Columns:" << result.cols;
        //QString strPixels = JVImage::getPixelsString(result);
        //qDebug() << strPixels;

        m_pJVANN->addInput(nNumImage,pJVImage);

        // Important: we need to specify the index of the classId in the list
        qint32 nIndexClassId = m_pJVANN->getClasses().indexOf(strClassId);

        m_pJVANN->addOutput(nNumImage,nIndexClassId,1);

        ++nNumImage;
    }

    m_pJVANN->train();

    //predict
   return predict(pJVTrainingSetData);
   
}

void JVBot::onUpdate(const QString& strFilePath)
{
    m_pFileSystemWatcher->addPath(strFilePath);
    m_timerFileChanged.setInterval(500);
    m_timerFileChanged.start();
}

void JVBot::loadConfig()
{
    QString strPath = QString("%1/%2/%3.json")
             .arg(JVBotServer::DATA_PATH)
             .arg("Bots")
             .arg(m_strId);
    QFile file(strPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == true)
    {
        qDebug() << "Load: OK";

        QString strFile = file.readAll();
        qDebug() << strFile;

        QJsonDocument jsonDocument = QJsonDocument::fromJson(strFile.toUtf8());
        QJsonObject jsonObject = jsonDocument.object();
        QString strId =  jsonObject.value("id").toString();
        qDebug() << "Id: " << strId;
        QJsonObject jsonArea = jsonObject.value("area").toObject();
    
        qint32 nX = jsonArea.value("x").toVariant().toInt();
        qint32 nY = jsonArea.value("y").toVariant().toInt();
        qint32 nHeight = jsonArea.value("height").toVariant().toInt();
        qint32 nWidth = jsonArea.value("width").toVariant().toInt();

        m_pRectArea.reset(new QRect(nX,nY,nWidth,nHeight));
        qDebug() << *m_pRectArea.data();  
        QRect rectArea(nX,nY,nWidth,nHeight);
        
        m_pJVScreenCapturer->setArea(rectArea);
        
        QJsonObject joPreprocesing = jsonObject.value("preprocesing").toObject();
        m_pJVImagePreProcessor->setConfiguration(joPreprocesing);
        
        
        QJsonObject joProcesing = jsonObject.value("procesing").toObject();
        m_pJVImageProcessor->setConfiguration(joProcesing);
        
        QJsonObject joANN = jsonObject.value("ANN").toObject();
        m_pJVANN->setConfiguration(joANN);
        
        m_pJVTrainer.reset(new JVTrainer(m_pJVANN->getSetName(),m_pJVANN->getClasses()));
         
        //train();
    }
}

QList<JVDataDetected> JVBot::processImage(JVImage* pJVImage)
{
    QList<JVDataDetected> lDataDetected;
    
    m_pJVImagePreProcessor->process(pJVImage);
        
    // Get blobs
    CBlobResult blobs = pJVImage->getBlobs();
    qint32 nNumBlobs = blobs.GetNumBlobs();
    //qDebug() << "Blobs: " << nNumBlobs;
   
    Mat matSrcImage = pJVImage->getSrcImage().clone(); 
    for(int i=0;i<nNumBlobs;i++)
    {
        CBlob *curblob = blobs.GetBlob(i);

        // Get sub image
        cv::Rect rect = curblob->GetBoundingBox();
        cv::Mat matBlob = matSrcImage(rect);

        
            QString strBlobId = QString("%1-%2").arg("blob").arg(i);
            //cv::imshow(strBlobId.toStdString(),matBlob);

            JVImage* pJVImage = new JVImage(matBlob);
            m_pJVImageProcessor->process(pJVImage);

            cv::Mat matInputs = m_pJVANN->generateInputs(pJVImage);

            QString strClassIdPredicted = m_pJVANN->predict(matInputs);

            //qDebug() << "strClassIdPredicted:" << strClassIdPredicted;

                JVDataDetected dataDetected;
                dataDetected.setData(strClassIdPredicted);
                dataDetected.setBoundingBox(curblob->GetBoundingBox());
                dataDetected.setMatSource(matBlob.clone());
            lDataDetected.append(dataDetected);
        
    }


    return lDataDetected;
}

QList<JVDataDetected> JVBot::processImage(QString strImageName)
{
     QString strPath = QString("%1/%2/%3")
             .arg(JVBotServer::DATA_PATH)
             .arg("Images")
             .arg(strImageName);
        qDebug() << "processImage: " << strPath;
        
        
        cv::Mat matSourceImage = cv::imread(strPath.toStdString(),cv::IMREAD_COLOR);

        //cv::imshow("matSourceImage",matSourceImage);
       
        Mat matTemp;
        matSourceImage.convertTo(matTemp, CV_8U);
        Mat matResult;
        cvtColor(matTemp, matResult, CV_BGRA2BGR);
        
        
        // Aplicar algoritmos seleccionados
        JVImage* pJVImage = new JVImage(matSourceImage);
        
        m_pJVImagePreProcessor->process(pJVImage);
        
        QList<JVDataDetected> lDataDetected;
        
        
        
        // Get blobs
        CBlobResult blobs = pJVImage->getBlobs();
        qint32 nNumBlobs = blobs.GetNumBlobs();
        qDebug() << "Blobs: " << nNumBlobs;
        Mat matSrcImage = pJVImage->getSrcImage().clone(); 
        for(int i=0;i<nNumBlobs;i++)
        {
            CBlob *curblob = blobs.GetBlob(i);

            // Get sub image
            cv::Rect rect = curblob->GetBoundingBox();
            cv::Mat matBlob = matSrcImage(rect);
            
            //if(i == 1)
            {
                QString strBlobId = QString("%1-%2").arg("blob").arg(i);
                cv::imshow(strBlobId.toStdString(),matBlob);
                
                JVImage* pJVImage = new JVImage(matBlob);
                m_pJVImageProcessor->process(pJVImage);
                
                
                //cv::Mat result = pJVImage->getProcessedImage();
                /*
                JVImage* pJVImage = m_pJVImageManager->getInstanceImage(strImagePath);
                if(pJVImage != NULL)
                {
                    //qDebug() << "before";
                    //cv::imshow("before", pJVImage->getProcessedImage());
                    m_pJVImageProcessor->process(pJVImage);
                }

                // Obtener la imagen resultado
                cv::Mat result = pJVImage->getProcessedImage();
                 */
                cv::Mat matInputs = m_pJVANN->generateInputs(pJVImage);

                QString strClassIdPredicted = m_pJVANN->predict(matInputs);
                
                    qDebug() << "strClassIdPredicted:" << strClassIdPredicted;
          
                    JVDataDetected dataDetected;
                    dataDetected.setData(strClassIdPredicted);
                    dataDetected.setBoundingBox(curblob->GetBoundingBox());
                    dataDetected.setMatSource(matBlob.clone());
                lDataDetected.append(dataDetected);
            }
        }
        
        
        // Replace original image with the data detected
        //Mat matSrcImage = pJVImage->getSrcImage().clone(); 
        
        cv::Mat matData(pJVImage->getSrcImage().rows,
                pJVImage->getSrcImage().cols,CV_8U,cv::Scalar(255));
        QList<JVDataDetected>::const_iterator itDataDetected;
        for(itDataDetected = lDataDetected.begin(); itDataDetected!= lDataDetected.end(); itDataDetected++)
        {
            JVDataDetected dataDetected = *itDataDetected;
            Rect rBoundingBox = dataDetected.getBoundingBox();
            //cv::Mat matData(rBoundingBox.width,rBoundingBox.height,CV_8U,cv::Scalar(0));
            
            qDebug() << "Put text: " << dataDetected.getData();
            qDebug() << "Point: " << rBoundingBox.br().x << "," << rBoundingBox.br().y;
            //src.copyTo(dst(Rect(left, top, src.cols, src.rows)));
            //putText(matData,dataDetected.getData(),rBoundingBox.br(),1,1,Scalar::all(255) 3,8);
            putText(matData, dataDetected.getData().toStdString(), rBoundingBox.br(), 
                FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,0), 1, CV_AA);
            
        }

        cv::imshow("FINAL", matData);
        
        
        // Publish original image
        cv_bridge::CvImage cv_image;
        cv_image.image = matResult;

        qDebug() << "published image";
        cv_image.encoding = sensor_msgs::image_encodings::BGR8;
        sensor_msgs::Image ros_image;
        cv_image.toImageMsg(ros_image);

        // Get image from the screen capturer
        //Convert the CvImage to a ROS image message and publish it on the "camera/image_processed" topic.
        m_ImagePublisher.publish(ros_image);     
        
        return lDataDetected;
}

void JVBot::tick()
{      
    //if(m_nCount == 0)
    //{
    /*
        QString strPath = QString("%1/%2/%3")
             .arg(JVBotServer::DATA_PATH)
             .arg("Images")
             .arg("numbers.png");
        qDebug() << "Tick: " << strPath;
        
        cv::Mat matSourceImage = cv::imread(strPath.toStdString(),cv::IMREAD_COLOR);

        //cv::imshow("matSourceImage",matSourceImage);
       
        Mat matTemp;
        matSourceImage.convertTo(matTemp, CV_8U);
        Mat matResult;
        cvtColor(matTemp, matResult, CV_BGRA2BGR);
        
        
        // Aplicar algoritmos seleccionados
        JVImage* pJVImage = new JVImage(matSourceImage);
        
        m_pJVImageProcessor->process(pJVImage);
        
        // Publish original image
        cv_bridge::CvImage cv_image;
        cv_image.image = matResult;

        qDebug() << "published image";
        cv_image.encoding = sensor_msgs::image_encodings::BGR8;
        sensor_msgs::Image ros_image;
        cv_image.toImageMsg(ros_image);

        // Get image from the screen capturer
        //Convert the CvImage to a ROS image message and publish it on the "camera/image_processed" topic.
        m_ImagePublisher.publish(ros_image);     
        
        m_nCount++;*/
     
   // }
    
    if(m_nCount == 1)
    {
        trainAutomatic();
        
    //cv_bridge::CvImage cv_image;
    //cv_image.image = m_pJVScreenCapturer->getImage();
    Mat aux = m_pJVScreenCapturer->getImage();
    JVImage* pJVImage = new JVImage(aux);
    
    QList<JVDataDetected> lDataDetected = processImage(pJVImage);
    
                cv::Mat matData(pJVImage->getSrcImage().rows,
                pJVImage->getSrcImage().cols,CV_8U,cv::Scalar(255));
        QList<JVDataDetected>::const_iterator itDataDetected;
        for(itDataDetected = lDataDetected.begin(); itDataDetected!= lDataDetected.end(); itDataDetected++)
        {
            JVDataDetected dataDetected = *itDataDetected;
            Rect rBoundingBox = dataDetected.getBoundingBox();
            //cv::Mat matData(rBoundingBox.width,rBoundingBox.height,CV_8U,cv::Scalar(0));
            
            //qDebug() << "Put text: " << dataDetected.getData();
            //qDebug() << "Point: " << rBoundingBox.br().x << "," << rBoundingBox.br().y;
            //src.copyTo(dst(Rect(left, top, src.cols, src.rows)));
            //putText(matData,dataDetected.getData(),rBoundingBox.br(),1,1,Scalar::all(255) 3,8);
            putText(matData, dataDetected.getData().toStdString(), rBoundingBox.br(), 
                FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,0), 1, CV_AA);
            
        }

        cv::imshow("FINAL", matData);
        
        // Publish original image
        cv_bridge::CvImage cv_image;
        cv_image.image = matData;
        
        /*
    qDebug() << "published image";
    cv_image.encoding = sensor_msgs::image_encodings::BGRA8;
    sensor_msgs::Image ros_image;
    cv_image.toImageMsg(ros_image);

    // Get image from the screen capturer
    //Convert the CvImage to a ROS image message and publish it on the "camera/image_processed" topic.
    m_ImagePublisher.publish(ros_image);*/
    }
    m_nCount++;
    
}
 qint32 JVBot::predict(JVTrainingSetData* pJVTrainingSetData)
 {
     // Obtener imagenes de training set. Obtener la image usando getInstanceImage y pasarle la imagen al
     QMultiHash<QString,QString> hashTestSet = pJVTrainingSetData->getTestSet();
     QMultiHash<QString,QString>::const_iterator itTestSet;

     qint32 nErrors = 0;
     for(itTestSet = hashTestSet.begin(); itTestSet != hashTestSet.end(); ++itTestSet)
     {
         QString strClassId = itTestSet.key();
         QString strImagePath = itTestSet.value();
         qDebug() << "ClassId:" << strClassId;
         qDebug() << "ImagePath:" << strImagePath;

         JVImage* pJVImage = m_pJVImageManager->getInstanceImage(strImagePath);
         if(pJVImage != NULL)
         {
             m_pJVImageProcessor->process(pJVImage);
         }

         // Obtener la imagen resultado
         //cv::Mat result = pJVImage->getProcessedImage();

         cv::Mat matInputs = m_pJVANN->generateInputs(pJVImage);

         QString strClassIdPredicted = m_pJVANN->predict(matInputs);
         if(strClassId != strClassIdPredicted)
         {
             qDebug() << "error";
             nErrors++;
         }
     }

     qDebug() << "num errors: " << nErrors;
     qint32 nErrorPtc = (double) nErrors*100/hashTestSet.size();
     qDebug() << "% errors: " << nErrorPtc;
     
     return nErrorPtc;
 }
void JVBot::onInit(QJsonObject joConfig)
{
    //m_pJVImageProcessor->setConfiguration(joConfigImageProcessor);
    //m_pJVANN->setConfiguration(joConfigANN);
}

JVBot::~JVBot()
{

}
