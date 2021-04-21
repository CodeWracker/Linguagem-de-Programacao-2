#include "menu.hpp"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    /*setCentralWidget(ui->BackgroundLabel);
    QMovie *movie = new QMovie(":/images/MenuBackground.gif");
    ui->BackgroundLabel->setMovie(movie);
    movie->start();*/
    QPixmap pix(":/images/MenuBackgroundImage.png");
    int w = ui->BackgroundLabel->width();
    int h = ui->BackgroundLabel->height();
    ui->BackgroundLabel->setPixmap(pix.scaled(w,h));
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_StartButton_clicked()
{

}

void Menu::on_AboutButton_clicked()
{
    About autores;
    autores.exec();
}

void Menu::on_QuitButton_clicked()
{
    Menu::close();
}
