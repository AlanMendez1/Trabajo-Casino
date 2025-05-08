#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Usuario {
private:
    int id, dinero = 0;
    string nombre;
public:
    int getId();
    int getDinero();
    string getNombre();
    void setId(int);
    void setDinero(int);
    void setNombre(string);
    void agregarGonzos(int);
    void sumarGonzos(int);
    bool restarGonzos(int);
};

#endif
