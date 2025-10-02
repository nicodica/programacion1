// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>

using namespace std;

void mostrarVector (vector<int> VectorMostrado);

int main() {
    system ("chcp 65001");
    system ("cls");

    vector<int> vectorEnteros;
    int contador = 0;
    int entero = 1;

    do {
        cout << "Ingresa el " << contador+1 << "° entero de tu vector: ";
        cin >> entero;
        
        // Agregar el entero al vector y aumentar el contador
        if (entero>=0) {
        vectorEnteros.push_back(entero);
        contador++;
        }
    } while(entero>=0 && contador<10);

    cout << endl;
    mostrarVector(vectorEnteros);

    return 0;
}

void mostrarVector (vector<int> VectorMostrado) {
    int n = VectorMostrado.size();
    for (int i=0; i<n; i++) {
        cout << VectorMostrado[i] << "\t";
    }
}