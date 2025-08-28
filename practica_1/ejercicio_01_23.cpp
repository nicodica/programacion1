// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 23

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numInicial;
    int numReves = 0;

    cout << "Ingresa un númeor para voltear: ";
    cin >> numInicial;
    int numAux = numInicial; // Dos variables para el mismo número

    while (numInicial>0){
        numReves += (numInicial%10);
        numReves *= 10;
        numInicial /= 10; // Se va bajando el valor del numero dígito a dígito
    }

    numReves /= 10; //Bajarle un cero al número
    cout << numAux << " --> " << numReves;
    return 0;
}