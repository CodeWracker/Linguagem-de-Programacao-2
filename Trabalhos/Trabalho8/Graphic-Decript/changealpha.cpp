#include "changealpha.h"
#include "ui_changealpha.h"

ChangeAlpha::ChangeAlpha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeAlpha)
{
    ui->setupUi(this);
    pos = 0;
}

ChangeAlpha::~ChangeAlpha()
{
    delete ui;
}

void ChangeAlpha::on_textEdit_textChanged()
{
    string text = ui->textEdit->toPlainText().toStdString();
    if(text != "")
    {
        *newChar = int(text[0]);
    }
}

void ChangeAlpha::on_spinBox_valueChanged(int arg1)
{

    *pos = arg1;
}

void ChangeAlpha::on_buttonBox_accepted()
{
    *cncl = true;
}

void ChangeAlpha::on_buttonBox_rejected()
{
    *cncl = false;
}
