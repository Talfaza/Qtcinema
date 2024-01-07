// userwindows.cpp
#include "userwindows.h"
#include "ui_userwindows.h"
#include <QtSql>
#include <QtDebug>
#include <QStandardItemModel>
#include "mainwindow.h"
#include "placewindow.h"
UserWindows::UserWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindows)
{
    ui->setupUi(this);

    // Connect to the database
    DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");
    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:" << DB_Connect.lastError().text();
    } else {
        qDebug() << "Connected";
    }

    setupModel();
}

UserWindows::~UserWindows()
{
    delete ui;
}

void UserWindows::setupModel()
{
    filmModel = new QSqlQueryModel(this);
    filmModel->setQuery("SELECT * FROM film");

    if (filmModel->lastError().isValid()) {
        qDebug() << "Error executing query:" << filmModel->lastError().text();
    } else {
        // Set the model to the QTableView
        ui->tableView->setModel(filmModel);
    }
}



void UserWindows::on_pushButton_clicked()
{
    PlaceWindow *PlaceWin = new PlaceWindow(this);
    PlaceWin->show();
}

void UserWindows::on_pushButton_2_clicked()
{
    MainWindow *main_w = new MainWindow(this);
    this->hide();
    main_w->show();
}

void UserWindows::on_pushButton_3_clicked()
{
    //reload
     setupModel();
}
