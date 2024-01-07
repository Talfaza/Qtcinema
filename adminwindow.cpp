#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "film.h"
#include "mainwindow.h"
AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
        DB_Connect.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");
        if (!DB_Connect.open()) {
            qDebug() << "Error opening database:" << DB_Connect.lastError().text();

        }
        else {
            qDebug() << "Connected";

    }

}

AdminWindow::~AdminWindow()
{
    delete ui;
}


void AdminWindow::on_pushButton_clicked()
{
    // Get data from your UI elements
    QString inputTitle = ui->lineEdit->text();
    QString inputRealisateur = ui->lineEdit_2->text();
    QString inputDuree = ui->lineEdit_3->text();  // Assuming duration is an integer
    QString inputGenre = ui->lineEdit_4->text();
    QString inputDateSortie = ui->lineEdit_5->text();
    QString inputDescription = ui->lineEdit_6->text();
    QString inputQuantite = ui->lineEdit_7->text();

    // Convert inputDuree to QString
    QString dureeAsString = inputDuree;

    // Create a Film object
    Film movie(inputTitle, inputRealisateur, dureeAsString, inputGenre, inputDateSortie, inputDescription, inputQuantite);

    // Call the insertFilm() method
    if (movie.insertFilm()) {
        qDebug() << "Film inserted successfully!";
        // Handle success
    } else {
        qDebug() << "Error inserting film:" << QSqlDatabase::database().lastError().text();
        // Handle error
    }
}


void AdminWindow::on_pushButton_2_clicked()
{
        MainWindow *main_w = new MainWindow(this);
        this->hide();
        main_w->show();
        DB_Connect.close();
}
