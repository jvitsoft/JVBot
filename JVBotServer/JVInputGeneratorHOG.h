/* 
 * File:   JVInputGeneratorHOG.h
 * Author: javi
 *
 * Created on 16 de agosto de 2014, 19:32
 */

#ifndef JVINPUTGENERATORHOG_H
#define	JVINPUTGENERATORHOG_H

#include "JVInputGenerator.h"

class JVInputGeneratorHOG : public JVInputGenerator
{
public:
    JVInputGeneratorHOG();
    ~JVInputGeneratorHOG();

    void onInit(QJsonObject joConfigInputGenerator);

    cv::Mat generateInputs(JVImage* pJVImage);
private:

};

#endif	/* JVINPUTGENERATORHOG_H */

