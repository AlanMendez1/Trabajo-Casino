#ifndef INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_ELMAYORDE13_H
#define INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_ELMAYORDE13_H
#include "Juego.h"
#include <vector>
#include <iostream>
#include <random>
using namespace std;

class ElMayorDe13 : public Juego {

public:
    ElMayorDe13() = default;
    ~ElMayorDe13() = default;
    int  jugar(int n , string c) override;
    void mostrarReglas() override;
};


#endif
