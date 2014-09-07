#include "JVTrainer.h"
#include "JVBotServer.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>

JVTrainer::JVTrainer(QString strSetName, QList<QString> lSetClasses)
{
    m_strSetName = strSetName;
    m_lSetClasses = lSetClasses;
    
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    
    readImages();
}

JVTrainer::~JVTrainer()
{
    
}

void JVTrainer::clear()
{
    m_lImages.clear();
}

void JVTrainer::generateValidCombination()
{
    JVTrainingSetData* pJVTrainingSetData = generateRandomTrainingSetData();
    
    
    /*if(m_hashCombinations.contains(pJVTrainerCombination->getId()) == false)
    {
        // Save combination
        m_hashCombinations.insert(pJVTrainerCombination->getId(),pJVTrainerCombination);
        qDebug() << "created combination";
    }*/
}

int JVTrainer::generateRandomNumber(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

JVTrainingSetData* JVTrainer::generateRandomTrainingSetData()
{
    /*JVTrainerCombination* pJVTrainerCombination = new JVTrainerCombination();
    
    while(lImages.size() > 0)
    {
        int randomValue = generateRandomNumber(0,lImages.size()-1);
        QString strPath = lImages.takeAt(randomValue);
        pJVTrainerCombination->addImage(strPath);
    }
    return pJVTrainerCombination;*/
    QList<QPair<QString,QString> > lImages(m_lImages);
    
    JVTrainingSetData* pJVTrainingSetData = new JVTrainingSetData(m_strSetName);
    
    QList<QPair<QString,QString> >::const_iterator itImages; 
    for(itImages = lImages.begin(); itImages != lImages.end(); itImages++)
    {
        QString strClassId = itImages->first;
        QString strImage = itImages->second;
        pJVTrainingSetData->addTestData(strClassId,strImage);
    }
    
    while(lImages.size() > 0)
    {
        int randomValue = generateRandomNumber(0,lImages.size()-1);
        QPair<QString,QString> pair = lImages.takeAt(randomValue);
        QString strClassId = pair.first;
        QString strImage = pair.second;
        pJVTrainingSetData->addTrainingData(strClassId,strImage);
    }
    return pJVTrainingSetData;
}

qint32 JVTrainer::train()
{
    
    //generateValidCombination();
    //QList<QString> lImagesCombination;
    //qint32 nIndex = 0;
    //generateCombinations(lImagesCombination,nIndex);
    //displayCombinations(lImagesCombination);
    
    return -1;
}

void JVTrainer::displayCombinations(const QList<QString>& lCombinations)
{
    qDebug() << "Combinations generated: " << lCombinations.size();
    QList<QString>::const_iterator itCombinations; 
    //QString strCombination
    for(itCombinations = lCombinations.begin(); itCombinations != lCombinations.end(); itCombinations++)
    {
        QString strImage = *itCombinations;
        
    }
}

void JVTrainer::readImages()
{
    clear();
    
    // Get all the images available from all the classes 
    QList<QString>::const_iterator itCLasses; 
    for(itCLasses = m_lSetClasses.begin(); itCLasses != m_lSetClasses.end(); itCLasses++)
    {
        QString strClass = *itCLasses;
        QString strDir = JVBotServer::DATA_PATH + "/Images/" + m_strSetName + "/" + strClass;
        QDir dir(strDir);

        qDebug() << "generateCombinations from:" << dir.absolutePath();

        QDirIterator itImages(dir.absolutePath(), QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);

        while(itImages.hasNext())
        {
            itImages.next();
            QPair<QString,QString> pair;
            pair.first = strClass;
            pair.second = itImages.filePath();
            m_lImages.append(pair);
        }
    }
    
    /*QList<QString>::const_iterator itImages; 
    
    for(itImages = m_lImages.begin(); itImages != m_lImages.end(); itImages++)
    {
        QString strImage = *itImages;
        qDebug() << "Image:" << strImage;
    }*/
    qDebug() << "Num Images:" << m_lImages.size();
        
}

void JVTrainer::generateCombinations(QList<QString>& lCombinations, qint32& nIndex)
{
    /*if(nIndex < m_lImages.size())
    {
        // Get next image
        QString strImage = m_lImages.at(nIndex);

        // Option 1: Don't take the image
        nIndex = nIndex + 1;
        generateCombinations(lCombinations,nIndex);

        // Option 1: Take the image
        lCombinations.append(strImage);
        generateCombinations(lCombinations,nIndex);
    }
    else
    {
        // Save
        //m_lCombinations.append()
    }*/
    
    // User una matriz con n filas (combinaciones posibles) y n columnas (classes)
    // Podemos usar una Lista o bien podemos intentar calcular el numero de cmbinaciones
}