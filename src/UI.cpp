#include "../include/UI.h"
#include <iostream>
#include <limits>
#include <cstdlib>

namespace UI {

void curataEcran() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauza() {
    std::cout << "\n  Apasa Enter pentru a continua...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void afiseazaBannerStart() {
    std::cout << "\n";
    std::cout << "  ##########################################\n";
    std::cout << "  #                                        #\n";
    std::cout << "  #     SISTEM REZERVARE CINEMA  v1.0      #\n";
    std::cout << "  #     Proiect Practica - Anul I          #\n";
    std::cout << "  #                                        #\n";
    std::cout << "  ##########################################\n";
}

void afiseazaMeniu() {
    std::cout << "\n";
    std::cout << "  +======================================+\n";
    std::cout << "  |          MENIU PRINCIPAL             |\n";
    std::cout << "  +======================================+\n";
    std::cout << "  |  1. Vezi filmele disponibile         |\n";
    std::cout << "  |  2. Vezi salile disponibile          |\n";
    std::cout << "  |  3. Rezerva locuri                   |\n";
    std::cout << "  |  4. Vezi toate rezervarile           |\n";
    std::cout << "  |  5. Anuleaza o rezervare             |\n";
    std::cout << "  |  0. Iesire                           |\n";
    std::cout << "  +======================================+\n";
    std::cout << "  Alege optiunea: ";
}

void mesajSucces(const std::string& text) {
    std::cout << "\n  [OK] " << text << "\n";
}

void mesajEroare(const std::string& text) {
    std::cout << "\n  [EROARE] " << text << "\n";
}

void afiseazaTitlu(const std::string& titlu) {
    std::cout << "\n";
    std::cout << "  ===== " << titlu << " =====\n";
}

}
