# Sistem de Rezervare Cinema

Proiect realizat în cadrul practicii de specialitate, anul I.

## Descrierea proiectului

Aplicația simulează un sistem simplu de rezervare a locurilor la cinematograf. Utilizatorul poate vedea filmele disponibile, alege o sală și rezerva locurile dorite. Proiectul a fost realizat pentru a aplica cunoștințele acumulate la programare orientată pe obiecte, algoritmi și structuri de date.

## Funcționalități

- Afișarea filmelor disponibile
- Alegerea unei săli de cinema
- Afișarea vizuală a locurilor (libere / ocupate / VIP)
- Rezervarea unuia sau mai multor locuri
- Verificarea automată a disponibilității locurilor
- Calculul prețului total
- Vizualizarea tuturor rezervărilor
- Anularea unei rezervări
- Salvarea datelor în fișier (în dezvoltare)

## Tehnologii folosite

- **Limbaj**: C++ (standard C++17)
- **Compilator**: g++ (MinGW pentru Windows, GCC pentru Linux/macOS)
- **Versionare**: Git + GitHub
- **Management proiect**: Trello

## Structura proiectului

```
cinema-reservation-system/
├── include/          # Fișiere header (.h)
│   ├── Film.h
│   ├── Loc.h
│   ├── Sala.h
│   └── Rezervare.h
├── src/              # Fișiere de implementare (.cpp)
│   ├── Film.cpp
│   ├── Loc.cpp
│   ├── Sala.cpp
│   ├── Rezervare.cpp
│   └── main.cpp
├── data/             # Fișiere de date (rezervări salvate)
├── docs/             # Documentație
├── tests/            # Teste
├── Makefile          # Pentru compilare pe Linux/macOS
├── compile.bat       # Pentru compilare pe Windows
└── README.md
```

## Cum se compilează și se rulează

### Pe Windows

1. Asigură-te că ai instalat **MinGW** (g++)
2. Deschide Command Prompt în folderul proiectului
3. Rulează:
```
compile.bat
```
4. Pornește aplicația:
```
cinema.exe
```

### Pe Linux / macOS

1. Asigură-te că ai instalat **g++**
2. Deschide terminal în folderul proiectului
3. Compilează:
```
make
```
4. Rulează:
```
make run
```
5. Pentru ștergerea fișierelor temporare:
```
make clean
```

## Echipa

| Membru | Rol |
|--------|-----|
| [Nume 1] | Product Owner & Demo Lead |
| [Nume 2] | Project Manager (Scrum Master) |
| [Nume 3] | Technical Lead & Developer |
| [Nume 4] | UX/UI Lead & Developer |
| [Nume 5] | QA Lead & Documentation Lead |

## Status proiect

- [x] Sprint 1: Arhitectură și clase de bază
- [ ] Sprint 2: Funcționalități complete
- [ ] Sprint 3: Testare și documentație finală

## Licență

Acest proiect este distribuit sub licența MIT.
