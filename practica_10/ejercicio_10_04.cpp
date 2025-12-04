// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/11/2025 
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

string transportarDatos();
int findFraseAndCount (string fraseBuscada, string textoCompleto);

int main() {
    system("chcp 65001");
    system("cls");

    string fraseABuscar;
    int nAparicionesFrase;

    string textoArchivo;
    textoArchivo = transportarDatos();

    cout << "TEXTO EN EL ARCHIVO" << endl;
    cout << textoArchivo << endl;

    cout << "Ingresa la palabra o frase que busca en el texto: ";
    getline(cin, fraseABuscar);

    nAparicionesFrase = findFraseAndCount(fraseABuscar, textoArchivo);
    if (nAparicionesFrase == 0) {
        cout << "No se encontró la palabra/frase";
    } else if (nAparicionesFrase == 1) {
        cout << "'" << fraseABuscar << "' aparece " << nAparicionesFrase << " vez.";
    } else {
        cout << "'" << fraseABuscar << "' aparece " << nAparicionesFrase << " veces.";
    }

    return 0;
}

string transportarDatos() {
    string textoCompleto;
    string lineaDeTexto;

    ifstream archivo;
    archivo.open("datos.txt");
    while (getline(archivo, lineaDeTexto)) {
        textoCompleto += lineaDeTexto + "\n";
    }
    archivo.close();
    return textoCompleto;
}

int findFraseAndCount (string fraseBuscada, string textoCompleto) {
    int nApariciones = 0;
    int posicionPalabra;

    posicionPalabra = textoCompleto.find(fraseBuscada);
    while (posicionPalabra != -1) {
        nApariciones++;
        posicionPalabra = textoCompleto.find(fraseBuscada, posicionPalabra+fraseBuscada.length());
    }
    return nApariciones;
}