#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    QPixmap pix(":/me.png");
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->imageLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->imageLabel->setVisible(true);
}

About::~About()
{
    delete ui;
}
