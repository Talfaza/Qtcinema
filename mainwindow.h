#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include "user.h"
#include "adminwindow.h"
#include "userwindows.h"
#include "placewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openDatabaseConnection();
    void closeDatabaseConnection();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connect;
    AdminWindow *Adminwin;
    UserWindows *UserWin;
    PlaceWindow *PlaceWin;
};

#endif // MAINWINDOW_H
