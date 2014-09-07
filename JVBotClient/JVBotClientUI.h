/* 
 * File:   JVBotClientUI.h
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 13:48
 */

#ifndef _JVBOTCLIENTUI_H
#define	_JVBOTCLIENTUI_H

#include "ui_JVBotClientUI.h"
#include "JVRenderArea.h"
#include <QHash>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
class JVAreaSelector;
class JVViewer;

using namespace cv;

class JVBotClientUI : public QMainWindow {
    Q_OBJECT
public:
    JVBotClientUI();
    virtual ~JVBotClientUI();
    void render(QString strId,Mat matImage);
    void tick();
    QRect getSelectedArea();
public slots:
    void selectArea();
    void startBot();
    void test();
private:
    Ui::JVBotClientUI widget;
    QHash<QString,JVViewer*> m_hashViewers;
    JVAreaSelector* m_pJVAreaSelector;

signals:
    void signal_startBot();
};

#endif	/* _JVBOTCLIENTUI_H */
