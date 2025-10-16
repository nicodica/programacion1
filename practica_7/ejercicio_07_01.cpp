// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/10/2025
// Número de ejercicio: 1

#include <iostream>

using namespace std;

void imprimirMatriz (int matriz[100][100], int filas, int columnas);

int main () {
    system("chcp 65001");
    system("cls");

    int matriz[100][100];
    int aux=0; //Entero auxiliar para realizar el intercambio de valores en las filas
    int n; //Matriz cuadrada: es igual el número de filas y columnas
    
    cout << "Introduce el número de filas y columnas (nxn): ";
    cin >> n;

    // Llenar la matriz
    for (int i=0; i<n; i++) {
        cout << "FILA " << i+1 << endl;
        for (int j=0; j<n; j++) {
            cout << j+1 << "° columna: ";
            cin >> matriz[i][j];
        }
        cout << endl;
    }

    imprimirMatriz(matriz, n, n);
    cout << endl;

    // Cambiar la primera y ultima fila
    for (int i=0; i<n; i++) {
        aux = matriz[0][i]; // Guardar en una auxliar un valor de la primera fila
        matriz[0][i] = matriz[n-1][i]; //Intercambiar el valor de la primera con la última
        matriz[n-1][i] = aux; //Rescatar el valor del auxliar
    }
    // Imprimir la matriz ya cambiada
    imprimirMatriz(matriz, n, n);

    return 0;
}

void imprimirMatriz (int matriz[100][100], int filas, int columnas) {
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}