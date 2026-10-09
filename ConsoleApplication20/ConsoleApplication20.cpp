#include "pch.h"
#include <iostream>
#include <time.h>

using namespace System;
using namespace std;

const int cols = 200;
const int rows = 45;

void initialSettings() {
    Console::SetWindowSize(cols, rows);
    Console::SetBufferSize(cols, rows);

    Console::CursorVisible = false;
}

void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}
//imprimir entidad U
void printU(int x, int y) {
    goToXY(x, y);
    cout << "U";
}
//eliminar entidad U
void deleteU(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

//imprimir entidad P
void printP(int x, int y) {
    goToXY(x, y);
    cout << "P";
}
//eliminar entidad P
void deleteP(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

//imprimir entidad C
void printC(int x, int y) {
    goToXY(x, y);
    cout << "C";
}
//eliminar entidad C
void deleteC(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

int getRandomNumber(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main()
{
    srand(time(NULL));
    //Atributos de u
    int wU = 1, hU = 1;
    int xU = getRandomNumber(0, (cols - 1) - wU), yU = getRandomNumber(0, (rows - 1) - hU);
    int directionU = getRandomNumber(0, 3);
    int dxU = -1, dyU = -1;
    if (directionU == 0) { dxU = 1; dyU = -1; }
    if (directionU == 1) { dxU = -1; dyU = -1; }
    if (directionU == 2) { dxU = 1; dyU = 1; }
    if (directionU == 3) {dxU = -1; dyU = 1;}

    //Atributos de p
    int wP = 1, hP = 1;
    int xP = getRandomNumber(0, (cols - 1) - wP), yP = getRandomNumber(0, (rows - 1) - hP);
    int directionP = getRandomNumber(0, 3);
    int dxP = -1, dyP = -1;
    if (directionP == 0) { dxP = 1; dyP = -1; }
    if (directionP == 1) { dxP = -1; dyP = -1; }
    if (directionP == 2) { dxP = 1; dyP = 1; }
    if (directionP == 3) { dxP = -1; dyP = 1; }

    //Atributos de c
    int wC = 1, hC = 1;
    int xC = getRandomNumber(0, (cols - 1) - wC), yC = getRandomNumber(0, (rows - 1) - hC);
    int directionC = getRandomNumber(0, 3);
    int dxC = -1, dyC = -1;
    if (directionC == 0) { dxC = 1; dyC = -1; }
    if (directionC == 1) { dxC = -1; dyC = -1; }
    if (directionC == 2) { dxC = 1; dyC = 1; }
    if (directionC == 3) { dxC = -1; dyC = 1; }


    int visibleU = 0, visibleP = 0, visibleC = 0;

    initialSettings();

    while (1) {
        deleteU(xU, yU);
        deleteP(xP, yP);
        deleteC(xC, yC);

        if (Console::KeyAvailable) {
            ConsoleKeyInfo tecla = Console::ReadKey(true);

            if (tecla.Key == ConsoleKey::U) {
                visibleU = 1;
            }
            if (tecla.Key == ConsoleKey::P) {
                visibleP = 1;
                visibleU = 0;
            }
            if (tecla.Key == ConsoleKey::C) {
                visibleP = 0;
                visibleU = 0;
                visibleC = 1;
            }
            if (tecla.Key == ConsoleKey::Escape) {
                break;
            }
        }

        //colisión U
        if (xU + dxU >= (cols - wU)) {dxU = -1;}
        if (xU + dxU <= 0) {dxU = 1;}
        if (yU + dyU >= (rows - hU)) {dyU = -1;}
        if (yU + dyU <= 0) {dyU = 1;}

        //colisión P
        if (xP + dxP >= (cols - wP)) { dxP = -1; }
        if (xP + dxP <= 0) { dxP = 1; }
        if (yP + dyP >= (rows - hP)) { dyP = -1; }
        if (yP + dyP <= 0) { dyP = 1; }

        //colisión C
        if (xC + dxC >= (cols - wC)) { dxC = -1; }
        if (xC + dxC <= 0) { dxC = 1; }
        if (yC + dyC >= (rows - hC)) { dyC = -1; }
        if (yC + dyC <= 0) { dyC = 1; }

        // actualizando coordenadas U
        xU += dxU;
        yU += dyU;
        // actualizando coordenadas P
        xP += dxP;
        yP += dyP;
        // actualizando coordenadas C
        xC += dxC;
        yC += dyC;

        if (visibleU == 1) printU(xU, yU);
        if (visibleP == 1) printP(xP, yP);
        if (visibleC == 1) printC(xC, yC);
        _sleep(10);
    }



    cin.get();
    cin.ignore();
    return 0;
}
