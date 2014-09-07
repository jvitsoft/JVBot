/* 
 * File:   JVAlgorithmGrayscale.h
 * Author: javi
 *
 * Created on 16 de agosto de 2014, 16:59
 */

#ifndef JVALGORITHMGRAYSCALE_H
#define	JVALGORITHMGRAYSCALE_H


#include <QString>
#include "JVAlgorithm.h"

class JVAlgorithmGrayscale : public JVAlgorithm
{
    public:
    JVAlgorithmGrayscale();
    ~JVAlgorithmGrayscale();
    //QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    void process(JVImage* pJVImage);

    void onInit(QString strId, QJsonObject joConfigAlgorithm);

private:
    
};

#endif	/* JVALGORITHMGRAYSCALE_H */

