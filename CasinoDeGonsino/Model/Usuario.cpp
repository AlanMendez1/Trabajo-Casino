#include "Usuario.h"

int Usuario::getId() {
    return id;
}

int Usuario::getDinero() {
    return dinero;
}

string Usuario::getNombre() {
    return nombre;
}

void Usuario::setId(int id) {
    this->id = id;
}

void Usuario::setDinero(int dinero) {
    this->dinero = dinero;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::agregarGonzos(int realDinero) {
    this->dinero += realDinero/100;
}
void Usuario::sumarGonzos(int Gonzos){
    this->dinero += Gonzos;
}
bool Usuario::restarGonzos(int Gonzos){
    bool ans = false;
    if(dinero-Gonzos >= 0){
        dinero -= Gonzos;
        ans = true;
    }
    return ans;
}