// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> almacenarEdades();
double calcularDesviacionTipica(vector<double> elementos);

int main()
{
    system ("chcp 65001");
    system ("cls");
    
    vector<double> edades;
    double desviacionTipica;
    
    cout << "ALMACENAMIENTO DE EDADES" << endl;
    edades = almacenarEdades();
    
    cout << endl << "DESVIACIÓN TÍPICA(POBLACIONAL) DE LAS EDADES" << endl;
    desviacionTipica = calcularDesviacionTipica(edades);
    cout << ">> " << desviacionTipica << endl;

    return 0;
}

vector<double> almacenarEdades() {
    vector<double> vectorEdades;
    double edad;
    bool parar = false;
    do {
        cout << "Ingresa una edad válida (-1 para parar): ";
        cin >> edad;
    
        if (edad>=0) {
            vectorEdades.push_back(edad);
        } else if (edad == -1) {
            parar = true;
        } else {
            cout << "Ingresa una edad válida, por favor." << endl;
        }
        
    } while (parar==false);
    
    return vectorEdades;
}

double calcularDesviacionTipica(vector<double> elementos) {
    double promedio;
    double suma = 0;
    double sumaParaVarianza = 0;
    double varianza;
    //Hallar el promedio de los elementos
    for (int i=0; i<elementos.size(); i++) {
        suma += elementos[i];
    }
    promedio = suma/elementos.size();
    
    //Calcular la varianza
    for (int i=0; i<elementos.size(); i++) {
        sumaParaVarianza += pow((elementos[i]-promedio),2); //suma de las desviaciones al cuadrado
    }
    varianza = sumaParaVarianza/elementos.size();
    
    return sqrt(varianza);
}