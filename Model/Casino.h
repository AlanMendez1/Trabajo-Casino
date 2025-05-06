//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_CASINO_H
#define CASINO_CASINO_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Juego.h"
#include "Mayor13.h"
#include "DosColores.h"
#include "Slots.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::iterator;

class Casino {
private:
    vector<Juego *> juegosDisponibles;
    unordered_map<long, Jugador *> jugadoresMap;

    bool
    verPuedeContinuar(int idJugador, float gonzosApostar); // True si tiene saldo para jugar, false en caso contrario

public:
    Casino();

    virtual ~Casino();

    float convertirPesosAGonzos(float dinero);

    bool verExisteJugador(long id);

    void retirarJugador(long id);

    void agregarJugador();

    // Retorna los gonzos ganados o perdidos por el jugador. Ganados positivos, perdidos negativos
    float jugar(int idJuego, long idJugador, float gonzosApostar);

    void verInfoJugador(long idJugador);

    void recargarGonzos(long idJugador);

};

#endif //CASINO_CASINO_H
