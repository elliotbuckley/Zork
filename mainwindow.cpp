#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"

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


void MainWindow::on_northButton_clicked()
{
    parseInput("go north");
}


void MainWindow::on_eastButton_clicked()
{

}


void MainWindow::on_southButton_clicked()
{

}


void MainWindow::on_westButton_clicked()
{

}



