// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 2

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    float n;
    int num;
    float contCara = 0.0;
    float contCruz = 0.0;
    float porcCara;
    float porcCruz;

    cout << "Ingresa el número de veces que se lanzará la moneda: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        num = rand()%2; //Se generará números entre 1 y 0
        if (num==1) { //1 es cara
            contCara += 1.0;
        } else { //0 es cruz
            contCruz += 1.0;
        }
    }
    porcCara = (contCara/n) * 100;
    porcCruz = (contCruz/n) * 100;

    cout << "PORCENTAJES DURANTE " << n << " LANZAMIENTOS" << endl;
    cout << "Porcentaje de cara = " << porcCara << "%" << endl;
    cout << "Porcentaje de cruz = " << porcCruz << "%" << endl;
    return 0;
}