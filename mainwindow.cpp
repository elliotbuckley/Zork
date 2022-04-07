#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

/*
template <typename T>
void addItem(vector<T> v, T t)
{
    v.push_back(t);
}
*/

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gameText->append(QString::fromStdString(zork->printWelcome() + "\n"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_northButton_clicked()
{
    goRoom("north");
}


void MainWindow::on_southButton_clicked()
{
    goRoom("south");
}


void MainWindow::on_eastButton_clicked()
{
    goRoom("east");
}


void MainWindow::on_westButton_clicked()
{
    goRoom("west");
}

void MainWindow::on_mapButton_clicked()
{
    ui->gameText->append(QString::fromStdString(zork->showMap()));
}

/*
void MainWindow::on_currentRoom_clicked()
{
    ui->gameText->append(QString::fromStdString(zork->getCurrentRoom()));
}
*/

void MainWindow::on_helpButton_clicked()
{
     ui->gameText->append(QString::fromStdString(zork->printHelp()));
}

void MainWindow::on_teleportButton_clicked()
{
    ui->gameText->append(QString::fromStdString(zork->teleport() + "\n"));
}

