#ifndef JVTRAININGSETDATA_H
#define JVTRAININGSETDATA_H

#include <QString>
#include <QSet>
#include <QMultiHash>
#include <QList>
#include <QJsonArray>

class JVTrainingSetData
{
public:
    JVTrainingSetData(QString strSetName);
    ~JVTrainingSetData();

    void addTrainingData(QString strClasId,QList<QString> lPathImages);
    void addTrainingData(QString strClasId, QString strPathImage);

    void addTestData(QString strClasId,QList<QString> lPathImages);
    void addTestData(QString strClasId, QString strPathImage);

    void save();
    bool load();

    QMultiHash<QString,QString> getTrainingSet();
    QMultiHash<QString,QString> getTestSet();
private:

    QJsonArray saveSet(const QMultiHash<QString,QString>& m_hashSet);
    void load(QMultiHash<QString,QString>& m_hashSet,QJsonArray jsonArraySet);
    QString m_strSetName;
    QMultiHash<QString,QString> m_hashTrainingSet;
    QMultiHash<QString,QString> m_hashTestSet;
};

#endif
