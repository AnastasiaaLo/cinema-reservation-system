# Script demo - Sistem de Rezervare Cinema

## Responsabil

SADOVNIC Alina  
Product Owner + Demo Lead

## Scopul demo-ului

Scopul demo-ului este prezentarea funcționalităților principale ale aplicației „Sistem de Rezervare Cinema” și demonstrarea modului în care utilizatorul poate face o rezervare, poate vizualiza rezervările și poate anula o rezervare.

## Durata estimată

8-10 minute

## Structura demo-ului

### 1. Introducere

Bună ziua! Astăzi vom prezenta proiectul nostru „Sistem de Rezervare Cinema”, realizat în cadrul practicii de specialitate.

Aplicația este realizată în C++ și permite utilizatorului să vizualizeze filme, să aleagă o sală, să rezerve locuri și să anuleze rezervările efectuate.

### 2. Pornirea aplicației

Se rulează aplicația în Dev-C++.

La pornire se afișează meniul principal:

- Vezi filmele disponibile;
- Vezi sălile disponibile;
- Rezervă locuri;
- Vezi toate rezervările;
- Anulează o rezervare;
- Ieșire.

### 3. Afișarea filmelor

Se alege opțiunea 1.

Explicație pentru prezentare:

Prin această opțiune, utilizatorul poate vedea lista filmelor disponibile. Pentru fiecare film sunt afișate informații precum titlul, genul, durata și ratingul.

### 4. Afișarea sălilor

Se alege opțiunea 2.

Explicație pentru prezentare:

Aplicația afișează sălile disponibile și numărul de locuri libere. În proiect avem două săli: Sala 1 - Standard și Sala 2 - Premium.

### 5. Rezervarea unui loc

Se alege opțiunea 3.

Pași pentru demo:

1. Alegem filmul cu ID-ul 1.
2. Alegem sala cu ID-ul 1.
3. Introducem numele clientului: Ion Popescu.
4. Alegem rândul A.
5. Alegem coloana 1.
6. La întrebarea „Mai rezervi un loc?”, alegem n.

Explicație pentru prezentare:

Aplicația verifică dacă locul ales este liber. Dacă locul este disponibil, rezervarea este creată și se calculează prețul total.

### 6. Vizualizarea rezervărilor

Se alege opțiunea 4.

Explicație pentru prezentare:

Prin această opțiune putem vedea rezervările existente. Se afișează ID-ul rezervării, numele clientului și prețul total.

### 7. Testarea unei rezervări duble

Se încearcă rezervarea aceluiași loc încă o dată.

Pași:

1. Alegem opțiunea 3.
2. Alegem același film.
3. Alegem aceeași sală.
4. Introducem un alt nume.
5. Alegem același loc A1.

Explicație pentru prezentare:

Aplicația trebuie să refuze rezervarea unui loc deja ocupat. Acest lucru demonstrează că sistemul verifică disponibilitatea locurilor.

### 8. Anularea rezervării

Se alege opțiunea 5.

Pași:

1. Alegem opțiunea 5.
2. Introducem ID-ul rezervării.
3. Aplicația anulează rezervarea.
4. Locul devine liber din nou.

Explicație pentru prezentare:

Această funcționalitate permite anularea rezervărilor și eliberarea locurilor rezervate anterior.

### 9. Testarea unei erori

Se introduce un ID de sală inexistent.

Explicație pentru prezentare:

Aplicația afișează mesaj de eroare atunci când sala nu există. În timpul testării QA a fost observat că validarea ID-ului filmului poate fi îmbunătățită într-o versiune viitoare.

### 10. Încheiere

În concluzie, aplicația permite realizarea funcționalităților principale ale unui sistem simplu de rezervare la cinema: afișarea filmelor, afișarea sălilor, rezervarea locurilor, vizualizarea rezervărilor și anularea acestora.

Proiectul ne-a ajutat să aplicăm concepte de programare orientată pe obiecte, lucru cu fișiere multiple, organizare pe roluri și colaborare în echipă.
