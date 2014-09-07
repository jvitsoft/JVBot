/*
 * File:   JVBotClientUI.cpp
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 13:48
 */

#include "JVBotClientUI.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include "JVAreaSelector.h"
#include "JVViewer.h"
#include "JVBotClient.h"

JVBotClientUI::JVBotClientUI()
{
    widget.setupUi(this);
    
    
    // Select area
    QObject::connect(widget.pSelectArea, SIGNAL(clicked()), this, SLOT(selectArea()));
    QObject::connect(widget.pStart, SIGNAL(clicked()), this, SLOT(startBot()));
    QObject::connect(widget.pButtonTest, SIGNAL(clicked()), this, SLOT(test()));
    
     
    // Init grid layout
    qint32 nNumRows = 2;
    qint32 nNumColumns = 2;
    for(qint32 nRow = 0; nRow < nNumRows; nRow++)
    {
        for(qint32 nColumn = 0; nColumn < nNumColumns; nColumn++)
        {
             QString strId = QString("%1-%2").arg(nRow).arg(nColumn);

             // Create JVViewer
             JVViewer* pJVViewer = new JVViewer();
             m_hashViewers.insert(strId,pJVViewer);
             widget.pGridLayout->addWidget(pJVViewer,nRow,nColumn);
        }
    }
    
    m_pJVAreaSelector = new JVAreaSelector();
}

void JVBotClientUI::test()
{
    qDebug() << "test";
}

void JVBotClientUI::startBot()
{
    emit signal_startBot();
}

QRect JVBotClientUI::getSelectedArea()
{
    return m_pJVAreaSelector->getSelectedArea();
}

void JVBotClientUI::selectArea()
{
    m_pJVAreaSelector->start();
    // Get area selected
    QRect rectArea = m_pJVAreaSelector->getSelectedArea();
    // Update the bot config

     QString strPath = QString("%1/%2.json")
             .arg(JVBotClient::DATA_PATH + "/Bots")
             .arg("bot1");
    QFile file(strPath);
    
    QString strConfig;
    if (file.open(QFile::ReadOnly | QFile::Text) == true)
    {
        qDebug() << "Load: OK1";

        QString strFile = file.readAll();
        qDebug() << strFile;

        QJsonDocument jsonDocument = QJsonDocument::fromJson(strFile.toUtf8());
        QJsonObject jsonObject = jsonDocument.object();
        QString strId =  jsonObject.value("id").toString();
        
        QJsonValueRef jsonAreaRef = jsonObject.find("area").value();
      
        QJsonObject jsonArea = jsonAreaRef.toObject();
        jsonArea["x"] = rectArea.x();
        jsonArea["y"] = rectArea.y();
        jsonArea["width"] = rectArea.width();
        jsonArea["height"] = rectArea.height();
                
        jsonAreaRef = jsonArea;

        strConfig = QJsonDocument(jsonObject).toJson();

         file.close();
    }
    
    if (file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate) == true)
    {
        qDebug() << "Load: OK2";

        QTextStream out(&file );

         out << strConfig << endl;
     
         file.close();
    }
    
    
}

void JVBotClientUI::render(QString strId, Mat matImage)
{
    //m_hashViewers[strId]->render(matImage);
}

void JVBotClientUI::tick()
{
    //m_pJVAreaSelector->processEvents();
}

JVBotClientUI::~JVBotClientUI() 
{

}
