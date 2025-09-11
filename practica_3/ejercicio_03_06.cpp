// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 6

#include <iostream>

using namespace std;

int diaEnMes (int anio, int mes);

int main() {
    system("chcp 65001");
    system("cls");

    int anio;
    int nMes;

    cout << "Ingresa el año: ";
    cin >> anio;
    cout << "Ingresa el número del mes (ej.febrero=2): ";
    cin >> nMes;

    cout << "El mes " << nMes << " del año " << anio << " tiene " << diaEnMes(anio,nMes) << " días.";
    return 0;
}

int diaEnMes (int anio, int mes) {
    int diasMes;
    if (mes== 1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
        diasMes = 31;
    } else {
        diasMes = 30;
    }
    if ((anio%4 == 0 && anio%100!=0) || (anio%400==0)) { //Verificar si es año bisiesto
        diasMes = 29;
    }
    return diasMes;
}