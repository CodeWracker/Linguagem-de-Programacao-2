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
    Data *message;
    bool edit;

public:
    MainWindow(QWidget *parent = nullptr);
    vector<string> splitString(string s, char it)
    {
        string str;
        vector<string> ret;
        for (char c : s)
        {
            if (c == it)
            {
                ret.emplace_back(str);
                str.clear();
            }
            else
            {
                str = str + c;
            }
        }
        ret.emplace_back(str);
        return ret;
    }
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionOpen_encripted_data_triggered();

    void on_actionOpen_tips_triggered();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
