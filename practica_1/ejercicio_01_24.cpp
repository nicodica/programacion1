// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 24

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int opcion;

    do {
        cout << "--MENU DE OPCIONES--" << endl << "1. Opcion 1" << endl << "2. Opción 2" << endl << "3. Opción 3" << endl << "0. Salir" << endl;
        cout << "--> ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Elegiste la Opción 1. ^-^" << endl;
        } else if (opcion == 2) {
            cout << "Elegiste la Opción 2. 6.6" << endl;
        } else if (opcion == 3) {
            cout << "Elegiste la Opción 3. :3" << endl;
        } else {
            if (opcion != 0){
            cout << "Opción no existente. u_u" << endl;
            }
        }
    } while(opcion!=0);

    if (opcion == 0) { //Mensaje para guiar al usuario
        cout << "Saliendo del menú...";
    }
    return 0;
}