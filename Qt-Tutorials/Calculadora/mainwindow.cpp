#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculadora");
    ui->Result->setText("0,0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Soma_clicked()
{
    ui-> Result->setAutoFillBackground(false);
    ui->Result->setText( QString::number( ui->number1->value() + ui->number2->value()) );
}

void MainWindow::on_Subtracao_clicked()
{
    ui-> Result->setAutoFillBackground(false);
    ui->Result->setText( QString::number( ui->number1->value() - ui->number2->value()) );
}

void MainWindow::on_Multiplicacao_clicked()
{
    ui-> Result->setAutoFillBackground(false);
    ui->Result->setText( QString::number( ui->number1->value() * ui->number2->value()) );
}

void MainWindow::on_Divisao_clicked()
{
    if(ui->number2->value() != 0){
        ui-> Result->setAutoFillBackground(false);
        ui->Result->setText( QString::number( ui->number1->value() / ui->number2->value()) );
    }
    else{
        QPalette sample_palette;
        sample_palette.setColor(QPalette::Window, Qt::red);
        ui-> Result->setAutoFillBackground(true);
        ui-> Result->setPalette(sample_palette);

        ui->Result->setText("Impossivel dividir por O!");
    }
}

