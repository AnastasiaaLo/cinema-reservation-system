#ifndef REZERVARE_H
#define REZERVARE_H

#include <string>
#include <vector>

struct LocRezervat {
    int rand;
    int coloana;
    double pret;
};

class Rezervare {
private:
    int id;
    std::string numeClient;
    int filmId;
    int salaId;
    std::vector<LocRezervat> locuriRezervate;
    double pretTotal;
    std::string dataRezervare;

public:
    // Constructori
    Rezervare();
    Rezervare(int id, const std::string& numeClient, int filmId, int salaId);

    // Getters
    int getId() const;
    std::string getNumeClient() const;
    int getFilmId() const;
    int getSalaId() const;
    double getPretTotal() const;
    std::string getDataRezervare() const;
    std::vector<LocRezervat> getLocuri() const;

    // Metode
    void adaugaLoc(int rand, int coloana, double pret);
    void calculeazaPretTotal();
    void afiseazaRezervare() const;
    std::string toString() const;
};

#endif
