#include "connection.h"

bool openDatabaseConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");

    if (!db.open())
    {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Connected";
        return true;
    }
}

void closeDatabaseConnection()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen())
    {
        db.close();
        qDebug() << "Database connection closed";
    }
}
