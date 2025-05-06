//
// Created by lufe0 on 7/05/2021.
// Modificada el 30 de 30/03/2022
//

#include "View.h"

void View::agregarJugador() {
    // Esta linea de codigo controla la excepcion que lanza el casino y lo muestra en pantalla
    try {
        casino.agregarJugador();
    } catch (std::invalid_argument &ex) {
        // Controla la aparecion de errores.
        // what es el metodo que muestra el mensaje de error de las excepciones
        cout << "ERROR con parámetros: " << ex.what();
    } catch (std::exception &ex) {
        cout << "ERROR contactate al adminstrador " << ex.what();
    }

}

void View::jugarView() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;

        float cantGonzos;
        cout << "Cuantos gonzos desea apostar \n";
        cin >> cantGonzos;

        // Hace toda la logica de jugar.
        int idJuego;
        float gonzosResultado;

        cout << "Elija el juego: " << endl;
        cout << "1. Mayor a 13." << endl;
        cout << "2. Dos colores." << endl;
        cout << "3. Slots" << endl;
        cout << "Opcion: ";
        cin >> idJuego;
        std::string textoResultado;
        gonzosResultado = casino.jugar(idJuego, idJugador, cantGonzos);
        if (gonzosResultado > 0) {
            textoResultado = "Haz ganado!: ";
        } else {
            textoResultado = "Haz perdido :(!: ";
        }
        cout << textoResultado << gonzosResultado << " Gonzos" << endl;

    } catch (std::domain_error &ex) {
        // Se muestran los mensajes de excepcion obtenidos
        cout << ex.what();
    }
}

int View::mostrarMenu() {
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador  " << std::endl;
    cout << "4. Recargar gonzos " << std::endl;
    cout << "5. Retirar jugador casino " << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal() {
    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                agregarJugador();
                break;
            case 2:
                jugarView();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                recargarGonzos();
                break;
            case 5:
                retirarJugador();
                break;
            case 0:
                cout << "Hasta pronto !";
                break;
            default:
                cout << "No hay ninguna opcion para ese numero";
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
    } catch (std::domain_error &ex) {
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::retirarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
        casino.retirarJugador(idJugador);
        cout << "Jugador retirado con exito." << std::endl;
    } catch (std::domain_error &ex) {
        // Se muestra un error si el usuario no existe
        std::cout << ex.what();
    }
}

void View::recargarGonzos() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.recargarGonzos(idJugador);
        cout << "Recarga realizada con exito." << std::endl;
    } catch (std::domain_error &ex) {
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}