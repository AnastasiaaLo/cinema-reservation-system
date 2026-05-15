#ifndef LOC_H
#define LOC_H

#include <string>

enum class TipLoc {
    NORMAL,
    VIP
};

class Loc {
private:
    int rand;
    int coloana;
    bool ocupat;
    TipLoc tip;
    double pret;

public:
    // Constructori
    Loc();
    Loc(int rand, int coloana, TipLoc tip = TipLoc::NORMAL);

    // Getters
    int getRand() const;
    int getColoana() const;
    bool esteOcupat() const;
    TipLoc getTip() const;
    double getPret() const;

    // Setters / Metode de modificare
    void ocupa();
    void elibereaza();
    void setPret(double pret);

    // Returneaza o reprezentare scurta (ex: "A5")
    std::string getCod() const;

    // Returneaza simbolul pentru afisare ([ ] sau [X])
    std::string getSimbol() const;
};

#endif
