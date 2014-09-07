
#include "JVInputGeneratorHOG.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QJsonObject>
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;

JVInputGeneratorHOG::JVInputGeneratorHOG() : JVInputGenerator()
{

}

JVInputGeneratorHOG::~JVInputGeneratorHOG()
{

}

void JVInputGeneratorHOG::onInit(QJsonObject joConfigInputGenerator)
{
    JVInputGenerator::onInit(joConfigInputGenerator);
}

cv::Mat JVInputGeneratorHOG::generateInputs(JVImage* pJVImage)
{
    cv::Mat matImage = pJVImage->getProcessedImage();
   

     HOGDescriptor hog(cvSize(32,32),cvSize(16,16),
                                          cvSize(8,8),cvSize(8,8),8);

     vector<float> descriptos;
     vector<Point>locs;
     hog.compute(matImage,descriptos,Size(1,1),Size(0,0),locs);

     cv::Mat matInputs(1,descriptos.size()
                       ,CV_32F,cv::Scalar::all(0));

     for(int i=0;i<descriptos.size();i++)
     {
      // qDebug() << "Descriptor " << i << ":" << descriptos.at(i);
         matInputs.at<float>(0,i) = descriptos.at(i);
     }

    // qDebug() << "Descriptors: " << descriptos.size();

    return matInputs;
}
