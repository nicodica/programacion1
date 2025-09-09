// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 07/09/2025
// Número de ejercicio: 5

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system ("chcp 65001");
    system ("cls");
    srand(time(NULL));

    float n;
    int num;
    float sum = 0;
    float promedio;
    int mayorValor = 0;
    int menorValor = 1000;

    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    cout << "NÚMEROS GENERADOS" << endl;

    for (int i=0; i<n; i++) {
        num = (rand()%1000) + 1; //Generar un número entre 1 y 1000
        sum += num;
        
        if (mayorValor<num) {
            mayorValor = num;
        }

        if (menorValor>num) {
            menorValor = num;
        }

        cout << num << " - ";
    }

    promedio = sum/n;

    cout << endl;
    cout << "a. Suma de los números: " << sum << endl;
    cout << "b. Promedio de los números: " << promedio << endl;
    cout << "c. Mayor valor generado: " << mayorValor << endl;
    cout << "d. Menor valor generado: " << menorValor << endl;
    return 0;
}