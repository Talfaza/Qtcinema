#ifndef USER_H
#define USER_H

#include <QString>
#include <QtSql>


class User
{
public:
    User();
    User(const QString &nom, const QString &password, bool role = false); // Constructor

    // Getters
    QString getNom() const;
    QString getPassword() const;
    bool getRole() const;

    // Setters
    void setNom(const QString &nom);
    void setPassword(const QString &password);
    void setRole(const bool &role);

    // Other methods if needed

   int SelectUser(QString a, QString b);


private:
    QString nom;
    QString password;
    bool role;
    QSqlDatabase DB_Connect;



};

#endif // USER_H
