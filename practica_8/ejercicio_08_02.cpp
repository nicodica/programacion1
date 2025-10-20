// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/10/2025
// Número de ejercicio: 2

#include <iostream>

using namespace std;

int potenciaRecursiva (int a, int n);

int main() {
    system("chcp 65001");
    system("cls");

    int base;
    int exp;
    int potencia;
    cout << "Ingresa la base: ";
    cin >> base;
    cout << "Ingresa el exponente: ";
    cin >> exp;

    potencia = potenciaRecursiva(base, exp);
    cout << base << "^("<<exp<<") = " << potencia;

    return 0;
}

int potenciaRecursiva (int a, int n) { // a=base, n=exponente
    if (n==1) {
        return a;
    } else {
        return a * potenciaRecursiva(a, (n-1));
    }
}