// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 9

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> dividirPalabrasOracion (string oracionOriginal);
void imprimirPalabrasSeparadasReversa (vector<string> oracion);

int main() {
    system("chcp 65001");
    system("cls");

    string oracion;
    vector<string>oracionDivididaPalabras; 
    
    cout << "Introduzca su oracion: ";
    getline(cin, oracion);

    oracionDivididaPalabras = dividirPalabrasOracion(oracion);
    imprimirPalabrasSeparadasReversa(oracionDivididaPalabras);


    return 0;
}

vector<string> dividirPalabrasOracion (string oracionOriginal) {
    string cadenaTemporal; 
    vector<string> cadenaEnPalabras;

    // Dividir en palabras y ponderlas en un vector
    for (int i=0; i<oracionOriginal.size(); i++) {
        if (oracionOriginal[i] != ' ') {
            cadenaTemporal.push_back(oracionOriginal[i]);
        }
        else if (cadenaTemporal.size()>0 && oracionOriginal[i] == ' ') {
            cadenaEnPalabras.push_back(cadenaTemporal);
            cadenaTemporal = ""; // vaciar la cadena temporal
        }
    }
    if (cadenaTemporal.size()>0) {
        cadenaEnPalabras.push_back(cadenaTemporal);
    }

    return cadenaEnPalabras;
}

void imprimirPalabrasSeparadasReversa (vector<string> oracion) {
    for (int i=oracion.size()-1; i>=0; i--) {
        if (i == 0) {
            cout << oracion[i];
        } else {
            cout << oracion[i] << " ";
        }
    }
}