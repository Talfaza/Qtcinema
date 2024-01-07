// user.cpp
#include "user.h"




User::User(const QString &nom, const QString &password,bool role)
{
    setNom(nom);
    setPassword(password);
    setRole(role);
}

// Getter implementations
QString User::getNom() const {
    return nom;
}

QString User::getPassword() const {
    return password;
}

bool User::getRole() const {
    return role;
}

// Setter implementations
void User::setNom(const QString &nom) {
    this->nom = nom;
}

void User::setPassword(const QString &password) {
    this->password = password;
}

void User::setRole(const bool &role){
    this->role = role;
}

int User::SelectUser(QString inputName, QString inputPassword) {
    QSqlDatabase DB_Connect = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connect.setDatabaseName("C:/Users/chari/OneDrive/Bureau/CinemaQT/database/cinema.db");

    if (!DB_Connect.open()) {
        qDebug() << "Error opening database:" << DB_Connect.lastError().text();
        return 3; // Return an error code to indicate the failure to open the database
    }

    qDebug() << "Connected";

    User currentUser(inputName, inputPassword, 0);

    QSqlQuery selectQuery(DB_Connect);

    // Use a prepared statement with placeholders to prevent SQL injection
    selectQuery.prepare("SELECT * FROM user WHERE nom = :nom AND password = :password");
    selectQuery.bindValue(":nom", currentUser.getNom());
    selectQuery.bindValue(":password", currentUser.getPassword());

    if (selectQuery.exec()) {
        // Process the results
        if (selectQuery.next()) {
            // User found in the database
            QString nom = selectQuery.value("nom").toString();
            QString password = selectQuery.value("password").toString();
            bool role = selectQuery.value("role").toBool();

            currentUser.setRole(role);

            QString roleString = (role) ? "admin" : "user";

            // Do something with the retrieved data, e.g., print it
            qDebug() << "User found in the database:";
            qDebug() << "Nom:" << nom << ", password:" << password << ", Role:" << roleString;

            // Add verification based on the user's role
            if (currentUser.getRole() == 1) {
                DB_Connect.close(); // Close the database connection
                return 1;
                // Add additional actions for admin role if needed
            } else if (currentUser.getRole() == 0) {
                DB_Connect.close(); // Close the database connection
                return 0;
                // Add additional actions for regular user role if needed
            }
        } else {
            qDebug() << "User not found in the database";
            DB_Connect.close(); // Close the database connection
            return 2;
        }
    }

    // If there was an error executing the query
    qDebug() << "Error executing query:" << selectQuery.lastError().text();
    DB_Connect.close(); // Close the database connection
    return 3; // Return an error code
}
