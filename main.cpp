#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication Zork(argc, argv); // Creates the Zork Application
    MainWindow gameWindow; // Creates the mainwindow and names it "gameWindow"
    gameWindow.show(); // shows gameWindow on the screem
    return Zork.exec(); // executes the Zork application
}
