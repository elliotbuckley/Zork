#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <ZorkUL.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Sets up the ui window

    ui->gameText->append(QString::fromStdString(zork->printWelcome() + "\n")); // runs the printWelcome function from ZorkUL.cpp upon startup
}

MainWindow::~MainWindow() // Destructor, terminates  the ui when finsihed
{
    delete ui;
}


// Runs the printHelp function from ZorkUL.cpp when the help button is pressed
void MainWindow::on_helpButton_clicked()
{
     ui->gameText->append(QString::fromStdString(zork->printHelp()));
}


// Runs the showMap function from ZorkUL.cpp when the map button is pressed
void MainWindow::on_mapButton_clicked()
{
    ui->gameText->append(QString::fromStdString(zork->showMap()));
}


/*
 * goRoom is a function that actually moves the player between the rooms
 * if the player clicks teleport the room is random
 * else the player moves in the direction that they chose if said move is possible
 */
void MainWindow::goRoom(string direction)
{
    if (direction == "teleport")
    {
        ui->gameText->append(QString::fromStdString(zork->teleport() + "\n"));
    }
    else
    {
        ui->gameText->append(QString::fromStdString(zork->goToRoom(direction) + "\n"));
    }
}


// Calls the goRoom function from above when the player presses a movement button
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


void MainWindow::on_teleportButton_clicked()
{
    goRoom("teleport");
}






