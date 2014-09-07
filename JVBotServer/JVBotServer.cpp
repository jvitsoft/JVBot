
#include "JVBotServer.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "JVScreenCapturer.h"

JVBotServer* JVBotServer::m_pInstance = NULL;  

QString JVBotServer::DATA_PATH = "/home/vrs/NetBeansProjects/Data";

JVBotServer::JVBotServer()
{
    m_timerTick = new QTimer(this);
    connect(m_timerTick, SIGNAL(timeout()), this, SLOT(tick()));
    m_timerTick->start(5000);
    
    pJVScreenCapturer = new JVScreenCapturer();
    m_bCaptureImages = false;
    
    m_pJVBotManager.reset(new JVBotManager());

}

JVBotServer* JVBotServer::getInstance()
{
    if (m_pInstance == NULL)
        m_pInstance = new JVBotServer();

    return m_pInstance;
}

JVBotServer::~JVBotServer()
{
    
}

QList<JVDataDetected> JVBotServer::processImage(QString strBotId,QString strImageName)
{
     return m_pJVBotManager->processImage(strBotId,strImageName);
}

void JVBotServer::startBotRequest(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("New request: [%s]", msg->data.c_str());
    
    QJsonDocument jsonDocument = QJsonDocument::fromJson(msg->data.c_str());
    QJsonObject jsonObject = jsonDocument.object();
    
    m_pJVBotManager->addBot(jsonObject);
    /*

    QString strBotName = jsonObject.value("botName").toString();
    qDebug() << "BotName:" << strBotName;

    QJsonObject jsonArea = jsonObject.value("area").toObject();
    qint32 nX = jsonArea.value("x").toInt();
    qint32 nY = jsonArea.value("y").toInt();
    qint32 nHeight = jsonArea.value("height").toInt();
    qint32 nWidth = jsonArea.value("width").toInt();
    
    QRect rectArea(nX,nY,nWidth,nHeight);
    qDebug() << rectArea;     
    
    pJVScreenCapturer->setArea(rectArea);
    m_bCaptureImages = true;
    */
}

void JVBotServer::run()
{
    qDebug() << "run";
  
    ros::NodeHandle nodeHandle;
    //Create an ImageTransport instance, initializing it with our NodeHandle.
    image_transport::ImageTransport imageTransport(nodeHandle);
    
    /**
    * The advertise() function is how you tell ROS that you want to
    * publish on a given topic name. This invokes a call to the ROS
    * master node, which keeps a registry of who is publishing and who
    * is subscribing. After this advertise() call is made, the master
    * node will notify anyone who is trying to subscribe to this topic name,
    * and they will in turn negotiate a peer-to-peer connection with this
    * node.  advertise() returns a Publisher object which allows you to
    * publish messages on that topic through a call to publish().  Once
    * all copies of the returned Publisher object are destroyed, the topic
    * will be automatically unadvertised.
    *
    * The second parameter to advertise() is the size of the message queue
    * used for publishing messages.  If messages are published more quickly
    * than we can send them, the number here specifies how many messages to
    * buffer up before throwing some away.
    */
    //m_ImagePublisher = imageTransport.advertise("screen_capturer", 1);
      m_ImagePublisher = imageTransport.advertise("/source", 1);  

      
   m_startBotPublisher = nodeHandle.subscribe("/startBot", 1000, 
           &JVBotServer::startBotRequest, this);
    
    ros::spin();
    
    //image_transport::Subscriber sub = it.subscribe("camera/image_raw", 1, imageCallback);
/*    ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);
*/
/*
  int count = 0;
  while (ros::ok())
  {
    
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

  
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    //if(count > 5)
    //break;
    //++count;
  }*/
}

qint32 JVBotServer::train(QString strBotId)
{
    return m_pJVBotManager->train(strBotId);
}

qint32 JVBotServer::trainAutomatic(QString strBotId)
{
    return m_pJVBotManager->trainAutomatic(strBotId);
}

void JVBotServer::tick()
{
    qDebug() << "JVBotServer::tick";
    m_pJVBotManager->tick();
 
    if(m_bCaptureImages == true)
    {
        cv_bridge::CvImage cv_image;
        cv_image.image = pJVScreenCapturer->getImage();

        //cv_image.image.

        qDebug() << "published image";
         cv_image.encoding = sensor_msgs::image_encodings::BGRA8;
         sensor_msgs::Image ros_image;
         cv_image.toImageMsg(ros_image);

         // Get image from the screen capturer
         //Convert the CvImage to a ROS image message and publish it on the "camera/image_processed" topic.
         m_ImagePublisher.publish(ros_image);
    }
    /*ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);


  int count = 0;
  while (ros::ok())
  {
      
  }*/
}