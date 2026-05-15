@echo off
echo Compilare sistem rezervare cinema...
g++ -std=c++17 -Wall -Iinclude src/main.cpp src/Film.cpp src/Loc.cpp src/Sala.cpp src/Rezervare.cpp -o cinema.exe
if %errorlevel% == 0 (
    echo Compilare reusita! Ruleaza cinema.exe
) else (
    echo Eroare la compilare!
)
pause
