#include "juego.h"
#include <iostream>
#include <cstdlib>

using namespace std;

juego::juego(int tamano_x, int tamano_y) {
    Tamano_x = tamano_x;
    Tamano_y = tamano_y;
    puntos = 0;
    comidasSeguidas = 0;
    Definir_tablero();
    Generar_comida();
}

void juego::setpuntos() {
    puntos++;
}

void juego::setCodex(int x, int y, int c) {
    Codex[x][y] = c;
}

int juego::getTamano_x() {
    return Tamano_x;
}

int juego::getTamano_y() {
    return Tamano_y;
}

int juego::getpuntos() {
    return puntos;
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
                    cout << "> ";
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
    bool perdiste = false;
    while (!perdiste) {
        Dibujar();
        V.setDirecion(J.escuchardireccion());
        int c = V.obtenerDireccionCabeza(J);
        if (ChequeoC(V.getCabeza_x(), V.getCabeza_y())) {
            Generar_comida();
        }
        Colision(V.getCabeza_x(), V.getCabeza_y(), J, perdiste);

        setCodex(V.getCabeza_x(), V.getCabeza_y(), c);
        borrarcola(V.getCabeza_x(), V.getCabeza_y());

        if (perdiste) {
            break; // Salir del bucle si se perdió el juego
        }
    }
    cout << "HAS PERDIDO " << J.getNombre() << endl << "Puntuacion: " << getpuntos() << endl;
}

void juego::Definir_tablero() {
    for (int i = 0; i <= getTamano_y(); i++) {
        for (int j = 0; j <= getTamano_x(); j++) {
            if (j == 0)
                setCodex(j, i, 3);
            if (j == getTamano_x())
                setCodex(j, i, -3);
            if (i == 0)
                setCodex(j, i, 2);
            if (i == 0 && j == getTamano_x())
                setCodex(j, i, -2);
            if (i == getTamano_y())
                setCodex(j, i, 2);
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

    comidasSeguidas++;
    if (comidasSeguidas >= 10) {
        int ranx2 = rand() % (getTamano_x() - 1) + 1;
        int rany2 = rand() % (getTamano_y() - 1) + 1;
        while (getCodex(ranx2, rany2) != 0) {
            ranx2 = rand() % (getTamano_x() - 1) + 1;
            rany2 = rand() % (getTamano_y() - 1) + 1;
        }
        setCodex(ranx2, rany2, 8);
        comidasSeguidas = 0;
    }
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
        perdiste = true;
        return;
    }

    // Comprobar colisión consigo misma
    for (int i = 1; i <= getTamano_y(); i++) {
        for (int j = 1; j <= getTamano_x(); j++) {
            if (getCodex(j, i) == 4 || getCodex(j, i) == 5 || getCodex(j, i) == 6 || getCodex(j, i) == 7) {
                if (j == Vcx && i == Vcy) {
                    // Ignorar colisión si la cabeza está en la misma posición que su propio cuerpo
                    if (getCodex(Vcx, Vcy) != 4) {
                        perdiste = true;
                        return;
                    }
                }
            }
        }
    }
}
void juego::Reiniciar() {
    puntos = 0;
    comidasSeguidas = 0;
    // Restablecer el tablero
    for (int i = 0; i <= getTamano_y(); i++) {
        for (int j = 0; j <= getTamano_x(); j++) {
            if (j == 0)
                setCodex(j, i, 3);
            if (j == getTamano_x())
                setCodex(j, i, -3);
            if (i == 0)
                setCodex(j, i, 2);
            if (i == 0 && j == getTamano_x())
                setCodex(j, i, -2);
            if (i == getTamano_y())
                setCodex(j, i, 2);
            if (i != 0 && i != getTamano_y() && j != 0 && j != getTamano_x())
                setCodex(j, i, 0);
        }
    }
    Generar_comida();
}