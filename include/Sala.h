#ifndef SALA_H
#define SALA_H

#include "Loc.h"
#include <vector>
#include <string>

class Sala {
private:
    int id;
    std::string nume;
    int nrRanduri;
    int nrColoane;
    std::vector<std::vector<Loc>> locuri;

public:
    // Constructori
    Sala();
    Sala(int id, const std::string& nume, int nrRanduri, int nrColoane);

    // Getters
    int getId() const;
    std::string getNume() const;
    int getNrRanduri() const;
    int getNrColoane() const;

    // Metode pentru locuri
    bool esteLocLiber(int rand, int coloana) const;
    bool rezervaLoc(int rand, int coloana);
    bool elibereazaLoc(int rand, int coloana);
    double getPretLoc(int rand, int coloana) const;

    // Afisare vizuala in consola
    void afiseazaSala() const;

    // Statistici
    int getNrLocuriLibere() const;
    int getNrLocuriOcupate() const;
};

#endif
