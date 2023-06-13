#include "juego.h"
#include <iostream>
#include <cstdlib>
using namespace std;

juego::juego(int x, int y) {
    Tamano_x = x;
    Tamano_y = y;
    puntos = 0;
    Codex[100][100];
    Definir_tablero();
    Generar_comida();
}

void juego::setpuntos() {
    puntos++;
}

void juego::setCodex(int x, int y, int c) {
    Codex[x][y] = c;
}

int juego::getpuntos() {
    return puntos;
}

int juego::getTamano_x() {
    return Tamano_x;
}

int juego::getTamano_y() {
    return Tamano_y;
}

int juego::getCodex(int f, int g) {
    return Codex[f][g];
}

void juego::Dibujar() {
    for (int i = 0; i <= getTamano_y(); i++) {
        for (int j = 0; j <= getTamano_x(); j++) {

            switch (getCodex(j, i)) {
                case 0:
                    cout << "  ";
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    cout << "O ";
                    break;
                case 3:
                    cout << "| ";
                    break;
                case -3:
                    cout << " |" << endl;
                    break;
                case 2:
                    cout << "__";
                    break;
                case -2:
                    cout << "__" << endl;
                    break;
                case -1:
                    cout << "@ ";
                    break;
                case 8:
                    cout << "* ";
                    break;

                default:
                    break;
            }
        }
    }
}

void juego::Jugar(vibora V, jugador J) {
    bool perdiste = false; // Inicializar la variable perdiste
    while (!perdiste) { // Cambiar la condición del bucle
        Dibujar();
        V.setDirecion(J.escuchardireccion());
        int c = V.obtenerDireccionCabeza(J);
        if (ChequeoC(V.getCabeza_x(), V.getCabeza_y())) {
            cout << "comi" << endl;
            Generar_comida();
        }
        Colision(V.getCabeza_x(), V.getCabeza_y(), J, perdiste); // Pasar la variable perdiste por referencia
        setCodex(V.getCabeza_x(), V.getCabeza_y(), c);
        borrarcola(V.getCabeza_x(), V.getCabeza_y());
    }
    cout << "HAS PERDIDO " << J.getNombre() << endl << "Puntuacion: " << getpuntos() << endl;
}

void juego::Definir_tablero() { //esta funcion dibuja el tablero segun la cantidad de espacios indicados
    for (int i = 0; i <= getTamano_y(); i++) {
        for (int j = 0; j <= getTamano_x(); j++) {
            if (j == 0) setCodex(j, i, 3);
            if (j == getTamano_x()) setCodex(j, i, -3);
            if (i == 0) setCodex(j, i, 2);
            if (i == 0 && j == getTamano_x()) setCodex(j,i, -2);
            if (i == getTamano_y()) setCodex(j, i, 2);
        }
    }
    Codex[5][5] = 4;
}

void juego::Generar_comida() {
    int ranx = rand() % (getTamano_x() - 1) + 1;
    int rany = rand() % (getTamano_y() - 1) + 1;
    while (getCodex(ranx, rany) != 0) {
        ranx = rand() % (getTamano_x() - 1) + 1;
        rany = rand() % (getTamano_y() - 1) + 1;
    }
    setCodex(ranx, rany, 8);
}

bool juego::ChequeoC(int Dx, int Dy) {
    if (getCodex(Dx, Dy) == 8) {
        setpuntos();
        return true;
    }
    return false;
}

void juego::borrarcola(int cabesax, int cabesay) {
    int Vp = puntos;
    int Vx = cabesax;
    int Vy = cabesay;
    bool cc = true;
    while (cc) {
        switch (getCodex(Vx, Vy)) {
            case 4:
                Vy--;
                break;
            case 5:
                Vy++;
                break;
            case 7:
                Vx--;
                break;
            case 6:
                Vx++;
                break;
            default:
                cc = false;
                break;
        }
        if (Vp <= 0) {
            setCodex(Vx, Vy, 0);
        }
        Vp--;
    }
}

void juego::Colision(int Vcx, int Vcy, jugador J, bool& perdiste) {
    if (getCodex(Vcx, Vcy) == 3 || getCodex(Vcx, Vcy) == -3 || getCodex(Vcx, Vcy) == 2 ||
        getCodex(Vcx, Vcy) == 5 || getCodex(Vcx, Vcy) == 7 || getCodex(Vcx, Vcy) == 4 ||
        getCodex(Vcx, Vcy) == 6 || getCodex(Vcx, Vcy) == -2) {
        perdiste = true; // Actualizar el valor de perdiste
        return;
    }

    // Comprobar colisión consigo misma
    for (int i = 1; i <= getTamano_y(); i++) {
        for (int j = 1; j <= getTamano_x(); j++) {
            if (getCodex(j, i) == 4 || getCodex(j, i) == 5 || getCodex(j, i) == 6 || getCodex(j, i) == 7) {
                if (j == Vcx && i == Vcy) {
                    perdiste = true; // Actualizar el valor de perdiste
                    return;
                }
            }
        }
    }
}