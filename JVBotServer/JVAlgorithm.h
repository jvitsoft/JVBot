#ifndef JVALGORITHM_H
#define JVALGORITHM_H

#include <QString>
#include "JVImage.h"
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QJsonObject>
class JVAlgorithm
{
public:
    JVAlgorithm();
    virtual ~JVAlgorithm();
   // QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    virtual void onInit(QString strId, QJsonObject joConfigAlgorithm);

    virtual void process(JVImage* pJVImage) = 0;

    QString getId();
private:

    QString m_strId;
    //int generateRandomNumber(int low, int high);
};

#endif

