# Testare - Sistem de Rezervare Cinema

Acest folder conține fișierele necesare pentru testarea aplicației „Sistem de Rezervare Cinema”.

## Fișier principal de testare

`test_clase.cpp`

Acest fișier testează clasele principale ale proiectului:

- Film
- Loc
- Sala
- Rezervare

## Ce se testează

### Clasa Film

Se verifică:

- salvarea corectă a ID-ului;
- salvarea corectă a titlului;
- salvarea corectă a genului;
- salvarea corectă a duratei;
- salvarea corectă a ratingului.

### Clasa Loc

Se verifică:

- dacă locul este liber inițial;
- dacă locul poate fi ocupat;
- dacă locul poate fi eliberat;
- dacă prețul locului normal este 50;
- dacă prețul locului VIP este 80.

### Clasa Sala

Se verifică:

- numărul de rânduri;
- numărul de coloane;
- numărul total de locuri libere;
- rezervarea unui loc liber;
- refuzarea rezervării unui loc deja ocupat;
- eliberarea unui loc;
- refuzarea coordonatelor invalide.

### Clasa Rezervare

Se verifică:

- salvarea ID-ului rezervării;
- salvarea numelui clientului;
- salvarea filmului și a sălii;
- adăugarea locurilor rezervate;
- calcularea corectă a prețului total.

## Cum se rulează testele

Pentru compilare se poate folosi comanda:

```bash
g++ -std=c++11 -Iinclude tests/test_clase.cpp src/Film.cpp src/Loc.cpp src/Sala.cpp src/Rezervare.cpp -o test_clase.exe
