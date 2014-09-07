/********************************************************************************
** Form generated from reading UI file 'JVBotServerUI.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JVBOTSERVERUI_H
#define UI_JVBOTSERVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JVBotServerUI
{
public:
    QWidget *centralwidget;
    QPushButton *pButtonTrain;
    QLabel *label;
    QLineEdit *pTextBoxErrors;
    QPushButton *pButtonAutomaticTrain;
    QPushButton *pButtonProcessImage;
    QLabel *label_2;
    QLineEdit *pTextBoxImage;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *pRenderLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JVBotServerUI)
    {
        if (JVBotServerUI->objectName().isEmpty())
            JVBotServerUI->setObjectName(QStringLiteral("JVBotServerUI"));
        JVBotServerUI->resize(582, 480);
        centralwidget = new QWidget(JVBotServerUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pButtonTrain = new QPushButton(centralwidget);
        pButtonTrain->setObjectName(QStringLiteral("pButtonTrain"));
        pButtonTrain->setGeometry(QRect(50, 50, 99, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 100, 67, 17));
        pTextBoxErrors = new QLineEdit(centralwidget);
        pTextBoxErrors->setObjectName(QStringLiteral("pTextBoxErrors"));
        pTextBoxErrors->setGeometry(QRect(120, 90, 113, 27));
        pButtonAutomaticTrain = new QPushButton(centralwidget);
        pButtonAutomaticTrain->setObjectName(QStringLiteral("pButtonAutomaticTrain"));
        pButtonAutomaticTrain->setGeometry(QRect(240, 50, 131, 27));
        pButtonProcessImage = new QPushButton(centralwidget);
        pButtonProcessImage->setObjectName(QStringLiteral("pButtonProcessImage"));
        pButtonProcessImage->setGeometry(QRect(300, 140, 99, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 140, 131, 17));
        pTextBoxImage = new QLineEdit(centralwidget);
        pTextBoxImage->setObjectName(QStringLiteral("pTextBoxImage"));
        pTextBoxImage->setGeometry(QRect(180, 140, 113, 27));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 200, 491, 221));
        pRenderLayout = new QVBoxLayout(verticalLayoutWidget);
        pRenderLayout->setObjectName(QStringLiteral("pRenderLayout"));
        pRenderLayout->setContentsMargins(0, 0, 0, 0);
        JVBotServerUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JVBotServerUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 582, 25));
        JVBotServerUI->setMenuBar(menubar);
        statusbar = new QStatusBar(JVBotServerUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        JVBotServerUI->setStatusBar(statusbar);

        retranslateUi(JVBotServerUI);

        QMetaObject::connectSlotsByName(JVBotServerUI);
    } // setupUi

    void retranslateUi(QMainWindow *JVBotServerUI)
    {
        JVBotServerUI->setWindowTitle(QApplication::translate("JVBotServerUI", "JVBotServerUI", 0));
        pButtonTrain->setText(QApplication::translate("JVBotServerUI", "Manual Train", 0));
        label->setText(QApplication::translate("JVBotServerUI", "Errors:", 0));
        pButtonAutomaticTrain->setText(QApplication::translate("JVBotServerUI", "Automatic Train", 0));
        pButtonProcessImage->setText(QApplication::translate("JVBotServerUI", "Process", 0));
        label_2->setText(QApplication::translate("JVBotServerUI", "Process Image", 0));
        pTextBoxImage->setText(QApplication::translate("JVBotServerUI", "numbers.png", 0));
    } // retranslateUi

};

namespace Ui {
    class JVBotServerUI: public Ui_JVBotServerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JVBOTSERVERUI_H
