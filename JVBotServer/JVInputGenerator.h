#ifndef JVINPUTGENERATOR_H
#define JVINPUTGENERATOR_H

#include <QString>
#include <QJsonObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "JVImage.h"
class JVInputGenerator
{
public:
    JVInputGenerator();
    virtual ~JVInputGenerator();

    virtual void onInit(QJsonObject joConfigInputGenerator);

    virtual cv::Mat generateInputs(JVImage* pJVImage) = 0;

private:

};

#endif
