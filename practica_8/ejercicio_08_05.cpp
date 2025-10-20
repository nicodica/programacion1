// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector <int> generarVectorInt (int cantidad);
int sumaVectorRecursiva (vector<int> enteros, int cantidad);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int n;
    vector <int> enteros;
    int sumaVector = 0;

    cout << "SUMA DE ELEMENTOS DE UN VECTOR" << endl;
    cout << "Ingrese el número de números enteros a generar en su vector: ";
    cin >> n;
    enteros = generarVectorInt(n);
    sumaVector=sumaVectorRecursiva(enteros, n);

    // Mostrar el vector y resultado
    for (int i=0; i<n; i++) {
        if (i!=(n-1)) {
            cout << enteros[i] << " + ";
        } else {
            cout << enteros[i];
        }
    }
    cout << " = " << sumaVector << endl;


    return 0;
}

vector <int> generarVectorInt (int cantidad) {
    vector <int> enteros;
    for (int i=0; i<cantidad; i++) {
        enteros.push_back(rand()%100); // enteros de 0 a 100
    }
    return enteros;
}

int sumaVectorRecursiva (vector<int> enteros, int cantidad) {
    if (cantidad==0) {
        return 0;
    } else {
        return enteros[cantidad-1] + sumaVectorRecursiva(enteros, cantidad-1);
    }
}

