// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 11

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> separarFrase (char separador, string fraseCadena);
void imprimirVectorString (vector<string> vectorParaImprimir);

int main() {
    system("chcp 65001");
    system("cls");

    char separador;
    string cadena;
    vector<string> cadenaSeparada;

    cout << "Ingresa tu cadena con los separadores correspondientes: ";
    getline(cin,cadena);

    cout << "Ingresa tu separador: ";
    cin >> separador;

    cadenaSeparada = separarFrase(separador, cadena);
    imprimirVectorString(cadenaSeparada);

    return 0;
}

vector<string> separarFrase (char separador, string fraseCadena) {
    vector<string> fraseSeparada;
    string palabraTemporal = "";
    for (int i=0; i<fraseCadena.size(); i++) {
        if (fraseCadena[i] != separador) {
            palabraTemporal += fraseCadena[i];
        } else if (palabraTemporal.size()>0 && fraseCadena[i]==separador) {
            fraseSeparada.push_back(palabraTemporal);
            palabraTemporal = "";
        }
    }
    if (palabraTemporal.size()>0) {
        fraseSeparada.push_back(palabraTemporal);
    }
    return fraseSeparada;
}

void imprimirVectorString (vector<string> vectorParaImprimir) {
    for (int i=0; i<vectorParaImprimir.size(); i++) {
        cout << vectorParaImprimir[i] << endl;
    }
}

