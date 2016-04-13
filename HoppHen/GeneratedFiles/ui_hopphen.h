/********************************************************************************
** Form generated from reading UI file 'hopphen.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOPPHEN_H
#define UI_HOPPHEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoppHenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HoppHenClass)
    {
        if (HoppHenClass->objectName().isEmpty())
            HoppHenClass->setObjectName(QStringLiteral("HoppHenClass"));
        HoppHenClass->resize(600, 400);
        menuBar = new QMenuBar(HoppHenClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HoppHenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HoppHenClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HoppHenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HoppHenClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HoppHenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HoppHenClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HoppHenClass->setStatusBar(statusBar);

        retranslateUi(HoppHenClass);

        QMetaObject::connectSlotsByName(HoppHenClass);
    } // setupUi

    void retranslateUi(QMainWindow *HoppHenClass)
    {
        HoppHenClass->setWindowTitle(QApplication::translate("HoppHenClass", "HoppHen", 0));
    } // retranslateUi

};

namespace Ui {
    class HoppHenClass: public Ui_HoppHenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOPPHEN_H
