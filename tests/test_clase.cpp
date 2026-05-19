// Program de testare pentru clasele de baza
// Sistem de rezervare cinema

#include "../include/Film.h"
#include "../include/Loc.h"
#include "../include/Sala.h"
#include "../include/Rezervare.h"
#include <iostream>

int testeReusite = 0;
int testeEsuate = 0;

void verifica(bool conditie, const std::string& numeTest) {
    if (conditie) {
        std::cout << "[OK] " << numeTest << "\n";
        testeReusite++;
    } else {
        std::cout << "[ESEC] " << numeTest << "\n";
        testeEsuate++;
    }
}

void testFilm() {
    std::cout << "\n=== Testare clasa Film ===\n";

    Film film(1, "Inception", "Science Fiction", 148,
              "Film despre vise si realitate.", 8.8);

    verifica(film.getId() == 1, "ID-ul filmului este corect");
    verifica(film.getTitlu() == "Inception", "Titlul filmului este corect");
    verifica(film.getGen() == "Science Fiction", "Genul filmului este corect");
    verifica(film.getDurata() == 148, "Durata filmului este corecta");
    verifica(film.getRating() == 8.8, "Ratingul filmului este corect");
}

void testLoc() {
    std::cout << "\n=== Testare clasa Loc ===\n";

    Loc locNormal(0, 0, TipLoc::NORMAL);
    Loc locVIP(5, 0, TipLoc::VIP);

    verifica(locNormal.esteOcupat() == false, "Locul normal este liber initial");
    verifica(locNormal.getPret() == 50.0, "Pretul locului normal este 50");
    verifica(locVIP.getPret() == 80.0, "Pretul locului VIP este 80");

    locNormal.ocupa();
    verifica(locNormal.esteOcupat() == true, "Locul poate fi ocupat");

    locNormal.elibereaza();
    verifica(locNormal.esteOcupat() == false, "Locul poate fi eliberat");
}

void testSala() {
    std::cout << "\n=== Testare clasa Sala ===\n";

    Sala sala(1, "Sala Test", 5, 6);

    verifica(sala.getId() == 1, "ID-ul salii este corect");
    verifica(sala.getNume() == "Sala Test", "Numele salii este corect");
    verifica(sala.getNrRanduri() == 5, "Numarul de randuri este corect");
    verifica(sala.getNrColoane() == 6, "Numarul de coloane este corect");
    verifica(sala.getNrLocuriLibere() == 30, "Sala are 30 de locuri libere initial");

    bool rezervare1 = sala.rezervaLoc(0, 0);
    verifica(rezervare1 == true, "Rezervarea unui loc liber functioneaza");

    bool rezervare2 = sala.rezervaLoc(0, 0);
    verifica(rezervare2 == false, "Rezervarea aceluiasi loc a doua oara este refuzata");

    verifica(sala.getNrLocuriOcupate() == 1, "Numarul locurilor ocupate este corect");

    sala.elibereazaLoc(0, 0);
    verifica(sala.getNrLocuriLibere() == 30, "Eliberarea locului functioneaza");

    bool rezervareInvalida = sala.rezervaLoc(100, 100);
    verifica(rezervareInvalida == false, "Rezervarea cu coordonate invalide este refuzata");
}

void testRezervare() {
    std::cout << "\n=== Testare clasa Rezervare ===\n";

    Rezervare rezervare(1, "Ion Popescu", 1, 1);

    verifica(rezervare.getId() == 1, "ID-ul rezervarii este corect");
    verifica(rezervare.getNumeClient() == "Ion Popescu", "Numele clientului este corect");
    verifica(rezervare.getFilmId() == 1, "ID-ul filmului este corect");
    verifica(rezervare.getSalaId() == 1, "ID-ul salii este corect");
    verifica(rezervare.getPretTotal() == 0.0, "Pretul initial este 0");

    rezervare.adaugaLoc(0, 0, 50.0);
    rezervare.adaugaLoc(0, 1, 50.0);

    verifica(rezervare.getLocuri().size() == 2, "Au fost adaugate 2 locuri");
    verifica(rezervare.getPretTotal() == 100.0, "Pretul total pentru 2 locuri normale este 100");

    rezervare.adaugaLoc(4, 0, 80.0);

    verifica(rezervare.getLocuri().size() == 3, "Au fost adaugate 3 locuri");
    verifica(rezervare.getPretTotal() == 180.0, "Pretul total cu loc VIP este 180");
}

int main() {
    std::cout << "========================================\n";
    std::cout << "     TESTE SISTEM REZERVARE CINEMA\n";
    std::cout << "========================================\n";

    testFilm();
    testLoc();
    testSala();
    testRezervare();

    std::cout << "\n========================================\n";
    std::cout << "Teste reusite: " << testeReusite << "\n";
    std::cout << "Teste esuate:  " << testeEsuate << "\n";
    std::cout << "Total teste:   " << testeReusite + testeEsuate << "\n";
    std::cout << "========================================\n";

    if (testeEsuate == 0) {
        std::cout << "Toate testele au trecut cu succes.\n";
    } else {
        std::cout << "Exista teste esuate. Verificati codul.\n";
    }

    return 0;
}
