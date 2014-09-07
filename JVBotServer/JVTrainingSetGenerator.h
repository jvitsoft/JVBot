#ifndef JVTRAININGSETGENERATOR_H
#define JVTRAININGSETGENERATOR_H

#include "JVTrainingSetData.h"
#include <QString>
#include <QSet>

// To-DO: Singleton
class JVTrainingSetGenerator
{
public:
    JVTrainingSetGenerator();
    ~JVTrainingSetGenerator();

    JVTrainingSetData* generateTrainingSet(QString strSetName,QString strPathDir, QList<QString> setClasses, qint32 numImagesTraining, qint32 numImagesTest);
    JVTrainingSetData* getTrainingSet(QString strSetName);
private:

};

#endif
