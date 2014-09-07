#include "JVBotManager.h"
#include "JVBotDemo.h"
#include <QDebug>
#include <QRect>
#include <QDir>
#include "JVBotServer.h"

JVBotManager::JVBotManager()
{
    m_bInit = false;
    /*
    QString strBotName = "bot1";
    JVBotDemo* pJVBot = new JVBotDemo(strBotName);
    m_hashBots.insert(strBotName,pJVBot);
    qDebug() << "Created demo bot!";
    */
}

JVBotManager::~JVBotManager()
{
    
}

void JVBotManager::startBots()
{
    if(m_queueStartBots.size() > 0)
    {
        
        QJsonObject joConfigBot = m_queueStartBots.dequeue();
        startBot(joConfigBot);
    }
}

void JVBotManager::tick()
{
    qDebug() << "JVBotManager::tick";
    
    startBots();
    
    QHash<QString,JVBot*>::const_iterator itBots;
    for(itBots = m_hashBots.begin(); itBots != m_hashBots.end(); itBots++)
    {
        JVBot* pJVBot = itBots.value();
        if(pJVBot != NULL)
        {
            pJVBot->tick();
        }
    }
}

void JVBotManager::addBot(QJsonObject joConfigBot)
{
    m_queueStartBots.enqueue(joConfigBot);
}

void JVBotManager::startBot(QJsonObject joConfigBot)
{

    
    QString strBotName = joConfigBot.value("botName").toString();
    qDebug() << "BotName:" << strBotName;
    
    QString strBotType = joConfigBot.value("botType").toString();
    qDebug() << "BotType:" << strBotType;
    
    if(m_hashBots.contains(strBotName) == true)
    {
        // Remove old bot
        JVBot* pBot = m_hashBots.value(strBotName);
        m_hashBots.remove(strBotName);
        delete pBot;
    }
    
    // Create new bot
    JVBot* pJVBot = NULL;
    // Create a new bot
    if(strBotType == "Demo")
    {
        pJVBot = new JVBotDemo(strBotName);
        m_hashBots.insert(strBotName,pJVBot);
        qDebug() << "Created demo bot!";
    }

    /*
    QJsonObject jsonArea = joConfigBot.value("area").toObject();
    qint32 nX = jsonArea.value("x").toInt();
    qint32 nY = jsonArea.value("y").toInt();
    qint32 nHeight = jsonArea.value("height").toInt();
    qint32 nWidth = jsonArea.value("width").toInt();
    
    QRect rectArea(nX,nY,nWidth,nHeight);
    qDebug() << rectArea;     
    */
    
    
    //pJVScreenCapturer->setArea(rectArea);
    //m_bCaptureImages = true;
    
}

qint32 JVBotManager::train(QString strBotId)
{
    JVBot* pBot = m_hashBots.value(strBotId,NULL);
    if(pBot != NULL)
    {
        return pBot->train();
    }
    return -1;
}

QList<JVDataDetected> JVBotManager::processImage(QString strBotId, QString strImageName)
{
    JVBot* pBot = m_hashBots.value(strBotId,NULL);
    if(pBot != NULL)
    {
        return pBot->processImage(strImageName);
    }
    return QList<JVDataDetected>();
}

qint32 JVBotManager::trainAutomatic(QString strBotId)
{
    JVBot* pBot = m_hashBots.value(strBotId,NULL);
    if(pBot != NULL)
    {
        return pBot->trainAutomatic();
    }
    return -1;
}


void JVBotManager::loadBot(QJsonObject joConfigBot)
{
    
}

void JVBotManager::stopBot(QJsonObject joConfigBot)
{
    
}