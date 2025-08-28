// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 16

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero;
    int nDivisores = 0;

    cout << "Ingresa un número: ";
    cin >> numero;

    for (int i=1; i<=numero; i++){
        if (numero % i == 0){
            nDivisores += 1; // Cuenta los divisores del número
        }
    }

    if (nDivisores == 2){
        cout << "El número " << numero << " es primo.";
    } else {
        cout << "El número " << numero << " no es primo.";
    }

    return 0;
}