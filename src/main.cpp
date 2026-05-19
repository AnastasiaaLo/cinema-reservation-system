#include "../include/Film.h"
#include "../include/Sala.h"
#include "../include/Rezervare.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

// Functie pentru curatarea ecranului
void curataEcran() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Functie pentru pauza pana cand utilizatorul apasa Enter
void pauza() {
    std::cout << "\nApasa Enter pentru a continua...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Afiseaza meniul principal
void afiseazaMeniu() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "   SISTEM REZERVARE CINEMA - MENIU\n";
    std::cout << "========================================\n";
    std::cout << "  1. Vezi filmele disponibile\n";
    std::cout << "  2. Vezi salile disponibile\n";
    std::cout << "  3. Rezerva locuri\n";
    std::cout << "  4. Vezi toate rezervarile\n";
    std::cout << "  5. Anuleaza o rezervare\n";
    std::cout << "  0. Iesire\n";
    std::cout << "========================================\n";
    std::cout << "  Alege optiunea: ";
}

int main() {
    // ===== Date de test (in versiunea finala vor fi incarcate din fisier) =====

    std::vector<Film> filme = {
        Film(1, "Inception", "Science Fiction", 148,
             "Un hot care fura secrete din subconstient...", 8.8),
        Film(2, "The Dark Knight", "Actiune", 152,
             "Batman se infrunta cu Joker...", 9.0),
        Film(3, "Interstellar", "Science Fiction", 169,
             "O echipa de exploratori calatoreste prin gaura de vierme...", 8.6)
    };

    std::vector<Sala> sali = {
        Sala(1, "Sala 1 - Standard", 6, 8),
        Sala(2, "Sala 2 - Premium", 5, 6)
    };

    std::vector<Rezervare> rezervari;
    int urmatorIdRezervare = 1;

    // ===== Bucla principala a meniului =====
    int optiune;
    do {
        afiseazaMeniu();
        std::cin >> optiune;

        // Validare input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Optiune invalida! Te rog introdu un numar.\n";
            continue;
        }

        switch (optiune) {
            case 1: {
                // Afiseaza filmele
                std::cout << "\n========== FILME DISPONIBILE ==========\n";
                for (const auto& film : filme) {
                    film.afiseazaDetalii();
                }
                pauza();
                break;
            }

            case 2: {
                // Afiseaza salile
                std::cout << "\n========== SALI DISPONIBILE ==========\n";
                for (auto& sala : sali) {
                    std::cout << "\nID: " << sala.getId()
                              << " | Nume: " << sala.getNume()
                              << " | Locuri libere: " << sala.getNrLocuriLibere()
                              << "/" << (sala.getNrRanduri() * sala.getNrColoane()) << "\n";
                }
                pauza();
                break;
            }

            case 3: {
                // Rezerva locuri
                std::cout << "\n========== REZERVARE LOC ==========\n";

                // 1. Alege film
                std::cout << "\nFilmele disponibile:\n";
                for (const auto& film : filme) {
                    std::cout << "  " << film.getId() << ". " << film.getTitlu() << "\n";
                }
                std::cout << "Alege ID-ul filmului: ";
                int filmId;
                std::cin >> filmId;

                // 2. Alege sala
                std::cout << "\nSalile disponibile:\n";
                for (const auto& sala : sali) {
                    std::cout << "  " << sala.getId() << ". " << sala.getNume() << "\n";
                }
                std::cout << "Alege ID-ul salii: ";
                int salaId;
                std::cin >> salaId;

                // Gaseste sala selectata
                Sala* salaSelectata = nullptr;
                for (auto& s : sali) {
                    if (s.getId() == salaId) {
                        salaSelectata = &s;
                        break;
                    }
                }

                if (!salaSelectata) {
                    std::cout << "Sala nu a fost gasita!\n";
                    pauza();
                    break;
                }

                // 3. Afiseaza sala si cere locul
                salaSelectata->afiseazaSala();

                // 4. Numele clientului
                std::cout << "Numele tau: ";
                std::cin.ignore();
                std::string numeClient;
                std::getline(std::cin, numeClient);

                Rezervare rez(urmatorIdRezervare++, numeClient, filmId, salaId);

                // 5. Alegerea locurilor
                bool continua = true;
                while (continua) {
                    std::cout << "Introdu randul (litera, A-" << char('A' + salaSelectata->getNrRanduri() - 1)
                              << "): ";
                    char litera;
                    std::cin >> litera;
                    litera = toupper(litera);
                    int rand = litera - 'A';

                    std::cout << "Introdu numarul coloanei (1-"
                              << salaSelectata->getNrColoane() << "): ";
                    int col;
                    std::cin >> col;
                    col -= 1;  // ajustare la index 0-based

                    if (salaSelectata->rezervaLoc(rand, col)) {
                        double pret = salaSelectata->getPretLoc(rand, col);
                        rez.adaugaLoc(rand, col, pret);
                        std::cout << "Loc rezervat cu succes! Pret: " << pret << " RON\n";
                    } else {
                        std::cout << "Locul nu este disponibil sau coordonate invalide!\n";
                    }

                    std::cout << "Mai vrei sa rezervi un loc? (d/n): ";
                    char raspuns;
                    std::cin >> raspuns;
                    continua = (raspuns == 'd' || raspuns == 'D');
                }

                // 6. Confirma rezervarea
                rezervari.push_back(rez);
                std::cout << "\nRezervare finalizata cu succes!\n";
                rez.afiseazaRezervare();
                pauza();
                break;
            }

            case 4: {
                // Vezi toate rezervarile
                std::cout << "\n========== TOATE REZERVARILE ==========\n";
                if (rezervari.empty()) {
                    std::cout << "Nu exista rezervari.\n";
                } else {
                    for (const auto& rez : rezervari) {
                        rez.afiseazaRezervare();
                    }
                }
                pauza();
                break;
            }

            case 5: {
                // Anuleaza rezervare
                std::cout << "\n========== ANULARE REZERVARE ==========\n";
                if (rezervari.empty()) {
                    std::cout << "Nu exista rezervari.\n";
                    pauza();
                    break;
                }

                std::cout << "Rezervari existente:\n";
                for (const auto& rez : rezervari) {
                    std::cout << "  ID: " << rez.getId()
                              << " | Client: " << rez.getNumeClient()
                              << " | Total: " << rez.getPretTotal() << " RON\n";
                }

                std::cout << "Introdu ID-ul rezervarii de anulat: ";
                int idAnulare;
                std::cin >> idAnulare;

                bool gasit = false;
                for (auto it = rezervari.begin(); it != rezervari.end(); ++it) {
                    if (it->getId() == idAnulare) {
                        // Elibereaza locurile din sala
                        for (auto& sala : sali) {
                            if (sala.getId() == it->getSalaId()) {
                                for (const auto& loc : it->getLocuri()) {
                                    sala.elibereazaLoc(loc.rand, loc.coloana);
                                }
                                break;
                            }
                        }
                        rezervari.erase(it);
                        std::cout << "Rezervare anulata cu succes!\n";
                        gasit = true;
                        break;
                    }
                }

                if (!gasit) {
                    std::cout << "Rezervarea nu a fost gasita.\n";
                }
                pauza();
                break;
            }

            case 0:
                std::cout << "\nLa revedere!\n";
                break;

            default:
                std::cout << "Optiune invalida!\n";
                pauza();
        }

    } while (optiune != 0);

    return 0;
}
