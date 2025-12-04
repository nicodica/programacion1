// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 12/11/2025 
// Número de ejercicio: 8

#include <iostream>
#include <fstream>

using namespace std;

// void sumarLineas(int &lineas);
string traerTexto();
int contCaracteres (string texto);
int contPalabras (string texto);
int contLineas (string texto);

int main() {
    system("chcp 65001");
    system("cls");

    int nLineas, nPalabras, nCaracteres = 0;
    string texto = traerTexto();

    nCaracteres = contCaracteres(texto);
    nPalabras = contPalabras(texto);
    nLineas = contLineas(texto);

    cout << "TEXTO:" << endl;
    cout << texto << endl;
    cout << "Líneas: " << nLineas << endl;
    cout << "Palabras: " << nPalabras << endl;
    cout << "Caracteres: " << nCaracteres << endl;

    return 0;
}

string traerTexto () {
    string linea;
    string texto;
    ifstream archivo;
    archivo.open("documento.txt");
    if (archivo.good()) {
        while (!archivo.eof()) {
            getline(archivo, linea);
            texto += linea + "\n";
        }
    } else {
        cout << "Error con el archivo\n";
    }
    archivo.close();
    return texto;
}

int contCaracteres (string texto) {
    int caracteres = 0;
    for (int i=0; i<texto.length(); i++) {
        if (texto[i] != '\n') {
            caracteres++;
        }
    }
    return caracteres;
}

int contPalabras (string texto) {
    int palabras = 0;
    for (int i=0; i<texto.length(); i++) {
        if (texto[i] == '\n' || texto[i] == ' ') {
            palabras++;
        }
    }
    return palabras;
}

int contLineas (string texto) {
    int lineas = 0;
    for (int i=0; i<texto.length(); i++) {
        if (texto[i] == '\n') {
            lineas++;
        }
    }
    return lineas;
}