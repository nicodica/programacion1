// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 5

#include <iostream>

using namespace std;

void sueldoDeTrabajo(float, float, float, float&, float&);

int main () {
    system("chcp 65001");
    system("cls");

    //Valores que se introducen por teclado
    float horasTrabajadas;
    float tarifaPorHora;
    float bonoPorExtra;
    //Valores que se devolverán
    float salario = 0;
    float salarioBono = 0;

    cout << "Ingresa los siguientes valores" << endl;
    cout << "Horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Tarifa por hora: ";
    cin >> tarifaPorHora;
    cout << "Bonificación por horas extra: ";
    cin >> bonoPorExtra;

    sueldoDeTrabajo (horasTrabajadas, tarifaPorHora, bonoPorExtra, salario, salarioBono);
    cout << endl; //Impresión de un espacio para mayor legibilidad
    if (salarioBono>0) {
        cout << "Salario: " << salario << " Bs." << endl;
        cout << "Salario bonificación: " << salarioBono << " Bs."<< endl;
    } else {
        cout << "Salario: " << salario << " Bs." << endl;
        cout << "No hay bonificación.";
    }

    return 0;
}

void sueldoDeTrabajo(float horasTrabajadas, float tarifaPorHora, float bonificacion, float& salario, float& salarioBono) {
    float horasExtra = 0;

    if (horasTrabajadas>8) {
        horasExtra = horasTrabajadas - 8.0;
        salario = 8.0 * tarifaPorHora;
        salarioBono = horasExtra * bonificacion;
    } else {
        salario = horasTrabajadas*tarifaPorHora;
    }
}