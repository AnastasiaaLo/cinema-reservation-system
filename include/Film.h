#ifndef FILM_H
#define FILM_H

#include <string>

class Film {
private:
    int id;
    std::string titlu;
    std::string gen;
    int durata;          // durata in minute
    std::string descriere;
    double rating;       // de la 0 la 10

public:
    // Constructori
    Film();
    Film(int id, const std::string& titlu, const std::string& gen,
         int durata, const std::string& descriere, double rating);

    // Getters
    int getId() const;
    std::string getTitlu() const;
    std::string getGen() const;
    int getDurata() const;
    std::string getDescriere() const;
    double getRating() const;

    // Setters
    void setTitlu(const std::string& titlu);
    void setRating(double rating);

    // Metode
    void afiseazaDetalii() const;
    std::string toString() const;
};

#endif
