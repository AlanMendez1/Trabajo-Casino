#include "ElMayorDe13.h"
int ElMayorDe13::jugar(int n , string c){
    int ans;
    mt19937 generador(random_device{}());
    int number= generador() % 14;
    if(c == "seguir"){
        if(n <= number){
            ans = 0;
        }else{
            ans = 2;
        }
    }else{
        ans = 0.5;
    }
    return ans;
}
void ElMayorDe13::mostrarReglas(){
    string ans = "1. El sistema genera un número aleatorio entre 1 y 13.\n "
                 "2. El usuario tiene 2 opciones para continuar \n"
                 "la primera: darse por perdido antes de que se genere el número en este caso perderá la mitad del dinero apostado.\n"
                 "La segunda: jugar, es decir, que se genere el número aleatorio.\n"
                 "3.Si saca un número menor o igual que el casino, perderá todo lo apostado.\n"
                 "4.Si saca un numero mayor que el casino ganará el doble de lo apostado.\n";
    cout << ans << endl;
}