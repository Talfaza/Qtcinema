#ifndef PLACEWINDOW_H
#define PLACEWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlaceWindow;
}

class PlaceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaceWindow(QWidget *parent = nullptr);
    ~PlaceWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlaceWindow *ui;
};

#endif // PLACEWINDOW_H
