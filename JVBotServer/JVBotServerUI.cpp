/*
 * File:   JVBotServerUI.cpp
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 11:52
 */
#include "JVBotServer.h"
#include "JVBotServerUI.h"
#include <QDebug>
#include <QInputDialog>

JVBotServerUI::JVBotServerUI() {
    widget.setupUi(this);
    
    
   // JVBotServer::getInstance()->start();
    
   QObject::connect(widget.pButtonTrain, SIGNAL(clicked()), this, SLOT(onTrain()));
    QObject::connect(widget.pButtonAutomaticTrain, SIGNAL(clicked()), this, SLOT(onAutomaticTrain())); 
    
    QObject::connect(widget.pButtonProcessImage, SIGNAL(clicked()), this, SLOT(onProcessImage())); 
    
    
    qDebug() << "LAYOUT WIDTH: " << widget.pRenderLayout->geometry().width();
     m_pRenderArea = new JVRenderArea(this,
                400, //widget.pRenderLayout->geometry().width(),
               400);//widget.pRenderLayout->geometry().height());
            // Display render area
        
        widget.pRenderLayout->layout()->addWidget(m_pRenderArea );
        
        QObject::connect(m_pRenderArea, SIGNAL(sig_mouseClicked(QPoint)), 
                this, SLOT(onMouseClicked(QPoint))); 
        
        
}

void JVBotServerUI::onMouseClicked(QPoint point)
{
    //qDebug() << "JVBotServerUI::onMouseClicked" << point.x() << "," << point.y();
    
    QList<JVDataDetected>::const_iterator itDataDetected;
    for(itDataDetected = m_lDataDetected.begin(); itDataDetected!= m_lDataDetected.end(); itDataDetected++)
    {
        JVDataDetected dataDetected = *itDataDetected;
        Rect rBoundingBox = dataDetected.getBoundingBox();
        //qDebug() << "checking: " << rBoundingBox.x << "," << rBoundingBox.y;
        if(rBoundingBox.contains(Point(point.x(),point.y())))
        {
            qDebug() << "Data selected:" << dataDetected.getData();
            
            // Create dialog for changing the label
            
             bool ok;
            QString text = QInputDialog::getText(this, tr("Train"),
                                                 tr("Label:"), QLineEdit::Normal,
                                                 dataDetected.getData(), &ok);
            if (ok && !text.isEmpty())
            {
                QString strData = text;
                qDebug() << "Data selected:" << strData;
                
                // Save the image
                QString strPath = QString("%1/%2/%3/%4/%5.png")
                    .arg(JVBotServer::DATA_PATH)
                    .arg("Images")
                    .arg("digits")
                    .arg(strData)
                    .arg("autosave");
                
                qDebug() << "Path:" << strPath;
                
                cv::imshow("blob source", dataDetected.getMatSource());
                Mat matSource = dataDetected.getMatSource();
                
                // Get the image from the source
                //cv::Mat matSourceImage = cv::imread(strPath.toStdString(),cv::IMREAD_COLOR);
                //cv::Mat matBlob = matSourceImage(rBoundingBox);    
                imwrite( strPath.toStdString(), matSource );
                
              //  textLabel->setText(text);
            }
            break;
        }
    }
    
}

void JVBotServerUI::onProcessImage()
{
    QString strImageName = widget.pTextBoxImage->text();
    m_lDataDetected = JVBotServer::getInstance()->processImage("bot1",strImageName);
    QString strPath = QString("%1/%2/%3")
             .arg(JVBotServer::DATA_PATH)
             .arg("Images")
             .arg(strImageName);
    
    cv::Mat matSourceImage = cv::imread(strPath.toStdString(),cv::IMREAD_COLOR);
    
    
    QList<JVDataDetected>::const_iterator itDataDetected;
    for(itDataDetected = m_lDataDetected.begin(); itDataDetected!= m_lDataDetected.end(); itDataDetected++)
    {
        JVDataDetected dataDetected = *itDataDetected;
        Rect rBoundingBox = dataDetected.getBoundingBox();
        //cv::Mat matData(rBoundingBox.width,rBoundingBox.height,CV_8U,cv::Scalar(0));

        QString strData = dataDetected.getData();
        if(strData == "?")
        {
            rectangle(matSourceImage,rBoundingBox,CV_RGB(255,0,0),1);
        }
        else
        {
            // Draw bounding box in the color image
            rectangle(matSourceImage,rBoundingBox,CV_RGB(255,255,255),CV_FILLED);

            qDebug() << "Put text: " << dataDetected.getData();
            qDebug() << "Point: " << rBoundingBox.br().x << "," << rBoundingBox.br().y;
            //src.copyTo(dst(Rect(left, top, src.cols, src.rows)));
            //putText(matData,dataDetected.getData(),rBoundingBox.br(),1,1,Scalar::all(255) 3,8);
            Point point(rBoundingBox.x,rBoundingBox.br().y);
            putText(matSourceImage, dataDetected.getData().toStdString(), point, 
                FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,0), 1, CV_AA);
        }
    }
    
    m_pRenderArea->render(matSourceImage);
    //cv::imshow("FINAL2", matSourceImage);
}

void JVBotServerUI::onTrain()
{
    qDebug() << "train!";
    // We want to receive the % errors
    qint32 nErrorPct = JVBotServer::getInstance()->train("bot1");
    widget.pTextBoxErrors->setText(QString("%1").arg(nErrorPct));
}

void JVBotServerUI::onAutomaticTrain()
{
    qDebug() << "Automatic train!";
    qint32 nErrorPct = JVBotServer::getInstance()->trainAutomatic("bot1");
}

JVBotServerUI::~JVBotServerUI() {
}
