#include "JVImage.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QString>

JVImage::JVImage(cv::Mat& matImageSrc)
{
    m_hashImages["src"] = matImageSrc;
    cv::Mat img;
    matImageSrc.copyTo(img);
    m_hashImages["img"] = img;
}

JVImage::~JVImage()
{

}

cv::Mat JVImage::getSrcImage()
{
    return m_hashImages["src"];
}

double* JVImage::getHuMoments()
{
    return m_huMoments;
}

void JVImage::setHuMoments(double huMoments[7])
{
    for(int i = 0; i < 7; i++)
    {
        m_huMoments[i] = huMoments[i];
    }
}

void JVImage::setProcessedImage(QString strName, const cv::Mat& matImage)
{
    m_hashImages[strName] = matImage;
    matImage.copyTo(m_hashImages["img"]);
}

cv::Mat JVImage::getProcessedImage()
{
    return m_hashImages["img"];
}

void JVImage::setBlobs(CBlobResult blobs)
{
    m_blobs = blobs;
}

CBlobResult JVImage::getBlobs()
{
    return m_blobs;
}


cv::Mat JVImage::getProcessedImage(QString strName)
{
    return m_hashImages[strName];
}

QString JVImage::getPixelsString(const cv::Mat& matImage)
{
    QString strPixels;
    int i =0;
    for(qint32 x=0;x<matImage.rows;x++)
    {
        for(qint32 y=0;y<matImage.cols;y++)
        {
            strPixels += QString("%1").arg((matImage.at<uchar>(x,y)==255)?1:0);
        }
    }
    return strPixels;
}

