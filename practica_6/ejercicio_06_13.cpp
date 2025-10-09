// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 13

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mayusculaPrimerChar(string &palabra);
vector<string> dividirPalabras (string oracionOg);
void mostrarVectorString(vector<string>);

int main() {
    system("chcp 65001");
    system("cls");

    string oracion;
    vector<string> palabrasDivididas;
    cout << "Introduce tu oración: ";
    getline(cin, oracion);

    palabrasDivididas = dividirPalabras(oracion);

    //volver a cada primera letra mayuscula
    for (int i=0; i<palabrasDivididas.size(); i++) {
        mayusculaPrimerChar(palabrasDivididas[i]);
    }
    //Imprimir
    mostrarVectorString(palabrasDivididas);

    return 0;
}

void mayusculaPrimerChar(string &palabra) {
    if (palabra[0]>='a' && palabra[0]<=122) {
        palabra[0] -= 32;
    }
}

vector<string> dividirPalabras (string oracionOg) {
    string cadenaTemporal; 
    vector<string> oracionDividida;

    // Dividir en palabras y ponderlas en un vector
    for (int i=0; i<oracionOg.size(); i++) {
        if (oracionOg[i] != ' ') {
            cadenaTemporal.push_back(oracionOg[i]);
        }
        else if (cadenaTemporal.size()>0 && oracionOg[i] == ' ') {
            oracionDividida.push_back(cadenaTemporal);
            cadenaTemporal = ""; // vaciar la cadena temporal
        }
    }
    if (cadenaTemporal.size()>0) {
        oracionDividida.push_back(cadenaTemporal);
    }

    return oracionDividida;
}

void mostrarVectorString (vector<string> AMostrar) {
    for (int i=0; i<AMostrar.size(); i++) {
        if (i!= AMostrar.size()-1) {
            cout << AMostrar[i] << " ";
        } else {
            cout << AMostrar[i];
        }
    }
}