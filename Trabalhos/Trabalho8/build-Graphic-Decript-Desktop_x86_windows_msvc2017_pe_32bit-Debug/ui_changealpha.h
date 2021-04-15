/********************************************************************************
** Form generated from reading UI file 'changealpha.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEALPHA_H
#define UI_CHANGEALPHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeAlpha
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *spinBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *ChangeAlpha)
    {
        if (ChangeAlpha->objectName().isEmpty())
            ChangeAlpha->setObjectName(QString::fromUtf8("ChangeAlpha"));
        ChangeAlpha->resize(369, 211);
        buttonBox = new QDialogButtonBox(ChangeAlpha);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 160, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(ChangeAlpha);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 30, 131, 41));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        widget = new QWidget(ChangeAlpha);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 90, 320, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 1, 0, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);


        retranslateUi(ChangeAlpha);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeAlpha, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeAlpha, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeAlpha);
    } // setupUi

    void retranslateUi(QDialog *ChangeAlpha)
    {
        ChangeAlpha->setWindowTitle(QApplication::translate("ChangeAlpha", "Dialog", nullptr));
        label_2->setText(QApplication::translate("ChangeAlpha", "Change alphabet", nullptr));
        label->setText(QApplication::translate("ChangeAlpha", "Position", nullptr));
        label_3->setText(QApplication::translate("ChangeAlpha", "New Char", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeAlpha: public Ui_ChangeAlpha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEALPHA_H
