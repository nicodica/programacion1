// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// estructuras
struct structEstudiante {
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct structNotas {
    char ci[10];
    char materia[30];
    int nota;
};

// Funciones
void menu();
bool validarEstudiante(char[]);
bool validarMateria(char[], char[]);
void anadirEstudiante();
structNotas ingresarNota();
void anadirNota();
void reporte();

// variables globales
string nombreArchivoEstudiantes = "Estudiantes.bin";
string nombreArchivoNotas = "NotasEstudiantes.bin";


int main() {
    system("chcp 65001");
    system("cls");

    menu();

    return 0;
}

void menu() {
    int opcion;

    do {
        system("cls");
        cout << "=== MENÚ DE OPCIONES ===" << endl;
        cout << "\t1. Ingresar datos de un estudiante" << endl;
        cout << "\t2. Ingresar las materias y notas" << endl;
        cout << "\t3. Reporte de estudiantes y notas" << endl;
        cout << "\t0. Salir" << endl << "--> ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            anadirEstudiante();
        } else if (opcion == 2) {
            anadirNota();
        } else if (opcion == 3) {
            reporte();
        } else if (opcion == 0) {
            cout << "Adios xnx";
        } else {
            cout << "Opción inválida";
        }
    } while (opcion != 0);
}

// funcion para ver si el estudiante existe en el archivo
bool validarEstudiante (char ciBuscado[]) {  // se buscará por ci
    ifstream archivoEstudiantes;
    structEstudiante student;
    bool encontrado = false;

    archivoEstudiantes.open(nombreArchivoEstudiantes, ios::binary);
    if (archivoEstudiantes.good()) {
        while (archivoEstudiantes.read((char*)(&student), sizeof(structEstudiante)) && encontrado==false) {
            if (strcmp(ciBuscado, student.ci) == 0) {
                encontrado = true;
            }
        }
        archivoEstudiantes.close();
        if (encontrado==false) {
            return false;
        } else {
            return true;
        }
    } else {
            cout << "No se pudo abrir el archivo de estudiantes\n";
    }
}

bool validarMateria (char materiaBuscada[], char ciStudent[]) {
    ifstream archivoNotas;
    structNotas note;
    bool encontrado = false;

    archivoNotas.open(nombreArchivoNotas, ios::binary);
    if (archivoNotas.good()) {
        while (archivoNotas.read((char*)(&note), sizeof(structNotas)) && encontrado==false) {
            if (strcmp(materiaBuscada,note.materia) == 0 && strcmp(ciStudent, note.ci)==0) {
                encontrado = true;
            }
        }
        archivoNotas.close();
        if (encontrado==false) {
            return false;
        } else {
            return true;
        }
    } else {
            cout << "No se pudo abrir el archivo de notas\n";
    }
}

void anadirEstudiante() {
    ofstream archivoEstudiantes;
    structEstudiante student;
    char ciParaValidar[10];
    bool ciValido = true;

    //validar estudiante primero
    while (ciValido) {
        cout << "CI: ";
        cin.getline(ciParaValidar, 10);
        ciValido = validarEstudiante(ciParaValidar);
        if (ciValido) {
            cout << "El estudiante ya existe.\n";
        }
    }

    archivoEstudiantes.open(nombreArchivoEstudiantes, ios::binary | ios::app);
    if (archivoEstudiantes.good()) {
        strcpy(student.ci, ciParaValidar);
        cout << "Nombre: ";
        cin.getline(student.nombres, 30);
        cout << "Apellido: ";
        cin.getline(student.apellidos, 30);
        archivoEstudiantes.write((char*)(&student), sizeof(structEstudiante));
        archivoEstudiantes.close();
        cout << "Estudiante añadido (^^)\n";
        system("pause");
    } else {
        cout << "Error al añadir estudiante\n";
    }
}

structNotas ingresarNota() {
    ofstream archivoNotas;
    structNotas note;
    char materiaParaValidar[10];
    char ciParaValidar[10];
    bool ciValido = false;
    bool materiaValida = true;
    
    while (ciValido==false) {
        cout << "CI: ";
        cin.getline(ciParaValidar, 10);
        ciValido = validarEstudiante(ciParaValidar);
        if (ciValido==false) {
            cout << "El estudiante no existe, vuelva a intentarlo.\n";
        }
    }

    while (materiaValida == true) {
        cout << "Materia: ";
        cin.getline(materiaParaValidar, 30);
        materiaValida = validarMateria(materiaParaValidar, ciParaValidar);
        if (materiaValida==true) {
            cout << "Materia ya existente. vuelva a intentarlo.\n";
        }
    }

    strcpy(note.ci, ciParaValidar);
    strcpy(note.materia, materiaParaValidar);
    cout << "Nota: ";
    cin >> note.nota;

    return note;
}

void anadirNota() {
    structNotas note;
    ofstream archivoNotas;

    archivoNotas.open(nombreArchivoNotas, ios::binary | ios::app);
    if (archivoNotas.good()) {
        note = ingresarNota();
        archivoNotas.write((char*)(&note), sizeof(structNotas));
        archivoNotas.close();
        cout << "Nota agregada (^^)\n";
        system("pause");
    } else {
        cout << "No se pudo agregar nota.\n";
    }
}

void reporte() {
    system("cls");
    ifstream archiveStudents;
    ifstream archiveNotes;
    structEstudiante student;
    structNotas note;

    archiveStudents.open(nombreArchivoEstudiantes, ios::binary);
    if (archiveStudents.good()) {
        cout << "=== REPORTE === \n";
        while (archiveStudents.read((char*)(&student), sizeof(structEstudiante))){
            cout << "================================\nCI: ";
            cout << student.ci << endl;
            cout << "Nombre: " << student.nombres << " " << student.apellidos << endl;
            cout << "NOTAS\n";
            archiveNotes.open(nombreArchivoNotas, ios::binary);
            if (archiveNotes.good()) {
                while (archiveNotes.read((char*)(&note), sizeof(structNotas))) {
                    if (strcmp(student.ci, note.ci) == 0) {
                        cout << note.materia << " - " << note.nota << endl;
                    }
                }
                archiveNotes.close();
            } else {
                cout << "Notas no encontradas\n";
            }
            cout << "===============================\n";
        }
        archiveStudents.close();
        system("pause");
    } else {
        cout << "Error en el reporte.\n";
    }
}