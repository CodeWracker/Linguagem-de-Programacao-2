/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *cen;
    QWidget *layoutWidget;
    QVBoxLayout *ver;
    QHBoxLayout *hor1;
    QLabel *label;
    QDoubleSpinBox *number1;
    QHBoxLayout *hor2;
    QLabel *label_2;
    QDoubleSpinBox *number2;
    QHBoxLayout *hor3;
    QPushButton *Soma;
    QPushButton *Subtracao;
    QPushButton *Multiplicacao;
    QPushButton *Divisao;
    QHBoxLayout *hor4;
    QLabel *label_4;
    QLabel *Result;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(491, 260);
        cen = new QWidget(MainWindow);
        cen->setObjectName(QString::fromUtf8("cen"));
        layoutWidget = new QWidget(cen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 397, 119));
        ver = new QVBoxLayout(layoutWidget);
        ver->setObjectName(QString::fromUtf8("ver"));
        ver->setContentsMargins(0, 0, 0, 0);
        hor1 = new QHBoxLayout();
        hor1->setObjectName(QString::fromUtf8("hor1"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        hor1->addWidget(label);

        number1 = new QDoubleSpinBox(layoutWidget);
        number1->setObjectName(QString::fromUtf8("number1"));
        number1->setMinimumSize(QSize(300, 0));
        number1->setMinimum(-9999.000000000000000);
        number1->setMaximum(9999.000000000000000);

        hor1->addWidget(number1);


        ver->addLayout(hor1);

        hor2 = new QHBoxLayout();
        hor2->setObjectName(QString::fromUtf8("hor2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hor2->addWidget(label_2);

        number2 = new QDoubleSpinBox(layoutWidget);
        number2->setObjectName(QString::fromUtf8("number2"));
        number2->setMinimumSize(QSize(300, 0));
        number2->setMinimum(-9999.000000000000000);
        number2->setMaximum(9999.000000000000000);

        hor2->addWidget(number2);


        ver->addLayout(hor2);

        hor3 = new QHBoxLayout();
        hor3->setObjectName(QString::fromUtf8("hor3"));
        Soma = new QPushButton(layoutWidget);
        Soma->setObjectName(QString::fromUtf8("Soma"));

        hor3->addWidget(Soma);

        Subtracao = new QPushButton(layoutWidget);
        Subtracao->setObjectName(QString::fromUtf8("Subtracao"));

        hor3->addWidget(Subtracao);

        Multiplicacao = new QPushButton(layoutWidget);
        Multiplicacao->setObjectName(QString::fromUtf8("Multiplicacao"));

        hor3->addWidget(Multiplicacao);

        Divisao = new QPushButton(layoutWidget);
        Divisao->setObjectName(QString::fromUtf8("Divisao"));

        hor3->addWidget(Divisao);


        ver->addLayout(hor3);

        hor4 = new QHBoxLayout();
        hor4->setObjectName(QString::fromUtf8("hor4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 200));

        hor4->addWidget(label_4);

        Result = new QLabel(layoutWidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setAlignment(Qt::AlignCenter);

        hor4->addWidget(Result);


        ver->addLayout(hor4);

        MainWindow->setCentralWidget(cen);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 491, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "N\303\272mero 1:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "N\303\272mero 2:", nullptr));
        Soma->setText(QApplication::translate("MainWindow", "+", nullptr));
        Subtracao->setText(QApplication::translate("MainWindow", "-", nullptr));
        Multiplicacao->setText(QApplication::translate("MainWindow", "*", nullptr));
        Divisao->setText(QApplication::translate("MainWindow", "/", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Resultado =", nullptr));
        Result->setText(QApplication::translate("MainWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
