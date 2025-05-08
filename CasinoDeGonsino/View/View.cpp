#include "View.h"

void View::menuPpal(int id) {
    int opc, flag = 1;
    while(opc != 3 && flag){
        cout << "[1] Jugar" << endl << "[2] Otras opciones" << endl << "[3] Exit" << endl;
        cin >> opc;
        if(opc== 1){
            jugarView(id);
        }else if(opc == 2) {
            verPrincipal(id);
        }
        else if (opc == 3) {cout << "Saliendo del Casino" << endl; flag = 0;}
    }
}

int View::login(int id2return) {
    int id, dinero = 0;
    string nombre;
    cout << "[1] Registrarme" << endl;
    cout << "[2] Acceder" << endl;
    int ans;
    cin >> ans;
    if (ans == 1) {
        cout << "Digite su cedula" << endl;
        cin >> id;
        if (casino.usuarioEnBBDD(id)) {
            cout << "Este usuario ya se encuentra registrado." << endl;
            cout << "Te recomendamos Acceder." << endl;
            id2return = 0;
        }
        else {
            Usuario* user = new Usuario();
            try {
                cout << "Digite su nombre" << endl;
                cin >> nombre;
            }
            catch (domain_error &ex){
                cout << "Esperaba un dato string" << endl;
            }
            user->setNombre(nombre);
            user->setId(id);
            cout << "Cuanto dinero (en pesos) quiere agregar" << endl;
            while (dinero <= 0){
                cin >> dinero;
                if (dinero > 0) {
                    user->agregarGonzos(dinero);
                    casino.addUsuario(id, *user);
                    cout << "Quedaste con $" << casino.getUsuario(id).getDinero() << " gonzos!" << endl;
                }
                else cout << "Monto no valido. Intenta de nuevo" << endl;
            }
            cout << "Usuario creado correctamente" << endl;
            id2return = id;
        }
    }
    else if (ans == 2) {
        int id2;
        cout << "Digite su cedula" << endl;
        cin >> id2;
        if (casino.usuarioEnBBDD(id2)) {
            Usuario user = casino.getUsuario(id2);
            cout << "Bienvenido " << user.getNombre() << " Tienes $" << user.getDinero() << endl;
            if (user.getDinero() <= 0) {
                cout << "Tienes que recargar dinero para seguir jugando." << endl;
                cout << "Cuanto quieres recargar?" << endl;
                int tmp = 0;
                while (tmp <= 0) {
                    cin >> tmp;
                    if (tmp > 0) {
                        casino.getUsuario(id2).agregarGonzos(tmp);
                        cout << "Quedaste con $" << casino.getUsuario(id).getDinero() << " gonzos!" << endl;
                    }
                    else cout << "Monto no valido. Intenta de nuevo" << endl;
                }
            }
            id2return = id2;
        }
        else {
            cout << "Usuario No encontrado" << endl;
            cout << "Te recomendamos registrarte" << endl;
        }

    }
    return id2return;
}

