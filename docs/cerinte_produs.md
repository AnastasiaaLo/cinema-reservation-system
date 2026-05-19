# Cerințe produs - Sistem de Rezervare Cinema

## Responsabil

SADOVNIC Alina  
Product Owner + Demo Lead

## Descriere generală

Aplicația „Sistem de Rezervare Cinema” este un program în consolă care permite utilizatorului să vizualizeze filmele disponibile, să aleagă o sală de cinema, să rezerve locuri, să vadă rezervările efectuate și să anuleze o rezervare.

Scopul aplicației este de a simula un sistem simplu de rezervare a locurilor la cinema, utilizând concepte de programare orientată pe obiecte, structuri de date și lucru în echipă.

## Public țintă

Aplicația este destinată:

- utilizatorilor care doresc să rezerve locuri la cinema;
- personalului de la casa de bilete;
- studenților și profesorilor, pentru prezentarea proiectului practic.

## Funcționalități principale

| Nr. | Funcționalitate | Descriere |
|---|---|---|
| 1 | Afișarea filmelor disponibile | Utilizatorul poate vedea lista filmelor existente în aplicație |
| 2 | Afișarea sălilor disponibile | Utilizatorul poate vedea sălile și numărul de locuri libere |
| 3 | Rezervarea locurilor | Utilizatorul poate alege un film, o sală și unul sau mai multe locuri |
| 4 | Verificarea locurilor ocupate | Aplicația nu permite rezervarea unui loc deja ocupat |
| 5 | Calcularea prețului total | Aplicația calculează automat prețul rezervării |
| 6 | Vizualizarea rezervărilor | Utilizatorul poate vedea toate rezervările efectuate |
| 7 | Anularea rezervării | Utilizatorul poate anula o rezervare după ID |
| 8 | Ieșirea din aplicație | Utilizatorul poate închide aplicația prin opțiunea 0 |

## Cerințe funcționale

### F1. Afișarea filmelor

Aplicația trebuie să afișeze cel puțin 3 filme disponibile.

Criterii de acceptare:

- fiecare film are ID;
- fiecare film are titlu;
- fiecare film are gen;
- fiecare film are durată;
- fiecare film are rating;
- filmele pot fi afișate din meniul principal.

### F2. Afișarea sălilor

Aplicația trebuie să afișeze sălile disponibile și numărul de locuri libere.

Criterii de acceptare:

- aplicația afișează cel puțin 2 săli;
- pentru fiecare sală se afișează ID-ul;
- pentru fiecare sală se afișează denumirea;
- pentru fiecare sală se afișează numărul de locuri libere.

### F3. Rezervarea locurilor

Aplicația trebuie să permită utilizatorului să rezerve unul sau mai multe locuri.

Criterii de acceptare:

- utilizatorul alege ID-ul filmului;
- utilizatorul alege ID-ul sălii;
- utilizatorul introduce numele clientului;
- utilizatorul alege rândul și coloana locului;
- aplicația confirmă rezervarea.

### F4. Verificarea disponibilității locului

Aplicația trebuie să verifice dacă locul ales este liber.

Criterii de acceptare:

- dacă locul este liber, rezervarea este permisă;
- dacă locul este ocupat, rezervarea este refuzată;
- dacă locul nu există, aplicația afișează mesaj de eroare.

### F5. Calcularea prețului

Aplicația trebuie să calculeze automat prețul rezervării.

Criterii de acceptare:

- locul normal are prețul 50 RON;
- locul VIP are prețul 80 RON;
- prețul total se calculează în funcție de locurile alese.

### F6. Vizualizarea rezervărilor

Aplicația trebuie să permită afișarea rezervărilor existente.

Criterii de acceptare:

- dacă există rezervări, acestea se afișează;
- dacă nu există rezervări, se afișează mesaj corespunzător;
- pentru fiecare rezervare se afișează ID-ul, clientul și prețul total.

### F7. Anularea rezervării

Aplicația trebuie să permită anularea unei rezervări.

Criterii de acceptare:

- utilizatorul introduce ID-ul rezervării;
- dacă rezervarea există, aceasta este anulată;
- locurile rezervate devin libere;
- dacă rezervarea nu există, aplicația afișează mesaj de eroare.

## Cerințe non-funcționale

| Nr. | Cerință | Descriere |
|---|---|---|
| 1 | Simplitate | Aplicația trebuie să fie ușor de utilizat |
| 2 | Claritate | Meniul trebuie să fie clar și organizat |
| 3 | Stabilitate | Aplicația nu trebuie să se închidă brusc la utilizare normală |
| 4 | Portabilitate | Aplicația poate fi rulată în Dev-C++ sau cu un compilator C++ |
| 5 | Organizare | Codul este împărțit în fișiere `.h` și `.cpp` |

## User Stories

### US1

Ca utilizator, vreau să văd filmele disponibile, ca să pot alege filmul dorit.

### US2

Ca utilizator, vreau să văd sălile disponibile, ca să pot alege sala potrivită.

### US3

Ca utilizator, vreau să văd locurile libere și ocupate, ca să pot alege un loc disponibil.

### US4

Ca utilizator, vreau să pot rezerva unul sau mai multe locuri, ca să merg la cinema cu prietenii.

### US5

Ca utilizator, vreau să pot anula o rezervare, dacă nu mai pot ajunge la film.

### US6

Ca utilizator, vreau să văd toate rezervările, ca să pot verifica ce locuri au fost rezervate.

## Observații Product Owner

Aplicația îndeplinește funcționalitățile principale necesare pentru un sistem simplu de rezervare la cinema. În timpul testării a fost identificată o problemă de validare: aplicația nu verifică complet ID-ul filmului introdus. Această funcționalitate poate fi îmbunătățită într-o versiune viitoare.
