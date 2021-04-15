#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/yes.png");
    int w = ui->label_picture->width();
    int h = ui->label_picture->height();
    //ui->label_picture->setPixmap(pix);
    ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_showButton_clicked()
{
    ui->label_picture->setVisible(true);

}

void myDialog::on_hideButton_clicked()
{
    ui->label_picture->setVisible(false);

}
