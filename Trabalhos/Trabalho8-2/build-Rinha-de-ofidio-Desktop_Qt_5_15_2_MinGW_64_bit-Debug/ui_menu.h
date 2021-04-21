/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QLabel *BackgroundLabel;
    QPushButton *StartButton;
    QPushButton *AboutButton;
    QPushButton *QuitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(704, 732);
        Menu->setMinimumSize(QSize(704, 732));
        Menu->setMaximumSize(QSize(704, 732));
        Menu->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackgroundLabel = new QLabel(centralwidget);
        BackgroundLabel->setObjectName(QString::fromUtf8("BackgroundLabel"));
        BackgroundLabel->setGeometry(QRect(0, 0, 704, 704));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(264, 320, 176, 64));
        StartButton->setStyleSheet(QString::fromUtf8("QPushButton#StartButton {\n"
"background-color: transparent;\n"
"background-image: url(:/images/StartButton.png);\n"
"border-image: none;\n"
"}\n"
"\n"
"QPushButton#StartButton:pressed {\n"
"	background-image: url(:/images/StartButtonClicked.png);\n"
"}"));
        AboutButton = new QPushButton(centralwidget);
        AboutButton->setObjectName(QString::fromUtf8("AboutButton"));
        AboutButton->setGeometry(QRect(264, 416, 176, 64));
        AboutButton->setStyleSheet(QString::fromUtf8("QPushButton#AboutButton {\n"
"background-color: transparent;\n"
"background-image: url(:/images/AboutButton.png);\n"
"border-image: none;\n"
"}\n"
"\n"
"QPushButton#AboutButton:pressed {\n"
"	background-image: url(:/images/AboutButtonClicked.png);\n"
"}"));
        QuitButton = new QPushButton(centralwidget);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setGeometry(QRect(264, 512, 176, 64));
        QuitButton->setStyleSheet(QString::fromUtf8("QPushButton#QuitButton {\n"
"background-color: transparent;\n"
"background-image: url(:/images/QuitButton.png);\n"
"border-image: none;\n"
"}\n"
"\n"
"QPushButton#QuitButton:pressed {\n"
"	background-image: url(:/images/QuitButtonClicked.png);\n"
"}"));
        Menu->setCentralWidget(centralwidget);
        BackgroundLabel->raise();
        AboutButton->raise();
        QuitButton->raise();
        StartButton->raise();
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 704, 25));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        BackgroundLabel->setText(QString());
        StartButton->setText(QString());
        AboutButton->setText(QString());
        QuitButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
