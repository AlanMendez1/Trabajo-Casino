#ifndef CASINO_H
#define CASINO_H

#include <unordered_map>
#include "Usuario.h"
#include <vector>
#include "Juego.h"
#include "DosColores.h"
#include "ElMayorDe13.h"
#include "AdivinaAdivinador.h"
class Casino {
private:
    unordered_map<int, Usuario> bbdd;
    DosColores primerJuego;
    ElMayorDe13 segundoJuego;
    AdivinaAdivinador tercerJuego;

public:
    Casino() = default; // Escribe un constructor por defecto
    int usuarioEnBBDD(int);
    Usuario getUsuario(int);
    DosColores getPrimerJuego();
    ElMayorDe13 getSegundoJuego();
    AdivinaAdivinador getTercerJuego();
    void eliminarUsuario(int);
    void addUsuario(int, Usuario);
    void setUsuarioEnBBDDDinero(int, int);
    bool restarUsuarioEnBBDDDinero(int, int);
};

#endif
