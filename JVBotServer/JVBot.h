#ifndef JVBOT_H
#define JVBOT_H

#include <QString>
//#include "JVImageProcessor.h"
#include <QJsonObject>
//#include "JVImage.h"
//#include "JVANN.h"
//#include "JVImageManager.h"
#include <QFileSystemWatcher>
#include <QRect>
//Includes all the headers necessary to use the most common public pieces of the ROS system.
#include <ros/ros.h>
//Use image_transport for publishing and subscribing to images in ROS
#include <image_transport/image_transport.h>
//Use cv_bridge to convert between ROS and OpenCV Image formats
#include <cv_bridge/cv_bridge.h>
//Include some useful constants for image encoding. Refer to: http://www.ros.org/doc/api/sensor_msgs/html/namespacesensor__msgs_1_1image__encodings.html for more info.
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/String.h"
#include "JVANN.h"
#include "JVImageManager.h"
#include "JVImageProcessor.h"
#include <QTimer>
#include "JVTrainingSetData.h"
#include "JVTrainer.h"
#include "JVDataDetected.h"

class JVScreenCapturer;

class JVBot : public QObject
{
    Q_OBJECT
public:
    JVBot(QString strId);
    virtual ~JVBot();
    void onInit(QJsonObject joConfig);
    qint32 train();
    qint32 trainAutomatic();
    //virtual QString detect(JVImage* pJVImage) = 0;

       public slots:
    void onUpdate(const QString& strFilePath);
    void onBotChanged();
    virtual void tick();
    qint32 predict(JVTrainingSetData* pJVTrainingSetData);
    QList<JVDataDetected> processImage(QString strBotId);
    
    QList<JVDataDetected> processImage(JVImage* pImage);
    
protected:
    QString m_strId;
     QScopedPointer<QFileSystemWatcher> m_pFileSystemWatcher;
    /*QScopedPointer<JVImageProcessor> m_pJVImageProcessor;
    QScopedPointer<JVANN> m_pJVANN;
    QScopedPointer<JVImageManager> m_pJVImageManager;
*/
    virtual void loadConfig();
    QScopedPointer<QRect> m_pRectArea;
    JVScreenCapturer* m_pJVScreenCapturer;
    image_transport::Publisher m_ImagePublisher;
    
     QScopedPointer<JVImageProcessor> m_pJVImageProcessor;
     QScopedPointer<JVImageProcessor> m_pJVImagePreProcessor;
    QScopedPointer<JVANN> m_pJVANN;
    QScopedPointer<JVImageManager> m_pJVImageManager;
    QTimer m_timerFileChanged;
    QScopedPointer<JVTrainer> m_pJVTrainer;
    
private:
    qint32 m_nCount;
};

#endif
