#ifndef VIBORA_H
#define VIBORA_H

#include <vector>
#include <utility>
#include <iostream>
#include "jugador.h"

class vibora {
private:
    int Cabeza_x;
    int Cabeza_y;
    char Direcion;
    std::vector<std::pair<int, int>> Cuerpo;
    int longitud;

public:
    vibora(char f);
    void setDirecion(char f);
    char getDirecion();
    void setCabeza_x(int x);
    void setCabeza_y(int z);
    int getCabeza_x();
    int getCabeza_y();
    void actualizarCuerpo();
    int obtenerDireccionCabeza(jugador J);
};

#endif // VIBORA_H