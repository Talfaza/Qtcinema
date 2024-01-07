// film.cpp
#include "film.h"
Film::Film() : id(0), titre(""), realisateur(""), duree(""), genre(""), dateSortie(""), description(""), quantite("") {}

Film::Film(const QString &titre, const QString &realisateur, const QString &duree, const QString &genre, const QString &dateSortie, const QString &description, const QString &quantite)
{
    setTitre(titre);
    setRealisateur(realisateur);
    setDuree(duree);
    setGenre(genre);
    setDateSortie(dateSortie);
    setDescription(description);
    setQuantite(quantite);
}

// ... (rest of the implementation)


int Film::getId() const {
    return id;
}

QString Film::getTitre() const {
    return titre;
}

QString Film::getRealisateur() const {
    return realisateur;
}

QString Film::getDuree() const {
    return duree;
}

QString Film::getGenre() const {
    return genre;
}

QString Film::getDateSortie() const {
    return dateSortie;
}

QString Film::getDescription() const {
    return description;
}

QString Film::getQuantite() const {
    return quantite;
}

void Film::setTitre(const QString &titre) {
    this->titre = titre;
}

void Film::setRealisateur(const QString &realisateur) {
    this->realisateur = realisateur;
}

void Film::setDuree(const QString &duree) {
    this->duree = duree;
}

void Film::setGenre(const QString &genre) {
    this->genre = genre;
}

void Film::setDateSortie(const QString &dateSortie) {
    this->dateSortie = dateSortie;
}

void Film::setDescription(const QString &description) {
    this->description = description;
}

void Film::setQuantite(const QString &quantite){
    this->quantite = quantite;
}

bool Film::insertFilm() {
    QSqlQuery query;
    query.prepare("INSERT INTO film (titre, realisateur, duree, genre, dateSortie, description,quantite) "
                  "VALUES (:titre, :realisateur, :duree, :genre, :dateSortie, :description, :quantite)");
    query.bindValue(":titre", titre);
    query.bindValue(":realisateur", realisateur);
    query.bindValue(":duree", duree);
    query.bindValue(":genre", genre);
    query.bindValue(":dateSortie", dateSortie);
    query.bindValue(":description", description);
    query.bindValue(":quantite", quantite);

    return query.exec();
}

bool Film::decrementQuantite(int movieId) {
    QSqlQuery query;
    query.prepare("UPDATE film SET quantite = quantite - 1 WHERE id = :id");
    query.bindValue(":id", movieId);

    return query.exec();
}
int Film::fetchMovieById(int movieId) {
    QSqlQuery query;
    query.prepare("SELECT id FROM film WHERE id = :id");
    query.bindValue(":id", movieId);

    if (query.exec() && query.next()) {
        id = query.value("id").toInt();


        return id;  // Successfully fetched the movie details
    }

    return false;  // Movie with the specified ID not found
}


