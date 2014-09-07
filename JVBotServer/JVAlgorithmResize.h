/* 
 * File:   JVAlgorithmResize.h
 * Author: vrs
 *
 * Created on August 22, 2014, 7:25 PM
 */

#ifndef JVALGORITHMRESIZE_H
#define JVALGORITHMRESIZE_H

#include <QString>
#include "JVAlgorithm.h"

class JVAlgorithmResize : public JVAlgorithm
{
public:
    JVAlgorithmResize();
    ~JVAlgorithmResize();
    //QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    void process(JVImage* pJVImage);

    void onInit(QString strId, QJsonObject joConfigAlgorithm);

private:
    //int generateRandomNumber(int low, int high);

    qint32 m_nWidth;
    qint32 m_nHeight;
};

#endif
