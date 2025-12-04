// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 12/11/2025 
// Número de ejercicio: 7

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> transportarTexto();
vector<string> nombresEnVector(vector<string> lineas);
vector<float> calcularPromedios (vector<string> lineas);
void crearArchivoPromedios(vector<string> nombres, vector<float> promedios);

int main() {
    system("chcp 65001");
    system("cls");

    vector<string> lineasTexto;
    vector<string> nombres;
    vector<float> promedios;

    lineasTexto = transportarTexto();
    nombres = nombresEnVector(lineasTexto);
    promedios = calcularPromedios(lineasTexto);

    crearArchivoPromedios(nombres, promedios);

    return 0;
}

vector<string> transportarTexto() {
    ifstream archivo;
    string linea;
    vector<string> lineas;
    
    archivo.open("calificaciones.txt");
    while (getline(archivo,linea)) {
        lineas.push_back(linea);
    }
    archivo.close();
    return lineas;
}

vector<string> nombresEnVector(vector<string> lineas) {
    vector<string> nombres;
    string nombre;
    string linea;
    int contPalabras = 1;
    
    for (int i=0; i<lineas.size(); i++) {
        contPalabras = 1;
        linea = lineas[i];
        stringstream lector(linea);
        while(getline(lector, nombre, ' ')) {
            if (contPalabras == 1) {
                nombres.push_back(nombre);
            }
            contPalabras++;
        }
    }

    return nombres;
}

vector<float> calcularPromedios (vector<string> lineas) {
    vector<float> promedios;
    string palabra;
    string linea;
    float contPalabras = 1;
    float suma = 0;
    float promedio;
    
    for (int i=0; i<lineas.size(); i++) {
        contPalabras = 1;
        linea = lineas[i];
        stringstream lector(linea);
        while(getline(lector, palabra, ' ')) {
            if (contPalabras != 1) {
                suma += stof(palabra);
            }
            contPalabras++;
        }
        promedio = suma / (contPalabras-2.0);
        promedios.push_back(promedio);
        suma = 0;
    }
    return promedios;
}

void crearArchivoPromedios(vector<string> nombres, vector<float> promedios) {
    ofstream archivo;
    archivo.open("promedios.txt");
    if (archivo.is_open()) {
        for (int i=0; i<nombres.size(); i++) {
            archivo << nombres[i] << " " << promedios[i] << "\n";
        }
    } else {
        cout << "No se pudo abrir el archivo";
        archivo.close();
        return;
    }
    archivo.close();
    cout << "Archivo creado con éxito";
}