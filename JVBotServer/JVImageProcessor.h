#ifndef JVIMAGEPROCESSOR_H
#define JVIMAGEPROCESSOR_H

#include <QString>
#include <opencv2/core/core.hpp>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QDir>
#include "JVImage.h"
#include <QList>
#include "JVAlgorithm.h"
class JVImageProcessor
{
public:
    JVImageProcessor();
    ~JVImageProcessor();

    void process(JVImage* pJVImage);

    void setConfiguration(QJsonObject jsonObjectProcesing);
    void clearConfiguration();
    
private:
    //int generateRandomNumber(int low, int high);
    QList<JVAlgorithm*> m_lAlgoritms;
};

#endif
