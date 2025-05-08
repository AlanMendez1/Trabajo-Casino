#ifndef INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_JUEGO_H
#define INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_JUEGO_H
#include <string>
#include "Usuario.h"
class Juego {
public:
    void  virtual mostrarReglas() = 0;
    int   virtual jugar(int n , string c) = 0 ;
};


#endif
