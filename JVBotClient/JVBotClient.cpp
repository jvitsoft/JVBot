#include "JVBotClient.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

QString JVBotClient::DATA_PATH = "/home/vrs/NetBeansProjects/Data";

JVBotClient::JVBotClient()
{
    m_timerTick = new QTimer(this);
    connect(m_timerTick, SIGNAL(timeout()), this, SLOT(tick()));
    m_timerTick->start(2000);
    m_pJVBotClientUI = new JVBotClientUI();
    m_pJVBotClientUI->show();
    connect(m_pJVBotClientUI, SIGNAL(signal_startBot()), this, SLOT(startBot()));
}
    
JVBotClient::~JVBotClient()
{
    
}

void JVBotClient::startBot()
{
    qDebug() << "start bot!";
    
    QJsonObject jsonStartBotRequest;
    jsonStartBotRequest["botName"] = QStringLiteral("bot1");
    jsonStartBotRequest["botType"] = QStringLiteral("Demo");
 
    QJsonObject jsonArea;
    QRect rectArea = m_pJVBotClientUI->getSelectedArea();
    jsonArea["x"] = rectArea.x();
    jsonArea["y"] = rectArea.y();
    jsonArea["width"] = rectArea.width();
    jsonArea["height"] = rectArea.height();
    
    jsonStartBotRequest["area"] = jsonArea;
    
    QString aux = QJsonDocument(jsonStartBotRequest).toJson();
    qDebug() << aux;
    std_msgs::String msg;

    std::stringstream ss;
    ss << aux.toStdString();
    msg.data = ss.str();

    m_pubStartBot.publish(msg);
}

void JVBotClient::imageCallback(const sensor_msgs::ImageConstPtr& img)
{
    ROS_INFO("Image recived");
    cv_bridge::CvImagePtr cv_ptr;
    //Always copy, returning a mutable CvImage
    //OpenCV expects color images to use BGR channel order.
    cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);

    m_pJVBotClientUI->render("0-0",cv_ptr->image);
}

void JVBotClient::chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void JVBotClient::run()
{
    qDebug() << "run";
    ros::NodeHandle nodeHandle;
    ros::Subscriber sub = nodeHandle.subscribe("chatter", 1000, &JVBotClient::chatterCallback, this);
    
    
    m_pubStartBot = nodeHandle.advertise<std_msgs::String>("/startBot", 1000);
      
   // image_transport::ImageTransport imageTransport(nodeHandle);
   // image_transport::Subscriber subImage = imageTransport.subscribe("/screen_capturer", 1, &JVBotClient::imageCallback, this);

    ros::spin();
}

void JVBotClient::tick()
{
    qDebug() << "Tick";
    m_pJVBotClientUI->tick();
}