void View::jugarView(int id) {
    int opc, n , soldi , ganancia , gano;
    string c;
    bool flag = false;
    cout << "Bienvenido a la zona de juegos" << endl;
    cout << "Que juego deseas jugar?" << endl << "[1] El Mayor Que 13" << endl << "[2] Dos Colores " << endl << "[3] Adivina Adivinador" << endl << "[4] Atras" << endl;
    cin >> opc;
    if(opc == 1){
        casino.getPrimerJuego().mostrarReglas();
        while(!flag){
            cout << "Cuanto dinero vas apostar?" << endl;
            cin >> soldi;
            flag = casino.restarUsuarioEnBBDDDinero(id, soldi);
//            flag = casino.getUsuario(id).restarGonzos(soldi);
            if(flag == false){
                cout << "No te alcanzan los gonzos" << endl;
            }
        }
        cout << "desea seguir o retirarse:" << endl;
        cin >> c;
        cout << "Elija un numero del 0 al 13: " << endl;
        cin >> n;
        ganancia = casino.getPrimerJuego().jugar(n,c);
        gano = ganancia * soldi;
        cout << "haz apostado : "  << soldi << " y ganaste: "<< gano <<endl;
    }else if(opc == 2){
        casino.getSegundoJuego().mostrarReglas();
        while(!flag){
            cout << "Cuanto dinero vas apostar?" << endl;
            cin >> soldi;
            flag = casino.restarUsuarioEnBBDDDinero(id, soldi);
            if(!flag){
                cout << "No te alcanzan los gonzos" << endl;
            }
        }
        cout << "Elija un color NEGRO o BLANCO: " << endl;
        cin >> c;
        cout << "Tirando Dado... " << endl;
        mt19937 generador(random_device{}());
        n= generador() % 6;
        ganancia =casino.getSegundoJuego().jugar(n,c);
        gano = ganancia * soldi;
        cout << "haz apostado : "  << soldi << " Y ganaste: "<< gano <<endl;
    }
    else if (opc == 3) {
        casino.getTercerJuego().mostrarReglas();
        if (casino.getUsuario(id).getDinero() <= 0) cout << "Necesitas al menos $20 Gonzos para jugar" << endl;
        else {
            int resultado = casino.getTercerJuego().jugar(0, "c");
            cout << "...................................... " << resultado;
            if (resultado) casino.restarUsuarioEnBBDDDinero(id, -10);
            else if (!resultado) casino.restarUsuarioEnBBDDDinero(id, 20);
        }
    }
    else if (opc == 4) menuPpal(id);
    else{
        cout << "juego invalido" << endl;
    }
}
void View::verPrincipal(int id){
    int opc;
    bool flag = true;
    while(flag){
        cout << "[1] Convertir pesos a Gonzos" << endl << "[2] Consultar Usuario" << endl << "[3] Recargar Gonzos" << endl << "[4] Retirar Usuario" << endl << "[5] Atras" << endl;
        cin >> opc;
        if(opc==1){
            cout << "Convertidor COP a Gonzos" << endl << "Ingrese la cantidad de COP: ";
            cout << "Recuerde que aqui no recarga. Solo convierte de COP a GONZOS" << endl;
            int n;
            cin >> n;
            n= n/100;
            cout << "Es equivalente a $" << n <<" Gonzos."<< endl;
        }else if(opc==2){
            int tmp;
            cout << "Digite la cedula del usuario a consultar" << endl;
            cin >> tmp;
            cout << "Id: " << casino.getUsuario(tmp).getId() << endl;
            cout << "Nombre: " << casino.getUsuario(tmp).getNombre() << endl;
            cout << "Dinero: " << casino.getUsuario(tmp).getDinero() << endl;

        }else if(opc==3){
            int dinero = 0;
            cout << "Ingrese la cantidad a recargar de COP a GONZOS: " << endl;
            while (dinero <= 0){
                cin >> dinero;
                if (dinero > 0) {
                    casino.setUsuarioEnBBDDDinero(id, dinero);
                    cout << "Quedaste con $" << casino.getUsuario(id).getDinero() << " gonzos!" << endl;
                }
                else cout << "Monto no valido. Intenta de nuevo" << endl;
            }
        }else if(opc ==4){
            cout << "Digite la cedula del usuario a eliminar" << endl;
            int tmp2;
            cin >> tmp2;
            cout << "Eliminara a " << casino.getUsuario(tmp2).getNombre() << endl;
            cout << "Tiene $" << casino.getUsuario(tmp2).getId() << "Gonzos" << endl;
            cout << "Presione" << endl << "[1] Para confirmar" << endl << "[2] Para cancelar" << endl;
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                casino.eliminarUsuario(tmp2);
                cout << "Eliminado correctamente" << endl;
            }
            else if (tmp == 2) {
                cout << "Eliminacion Cancelada" << endl;
            }
        }
        else if (opc == 5) menuPpal(id);
    }

}

