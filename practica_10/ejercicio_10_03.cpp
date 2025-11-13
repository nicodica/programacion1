// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/11/2025 
// Número de ejercicio: 3

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct datosEstudiante {
    char nombre [20];
    int edad;
    float promedio;
};

datosEstudiante ingresarDatos();
void exportarDatos (vector<datosEstudiante> students);

int main() {
    system("chcp 65001");
    system("cls");

    int opcion;
    vector<datosEstudiante> estudiantes;

    do {
        system("cls");
        cout << "== LISTA DE ESTUDIANTES ==" << endl;
        cout << "\t1. Registrar estudiante" << endl;
        cout << "\t2. Exportar lista (Salir)" << endl;
        cout << "--> ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            estudiantes.push_back(ingresarDatos());
        } else if (opcion == 2) {
            exportarDatos(estudiantes);
            cout << "Datos exportados :3";
        } else {
            cout << "Opción no existente";
            continue;
        }
        
    } while (opcion !=2);

    return 0;
}

datosEstudiante ingresarDatos() {
    datosEstudiante student;
    cout << "Nombre: ";
    cin.getline(student.nombre, 20);
    cout << "Edad: ";
    cin >> student.edad;
    cout << "Promedio: ";
    cin >> student.promedio;
    cin.ignore();

    return student;
}

void exportarDatos (vector<datosEstudiante> students) {
    ofstream archivo;
    archivo.open("estudiantes.txt");
    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo";
        return;
    } else {
        for (int i=0; i<students.size(); i++) {
            archivo << "Nombre: " << students[i].nombre << "\n";
            archivo << "Edad: " << students[i].edad << "\n";
            archivo << "Promedio: " << students[i].promedio << "\n";
            archivo << "\n";
        }
    }
    archivo.close();
}