/* 
 * File:   JVBotManager.h
 * Author: javi
 *
 * Created on 14 de agosto de 2014, 11:04
 */

#ifndef JVBOTMANAGER_H
#define	JVBOTMANAGER_H

#include <QHash>
#include <QJsonObject>
#include "JVBot.h"
#include <QQueue>
#include <QFileSystemWatcher>
#include "JVDataDetected.h"
class JVBotManager : public QObject
{
    Q_OBJECT
public:
    JVBotManager();
    ~JVBotManager();
    
    void addBot(QJsonObject joConfigBot);
    void startBot(QJsonObject joConfigBot);
    void stopBot(QJsonObject joConfigBot);
    void tick();
    qint32 train(QString strBotId);
    qint32 trainAutomatic(QString strBotId);
    QList<JVDataDetected> processImage(QString strBotId,QString strImageName);
    
private:
    void loadBot(QJsonObject joConfigBot);
    void startBots();
    QHash<QString,JVBot*> m_hashBots;
    QScopedPointer<QFileSystemWatcher> m_pFileSystemWatcher;
    bool m_bInit;
    QQueue<QJsonObject> m_queueStartBots;
};

#endif	/* JVBOTMANAGER_H */

