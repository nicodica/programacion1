// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>

using namespace std;

struct Empleado {
    char nombre[30];
    char genero[30];
    float salario;
};

Empleado ingresarEmpleado();
int encontrarMayorSalario (vector<Empleado> empleados);
int encontrarMenorSalario (vector<Empleado> empleados);

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<Empleado> ListaEmpleados;
    int mayorSalarioIndice;
    int menorSalarioIndice;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++) {
        cout << "EMPLEADO " << i+1 << endl;
        ListaEmpleados.push_back(ingresarEmpleado());
        cout << endl;
    }

    mayorSalarioIndice = encontrarMayorSalario(ListaEmpleados);
    menorSalarioIndice = encontrarMenorSalario(ListaEmpleados);

    cout << "EMPLEADO CON MENOR SALARIO" << endl;
    cout << ListaEmpleados[menorSalarioIndice].nombre << ", " << ListaEmpleados[menorSalarioIndice].genero << ", gana " << ListaEmpleados[menorSalarioIndice].salario << endl;

    cout << "EMPLADO CON MAYOR SALARIO" << endl;
    cout << ListaEmpleados[mayorSalarioIndice].nombre << ", " << ListaEmpleados[mayorSalarioIndice].genero << ", gana " << ListaEmpleados[mayorSalarioIndice].salario << endl;


    return 0;
}

Empleado ingresarEmpleado() {
    Empleado employee;
    cout << "Nombre: ";
    cin.getline(employee.nombre,30);
    cout << "Género: ";
    cin.getline(employee.genero, 30);
    cout << "Salario: ";
    cin >> employee.salario;
    cin.ignore();

    return employee;
}

int encontrarMayorSalario (vector<Empleado> empleados) {
    float mayorSalario = empleados[0].salario;
    int indiceMayor = 0;

    for (int i=0; i<empleados.size(); i++) {
        if (mayorSalario<empleados[i].salario) {
            mayorSalario = empleados[i].salario;
            indiceMayor = i;
        }
    }
    return indiceMayor;
}

int encontrarMenorSalario (vector<Empleado> empleados) {
    float menorSalario = empleados[0].salario;
    int indiceMenor = 0;

    for (int i=0; i<empleados.size(); i++) {
        if (menorSalario>empleados[i].salario) {
            menorSalario = empleados[i].salario;
            indiceMenor = i;
        }
    }
    return indiceMenor;
}