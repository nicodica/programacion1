// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 10

#include <iostream>
#include <string>

using namespace std;

string quitarDigsACadena(string cadena);

int main () {
    system ("chcp 65001");
    system("cls");
    
    string cadena;
    string cadenaNODigs;

    cout << "Ingresa tu cadena: ";
    getline(cin, cadena);

    cadenaNODigs = quitarDigsACadena(cadena);
    cout << cadenaNODigs;

    return 0;
}

/* string almacenarDigitosDeCadena (string cadenaAnalizada) {
    string digitosAlmacenados;
    for (int i=0; i< cadenaAnalizada.size(); i++) {
        if (cadenaAnalizada[i] >=48 && cadenaAnalizada[i]<=57) {
            digitosAlmacenados.push_back(cadenaAnalizada[i]);
        }
    }
    return digitosAlmacenados;
} */

string almacenarDigitosDeCadena (string cadenaAnalizada) {
    string digitosAlmacenados;
    for (int i=0; i< cadenaAnalizada.size(); i++) {
        if (cadenaAnalizada[i] >=48 && cadenaAnalizada[i]<=57) {
            digitosAlmacenados.push_back(cadenaAnalizada[i]);
        }
    }
    return digitosAlmacenados;
}

/* void eliminarDigCadena (string &cadenaAnalizada, string cadenaDigitos) {
    for (int i=0; i<cadenaAnalizada.size(); i++) {
        for (int j=0; j<cadenaDigitos.size(); j++) {
            if (cadenaAnalizada[i] == cadenaDigitos[j]) {
                cadena
            }
        }
    }
} */

string quitarDigsACadena(string cadena) {
    string cadenaSinDigs;
    for (int i=0; i<cadena.size(); i++) {
        if (cadena[i]<'0' || cadena[i]>'9') {
            cadenaSinDigs.push_back(cadena[i]);
        }
    }
    return cadenaSinDigs;
}