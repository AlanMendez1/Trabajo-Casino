#ifndef INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_DOSCOLORES_H
#define INC_6_CLASES_HERENCIA_POLIMORFISMO_CASINO_JOSHUA_MENDEZ_Y_SEBASTIAN_IZQUIERDO_DOSCOLORES_H
#include "Juego.h"
#include <vector>
#include <iostream>
#include <random>
using namespace std;
class DosColores : public Juego {
private:
    vector<int> dado = {1 , 2 , 3 ,4 , 5 ,6};
    vector<string> color = {"NEGRO" , "BLANCO"};
public:
    DosColores() = default;
    ~DosColores() = default;
    int  jugar(int n , string c) override ;
    void mostrarReglas() override;
};

#endif