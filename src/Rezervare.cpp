#include "../include/Rezervare.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

// Functie helper pentru obtinerea datei curente
static std::string getDataCurenta() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(now, "%d.%m.%Y %H:%M");
    return oss.str();
}

// Constructor implicit
Rezervare::Rezervare()
    : id(0), numeClient(""), filmId(0), salaId(0),
      pretTotal(0.0), dataRezervare(getDataCurenta()) {}

// Constructor cu parametri
Rezervare::Rezervare(int id, const std::string& numeClient, int filmId, int salaId)
    : id(id), numeClient(numeClient), filmId(filmId), salaId(salaId),
      pretTotal(0.0), dataRezervare(getDataCurenta()) {}

// Getters
int Rezervare::getId() const { return id; }
std::string Rezervare::getNumeClient() const { return numeClient; }
int Rezervare::getFilmId() const { return filmId; }
int Rezervare::getSalaId() const { return salaId; }
double Rezervare::getPretTotal() const { return pretTotal; }
std::string Rezervare::getDataRezervare() const { return dataRezervare; }
std::vector<LocRezervat> Rezervare::getLocuri() const { return locuriRezervate; }

// Adauga un loc la rezervare
void Rezervare::adaugaLoc(int rand, int coloana, double pret) {
    LocRezervat lr = {rand, coloana, pret};
    locuriRezervate.push_back(lr);
    calculeazaPretTotal();
}

// Calculeaza pretul total
void Rezervare::calculeazaPretTotal() {
    pretTotal = 0.0;
    for (const auto& loc : locuriRezervate) {
        pretTotal += loc.pret;
    }
}

// Afiseaza detaliile rezervarii
void Rezervare::afiseazaRezervare() const {
    std::cout << "\n----------------------------------------\n";
    std::cout << "  REZERVARE #" << id << "\n";
    std::cout << "  Client: " << numeClient << "\n";
    std::cout << "  Film ID: " << filmId << " | Sala ID: " << salaId << "\n";
    std::cout << "  Data: " << dataRezervare << "\n";
    std::cout << "  Locuri rezervate (" << locuriRezervate.size() << "):\n";
    for (const auto& loc : locuriRezervate) {
        char litera = 'A' + loc.rand;
        std::cout << "    - " << litera << (loc.coloana + 1)
                  << " (" << loc.pret << " RON)\n";
    }
    std::cout << "  TOTAL: " << pretTotal << " RON\n";
    std::cout << "----------------------------------------\n";
}

// Conversie la string pentru salvare in fisier
std::string Rezervare::toString() const {
    std::ostringstream oss;
    oss << id << "|" << numeClient << "|" << filmId << "|"
        << salaId << "|" << dataRezervare << "|" << pretTotal << "|";
    for (size_t i = 0; i < locuriRezervate.size(); i++) {
        oss << locuriRezervate[i].rand << ","
            << locuriRezervate[i].coloana << ","
            << locuriRezervate[i].pret;
        if (i < locuriRezervate.size() - 1) oss << ";";
    }
    return oss.str();
}
