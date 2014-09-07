/********************************************************************************
** Form generated from reading UI file 'JVBotClientUI.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JVBOTCLIENTUI_H
#define UI_JVBOTCLIENTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JVBotClientUI
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pStart;
    QPushButton *pSelectArea;
    QPushButton *pManualCapture;
    QPushButton *pButtonTest;
    QGridLayout *pGridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JVBotClientUI)
    {
        if (JVBotClientUI->objectName().isEmpty())
            JVBotClientUI->setObjectName(QStringLiteral("JVBotClientUI"));
        JVBotClientUI->resize(439, 368);
        centralwidget = new QWidget(JVBotClientUI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pStart = new QPushButton(centralwidget);
        pStart->setObjectName(QStringLiteral("pStart"));

        gridLayout->addWidget(pStart, 0, 0, 1, 1);

        pSelectArea = new QPushButton(centralwidget);
        pSelectArea->setObjectName(QStringLiteral("pSelectArea"));

        gridLayout->addWidget(pSelectArea, 0, 1, 1, 1);

        pManualCapture = new QPushButton(centralwidget);
        pManualCapture->setObjectName(QStringLiteral("pManualCapture"));

        gridLayout->addWidget(pManualCapture, 0, 2, 1, 1);

        pButtonTest = new QPushButton(centralwidget);
        pButtonTest->setObjectName(QStringLiteral("pButtonTest"));

        gridLayout->addWidget(pButtonTest, 0, 3, 1, 1);

        pGridLayout = new QGridLayout();
        pGridLayout->setObjectName(QStringLiteral("pGridLayout"));

        gridLayout->addLayout(pGridLayout, 1, 0, 1, 4);

        JVBotClientUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JVBotClientUI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 439, 25));
        JVBotClientUI->setMenuBar(menubar);
        statusbar = new QStatusBar(JVBotClientUI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        JVBotClientUI->setStatusBar(statusbar);

        retranslateUi(JVBotClientUI);

        QMetaObject::connectSlotsByName(JVBotClientUI);
    } // setupUi

    void retranslateUi(QMainWindow *JVBotClientUI)
    {
        JVBotClientUI->setWindowTitle(QApplication::translate("JVBotClientUI", "JVBotClientUI", 0));
        pStart->setText(QApplication::translate("JVBotClientUI", "Start", 0));
        pSelectArea->setText(QApplication::translate("JVBotClientUI", "Select Area", 0));
        pManualCapture->setText(QApplication::translate("JVBotClientUI", "Manual Capture", 0));
        pButtonTest->setText(QApplication::translate("JVBotClientUI", "Test", 0));
    } // retranslateUi

};

namespace Ui {
    class JVBotClientUI: public Ui_JVBotClientUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JVBOTCLIENTUI_H
