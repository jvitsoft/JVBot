/* 
 * File:   JVBotClient.h
 * Author: javi
 *
 */

#ifndef JVBOTCLIENT_H
#define	JVBOTCLIENT_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QThread>
#include <QTimer>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
//Include some useful constants for image encoding. Refer to: http://www.ros.org/doc/api/sensor_msgs/html/namespacesensor__msgs_1_1image__encodings.html for more info.
#include <sensor_msgs/image_encodings.h>
#include "JVBotClientUI.h"

using namespace cv;

class JVBotClient : public QThread
{
    Q_OBJECT
public:
    JVBotClient();
    ~JVBotClient();
    void run() Q_DECL_OVERRIDE;
    
    void chatterCallback(const std_msgs::String::ConstPtr& msg);
    void imageCallback(const sensor_msgs::ImageConstPtr& img);
    
    static QString DATA_PATH;
public slots:
    void tick();
    void startBot();
    
private:
    QTimer* m_timerTick;
    JVBotClientUI* m_pJVBotClientUI;
    ros::Publisher m_pubStartBot;
};

#endif

