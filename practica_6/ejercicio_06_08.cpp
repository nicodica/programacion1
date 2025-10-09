// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <string>

using namespace std;

bool estaEsteCaracter(string cadena, char caracterBuscado);
int cuantasVecesEstaEsteCaracter(string cadena, char caracterBuscado);
bool validarCorreo (string correoAAnalizar);

int main() {
    system("chcp 65001");
    system("cls");

    string correo;

    cout << "Ingresa tu correo: ";
    getline(cin,correo);

    if (validarCorreo(correo)) {
        cout << "Correo válido ^-^)!" << endl;
    } else {
        cout << "Correo inválido u_u" << endl;
    }

    return 0;
}

bool estaEsteCaracter(string cadena, char caracterBuscado) {
    for (int i=0; i<cadena.size(); i++) {
        if (caracterBuscado == cadena[i]) {
            return true;
        }
    }
    return false;
}

int cuantasVecesEstaEsteCaracter(string cadena, char caracterBuscado) {
    int numeroVeces = 0;
    for (int i=0; i<cadena.size(); i++) {
        if (cadena[i] == caracterBuscado) {
            numeroVeces++;
        }
    }
    return numeroVeces;
}

bool validarCorreo (string correoAAnalizar) {
    bool unaArroba = false;
    bool masDeUnPunto = false;
    
    if (estaEsteCaracter(correoAAnalizar,'@') && (cuantasVecesEstaEsteCaracter(correoAAnalizar,'@')==1)) {
        unaArroba = true;
    }
    if (estaEsteCaracter(correoAAnalizar,'.') && (cuantasVecesEstaEsteCaracter(correoAAnalizar,'.')>=1)) {
        masDeUnPunto = true;
    }
    if (unaArroba && masDeUnPunto) {
        return true;
    } else {
        return false;
    }
}