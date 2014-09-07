#include "JVAlgorithmBlobs.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>
#include "opencvblobslib/blob.h"
#include "opencvblobslib/BlobResult.h"

JVAlgorithmBlobs::JVAlgorithmBlobs()
{

}

JVAlgorithmBlobs::~JVAlgorithmBlobs()
{

}

void JVAlgorithmBlobs::onInit(QString strId, QJsonObject joConfigAlgorithm)
{
    JVAlgorithm::onInit(strId,joConfigAlgorithm);
}

void JVAlgorithmBlobs::process(JVImage* pJVImage)
{
    //qDebug() << "JVAlgorithmBlobs::process";
    
    using namespace cv;
    
    Mat matBinaryImage = pJVImage->getProcessedImage();

    // Create copy original image
    Mat matSrcImage = pJVImage->getSrcImage().clone(); 
    
    // Get blobs
    CBlobResult blobs;
    IplImage temp = (IplImage)matBinaryImage;
    blobs = CBlobResult(&temp,NULL,1);

    qint32 nNumBlobs = blobs.GetNumBlobs();
    //qDebug() << "Blobs found:" << nNumBlobs;
    for(int i=0;i<nNumBlobs;i++)
    {
        CBlob *curblob = blobs.GetBlob(i);

        // Get sub image
        cv::Rect rect = curblob->GetBoundingBox();
        cv::Mat matBlob = matBinaryImage(rect);

        // Draw bounding box in the color image
        rectangle(matSrcImage,rect,CV_RGB(200,100,50),1);

        pJVImage->setProcessedImage("blob",matBlob);
    }
    
    pJVImage->setBlobs(blobs);
    pJVImage->setProcessedImage(getId(),matSrcImage);
}
