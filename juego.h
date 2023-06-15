#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include "vibora.h"

class juego {
protected:
    int Tamano_x;
    int Tamano_y;
    int puntos;
    int comidasSeguidas;
    int Codex[100][100]; // Almacena la actual disposición del juego de forma codificada

public:
    juego(int tamano_x, int tamano_y);
    void setpuntos();
    void setCodex(int x, int y, int valor);
    int getTamano_x();
    int getTamano_y();
    int getpuntos();
    int getCodex(int x, int y);
    void Dibujar();
    void Jugar(vibora V, jugador J);
    void Generar_comida();
    bool ChequeoC(int x, int y);
    void Colision(int Vcx, int Vcy, jugador J, bool& perdiste);
    void Definir_tablero();
    void borrarcola(int x, int y);
    void Reiniciar();
};

#endif // JUEGO_Hlaur