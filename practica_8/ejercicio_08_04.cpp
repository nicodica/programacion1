// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

int MCD_recursiva(int n1, int n2);

int main() {
    system("chcp 65001");
    system("cls");

    int num1;
    int num2;
    int MCD;
    cout <<"MÁXIMO COMÚN DIVISOR" << endl << "Ingresa el primer número: ";
    cin >> num1;
    cout << "Ingresa el segundo número: ";
    cin >> num2;

    MCD = MCD_recursiva(num1, num2);
    cout << "El MCD es: " << MCD;

    return 0;
}

int MCD_recursiva(int n1, int n2) {
    // Cambiar el orden si el primero no es el mayor
    int aux;
    if (n1<n2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    if (n2 == 0) {
        return n1;
    } else {
        return MCD_recursiva(n2,(n1%n2));
    }
}