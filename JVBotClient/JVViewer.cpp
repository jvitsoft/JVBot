/*
 * File:   JVViewer.cpp
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 21:13
 */

#include "JVViewer.h"
#include "JVRenderArea.h"
#include <QDebug>
#include "JVRenderArea.h"

JVViewer::JVViewer(QWidget *parent) : QWidget(parent){
    widget.setupUi(this);
    
    QObject::connect(widget.pComboBoxType,
           SIGNAL(currentIndexChanged(QString)), this, SLOT(onTypeChanged(QString)));
}
/*
void JVViewer::imageCallback(const sensor_msgs::ImageConstPtr& img)
{
    qDebug() << "Image receivied!";
}*/

void JVViewer::onTypeChanged(QString strType)
{
    qDebug() << "Type: " << strType;
    if(strType == "Source")
    {
        qDebug() << "Created render area";
        
        // Display render area
        widget.pGridLayout->layout()->removeWidget( widget.pWidget );
        JVRenderArea* pRenderArea = new JVRenderArea(this,
                widget.pWidget->geometry().width(),
                widget.pWidget->geometry().height());
        delete widget.pWidget;
        widget.pWidget = pRenderArea;
        widget.pGridLayout->layout()->addWidget( widget.pWidget );

        // Subscribe to the source topic
        ros::NodeHandle nodeHandle;      
        image_transport::ImageTransport imageTransport(nodeHandle);
        QString strNameTopic = QString("/%1/images/%2").arg("bot1").arg("source");
        m_subImage = imageTransport.subscribe(strNameTopic.toStdString(), 
                1, &JVRenderArea::imageCallback, pRenderArea);

    }
}

JVViewer::~JVViewer() {
}
