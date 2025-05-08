#include "AdivinaAdivinador.h"

void AdivinaAdivinador::mostrarReglas(){
    string ans = "1. La maquina va a pensar en un numero del 1 al 3.\n"
                 "2. Ingresaras un numero.\n"
                 "3. Si ese numero es el que la maquina penso. Ganas. \n"
                 "4. De lo contrario, pierdes.\n"
                 "5. La recompensa es de 10 Gonzos por adivinar el numero\n"
                 "6. Perderas 20 Gonzos si no lo adivinas.\n";
    cout << ans << endl;
}
int AdivinaAdivinador::jugar(int n , string c){
    int gano = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);

    int numeroAleatorio = dist(gen);

    int adivina;
    cout << "Digite el numero que cree que la maquina esta pensando" << endl;
    cin >> adivina;
    if (adivina == numeroAleatorio) {
        gano = 1;
        cout << "Que buena suerte!. Ganaste $10 Gonzos!";
    }
    else {
        cout << "Que mala suerte!. El numero que la maquina pensaba era " << numeroAleatorio << endl;
        cout << "Perdiste $20 Gonzos" << endl;
    }

    return gano;
}
