#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Data message;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionOpen_encripted_data_triggered();

    void on_actionOpen_tips_triggered();

    void on_spinBox_valueChanged(int arg1);

    void on_alphaTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
