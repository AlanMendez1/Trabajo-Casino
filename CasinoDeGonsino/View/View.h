#ifndef CASINO_VIEW_H
#define CASINO_VIEW_H

#include "../Model/Casino.h"

class View {
private:
    // Objeto de que se enlaza con la vista del casino
    Casino casino;

public:
    View() = default; // Escribe un constructor por defecto
    int login(int);
    void jugarView(int);
    void verPrincipal(int);
    void menuPpal(int);
};

#endif
