#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "adminwindow.h"
#include "userwindows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    QString inputName = ui->lineEdit->text();
    QString inputPassword = ui->lineEdit_2->text();

    User currentUser(inputName, inputPassword);


    if (currentUser.SelectUser(inputName,inputPassword) == 1) {
        qDebug() << "User is an admin";
        this->hide();
        Adminwin = new AdminWindow(this);
        Adminwin->show();


    }else if (currentUser.SelectUser(inputName,inputPassword) == 0) {
        this->hide();
        UserWin = new UserWindows(this);
        UserWin->show();
        qDebug() << "User is a regular user";






    }else if (currentUser.SelectUser(inputName,inputPassword) == 2) {


    }else {

}
}
void MainWindow::on_pushButton_3_clicked()
{
    QSqlDatabase DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");

    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:" << DB_Connect.lastError().text();
    }else {
        qDebug() << "Connected";
    }


    QString inputName = ui->lineEdit->text();
    QString inputPassword = ui->lineEdit_2->text();

    // Create a user object
    User currentUser(inputName, inputPassword, 0);

    // Insert user data into the database
    if (DB_Connect.isOpen())
    {
        // Use a QSqlQuery object to perform the database operations
        QSqlQuery insertQuery(DB_Connect);

        // Use a transaction to ensure data consistency
        DB_Connect.transaction();

        insertQuery.prepare("INSERT INTO user(nom, password, role) VALUES(:nom, :password, :role)");
        insertQuery.bindValue(":nom", currentUser.getNom());
        insertQuery.bindValue(":password", currentUser.getPassword());
        insertQuery.bindValue(":role", currentUser.getRole());

        // Check if the query is executed successfully
        if (insertQuery.exec())
        {
            qDebug() << "User data inserted successfully";
            // Commit the transaction if the query is successful
            DB_Connect.commit();
        }
        else
        {
            // If the query fails, rollback the transaction
            qDebug() << "Error inserting user data:" << insertQuery.lastError().text();
            DB_Connect.rollback();
        }
    }
    else
    {
        qDebug() << "Database not open";
    }

    // Close the database connection after finishing the operations
    DB_Connect.close();
}


