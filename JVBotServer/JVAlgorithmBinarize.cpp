#include "JVAlgorithmBinarize.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>

JVAlgorithmBinarize::JVAlgorithmBinarize()
{
    m_nThresh = 50;
    m_nMaxval = 255;
    m_nType = cv::THRESH_BINARY;
}

JVAlgorithmBinarize::~JVAlgorithmBinarize()
{

}

void JVAlgorithmBinarize::onInit(QString strId, QJsonObject joConfigAlgorithm)
{
    JVAlgorithm::onInit(strId,joConfigAlgorithm);

    if(joConfigAlgorithm.contains("thresh"))
    {
        m_nThresh = joConfigAlgorithm.value("thresh").toVariant().toInt();
    }

    if(joConfigAlgorithm.contains("maxval"))
    {
        m_nMaxval = joConfigAlgorithm.value("maxval").toVariant().toInt();
    }

    if(joConfigAlgorithm.contains("type"))
    {
        m_nType = joConfigAlgorithm.value("type").toVariant().toInt();
    }
}

void JVAlgorithmBinarize::process(JVImage* pJVImage)
{
    //qDebug() << "JVAlgorithmBinarize::process";
    
    using namespace cv;
    cv::Mat matGrayscaleImage = pJVImage->getProcessedImage();
    // check type CV_8UC1
    
    //qDebug() << "thresh:" << m_nThresh << ", maxval:" << m_nMaxval << ", type:" << m_nType;
    //thresholding to get a binary image
    cv::Mat matBinaryImage;
    cv::threshold(matGrayscaleImage,matBinaryImage,m_nThresh,m_nMaxval,CV_THRESH_BINARY_INV);

    // Save image
    pJVImage->setProcessedImage(getId(),matBinaryImage);
}
