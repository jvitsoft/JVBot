#include "JVTrainingSetGenerator.h"
#include "JVImageScanner.h"
#include <QDebug>
#include <QFile>

JVTrainingSetGenerator::JVTrainingSetGenerator()
{

}

JVTrainingSetGenerator::~JVTrainingSetGenerator()
{

}

JVTrainingSetData* JVTrainingSetGenerator::getTrainingSet(QString strSetName)
{
    JVTrainingSetData *pJVTrainingSetData = new JVTrainingSetData(strSetName);
    if(pJVTrainingSetData->load() == true)
        return pJVTrainingSetData;
    delete pJVTrainingSetData;
    return NULL;
}

JVTrainingSetData* JVTrainingSetGenerator::generateTrainingSet(QString strSetName, 
        QString strPathDir, 
        QList<QString> setClasses, 
        qint32 numImagesTraining, 
        qint32 numImagesTest)
{
    JVImageScanner imageScanner;

    // Calculate num images training per class
    qint32 numImagesTrainingClass = numImagesTraining / setClasses.size();

    // Calculate num images test per class
    qint32 numImagesTestClass = numImagesTest / setClasses.size();

    qDebug() << "ImagesTrainingClass:" << numImagesTrainingClass << "ImagesTestClass:" << numImagesTestClass;

    JVTrainingSetData *pJVTrainingSetData = new JVTrainingSetData(strSetName);

    QList<QString>::const_iterator itClasses;
    for(itClasses = setClasses.begin(); itClasses != setClasses.end(); itClasses++)
    {
        QString strClassId = *itClasses;
        qDebug() << "Class:" << strClassId;
        // Get Training images
        
        QString strPathClass = QString("%1/%2").arg(strPathDir).arg(strClassId);
        QList<QString> lTraniningImages = imageScanner.getPathRandomImages(strPathClass,numImagesTrainingClass,QList<QString>());
        pJVTrainingSetData->addTrainingData(strClassId,lTraniningImages);
        qDebug() << "Training images:" << lTraniningImages.size();

        // Get Test images. Exclude the training images
        // lTraniningImages
        QList<QString> lTestImages = imageScanner.getPathRandomImages(strPathClass,numImagesTestClass,QList<QString>());
        pJVTrainingSetData->addTestData(strClassId,lTestImages);
        qDebug() << "Test images:" << lTestImages.size();
        qDebug() << "-------------------------------------------";
    }

    return pJVTrainingSetData;
}
