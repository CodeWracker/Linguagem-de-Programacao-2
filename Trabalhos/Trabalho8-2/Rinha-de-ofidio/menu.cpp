#include "menu.h"
#include "gameenv.h"
#include "ui_menu.h"
GameEnv *gameEnv;
Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    gameEnv = new GameEnv();

}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_pushButton_clicked()
{
    gameEnv->gameExecution(0);

    //while (gameEnv->player->isVivo && gameEnv->enemy->isVivo);
    //gameEnv->close();
}
