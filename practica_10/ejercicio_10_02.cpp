// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 07/11/2025 
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> separarFrase (string fraseOg);
void exportarFraseyPalabras(char fraseExportada[], int nPalabrasenFrase);

int main() {
    system("chcp 65001");
    system("cls");

    char frase[100];   // esta frase se va a proyectar en el documento de texto al momento de mostrar la frase original
    string fraseTemporal;
    vector<string> fraseSeparada;
    int nPalabras;

    cout << "Ingrese la palabra a guardar(100 caracteres): ";
    cin.getline(frase, 100);
    fraseTemporal = frase; // se guarda las frase para separarla (así se podrá contar las palabras)

    fraseSeparada = separarFrase(fraseTemporal);
    nPalabras = fraseSeparada.size();

    exportarFraseyPalabras(frase, nPalabras);
    cout << "Archivo exportado";

    return 0;
}

vector<string> separarFrase (string fraseOg) {
    vector<string> fraseSeparada;
    string palabraTemporal = "";
    for (int i=0; i<fraseOg.length(); i++) {
        if (fraseOg[i] != ' ') {
            palabraTemporal += fraseOg[i];
        } else if (palabraTemporal.length() > 0 && fraseOg[i] == ' ') {
            fraseSeparada.push_back(palabraTemporal);
            palabraTemporal = "";
            cout << palabraTemporal;
        }
        
    }
    if (palabraTemporal.length() > 0) {
        fraseSeparada.push_back(palabraTemporal);
    }
    return fraseSeparada;
}

// escribir en el documento
void exportarFraseyPalabras(char fraseExportada[], int nPalabrasenFrase) {
    ofstream archivo;
    archivo.open("Texto.txt");
    archivo << "Frase: " << fraseExportada << endl;
    archivo << "Número de palabras: " << nPalabrasenFrase;
    archivo.close();
}