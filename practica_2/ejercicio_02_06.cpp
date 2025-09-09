// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 07/09/2025
// Número de ejercicio: 6

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system ("chcp 65001");
    system ("cls");
    srand(time(NULL));

    int n;
    int num;
    int contDivisores = 0;
    int cantidadPrimos = 0;

    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    cout << "NÚMEROS GENERADOS" << endl;
    for (int i=0; i<n; i++) {
        num = (rand()%10000) + 1;

        contDivisores = 0; //Volvemos el contador a 0 cada iteración
        for (int j=2; j<num; j++) {
            if (num%j==0) {
                contDivisores += 1;
            }
        }
        if (contDivisores == 0) {
            cantidadPrimos += 1;
            cout << num << " es primo." << endl;
        } else {
            cout << num << " NO es primo." << endl;
        }
    }
    cout << endl << "Cantidad de números primos: " << cantidadPrimos;

    return 0;
}