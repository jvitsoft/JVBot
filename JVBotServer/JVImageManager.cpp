
#include "JVImageManager.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"


JVImageManager::JVImageManager()
{

}

JVImage* JVImageManager::getInstanceImage(QString strPathImage)
{
    // Check if the image is already loaded
     using namespace cv;
    cv::Mat copyImage;
   
    if(m_hashImages.contains(strPathImage) == false)
    {
        // We need to load the image
        cv::Mat src = cv::imread(strPathImage.toStdString(),cv::IMREAD_COLOR);
       
        Mat matTemp;
        src.convertTo(matTemp, CV_8U);
        Mat matResult;
        cvtColor(matTemp, matResult, CV_BGRA2BGR);
        
        m_hashImages["strPathImage"] = matResult;
        matResult.copyTo(copyImage);
    }
    else
    {
        m_hashImages.value(strPathImage).copyTo(copyImage);
    }
     
    JVImage* pJVImage = new JVImage(copyImage);
    cv::imshow("copyImage", copyImage);
    return pJVImage;
}

JVImageManager::~JVImageManager()
{

}
