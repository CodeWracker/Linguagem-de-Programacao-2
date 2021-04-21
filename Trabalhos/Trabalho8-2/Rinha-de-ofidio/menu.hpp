#ifndef MENU_H
#define MENU_H

#include "about.hpp"
#include <QMainWindow>
#include <QMovie>

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
    Ui::Menu *ui;
};
#endif // MENU_H
