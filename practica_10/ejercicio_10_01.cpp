// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 07/11/2025 
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct nombreApellido {
    char nombre[20];
    char apellido[20];
};

nombreApellido ingresarNombre();
void exportarLista(vector<nombreApellido> names);

int main() {
    system("chcp 65001");
    system("cls");
    int opcion;
    vector<nombreApellido> nombres;

    do {
        system("cls");
        cout << "== INGRESAR NOMBRES ==" << endl;
        cout << "\t1. Ingresar persona" << endl;
        cout << "\t2. Crear archivo de lista de nombres" << endl << "-->";
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            nombres.push_back(ingresarNombre());
        } else if (opcion == 2){
            exportarLista(nombres);
            cout << "Lista exportada :)";
        } else{
            cout << "Opción inválida" << endl;
        }

    } while (opcion != 2);
    

    return 0;
}

nombreApellido ingresarNombre () {
    nombreApellido name;

    cout << "Nombre: ";
    cin.getline(name.nombre, 20);
    cout << "Apellido: ";
    cin.getline(name.apellido, 20);

    return name;
}

void exportarLista(vector<nombreApellido> names) {
    ofstream archivo;
    archivo.open("nombres.txt");
    for (int i=0; i<names.size(); i++) {
        archivo << i+1 << "° " << names[i].nombre << " " << names[i].apellido << endl;
    }
    archivo.close();
}