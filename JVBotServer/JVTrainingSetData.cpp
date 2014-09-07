#include "JVTrainingSetData.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>

JVTrainingSetData::JVTrainingSetData(QString strSetName)
{
    m_strSetName = strSetName;
}

JVTrainingSetData::~JVTrainingSetData()
{

}

QMultiHash<QString,QString> JVTrainingSetData::getTrainingSet()
{
    return m_hashTrainingSet;
}

QMultiHash<QString,QString> JVTrainingSetData::getTestSet()
{
    return m_hashTestSet;
}

void JVTrainingSetData::addTrainingData(QString strClasId,QList<QString> lPathImages)
{
    QList<QString>::const_iterator itPathImages;
    for(itPathImages = lPathImages.begin(); itPathImages != lPathImages.end(); itPathImages++)
    {
       QString strPathImage = *itPathImages;
       addTrainingData(strClasId,strPathImage);
    }
}

void JVTrainingSetData::addTestData(QString strClasId,QList<QString> lPathImages)
{
    QList<QString>::const_iterator itPathImages;
    for(itPathImages = lPathImages.begin(); itPathImages != lPathImages.end(); itPathImages++)
    {
       QString strPathImage = *itPathImages;
       addTestData(strClasId,strPathImage);
    }
}

void JVTrainingSetData::addTrainingData(QString strClasId, QString strPathImage)
{
    m_hashTrainingSet.insert(strClasId,strPathImage);
}

void JVTrainingSetData::addTestData(QString strClasId, QString strPathImage)
{
    m_hashTestSet.insert(strClasId,strPathImage);
}

bool JVTrainingSetData::load()
{
    QString strPath = QString("%1/%2.json").arg("./trainingSets").arg(m_strSetName);
    QFile file(strPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == true)
    {
        qDebug() << "Load: OK";

        QString strFile = file.readAll();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(strFile.toUtf8());
        QJsonObject jsonObject = jsonDocument.object();

        QString strSetName = jsonObject.value("setName").toString();
        qDebug() << "SetName:" << strSetName;

        // Load Training set
        qDebug() << "Training set:";
        load(m_hashTrainingSet,jsonObject.value("trainingSet").toArray());

        // Load Test set
        qDebug() << "Test set:";
        load(m_hashTestSet,jsonObject.value("testSet").toArray());
        return true;
    }
    else
    {
         qDebug() << "Load: Error";
         return false;
    }
}

void JVTrainingSetData::load(QMultiHash<QString,QString>& m_hashSet, QJsonArray jsonArraySet)
{
    for (qint32 nIndex = 0; nIndex < jsonArraySet.size(); ++nIndex)
    {
        QJsonObject jsonObjectSet = jsonArraySet[nIndex].toObject();
        QString strClassId = jsonObjectSet.value("classId").toString();
        QString strPathImage = jsonObjectSet.value("pathImage").toString();
        qDebug() << "ClassId:" << strClassId << ", PathImage:" << strPathImage;
        m_hashSet.insert(strClassId,strPathImage);
    }
}

QJsonArray JVTrainingSetData::saveSet(const QMultiHash<QString,QString>& m_hashSet)
{
    QJsonArray jsonArraySet;
    QMultiHash<QString,QString>::const_iterator itTrainingSet;
    for(itTrainingSet = m_hashSet.begin(); itTrainingSet != m_hashSet.end(); itTrainingSet++)
    {
        QString strClassId = itTrainingSet.key();
        QString strPathImage = itTrainingSet.value();
        QJsonObject jsonSet;
        jsonSet["classId"] = strClassId;
        jsonSet["pathImage"] = strPathImage;
        jsonArraySet.append(jsonSet);
    }
    return jsonArraySet;
}

void JVTrainingSetData::save()
{
    QJsonObject jsontrainingSet;
    jsontrainingSet["setName"] = m_strSetName;

    // Save training set
    QJsonArray jsonArrayTrainingSet = saveSet(m_hashTrainingSet);
    jsontrainingSet["trainingSet"] = jsonArrayTrainingSet;

    // Save test set
    QJsonArray jsonArrayTestSet = saveSet(m_hashTestSet);
    jsontrainingSet["testSet"] = jsonArrayTestSet;

    QString strPath = QString("%1/%2.json").arg("./trainingSets").arg(m_strSetName);
    QFile file(strPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text) == true)
    {
        QTextStream stream( &file );
        stream << QJsonDocument(jsontrainingSet).toJson() << endl;
        file.close();
        qDebug() << "Save: OK";
    }
    else
    {
        qDebug() << "Save: Error";
    }
}
