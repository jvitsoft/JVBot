#include "JVAlgorithmGrayscale.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>

JVAlgorithmGrayscale::JVAlgorithmGrayscale()
{

}

JVAlgorithmGrayscale::~JVAlgorithmGrayscale()
{

}

void JVAlgorithmGrayscale::onInit(QString strId, QJsonObject joConfigAlgorithm)
{
    JVAlgorithm::onInit(strId,joConfigAlgorithm);
}

void JVAlgorithmGrayscale::process(JVImage* pJVImage)
{
    //qDebug() << "JVAlgorithmGrayscale::process";
    
    using namespace cv;
    Mat matColorImage = pJVImage->getProcessedImage();

    Mat matGrayscaleImage(matColorImage.size(),CV_8UC1);
    cvtColor(matColorImage,matGrayscaleImage,CV_BGR2GRAY);

    pJVImage->setProcessedImage(getId(),matGrayscaleImage);
}

