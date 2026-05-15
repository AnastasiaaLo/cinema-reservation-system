#include "../include/Film.h"
#include <iostream>
#include <sstream>

// Constructor implicit
Film::Film() : id(0), titlu(""), gen(""), durata(0), descriere(""), rating(0.0) {}

// Constructor cu parametri
Film::Film(int id, const std::string& titlu, const std::string& gen,
           int durata, const std::string& descriere, double rating)
    : id(id), titlu(titlu), gen(gen), durata(durata),
      descriere(descriere), rating(rating) {}

// Getters
int Film::getId() const { return id; }
std::string Film::getTitlu() const { return titlu; }
std::string Film::getGen() const { return gen; }
int Film::getDurata() const { return durata; }
std::string Film::getDescriere() const { return descriere; }
double Film::getRating() const { return rating; }

// Setters
void Film::setTitlu(const std::string& titlu) { this->titlu = titlu; }
void Film::setRating(double rating) {
    if (rating >= 0 && rating <= 10) {
        this->rating = rating;
    }
}

// Afișează detaliile filmului în consolă
void Film::afiseazaDetalii() const {
    std::cout << "\n========================================\n";
    std::cout << "  Film ID: " << id << "\n";
    std::cout << "  Titlu:   " << titlu << "\n";
    std::cout << "  Gen:     " << gen << "\n";
    std::cout << "  Durata:  " << durata << " minute\n";
    std::cout << "  Rating:  " << rating << "/10\n";
    std::cout << "  Descriere: " << descriere << "\n";
    std::cout << "========================================\n";
}

// Conversie la string (utila pentru salvare in fisier)
std::string Film::toString() const {
    std::ostringstream oss;
    oss << id << "|" << titlu << "|" << gen << "|"
        << durata << "|" << descriere << "|" << rating;
    return oss.str();
}
