#include "../include/Film.h"
#include "../include/Sala.h"
#include "../include/Rezervare.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include "../include/UI.h"


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
    
UI::afiseazaBannerStart();
    // ===== Bucla principala a meniului =====
    int optiune;
    do {
        UI::afiseazaMeniu();
        std::cin >> optiune;

        // Validare input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            UI::mesajEroare("Optiune invalida! Te rog introdu un numar.");
            continue;
        }

        switch (optiune) {
            case 1: {
                // Afiseaza filmele
                UI::afiseazaTitlu("FILME DISPONIBILE");
                for (const auto& film : filme) {
                    film.afiseazaDetalii();
                }
                UI::pauza();
                break;
            }

            case 2: {
                // Afiseaza salile
                UI::afiseazaTitlu("SALI DISPONIBILE");
                for (auto& sala : sali) {
                    std::cout << "\nID: " << sala.getId()
                              << " | Nume: " << sala.getNume()
                              << " | Locuri libere: " << sala.getNrLocuriLibere()
                              << "/" << (sala.getNrRanduri() * sala.getNrColoane()) << "\n";
                }
                UI::pauza();
                break;
            }

            case 3: {
                // Rezerva locuri
                UI::afiseazaTitlu("REZERVARE LOC");

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
                    UI::mesajEroare("Sala nu a fost gasita!");
                    UI::pauza();
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
                        std::cout << "\n  [OK] Loc rezervat cu succes! Pret: " << pret << " MDL\n";
                    } else {
                        UI::mesajEroare("Locul nu este disponibil sau coordonate invalide!");
                    }

                    std::cout << "Mai vrei sa rezervi un loc? (d/n): ";
                    char raspuns;
                    std::cin >> raspuns;
                    continua = (raspuns == 'd' || raspuns == 'D');
                }

                // 6. Confirma rezervarea
                rezervari.push_back(rez);
                UI::mesajSucces("Rezervare finalizata cu succes!");
                rez.afiseazaRezervare();
                UI::pauza();
                break;
            }

            case 4: {
                // Vezi toate rezervarile
                UI::afiseazaTitlu("TOATE REZERVARILE");
                if (rezervari.empty()) {
                    std::cout << "Nu exista rezervari.\n";
                } else {
                    for (const auto& rez : rezervari) {
                        rez.afiseazaRezervare();
                    }
                }
                UI::pauza();
                break;
            }

            case 5: {
                // Anuleaza rezervare
                UI::afiseazaTitlu("ANULARE REZERVARE");
                if (rezervari.empty()) {
                    std::cout << "Nu exista rezervari.\n";
                    UI::pauza();
                    break;
                }

                std::cout << "Rezervari existente:\n";
                for (const auto& rez : rezervari) {
                    std::cout << "  ID: " << rez.getId()
                              << " | Client: " << rez.getNumeClient()
                              << " | Total: " << rez.getPretTotal() << " MDL\n";
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
                        UI::mesajSucces("Rezervare anulata cu succes!");
                        gasit = true;
                        break;
                    }
                }

                if (!gasit) {
                    UI::mesajEroare("Rezervarea nu a fost gasita.");
                }
                UI::pauza();
                break;
            }

            case 0:
                std::cout << "\nLa revedere!\n";
                break;

            default:
                UI::mesajEroare("Optiune invalida!");
                UI::pauza();
        }

    } while (optiune != 0);

    return 0;
}
