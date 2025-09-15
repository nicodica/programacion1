// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 7

#include <iostream>

using namespace std;

int MCD (int, int);
int mcm (int, int);

int main() {
    system ("chcp 65001");
    system("cls");

    int num1, num2;
    cout << "Ingrese dos valores" << endl << "Valor 1: ";
    cin >> num1;
    cout << "Valor 2: ";
    cin >> num2;

    cout << "Máximo Común Divisor: " << MCD (num1, num2) << endl;
    cout << "Mínimo Común Múltiplo: " << mcm (num1, num2) << endl;
    return 0;
}

int MCD (int n1, int n2) {
    int residuo = 0;
    do {
        residuo = n1%n2; //se obtiene el residuo
        n1 = n2;         // El divisor es ahora el dividendo (el que se divide)
        n2 = residuo;    // El residuo es ahora el divisor (el que divide)
    } while (residuo!=0);
    return n1;
}

int mcm (int n1, int n2) {
    return (n1*n2)/MCD(n1,n2);
}
