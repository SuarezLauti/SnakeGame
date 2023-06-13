#ifndef _juego_H_
#define _juego_H_
#include <string.h>
#include "jugador.h"
class vibora{
protected:
    int Cabeza_x;
    int Cabeza_y;
    char Direcion;

public:
    vibora(char);
    void setCabeza_x(int);
    void setCabeza_y(int);
    void setDirecion(char);
    char getDirecion();
    int getCabeza_x();
    int getCabeza_y();
    int obtenerDireccionCabeza(jugador);
};
#endif