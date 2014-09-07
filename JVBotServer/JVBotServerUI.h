/* 
 * File:   JVBotServerUI.h
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 11:52
 */

#ifndef _JVBOTSERVERUI_H
#define	_JVBOTSERVERUI_H

#include "ui_JVBotServerUI.h"
#include "JVRenderArea.h"
#include "JVDataDetected.h"

class JVBotServerUI : public QMainWindow {
    Q_OBJECT
public:
    JVBotServerUI();
    virtual ~JVBotServerUI();
    public slots:
        void onTrain();
        void onAutomaticTrain();
        void onProcessImage();
        void onMouseClicked(QPoint point);
private:
    Ui::JVBotServerUI widget;
    JVRenderArea* m_pRenderArea;
    QList<JVDataDetected> m_lDataDetected;
    
};

#endif	/* _JVBOTSERVERUI_H */
