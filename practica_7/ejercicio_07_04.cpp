// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/10/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

void imprimirMatrizSimetrica (int matriz[100][100], int filasColumnas);

int main () {
    system ("chcp 65001");
    system ("cls");

    int n;
    int matriz[n=100][100];
    int numeroAgregado = 1;
    cout << "Ingrese el número de filas y columnas: ";
    cin >> n;

    /* Llenar la matriz con el siguiente patrón
        1   2   3   4   5  
        3   4   5   6   7
        5   6   7   8   9...
    */
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matriz[i][j] = numeroAgregado;
            numeroAgregado += 1;
        }
        numeroAgregado = matriz[i][2];
    }

    imprimirMatrizSimetrica(matriz, n);

    return 0;
}

void imprimirMatrizSimetrica (int matriz[100][100], int filasColumnas) {
    for (int i=0; i<filasColumnas; i++) {
        for (int j=0; j<filasColumnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}