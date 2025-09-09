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
    int edad;
    int ninos1 = 0; //Consumen 6 pañales
    int ninos2 = 0; //Consumen 3 pañales
    int ninos3 = 0; //Consumen 2 pañales
    int nPanales;

    cout << "Ingrese la cantidad de niños: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        edad = (rand()%3) + 1;
        if (edad==1) {
            ninos1 += 1;
        } else if (edad==2) {
            ninos2 += 1;
        } else {
            ninos3 += 1;
        }
    }
    nPanales = (ninos1*6) + (ninos2*3) + (ninos3*2);

    cout << "Niños de 1 año: " << ninos1 << " --> " << (ninos1*6) << " pañales." << endl;
    cout << "Niños de 2 año: " << ninos2 << " --> " << (ninos2*3) << " pañales." << endl;
    cout << "Niños de 3 año: " << ninos3 << " --> " << (ninos3*2) << " pañales." << endl;
    cout << n << " niños consumen " << nPanales << " pañales al día.";

    return 0;
}