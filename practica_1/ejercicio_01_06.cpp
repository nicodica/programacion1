// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 6

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");
    int numero = 0;

    cout << "Ingresa un número entero: ";
    cin >> numero;

    if (numero > 0){
        cout << "El número " << numero << " es positivo.";
    } else {
        if (numero < 0){ // IF anidado para determinar si el número es negativo o cero
            cout << "El número " << numero << " es negativo.";
        } else {
            cout << "El número " << numero << " es cero";
        }
    }
    
    return 0;
}