// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 4

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int num = rand()%51;
    int intentoUsuario = -1; //Variable para identificar lo que el ususario ingrese
    int intentos = 1;
    bool siAdivino = false; //Variable para salir del while

    int minimo = 0, maximo = 50;
    
    cout << "!!ADIVINA UN NÚMERO ENTRE 0 Y 50!!" << endl;
    while (intentos<=5 && siAdivino==false) {
        cout << endl;
        cout << intentos << "° intento." << endl;
        cout << "Estoy pensando en un número del " << minimo << " al " << maximo << endl << ">...";
        cin >> intentoUsuario;

        if (intentoUsuario<num) {
            minimo = intentoUsuario;
            cout << "Número incorrecto x_x" << endl;
        } else if (intentoUsuario>num) {
            maximo = intentoUsuario;
            cout << "Número incorrecto x_x" << endl;
        }

        if (num==intentoUsuario) {
            siAdivino = true;
        }
        intentos += 1;
    }

    if (siAdivino==true) {
        cout << endl;
        cout << "Felicidades. Adivinaste el número ";
        cout << num;
    } else {
        cout << endl;
        cout <<"Intentos agotados :(" << endl;
        cout << "El número era " << num;
    }
    return 0;
}