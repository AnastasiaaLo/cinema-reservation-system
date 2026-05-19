# Sistem de Rezervare Cinema

Proiect realizat în cadrul practicii de specialitate, anul I.

## Descriere

Acest proiect reprezintă o aplicație simplă pentru rezervarea locurilor la cinema. Programul permite utilizatorului să aleagă un film, să vadă locurile disponibile într-o sală și să facă o rezervare.

Aplicația este realizată în C++ și rulează în consolă. Proiectul a fost făcut pentru a exersa lucrul cu clase, obiecte, vectori, funcții și organizarea codului în mai multe fișiere.

Proiectul nu este un sistem real de cinema, ci o simulare realizată în scop educațional.

## Funcționalități

Aplicația permite:

- afișarea filmelor disponibile;
- alegerea unei săli de cinema;
- afișarea locurilor din sală;
- verificarea locurilor libere și ocupate;
- rezervarea unuia sau mai multor locuri;
- calcularea prețului total;
- afișarea rezervărilor efectuate;
- anularea unei rezervări.

Funcționalitatea de salvare a datelor în fișier este încă în dezvoltare.

## Tehnologii folosite

- C++
- C++17
- g++ / MinGW
- Git și GitHub
- Trello pentru organizarea sarcinilor

## Structura proiectului

```text
cinema-reservation-system/
├── include/
│   ├── Film.h
│   ├── Loc.h
│   ├── Sala.h
│   └── Rezervare.h
│
├── src/
│   ├── Film.cpp
│   ├── Loc.cpp
│   ├── Sala.cpp
│   ├── Rezervare.cpp
│   └── main.cpp
│
├── data/
├── docs/
├── tests/
├── compile.bat
├── Makefile
└── README.md
