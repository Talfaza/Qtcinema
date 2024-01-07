// userwindows.h
#ifndef USERWINDOWS_H
#define USERWINDOWS_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class UserWindows;
}

class UserWindows : public QMainWindow {
    Q_OBJECT

public:
    explicit UserWindows(QWidget *parent = nullptr);
    ~UserWindows();

private:
    Ui::UserWindows *ui;
    QSqlDatabase DB_Connect;
    QSqlQueryModel *filmModel;

    void setupModel();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // USERWINDOWS_H
