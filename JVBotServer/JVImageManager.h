#ifndef JVIMAGEMANAGER_H
#define JVIMAGEMANAGER_H

#include <QString>
#include "JVImage.h"
#include <QHash>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
class JVImageManager
{
public:
    JVImageManager();
    ~JVImageManager();
   // QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    JVImage* getInstanceImage(QString strPathImage);

private:
    //int generateRandomNumber(int low, int high);
    QHash<QString,cv::Mat> m_hashImages;
};

#endif
