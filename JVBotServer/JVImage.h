#ifndef JVIMAGE_H
#define JVIMAGE_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QHash>
#include "opencvblobslib/blob.h"
#include "opencvblobslib/BlobResult.h"
class JVImage
{
public:
    JVImage(cv::Mat& matImageSrc);
    ~JVImage();
    //QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    void setBlobs(CBlobResult blobs);
    CBlobResult getBlobs();
    
    cv::Mat getSrcImage();
    cv::Mat getProcessedImage();
    cv::Mat getProcessedImage(QString strName);
    void setProcessedImage(QString strName, const cv::Mat& matImage);

    static QString getPixelsString(const cv::Mat& matImage);

    void setHuMoments(double huMoments[7]);
    double* getHuMoments();
private:
    //int generateRandomNumber(int low, int high);

    CBlobResult m_blobs;
    double m_huMoments[7];
    QHash<QString,cv::Mat> m_hashImages;
};

#endif
