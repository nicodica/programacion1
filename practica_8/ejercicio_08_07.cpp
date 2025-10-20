// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <cmath>

using namespace std;

int sumaQRecursiva (int n);

int main() {
    system("chcp 65001");
    system("cls");

    int sumaQ;
    int n;
    cout << "RESOLVIENDO . . . Q(n) = 1²+2²+3²...+n²" << endl;
    cout << "Ingrese n: ";
    cin >> n;

    sumaQ = sumaQRecursiva(n);
    cout << "Q = " << sumaQ;

    return 0;
}

int sumaQRecursiva (int n) {
    if (n==1) {
        return 1;
    } else {
        return pow(n,2) + sumaQRecursiva(n-1); //Ir disminuyendo la base hasta 1
    }
}