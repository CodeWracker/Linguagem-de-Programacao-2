#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    About mDialog;
    mDialog.setModal(true);
    mDialog.exec();

}

void MainWindow::on_actionOpen_encripted_data_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
    QString(),
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
     if (!fileName.isEmpty()) {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
             return;
         }
         QTextStream in(&file);
         message.loadMessage(in.readAll().toStdString());
         ui->messageTextEdit->setText(QString::fromStdString(message.dencriptMessage()));
         ui->alphaTextEdit->setText(QString::fromStdString(message.getFrequency()));
         file.close();
     }
}

void MainWindow::on_actionOpen_tips_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
    QString(),
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
     if (!fileName.isEmpty()) {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
             return;
         }
         QTextStream in(&file);
         message.loadAlphabet(in.readAll().toStdString());
         ui->messageTextEdit->setText(QString::fromStdString(message.dencriptMessage()));
         ui->alphaTextEdit->setText(QString::fromStdString(message.getFrequency()));
         file.close();
     }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    message.setShift(arg1);
    ui->messageTextEdit->setText(QString::fromStdString(message.dencriptMessage()));
    ui->alphaTextEdit->setText(QString::fromStdString(message.getFrequency()));
}

void MainWindow::on_alphaTextEdit_textChanged()
{
    vector<string> t;
    stringstream s;
    s <<ui->alphaTextEdit->toPlainText().toStdString();
    string tmp;
    while (s>>tmp) {
        t = splitString(tmp,' ');
        if(t.size()>0) cout <<t.at(t.size()-1);
    }

}
