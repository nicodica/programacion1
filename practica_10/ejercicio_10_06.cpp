// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 12/11/2025 
// Número de ejercicio: 5

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> transportarTexto();
vector<string> ciudadesEnVector(vector<string> lineas);
vector<float> tempAVector(vector<string> lineas);
void archivoAltasTemps(vector<string> ciudades, vector<float> temps, float altaTemp);

int main() {
    system("chcp 65001");
    system("cls");
    float N;
    vector<string> lineasTexto;
    vector<string> nombreCiudades;
    vector<float> temperaturas;

    lineasTexto = transportarTexto();
    nombreCiudades = ciudadesEnVector(lineasTexto);
    temperaturas = tempAVector(lineasTexto);

    cout << "Ingresa desde qué grado se clasificarán las temperaturas: ";
    cin >> N;

    archivoAltasTemps(nombreCiudades, temperaturas, N);
    cout << "El archivo ha sido creado con éxito";

    
    return 0;
}

vector<string> transportarTexto() {
    ifstream archivo;
    vector <string> lineas;
    string lineaTemporal;
    archivo.open("temperaturas.txt");
    while (getline(archivo, lineaTemporal)) {
        lineas.push_back(lineaTemporal);
    }
    archivo.close();
    return lineas;
}

vector<string> ciudadesEnVector(vector<string> lineas) {
    vector<string> ciudades;
    string ciudad = "";
    string linea;
    bool bandera = true;

    for (int i=0; i<lineas.size(); i++) {
        linea = lineas[i];
        for (int j=0; j<linea.length(); j++) {
            if (bandera) {
                ciudad += linea[j];
            }
            if (linea[j] == ' ') {
                bandera = false;
            }
        }
        ciudades.push_back(ciudad);
        ciudad = "";
        bandera = true;
    }
    return ciudades;
}

vector<float> tempAVector(vector<string> lineas) {
    vector<float> temps;
    string tempString = "";
    float tempFloat;
    string linea;
    bool bandera = false; //bandera para determinar si hay un espacio en la cadena

    for (int i=0; i<lineas.size(); i++) {
        linea = lineas[i];
        for (int j=0; j<linea.length(); j++) {
            if (linea[j]==' ') {
                bandera = true;
            }
            if (bandera && linea[j]!=' ' && linea[j]!='\n') {
                tempString += linea[j];
            }
        }
        tempFloat = stof(tempString);
        temps.push_back(tempFloat);
        tempString = "";
        bandera = false;
    }
    return temps;
}

void archivoAltasTemps(vector<string> ciudades, vector<float> temps, float altaTemp) {
    ofstream archivo;
    vector<string> ciudadesAltTemp;
    vector<float> tempsAltTemp;

    for(int i=0; i<ciudades.size(); i++) {
        if (temps[i]>altaTemp) {
            tempsAltTemp.push_back(temps[i]);
            ciudadesAltTemp.push_back(ciudades[i]);
        }
    }

    archivo.open("altas_temperaturas.txt");
    if (archivo.is_open()) {
        for (int i=0; i<ciudadesAltTemp.size(); i++) {
            archivo << ciudadesAltTemp[i] << " " << tempsAltTemp[i] << "\n";
        }
    } else {
        cout << "Error al abrir el nuevo archivo";
    }
    archivo.close();
    
}
