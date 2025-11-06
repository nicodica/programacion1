// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>

using namespace std;

struct Empleado {
    char nombre[30];
    int id;
    float sueldo;
    int antiguedad;
};

Empleado ingresarEmpleado();
int NEmpleadosConMayorSueldo (vector<Empleado> employees, float sueldoValor);
float promedioAntiguedad(vector<Empleado> employees);

int main() {
    system("chcp 65001");
    system("cls");
    int N;
    vector<Empleado> ListaEmpleados;
    int cantidadEmpladosMayorSueldo;
    float SueldoValor;
    float promAntiguedad;

    cout << "Ingresa el número de empleados: ";
    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++) {
        cout << "EMPLEADO " << i+1;
        ListaEmpleados.push_back(ingresarEmpleado());
    }

    cout << "Ingrese un sueldo: ";
    cin >> SueldoValor;
    cantidadEmpladosMayorSueldo = NEmpleadosConMayorSueldo(ListaEmpleados, SueldoValor);
    cout << "Hay " << cantidadEmpladosMayorSueldo << " empleados con un sueldo mayor.";

    promAntiguedad = promedioAntiguedad(ListaEmpleados);
       cout << "Promedio de Antigüedades: " << promAntiguedad << endl; 

    

    return 0;
}

Empleado ingresarEmpleado() {
    Empleado employee;
    cout << "Nombre";
    cin.getline(employee.nombre, 30);
    cout << "ID: ";
    cin >> employee.id;
    cout << "Sueldo: ";
    cin >> employee.sueldo;
    cout << "Antigüedad: ";
    cin >> employee.antiguedad;
    cin.ignore();

    return employee;
}

int NEmpleadosConMayorSueldo (vector<Empleado> employees, float sueldoValor) {
    int sum=0;
    for (int i=0; i<employees.size(); i++) {
        if (employees[i].sueldo> sueldoValor) {
            sum++;
        }
    }
    return sum;
}

float promedioAntiguedad(vector<Empleado> employees) {
    float sumaAntiguedad =0;
    for (int i=0; i<employees.size(); i++) {
        sumaAntiguedad += employees[i].antiguedad;
    }
    return sumaAntiguedad/employees.size();
}