// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 14

#include <iostream>

using namespace std;

int main(){
    int N = 0;

    cout << "Ingresa el valor de N: ";
    cin >> N;

    for (int i=1; i<=N; i++){ // Controla las filas
        for (int j=0; j<i; j++){ // Controlar el número de asteriscos por fila
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}