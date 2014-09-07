/* 
 * File:   JVAlgorithmBlobs.h
 * Author: javi
 *
 * Created on 16 de agosto de 2014, 17:16
 */

#ifndef JVALGORITHMBLOBS_H
#define	JVALGORITHMBLOBS_H

#include <QString>
#include "JVAlgorithm.h" 

class JVAlgorithmBlobs : public JVAlgorithm
{
public:
    JVAlgorithmBlobs();
    ~JVAlgorithmBlobs();
    //QList<QString> getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles);

    void process(JVImage* pJVImage);

    void onInit(QString strId, QJsonObject joConfigAlgorithm);

private:
    
};

#endif	/* JVALGORITHMBLOBS_H */

