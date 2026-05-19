# Outline prezentare - Sistem de Rezervare Cinema

## Responsabil

SADOVNIC Alina  
Product Owner + Demo Lead

## Slide 1 - Titlul proiectului

**Sistem de Rezervare Cinema**

Conținut:

- denumirea proiectului;
- numele echipei;
- grupa;
- disciplina / practica;
- anul de studii.

## Slide 2 - Echipa și rolurile

Conținut:

| Student | Rol |
|---|---|
| SADOVNIC Alina | Product Owner + Demo Lead |
| LOBOICO Anastasia | Project Manager / Scrum Master-lite |
| ȚURCAN Eric | Technical Lead + Developer |
| CUTCOVEȚCHI Denis | UX/UI Lead + Developer |
| BORȘ Constantin-Mihai | QA Lead + Documentation Lead |

## Slide 3 - Ideea proiectului

Conținut:

Aplicația simulează un sistem simplu de rezervare a locurilor la cinema. Utilizatorul poate vedea filmele disponibile, poate alege o sală, poate rezerva locuri și poate anula rezervările.

## Slide 4 - De ce am ales această temă

Conținut:

- tema este practică și ușor de înțeles;
- permite utilizarea claselor C++;
- include lucru cu vectori și structuri de date;
- permite repartizarea clară a responsabilităților în echipă;
- este potrivită pentru nivelul anului I.

## Slide 5 - Tehnologii utilizate

Conținut:

- C++;
- Dev-C++;
- GitHub;
- Trello;
- Markdown pentru documentație.

## Slide 6 - Structura proiectului

Conținut:

- folderul `include` conține fișierele `.h`;
- folderul `src` conține fișierele `.cpp`;
- folderul `tests` conține fișierele de testare;
- folderul `docs` conține documentația proiectului.

## Slide 7 - Clasele principale

Conținut:

| Clasă | Rol |
|---|---|
| Film | Păstrează informații despre filme |
| Loc | Reprezintă un loc din sală |
| Sala | Gestionează locurile disponibile și ocupate |
| Rezervare | Păstrează datele despre rezervare |
| UI | Gestionează afișarea meniului și mesajele |

## Slide 8 - Funcționalități implementate

Conținut:

- afișarea filmelor disponibile;
- afișarea sălilor disponibile;
- rezervarea locurilor;
- verificarea locurilor ocupate;
- calcularea prețului total;
- afișarea rezervărilor;
- anularea rezervărilor.

## Slide 9 - Meniul aplicației

Conținut:

Se prezintă captura de ecran cu meniul principal.

Explicație:

Meniul este simplu și permite accesul rapid la toate funcționalitățile aplicației.

## Slide 10 - Demonstrarea rezervării

Conținut:

Se prezintă pașii pentru rezervarea unui loc:

1. alegerea filmului;
2. alegerea sălii;
3. introducerea numelui clientului;
4. alegerea rândului și coloanei;
5. confirmarea rezervării.

## Slide 11 - Testare

Conținut:

- testarea afișării filmelor;
- testarea afișării sălilor;
- testarea rezervării;
- testarea anulării;
- testarea inputului invalid;
- identificarea bug-ului privind ID-ul filmului.

## Slide 12 - GitHub și organizarea codului

Conținut:

- repository GitHub;
- commit-uri realizate de membrii echipei;
- fișiere organizate în foldere;
- modificări încărcate treptat.

## Slide 13 - Trello și managementul proiectului

Conținut:

- task-uri împărțite pe roluri;
- coloane Backlog, To Do, In Progress, Done;
- urmărirea progresului;
- colaborarea în echipă.

## Slide 14 - Probleme identificate

Conținut:

| Problemă | Soluție viitoare |
|---|---|
| ID-ul filmului nu este verificat complet | Validare suplimentară |
| Datele nu se salvează după închiderea aplicației | Salvare în fișier |
| Interfața este doar în consolă | Posibilă interfață grafică |

## Slide 15 - Concluzie

Conținut:

Proiectul a demonstrat modul de creare a unui sistem simplu de rezervare la cinema folosind C++. Echipa a aplicat concepte de programare orientată pe obiecte, testare, documentare, lucru cu GitHub și organizare în Trello.
