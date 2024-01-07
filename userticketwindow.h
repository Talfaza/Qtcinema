#ifndef USERTICKETWINDOW_H
#define USERTICKETWINDOW_H

#include <QMainWindow>

namespace Ui {
class UserTicketWindow;
}

class UserTicketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserTicketWindow(QWidget *parent = nullptr);
    ~UserTicketWindow();

private:
    Ui::UserTicketWindow *ui;
};

#endif // USERTICKETWINDOW_H
