#ifndef MENU_H
#define MENU_H

#include "about.hpp"
#include "gameover.hpp"
#include <QMainWindow>
#include <QMovie>
#include <QMediaPlayer>
#include "gameenv.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_StartButton_clicked();

    void on_AboutButton_clicked();

    void on_QuitButton_clicked();

private:
    QMediaPlayer * MenuMusic;
    Ui::Menu *ui;
    GameEnv* gameEnv;
};
#endif // MENU_H
