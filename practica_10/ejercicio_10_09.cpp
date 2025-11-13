// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/11/2025 
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// funciones
void crearArchivo();
void cifrarArchivo();

int main () {
    system("chcp 65001");
    system("cls");

    crearArchivo();
    cifrarArchivo();


    return 0;
}

void crearArchivo() {
    char texto[100];
    ofstream archivo;
    archivo.open("Mensaje.txt", ios::app);

    if (!archivo.is_open()){
        cout << "Error al abrir el archivo x-x)" << endl;
        return;
    }
    cout << "Escribe tu mensaje a cifrar: ";
    cin.getline(texto, 100);
    archivo << texto << "\n";
    archivo.close();
}

void cifrarArchivo() {
    string lineaTexto;
    string lineaCifrada = "";
    char charTemporal;

    ifstream archivoOg;
    ofstream archivoNew;
    archivoOg.open("Mensaje.txt");
    archivoNew.open("Mensaje_cifrado.txt");

    if (!archivoOg.good()) {
        cout << "Error al abrir el archivo x-x" << endl;
        return;
    }
    if (!archivoNew.is_open()) {
        cout << "Error al crear el archivo unu" << endl;
        return;
    }

    while(!archivoOg.eof()) {
        getline(archivoOg, lineaTexto);
        for (int i=0; i<lineaTexto.length(); i++) {
            charTemporal = lineaTexto[i] + 3;
            lineaCifrada += charTemporal;
        }
        archivoNew << lineaCifrada << "\n";
        lineaCifrada = "";
    }

    archivoOg.close();
    archivoNew.close();
    cout << "Mensaje cifrado con éxito !!" << endl;
}