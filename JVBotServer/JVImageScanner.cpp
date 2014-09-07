
#include "JVImageScanner.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>

JVImageScanner::JVImageScanner()
{
    // Create seed for the random.
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

JVImageScanner::~JVImageScanner()
{

}

// Return path random unique images. (it doesn´t return duplicates).
QList<QString> JVImageScanner::getPathRandomImages(QString strDir, qint32 numImages, const QList<QString>& liExcludeFiles)
{
    QDir dir(strDir);

    qDebug() << "getRandomImages from:" << dir.absolutePath();

    QDirIterator itImages(dir.absolutePath(), QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::NoIteratorFlags);

    QList<QString> lImages;
    while(itImages.hasNext())
    {
        itImages.next();
        lImages.append(itImages.filePath());
    }

    // Get random images
    QList<QString> lRandomImages;
    while(lRandomImages.size() < numImages && lImages.size() > 0)
    {
        int randomValue = generateRandomNumber(0,lImages.size()-1);
        QString strPath = lImages.at(randomValue);
        if(liExcludeFiles.contains(strPath) == true)
        {
            // Remove image
            lImages.removeAt(randomValue);
        }
        else
        {
            if(lRandomImages.contains(strPath) == false)
            {
                qDebug() << "Image: " << strPath;
                lRandomImages.append(strPath);
                // Remove image from the list
                lImages.removeAt(randomValue);
            }
        }
    }

    if(lRandomImages.size() != numImages)
    {
        // It was not possible get all the images
        qDebug() << "Error: not enought images";
    }

    return lRandomImages;
}

int JVImageScanner::generateRandomNumber(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}
