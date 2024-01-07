#include "placewindow.h"
#include "ui_placewindow.h"
#include "film.h"
#include <QMessageBox>

PlaceWindow::PlaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaceWindow)
{
    ui->setupUi(this);

}

PlaceWindow::~PlaceWindow()
{
    delete ui;
}

void PlaceWindow::on_pushButton_clicked()
{
    int movieId = ui->lineEdit->text().toInt();

    // Create a Film object
    Film movie;

    // Use the updated decrementQuantite method
    int updatedQuantite = movie.decrementQuantite(movieId);

    if (movie.getQuantite() >= 0 && movieId == movie.fetchMovieById(movieId)) {
        // Set the updated quantity in the Film object
        movie.setQuantite(QString::number(updatedQuantite));

        QMessageBox::information(this, "Success", "Quantite decremented successfully.");
    } else {
        // Show a message indicating that the quantity is unavailable or an error occurred
        QMessageBox::warning(this, "Quantite Unavailable", "Quantite is not available or an error occurred.");
    }
}
