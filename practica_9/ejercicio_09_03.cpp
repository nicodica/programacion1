// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 4/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>

using namespace std;

struct Alumno {
    int cedula;
    char nombre[30];
    char apellido[30];
    int edad;
    char profesion[30];
    char lugar_nacimiento[30];
    char direccion[30];
    int telefono;
};

Alumno ingresarAlumno();
void mostrarVector(vector<Alumno>);

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<Alumno> listaAlumnos;

    cout << "LISTA DE ALUMNOS" << endl;
    cout << "Ingresa el número de alumnos: ";
    cin >> N;

    for (int i=0; i<N; i++) {
        cout << "ALUMNO " << i+1 << endl;
        listaAlumnos.push_back(ingresarAlumno());
        cout << endl;
    }

    mostrarVector(listaAlumnos);


    return 0;
}

Alumno ingresarAlumno() {
    Alumno alumnoIndividuo;
    cout << "Cédula: ";
    cin >> alumnoIndividuo.cedula;
    cin.ignore(); // Limpiar el buffer
    cout << "Nombre: ";
    cin.getline(alumnoIndividuo.nombre,30);
    cout << "Apellido: ";
    cin.getline(alumnoIndividuo.apellido, 30);
    cout << "Edad: ";
    cin >> alumnoIndividuo.edad;
    cin.ignore();
    cout << "Profesión: ";
    cin.getline(alumnoIndividuo.profesion, 30);
    cout << "Lugar de Nacimiento: ";
    cin.getline(alumnoIndividuo.lugar_nacimiento, 30);
    cout << "Dirección: ";
    cin.getline(alumnoIndividuo.direccion, 30);
    cout << "Teléfono: ";
    cin >> alumnoIndividuo.telefono;
    cin.ignore();

    return alumnoIndividuo;
}

void mostrarVector(vector<Alumno> alumnos) {
    cout << "== ALUMNOS PROGRAMACIÓN I ==" << endl;
    for (int i=0; i<alumnos.size(); i++) {
        cout << alumnos[i].nombre << " " << alumnos[i].apellido << endl;
        cout << "Edad: " << alumnos[i].edad << " años" << endl;
        cout << "Profesión: " << alumnos[i].profesion << endl;
        cout << "Lugar de Nacimiento: " << alumnos[i].lugar_nacimiento << endl;
        cout << "Dirección: " << alumnos[i].direccion << endl;
        cout << "Teléfono: " << alumnos[i].telefono << endl;
        cout << endl;
    }
}