// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 8

// Número par o impar
#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero = 0;

    cout << "Ingresa un número entero: ";
    cin >> numero;

    if (numero%2 != 0){
        cout << "El número " << numero << " es impar.";
    } else {
        if (numero != 0){ // Discriminar el cero
            cout << "El número " << numero << " es par.";
        } else {
            cout << "El número es cero.";
        }
    }
    return 0;
}
