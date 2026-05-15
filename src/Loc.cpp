#include "../include/Loc.h"

// Constructor implicit
Loc::Loc() : rand(0), coloana(0), ocupat(false), tip(TipLoc::NORMAL), pret(50.0) {}

// Constructor cu parametri
Loc::Loc(int rand, int coloana, TipLoc tip)
    : rand(rand), coloana(coloana), ocupat(false), tip(tip) {
    // Preturi diferite in functie de tipul locului
    if (tip == TipLoc::VIP) {
        pret = 80.0;
    } else {
        pret = 50.0;
    }
}

// Getters
int Loc::getRand() const { return rand; }
int Loc::getColoana() const { return coloana; }
bool Loc::esteOcupat() const { return ocupat; }
TipLoc Loc::getTip() const { return tip; }
double Loc::getPret() const { return pret; }

// Modificare stare
void Loc::ocupa() { ocupat = true; }
void Loc::elibereaza() { ocupat = false; }
void Loc::setPret(double pret) {
    if (pret > 0) {
        this->pret = pret;
    }
}

// Cod unic pentru loc (ex: A5, B3)
std::string Loc::getCod() const {
    char litera = 'A' + rand;
    return std::string(1, litera) + std::to_string(coloana + 1);
}

// Simbol pentru afisarea in consola
std::string Loc::getSimbol() const {
    if (ocupat) {
        return "[X]";
    }
    if (tip == TipLoc::VIP) {
        return "[V]";
    }
    return "[ ]";
}
