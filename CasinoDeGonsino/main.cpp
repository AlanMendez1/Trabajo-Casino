#include "View/View.h"
#include <iostream>
// Codigo
using namespace std;

int main() {
    View vistaPPAL;
    cout << "Bienvenido al Ca$ino de Gon$ino" << endl;
    int id = 0, opc = 0;
    while (!id){
        id = vistaPPAL.login(id);
    }
    vistaPPAL.menuPpal(id);

    return 0;
}
