#include "userticketwindow.h"
#include "ui_userticketwindow.h"

UserTicketWindow::UserTicketWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserTicketWindow)
{
    ui->setupUi(this);
}

UserTicketWindow::~UserTicketWindow()
{
    delete ui;
}
