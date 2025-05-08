#include "DosColores.h"

void DosColores::mostrarReglas(){
    string ans = "1. El usuario tira el dado y escoge entre 2 colores Blanco o Negro.\n"
                 "2. Si coincide con el valor del dado y el color aleatorio del casino gana de lo contrario pierde.\n"
                 "3. Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado. \n"
                 "4. Si coincide sólo con el valor del dado ganará 0.5 veces lo apostado.\n"
                 "5. Si coincide sólo con el color elegido no gana ni pierde nada.\n"
                 "6. Si no coincide en nada, pierde todo el dinero apostado.\n";
    cout << ans << endl;
}
int DosColores::jugar(int n , string c){
    int ans;
    mt19937 generador(random_device{}());
    int n1= generador() % 6;
    int n2= generador() % 2;
    if(n == dado[n1] && c == color[n2]){
        ans = 4;
    }else if(n == dado[n1]){
        ans = 0.5;
    }else if(c == color[n2]){
        ans = 1;
    }else{
        ans = 0;
    }
    return ans;
}
