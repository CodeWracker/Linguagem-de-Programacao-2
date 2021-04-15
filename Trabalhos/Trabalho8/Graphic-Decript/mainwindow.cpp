#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "changealpha.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    message = new Data();
    edit = false;
}

MainWindow::~MainWindow()
{
    delete message;
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
         message->loadMessage(in.readAll().toStdString());
         ui->messageTextEdit->setText(QString::fromStdString(message->dencriptMessage()));
         ui->alphaTextEdit->setText(QString::fromStdString(message->getFrequency()));
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
         message->loadAlphabet(in.readAll().toStdString());
         ui->messageTextEdit->setText(QString::fromStdString(message->dencriptMessage()));
         ui->alphaTextEdit->setText(QString::fromStdString(message->getFrequency()));
         file.close();
     }
     edit = true;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    message->setShift(arg1);
    ui->messageTextEdit->setText(QString::fromStdString(message->dencriptMessage()));
    ui->alphaTextEdit->setText(QString::fromStdString(message->getFrequency()));
}



void MainWindow::on_pushButton_clicked()
{
    // aparece uma nova tela e pede a posição e o novo caractere e ai atualiza os textos em baixo
    if(edit){
        int* position = new int();
        size_t* chr = new size_t();
        bool* cncl = new bool(false);
        ChangeAlpha mDialog;
        mDialog.setModal(true);
        mDialog.pos = position;
        mDialog.newChar = chr;
        mDialog.cncl = cncl;
        mDialog.exec();
        if(*cncl)
            message->addAlpha(*position,*chr);
        delete position;
        delete chr;
        delete cncl;
        ui->messageTextEdit->setText(QString::fromStdString(message->dencriptMessage()));
        ui->alphaTextEdit->setText(QString::fromStdString(message->getFrequency()));
    }
}
