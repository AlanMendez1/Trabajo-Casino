#include "Casino.h"

int Casino::usuarioEnBBDD(int id) {
    int ans = 0;
    unordered_map<int, Usuario>::iterator it = bbdd.find(id);
    if (it != bbdd.end()) {
        ans = 1;
    } 
    return ans;
}

Usuario Casino::getUsuario(int id) {
    return bbdd[id];
}
DosColores  Casino::getPrimerJuego(){
    return primerJuego;
}
ElMayorDe13  Casino::getSegundoJuego(){
    return segundoJuego;
}

AdivinaAdivinador Casino::getTercerJuego() {
    return tercerJuego;
}

void  Casino:: eliminarUsuario(int id){
    bbdd.erase(id);
}

void Casino::addUsuario(int id, Usuario user){
    pair<int, Usuario> newUser(id, user);
    bbdd.insert(newUser);
}

void Casino::setUsuarioEnBBDDDinero(int id, int dinero) {
    bbdd[id].agregarGonzos(dinero);
}

bool Casino::restarUsuarioEnBBDDDinero(int id, int dinero) {
    bool flag = false;
    flag = bbdd[id].restarGonzos(dinero);
    return flag;
}