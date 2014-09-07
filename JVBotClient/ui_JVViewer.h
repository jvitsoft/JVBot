/********************************************************************************
** Form generated from reading UI file 'JVViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JVVIEWER_H
#define UI_JVVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JVViewer
{
public:
    QGridLayout *gridLayout;
    QComboBox *pComboBoxType;
    QGridLayout *pGridLayout;
    QWidget *pWidget;

    void setupUi(QWidget *JVViewer)
    {
        if (JVViewer->objectName().isEmpty())
            JVViewer->setObjectName(QStringLiteral("JVViewer"));
        JVViewer->resize(400, 300);
        gridLayout = new QGridLayout(JVViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pComboBoxType = new QComboBox(JVViewer);
        pComboBoxType->setObjectName(QStringLiteral("pComboBoxType"));

        gridLayout->addWidget(pComboBoxType, 0, 0, 1, 1);

        pGridLayout = new QGridLayout();
        pGridLayout->setObjectName(QStringLiteral("pGridLayout"));
        pWidget = new QWidget(JVViewer);
        pWidget->setObjectName(QStringLiteral("pWidget"));

        pGridLayout->addWidget(pWidget, 0, 0, 1, 1);


        gridLayout->addLayout(pGridLayout, 1, 0, 1, 1);


        retranslateUi(JVViewer);

        QMetaObject::connectSlotsByName(JVViewer);
    } // setupUi

    void retranslateUi(QWidget *JVViewer)
    {
        JVViewer->setWindowTitle(QApplication::translate("JVViewer", "JVViewer", 0));
        pComboBoxType->clear();
        pComboBoxType->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("JVViewer", "Source", 0)
         << QApplication::translate("JVViewer", "Blobs", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class JVViewer: public Ui_JVViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JVVIEWER_H
