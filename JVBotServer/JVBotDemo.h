#ifndef JVBOTDEMO_H
#define JVBOTDEMO_H

#include <QString>
#include "JVBot.h"
//#include "JVTrainingSetData.h"

class JVBotDemo : public JVBot
{
    Q_OBJECT
public:
    JVBotDemo(QString strId);
    ~JVBotDemo();

    void onInit(QJsonObject joConfig);

    void train();
    void loadConfig() Q_DECL_OVERRIDE;
    void tick() Q_DECL_OVERRIDE;

    //

    //QString detect(JVImage* pJVImage);
    //void addInputs(cv::Mat matInputs, cv::Mat matImage, qint32 nRow);
private:


};

#endif
