// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/09/2025 
// Número de ejercicio: 11

#include <iostream>

using namespace std;
double retirarDinero(double saldo, int cantidad);

int main() {
    system ("chcp 65001");
    system("cls");
    double saldo;
    int retiro;
    double saldoActualizado;

    cout << "Ingrese su saldo: ";
    cin >> saldo;

    cout << "Ingrese la cantidad de dinero que desea retirar: ";
    cin >> retiro;

    saldoActualizado = retirarDinero(saldo,retiro);

    if (saldoActualizado==0.0) {
        cout << "Retiro NO realizado.";
    } else {
        cout << "Retiro exitoso." << endl << "Saldo actual: " << saldoActualizado << "Bs.";
    }
    return 0;
}

double retirarDinero (double saldo, int cantidad) {
    if (saldo<cantidad) { 
        cout << "Saldo insuficiente." << endl;
        return 0.0; //corta la función y devuelve 0
    } else if (cantidad%10!=0) {
        cout << "Cantidad no válida para retiro." << endl;
        return 0.0;
    } else {
        saldo -= cantidad;
        return saldo;
    }
}