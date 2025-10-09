// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 04/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;

string convertirAMayusculas (string palabra);
void buscarPorNombre(string nombreMineral, vector<double> produccion, vector<string> nombres);
vector<double> ordenarMayorAMenorProduccion(vector<double> produccion);

int main() {
    system("chcp 65001");
    system("cls");

    vector<double> produccionCifras = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};
    vector<string> nombreMinerales = {"SN", "SB", "AU", "PT", "AG", "CU"};
    int opcion;
    string opcionNombre;
    vector<double> produccionCifrasORDENADA;

    cout << "Minerales = SN, SB, AU, PT, AG, CU" << endl;
    cout << "Ingresa el nombre del mineral para ver su producción: ";
    getline(cin, opcionNombre);

    buscarPorNombre(opcionNombre, produccionCifras, nombreMinerales);

    produccionCifrasORDENADA = ordenarMayorAMenorProduccion(produccionCifras);
    for (int i=0; i<6; i++) {
        cout << produccionCifrasORDENADA[i] << " - ";
    }

    return 0;
}

string convertirAMayusculas (string palabra) {
    string palabraMayuscula;
    for (int i=0; i<palabra.size(); i++) {
        if (palabra[i]>='a' && palabra[i]<='z') {
            palabraMayuscula.push_back(palabra[i]-32);
        } else {
            palabraMayuscula.push_back(palabra[i]);
        }
    }
    return palabraMayuscula;
}

void buscarPorNombre(string nombreMineral, vector<double> produccion, vector<string> nombres) {
    nombreMineral = convertirAMayusculas(nombreMineral);
    for (int i=0; i<6; i++) {
        if (nombreMineral==nombres[i]) {
            cout << nombres[i] << " = " << produccion[i] << " MT" << endl;
        }
    }
}

vector<double> ordenarMayorAMenorProduccion(vector<double> produccion) {
    double aux;
    vector<double> produccionOrdenada(6);
    for (int i=0; i<5; i++) {
        for (int j=0; j<(5-i); j++) {
            if (produccion[j]<produccion[j+1]) {
                aux = produccion[j];
                produccion[j] = produccion[j+1];
                produccion[j+1] = aux;
            }
        }
    }
    produccionOrdenada = produccion;
    return produccionOrdenada;
}

vector<string> ordenarMayorAMenorNombres (vector<string> nombresOriginal, vector<double> produccionOriginal, vector<double> produccionOrdenada) {
    vector<string> nombresOrdenado;
    int contador = 0;
    while (contador<6) {
        for (int i=0; i<6; i++) {
            if (produccionOrdenada[0] == produccionOriginal[i]) {
                nombresOrdenado[0] = nombresOriginal[0]; 
                contador++;
            }
        }
    }
    return nombresOrdenado;
} 