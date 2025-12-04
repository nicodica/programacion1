// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

string nombreArchivo = "EstudiantesDatos.bin";

struct Estudiante{
    char ci[10];
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
    double nota;
    bool eliminado;
};

void menu();
void ingresarEstudiante();
bool validarCarnet(char[]);
Estudiante datosEstudiante();
void mostrarEstudiantesHabilitados();
void ingresarNota();
void eliminarEstudiante();

int main() {
    system("chcp 65001");
    system("cls");

    menu();

    return 0;
}

void menu() {
    int opcion;
    do {
        cout << "=== MENÚ NOTAS UCB ===" << endl;
        cout << "\t1. Adicionar Estudiante" << endl;
        cout << "\t2. Listado de Estudiantes Habilitados" << endl;
        cout << "\t3. Eliminar una Estudiante" << endl;
        cout << "\t4. Adicionar Notas de Habilitación" << endl;
        cout << "\t0. Parar" << endl;
        cout << "--> ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            ingresarEstudiante();
        } else if (opcion == 2) {
            mostrarEstudiantesHabilitados();
        } else if (opcion == 3) {
            eliminarEstudiante();
        } else if (opcion == 4) {
            ingresarNota();
        } else if (opcion == 0){
            cout << "Saliendo...";
        } else {
            cout << "Opción no existente\n";
        }
    } while (opcion != 0);
}

Estudiante datosEstudiante() {
    Estudiante student;
    bool ciValido = false;  
    while (ciValido != true) {
        cout << "CI: ";
        cin.getline(student.ci, 10);
        ciValido = validarCarnet(student.ci);
        if (!ciValido) {
            cout << "CI ya registrado, vuelva a intentarlo" << endl;
        }
    }
    // Al salir del loop...
        cout << "Nombres: ";
        cin.getline(student.nombres,30);
        cout << "Apellidos: ";
        cin.getline(student.apellidos,30);
        cout << "Materia: ";
        cin.getline(student.materia,30);
        cout << "Paralelo: ";
        cin >> student.paralelo;
        cin.ignore();
        student.nota = 0.0; // 0 al empezar
        student.eliminado = false; //false para iniciar, se cambiará a true si es que es eliminado
        return student;
}

void ingresarEstudiante() {
    Estudiante student = datosEstudiante();
    ofstream archivo;
    // abrir archivo binario
    archivo.open(nombreArchivo, ios::binary | ios::app);

    if (archivo.good()) {
        archivo.write((char*)&student, sizeof(Estudiante));
        archivo.close();
        cout << "Estudiante registrado" << endl;
    } else {
        cout << "Error al agregar al estudiante" <<endl;
        return;
    }
}

bool validarCarnet(char carnet[]) {
    ifstream archivo;
    Estudiante student;
    bool valido = true;

    archivo.open(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        while (archivo.read((char*)(&student), sizeof(Estudiante))) {
            if (strcmp(carnet, student.ci) == 0) {
                valido = false;
            }
        }
    } else {
        cout << "Error al validar";
        system("pause");
        return NULL;
    }
    archivo.close();
    return valido;
}

void mostrarEstudiantesHabilitados() {
    Estudiante student;
    ifstream archivo;
    
    archivo.open(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        cout << "CI\tNOMBRES\tAPELLIDOS\tMATERIA\tPARALELO\tNOTA\tESTADO" << endl;
        while (archivo.read((char*)(&student), sizeof(Estudiante))) {
            if (student.nota >= 60) {
                cout << student.ci << "\t" << student.nombres << "\t" << student.apellidos << "\t" << student.materia << "\t" << student.paralelo << "\t" << student.nota << "\tHABILITADO\n";
            }
        }
    } else {
        cout << "Error al abrir el archivo";
        system("pause");
        return;
    }
    archivo.close();
    system("pause");
}

void eliminarEstudiante() {
    fstream archivo;
    Estudiante student;
    char CIBuscado[10];
    bool encontrado = false;
    cout << "Carnet del estudiante que desea eliminar: ";
    cin.getline(CIBuscado, 10);

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&student), sizeof(Estudiante)) && encontrado!=true) {
            if (strcmp(CIBuscado,student.ci)==0 && student.eliminado!=true) {
                encontrado = true;
                archivo.seekp(-sizeof(Estudiante), ios::cur);
                student.eliminado = true;
                archivo.write((char*)(&student), sizeof(Estudiante));
            }
        }
        if (encontrado==false) {
            cout << "No se encontró un estudiante con ese CI";
            system("pause");
        } else {
            cout << "Estudiante eliminado.\n";
        }
    } else {
        cout << "Error al eliminar estudiante";
        system("pause");
        return;
    }
    archivo.close();
    system("pause");
}

void ingresarNota() {
    fstream archivo;
    Estudiante student;
    char CIBuscado[10];
    bool encontrado = false;
    char materiaBuscada[30];

    cout << "DATOS PARA LAS NOTAS:\n";
    cout << "CI: ";
    cin.getline(CIBuscado, 10);
    cout << "Materia: ";
    cin.getline(materiaBuscada, 30);

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&student), sizeof(Estudiante)) && encontrado!=true) {
            if (strcmp(CIBuscado,student.ci)==0 && strcmp(materiaBuscada, student.materia)==0 && student.eliminado!=true) {

                encontrado = true;
                archivo.seekp(-sizeof(Estudiante), ios::cur);
                cout << "Agregar nota: ";
                cin >> student.nota;
                archivo.write((char*)(&student), sizeof(Estudiante));
            }
        }
        if (encontrado==false) {
            cout << "No se encontró un estudiante con ese CI";
            system("pause");
        } else {
            cout << "Nota agregada.\n";
        }
    } else {
        cout << "Error al agregar nota del estudiante";
        system("pause");
        return;
    }
    archivo.close();
    system("pause");

}