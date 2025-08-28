// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 12

#include <iostream>

using namespace std;

int main(){
    system ("chcp 65001");
    system ("cls");

    short int numero;

    while (numero < 1 || numero > 5) {
        cout << "Ingresa un número del 1 al 5: ";
        cin >> numero;
    }

    cout << "Ingresaste " << numero; // Mostrar que número se ingresó si este es correcto
    return 0;
}