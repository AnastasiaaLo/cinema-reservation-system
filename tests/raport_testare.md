# Raport de testare

## Proiect

Sistem de Rezervare Cinema

## Responsabil testare

BORȘ Constantin-Mihai  
QA Lead + Documentation Lead

## Scopul testării

Scopul testării este verificarea funcționalităților principale ale aplicației și identificarea eventualelor erori înainte de prezentarea finală.

## Funcționalități testate

| Nr. | Funcționalitate | Status |
|---|---|---|
| 1 | Afișarea meniului principal | Trecut |
| 2 | Afișarea filmelor disponibile | Trecut |
| 3 | Afișarea sălilor disponibile | Trecut |
| 4 | Rezervarea unui loc normal | Trecut |
| 5 | Refuzarea unui loc deja ocupat | Trecut |
| 6 | Afișarea tuturor rezervărilor | Trecut |
| 7 | Anularea unei rezervări | Trecut |
| 8 | Eliberarea locului după anulare | Trecut |
| 9 | Tratarea inputului invalid | Parțial trecut |
| 10 | Ieșirea din aplicație | Trecut |

## Probleme identificate

| Nr. | Problemă | Gravitate | Soluție propusă |
|---|---|---|---|
| 1 | Aplicația nu verifică dacă ID-ul filmului introdus există | Medie | Adăugarea unei verificări pentru filmId înainte de continuarea rezervării |
| 2 | Aplicația verifică ID-ul sălii și afișează eroare dacă sala nu există | Observație | Funcționalitatea lucrează corect |
| 3 | Inputul invalid este tratat complet doar la meniul principal | Medie | Adăugarea validării pentru toate câmpurile introduse de utilizator |

## Scenarii testate manual

| Nr. | Scenariu | Pași efectuați | Rezultat |
|---|---|---|---|
| 1 | Pornirea aplicației | Aplicația a fost rulată în Dev-C++ | Meniul principal s-a afișat corect |
| 2 | Afișare filme | A fost selectată opțiunea 1 | Filmele au fost afișate |
| 3 | Afișare săli | A fost selectată opțiunea 2 | Sălile au fost afișate |
| 4 | Rezervare loc | Film 1, sala 1, loc A1 | Rezervarea a fost creată |
| 5 | ID film inexistent | A fost introdus ID film 4 | Aplicația a continuat fără eroare, bug identificat |
| 6 | ID sală inexistent | A fost introdus ID sală 3 | Aplicația a afișat eroare corect |
| 7 | Vizualizare rezervări | A fost selectată opțiunea 4 | Rezervarea a fost afișată |
| 8 | Anulare rezervare | A fost selectată opțiunea 5 și ID-ul rezervării | Rezervarea a fost anulată |
| 9 | Ieșire din aplicație | A fost selectată opțiunea 0 | Aplicația s-a închis corect |

## Concluzie

Aplicația funcționează corect pentru funcționalitățile principale: afișarea filmelor, afișarea sălilor, rezervarea locurilor, vizualizarea rezervărilor și anularea rezervărilor.

În timpul testării a fost identificat un bug de validare: aplicația nu verifică dacă ID-ul filmului introdus există. Totuși, aplicația verifică corect ID-ul sălii și afișează mesaj de eroare dacă sala nu există.

Bug-ul identificat nu oprește rularea aplicației, dar poate fi îmbunătățit într-o versiune viitoare prin validarea tuturor datelor introduse de utilizator.
