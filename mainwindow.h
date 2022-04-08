#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "ZorkUL.h"

namespace Ui
{
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Room; // friendship

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // destructor used

private slots:
    void on_mapButton_clicked();
    void on_helpButton_clicked();
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_eastButton_clicked();
    void on_westButton_clicked();
    void on_teleportButton_clicked();


private:
    Ui::MainWindow *ui;
    ZorkUL *zork = new ZorkUL();
    void goRoom(string direction);

};
#endif
