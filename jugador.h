#ifndef _JUGADOR_H_ // Si el símbolo _JUGADOR_H_ no está definido, significa que el archivo de encabezado no ha sido incluido previamente.
#define _JUGADOR_H_ //Esto evita que el código dentro del bloque #ifndef sea incluido nuevamente si se encuentra en otra parte del programa.

#include <string>
using namespace std;
class jugador {
protected:
    string Nombre;

public:
    jugador(const string& nombre);
    void setNombre(const string& nombre);
    const string& getNombre() const;
    char escuchardireccion();
};

#endif //Cierra el bloque condicional #ifndef y finaliza la inclusión condicional.