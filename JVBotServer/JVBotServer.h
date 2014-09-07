/* 
 * File:   JVBotServer.h
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 13:18
 */

#ifndef JVBOTSERVER_H
#define	JVBOTSERVER_H

#include <QThread>
#include <QTimer>
#include <QDebug>
#include "JVBotManager.h"
#include "JVBot.h"

//Includes all the headers necessary to use the most common public pieces of the ROS system.
#include <ros/ros.h>
//Use image_transport for publishing and subscribing to images in ROS
#include <image_transport/image_transport.h>
//Use cv_bridge to convert between ROS and OpenCV Image formats
#include <cv_bridge/cv_bridge.h>
//Include some useful constants for image encoding. Refer to: http://www.ros.org/doc/api/sensor_msgs/html/namespacesensor__msgs_1_1image__encodings.html for more info.
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/String.h"
#include "JVDataDetected.h"
class JVScreenCapturer;
using namespace cv;


class JVBotServer : public QThread
{
    Q_OBJECT
public:
   
    ~JVBotServer();
    void run() Q_DECL_OVERRIDE;
    void startBotRequest(const std_msgs::String::ConstPtr& msg);
    static JVBotServer* getInstance();
    
     static QString DATA_PATH;
     qint32 train(QString strBotId);
     qint32 trainAutomatic(QString strBotId);
     QList<JVDataDetected> processImage(QString strBotId,QString strImageName);
     
public slots:
    void tick();
    
   
    
private:
    QTimer* m_timerTick;
    JVScreenCapturer* pJVScreenCapturer;
    //ros::Publisher m_ImagePublisher;
    image_transport::Publisher m_ImagePublisher;
    ros::Subscriber m_startBotPublisher;
    bool m_bCaptureImages;
    
    QScopedPointer<JVBotManager> m_pJVBotManager;
    QHash<QString,JVBot*> m_hashBots;
    JVBotServer();
    static JVBotServer* m_pInstance;
    
};

#endif	/* JVBOTSERVER_H */

