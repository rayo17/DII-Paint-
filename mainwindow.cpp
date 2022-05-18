#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas=new Screen();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}



void MainWindow::on_create_clicked()
{
    int x=ui->widht->text().toInt();

    int y = ui->height->text().toInt();
    canvas->createScreen(x,y);

    canvas->show();
    qDebug()<<"f";
}


void MainWindow::on_actionsize_triggered()
{

}


void MainWindow::on_actioncolor_triggered()
{

}

