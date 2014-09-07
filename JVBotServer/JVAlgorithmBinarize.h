#ifndef JVBINARIZEIMAGE_H
#define JVBINARIZEIMAGE_H

#include <QString>
#include "JVAlgorithm.h"

class JVAlgorithmBinarize : public JVAlgorithm
{
public:
    JVAlgorithmBinarize();
    ~JVAlgorithmBinarize();
    //QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    void process(JVImage* pJVImage);

    void onInit(QString strId, QJsonObject joConfigAlgorithm);

private:
    //int generateRandomNumber(int low, int high);
    qint32 m_nThresh; // threshold value
    qint32 m_nMaxval; // maximum value to use with the THRESH_BINARY and THRESH_BINARY_INV thresholding types.
    qint32 m_nType; // thresholding type
};

#endif
