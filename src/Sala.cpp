#include "../include/Sala.h"
#include <iostream>
#include <iomanip>

// Constructor implicit
Sala::Sala() : id(0), nume(""), nrRanduri(0), nrColoane(0) {}

// Constructor cu parametri
Sala::Sala(int id, const std::string& nume, int nrRanduri, int nrColoane)
    : id(id), nume(nume), nrRanduri(nrRanduri), nrColoane(nrColoane) {

    // Initializam matricea de locuri
    locuri.resize(nrRanduri);
    for (int i = 0; i < nrRanduri; i++) {
        locuri[i].resize(nrColoane);
        for (int j = 0; j < nrColoane; j++) {
            // Ultimele 2 randuri sunt VIP
            TipLoc tip = (i >= nrRanduri - 2) ? TipLoc::VIP : TipLoc::NORMAL;
            locuri[i][j] = Loc(i, j, tip);
        }
    }
}

// Getters
int Sala::getId() const { return id; }
std::string Sala::getNume() const { return nume; }
int Sala::getNrRanduri() const { return nrRanduri; }
int Sala::getNrColoane() const { return nrColoane; }

// Verifica daca un loc este liber
bool Sala::esteLocLiber(int rand, int coloana) const {
    if (rand < 0 || rand >= nrRanduri || coloana < 0 || coloana >= nrColoane) {
        return false;
    }
    return !locuri[rand][coloana].esteOcupat();
}

// Rezerva un loc; returneaza true daca a reusit
bool Sala::rezervaLoc(int rand, int coloana) {
    if (!esteLocLiber(rand, coloana)) {
        return false;
    }
    locuri[rand][coloana].ocupa();
    return true;
}

// Elibereaza un loc (anulare rezervare)
bool Sala::elibereazaLoc(int rand, int coloana) {
    if (rand < 0 || rand >= nrRanduri || coloana < 0 || coloana >= nrColoane) {
        return false;
    }
    locuri[rand][coloana].elibereaza();
    return true;
}

// Returneaza pretul unui loc
double Sala::getPretLoc(int rand, int coloana) const {
    if (rand < 0 || rand >= nrRanduri || coloana < 0 || coloana >= nrColoane) {
        return 0.0;
    }
    return locuri[rand][coloana].getPret();
}

// Afiseaza sala in consola
void Sala::afiseazaSala() const {
    std::cout << "\n";
    std::cout << "  ============= " << nume << " =============\n\n";

    // Ecranul
    std::cout << "  ";
    for (int j = 0; j < nrColoane; j++) {
        std::cout << "====";
    }
    std::cout << "\n";
    std::cout << "  ";
    for (int j = 0; j < nrColoane; j++) {
        std::cout << "  E ";
    }
    std::cout << " (ECRAN)\n";
    std::cout << "  ";
    for (int j = 0; j < nrColoane; j++) {
        std::cout << "====";
    }
    std::cout << "\n\n";

    // Numere coloane
    std::cout << "    ";
    for (int j = 0; j < nrColoane; j++) {
        std::cout << std::setw(3) << (j + 1) << " ";
    }
    std::cout << "\n";

    // Randurile cu locuri
    for (int i = 0; i < nrRanduri; i++) {
        char litera = 'A' + i;
        std::cout << "  " << litera << " ";
        for (int j = 0; j < nrColoane; j++) {
            std::cout << locuri[i][j].getSimbol() << " ";
        }
        std::cout << "\n";
    }

    // Legenda
    std::cout << "\n  Legenda: [ ] liber  [X] ocupat  [V] VIP liber\n\n";
}

// Numar locuri libere
int Sala::getNrLocuriLibere() const {
    int count = 0;
    for (int i = 0; i < nrRanduri; i++) {
        for (int j = 0; j < nrColoane; j++) {
            if (!locuri[i][j].esteOcupat()) count++;
        }
    }
    return count;
}

// Numar locuri ocupate
int Sala::getNrLocuriOcupate() const {
    return (nrRanduri * nrColoane) - getNrLocuriLibere();
}
