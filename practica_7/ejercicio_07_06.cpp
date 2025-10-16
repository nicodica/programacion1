// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void mostrarMatriz (int matriz[100][100], int nFilas, int nColumnas);

int generarIntRandom (int inf, int sup);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int matriz[100][100];
    int matrizTranspuesta[100][100];
    int N, M;
    
    cout << "Insertar filas: ";
    cin >> N;
    cout << "Insertar columnas: ";
    cin >> M;


    // Generar matriz
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            matriz[i][j] = generarIntRandom(0,9);
        }
    }

    // Mostrar matriz Original
    cout << endl << "MATRIZ ORIGINAL" << endl;
    mostrarMatriz(matriz, N, M);

    //Trasponer
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            matrizTranspuesta[i][j] = matriz[j][i];
        }
    }
    // Mostrar Matriz Transpuesta
    cout << endl << "MATRIZ TRANSPUESTA" << endl;
    mostrarMatriz(matrizTranspuesta, M, N);

    return 0;
}

int generarIntRandom (int inf, int sup) {
    return ((rand()%(sup-inf+1))+sup);
}

void mostrarMatriz (int matriz[100][100], int nFilas, int nColumnas) {
    for (int i=0; i<nFilas; i++) {
        for (int j=0; j<nColumnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}