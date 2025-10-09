// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 12

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool esPalindromo (string texto);
string convertirAMinusculas (string textoAConvertir);
string quitarespacios(string textoAQuitar);

int main() {
    system("chcp 65001");
    system("cls");

    string texto;
    cout << "Ingrese su texto: ";
    getline(cin,texto);

    

    if (esPalindromo(texto)) {
        cout << "'" << texto << "' es palíndromo.";
    } else {
        cout << "'"<< texto << "' no es palíndromo";
    }

    return 0;
}

//Quitar los espacios para frases;
string quitarespacios(string textoAQuitar) {
    string textoSinEspacios;
    for (int i=0; i<textoAQuitar.size(); i++) {
        if (textoAQuitar[i] != ' ') {
            textoSinEspacios.push_back(textoAQuitar[i]);
        }
    }
    return textoSinEspacios;
}

//Usarse cuando ya se tiene un texto sin espacios
string convertirAMinusculas (string textoAConvertir) {
    textoAConvertir = quitarespacios(textoAConvertir);
    string textoMinusculas;

    for (int i=0; i<textoAConvertir.size(); i++) {
        if (textoAConvertir[i]>=65 && textoAConvertir[i]<=90) {
            textoMinusculas.push_back(textoAConvertir[i]+32);
        } else {
            textoMinusculas.push_back(textoAConvertir[i]);
        }
    }
    return textoMinusculas;
}

bool esPalindromo (string texto) {
    texto = convertirAMinusculas(texto);
    string textoInvertido;

    for (int i=texto.size()-1; i>=0; i--) {
        textoInvertido.push_back(texto[i]);
    }
    if ( textoInvertido == texto) {
        return true;
    } else {
        return false;
    }
}