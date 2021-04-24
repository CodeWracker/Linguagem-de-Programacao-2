/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QLabel *GameOverLabel;
    QLabel *RoundsLabel;
    QLabel *NormalLabel;
    QLabel *BossLabel;
    QLabel *FoodLabel;

    void setupUi(QDialog *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->resize(704, 704);
        GameOver->setMinimumSize(QSize(704, 704));
        GameOver->setMaximumSize(QSize(704, 704));
        GameOver->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        GameOverLabel = new QLabel(GameOver);
        GameOverLabel->setObjectName(QString::fromUtf8("GameOverLabel"));
        GameOverLabel->setGeometry(QRect(0, 0, 704, 704));
        RoundsLabel = new QLabel(GameOver);
        RoundsLabel->setObjectName(QString::fromUtf8("RoundsLabel"));
        RoundsLabel->setGeometry(QRect(384, 352, 96, 32));
        RoundsLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 241, 232);\n"
"font: 32pt '8-bit Arcade In';"));
        NormalLabel = new QLabel(GameOver);
        NormalLabel->setObjectName(QString::fromUtf8("NormalLabel"));
        NormalLabel->setGeometry(QRect(384, 408, 96, 32));
        NormalLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 241, 232);\n"
"font: 32pt '8-bit Arcade In';"));
        BossLabel = new QLabel(GameOver);
        BossLabel->setObjectName(QString::fromUtf8("BossLabel"));
        BossLabel->setGeometry(QRect(384, 472, 96, 32));
        BossLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 241, 232);\n"
"font: 32pt '8-bit Arcade In';"));
        FoodLabel = new QLabel(GameOver);
        FoodLabel->setObjectName(QString::fromUtf8("FoodLabel"));
        FoodLabel->setGeometry(QRect(384, 536, 96, 32));
        FoodLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 241, 232);\n"
"font: 32pt '8-bit Arcade In';"));

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QDialog *GameOver)
    {
        GameOver->setWindowTitle(QCoreApplication::translate("GameOver", "Dialog", nullptr));
        GameOverLabel->setText(QString());
        RoundsLabel->setText(QCoreApplication::translate("GameOver", "x", nullptr));
        NormalLabel->setText(QCoreApplication::translate("GameOver", "x", nullptr));
        BossLabel->setText(QCoreApplication::translate("GameOver", "x", nullptr));
        FoodLabel->setText(QCoreApplication::translate("GameOver", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
