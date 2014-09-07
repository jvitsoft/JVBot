#include "JVAlgorithmResize.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>

JVAlgorithmResize::JVAlgorithmResize()
{
    m_nWidth = 16;
    m_nHeight = 16;
}

JVAlgorithmResize::~JVAlgorithmResize()
{

}

void JVAlgorithmResize::onInit(QString strId, QJsonObject joConfigAlgorithm)
{
    JVAlgorithm::onInit(strId,joConfigAlgorithm);

    if(joConfigAlgorithm.contains("width"))
    {
        m_nWidth = joConfigAlgorithm.value("width").toVariant().toInt();
    }

    if(joConfigAlgorithm.contains("height"))
    {
        m_nHeight = joConfigAlgorithm.value("height").toVariant().toInt();
    }
}

void JVAlgorithmResize::process(JVImage* pJVImage)
{
    //qDebug() << "JVAlgorithmResize::process";
    //qDebug() << "width" << m_nWidth << ", height:" << m_nHeight;
/*
    cv::Mat img = pJVImage->getProcessedImage();
    cv::Mat output(m_nWidth,m_nHeight,CV_8U,cv::Scalar(0));
    for(int x=0;x<img.cols;x++)
      {
          for(int y=0;y<img.rows ;y++)
          {
              int yd =ceil((float)(y*img.cols/m_nWidth));
              int xd = ceil((float)(x*img.rows/m_nHeight));
              output.at<uchar>(x,y) = img.at<uchar>(xd,yd);
          }
      }
*/
    //thresholding to get a binary image

    cv::Mat output2(m_nWidth,m_nHeight,CV_8U,cv::Scalar(0));
   // cv::imwrite("aa.png",output);
    cv::resize(pJVImage->getProcessedImage("blob"),output2,cv::Size(m_nWidth,m_nHeight));

   //cv::resize(output,output2,cv::Size(m_nWidth,m_nHeight));
    // Save image
    pJVImage->setProcessedImage(getId(),output2);

}
