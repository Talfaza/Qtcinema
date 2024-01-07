// film.h
#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QDate>
#include <QtSql>

class Film {
public:
    // Constructors
    Film();
    Film(const QString &titre, const QString &realisateur, const QString &duree, const QString &genre, const QString &dateSortie, const QString &description, const QString &quantite);

    // Getters
    int getId() const;
    QString getTitre() const;
    QString getRealisateur() const;
    QString getDuree() const;
    QString getGenre() const;
    QString getDateSortie() const;
    QString getDescription() const;
    QString getQuantite() const;

    // Setters
    void setTitre(const QString &titre);
    void setRealisateur(const QString &realisateur);
    void setDuree(const QString &duree);
    void setGenre(const QString &genre);
    void setDateSortie(const QString &dateSortie);
    void setDescription(const QString &description);
    void setQuantite(const QString &quantite);

    // Database operations
    bool insertFilm();
    bool decrementQuantite(int movieId);
    int fetchMovieById(int movieId);
    int fetchMovieByQte(int movieId);
private:

    int id;
    QString titre;
    QString realisateur;
    QString duree;
    QString genre;
    QString dateSortie;
    QString description;
    QString quantite;  // Added quantite member variable
};

#endif // FILM_H
