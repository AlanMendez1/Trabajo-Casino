#ifndef INC_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_AA_H
#define INC_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_AA_H
#include "Juego.h"
#include <iostream>
#include <random>

using namespace std;

class AdivinaAdivinador : public Juego {
public:
    AdivinaAdivinador() = default;
    ~AdivinaAdivinador() = default;
    int  jugar(int n , string c) override ;
    void mostrarReglas() override;
};

#endif
