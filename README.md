# 🎬 Sistem de Rezervare a Locurilor la Cinema

Proiect realizat în cadrul practicii de specialitate, anul I.

---

# 📖 Descriere

Acest proiect reprezintă o aplicație simplă pentru rezervarea locurilor la cinema. Programul permite utilizatorului să aleagă un film, să vizualizeze locurile disponibile într-o sală și să efectueze rezervări.

Aplicația este realizată în limbajul C++ și rulează în consolă. Scopul principal al proiectului este aplicarea cunoștințelor studiate în anul I, precum:

- programarea orientată pe obiecte;
- utilizarea claselor și obiectelor;
- lucrul cu vectori și funcții;
- organizarea codului în mai multe fișiere;
- utilizarea GitHub pentru colaborare în echipă.

Proiectul reprezintă o simulare educațională și nu un sistem real utilizat într-un cinematograf comercial.

---

# ✨ Funcționalități

Aplicația permite:

- afișarea filmelor disponibile;
- alegerea unei săli de cinema;
- afișarea locurilor din sală;
- verificarea locurilor libere și ocupate;
- rezervarea unuia sau mai multor locuri;
- calcularea prețului total;
- afișarea rezervărilor efectuate;
- anularea unei rezervări.

⚠️ Funcționalitatea de salvare a datelor în fișier este încă în dezvoltare.

---

# 🛠️ Tehnologii utilizate

- C++
- Standard C++17
- g++ / MinGW
- Git și GitHub
- Trello pentru organizarea sarcinilor

---

# 👥 Echipa proiectului

| Student | Rol |
|---|---|
| LOBOICO Anastasia | Project Manager / Scrum Master-lite |
| SADOVNIC Alina | Product Owner + Demo Lead |
| ȚURCAN Eric | Technical Lead + Developer |
| CUTCOVEȚCHI Denis | UX/UI Lead + Developer |
| BORȘ Constantin-Mihai | QA Lead + Documentation Lead |

---

# 📂 Structura proiectului

```bash
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
