#include "JVBotDemo.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QList>
#include <QTime>
//#include "JVTrainingSetGenerator.h"
//#include "JVTrainingSetData.h"

JVBotDemo::JVBotDemo(QString strId) : JVBot(strId)
{
    loadConfig();
}

void JVBotDemo::loadConfig()
{
    // Load config parent
    JVBot::loadConfig();
    
    // Load specific config
}

 void JVBotDemo::onInit(QJsonObject joConfig)
 {
     JVBot::onInit(joConfig);
 }

 void JVBotDemo::train()
 {
  

 }
 
void JVBotDemo::tick()
{
    JVBot::tick();

}

JVBotDemo::~JVBotDemo()
{

}
