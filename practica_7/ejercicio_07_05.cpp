// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int generarIntAleatorio(int inf, int sup);
void mostrarMatriz (int matriz[][100], int filas, int columnas);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int N, M;
    int matrizNM [100][100]; // NxM
    int matrizMN [100][100]; //MxN
    int matrizProducto [100][100];
    int suma=0;

    cout << "MULTIPLICACIÓN DE MATRICES" << endl;
    cout << "Ingrese N: ";
    cin >> N;
    cout << "Ingrese M: ";
    cin >> M;

    // Llenar las matrices
    // NxM
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            matrizNM[i][j] = generarIntAleatorio(1,10);
        }
    }
    // MxN
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            matrizMN[i][j] = generarIntAleatorio(1,10);
        }
    }

    //Multiplicar las matrices
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                suma += (matrizNM[i][k]*matrizMN[k][j]);
            }
            matrizProducto[i][j] = suma;
            suma = 0;
        }
    }

    // Mostrar todas las matrices
    mostrarMatriz(matrizNM, N, M);
    cout << "x" << endl;
    mostrarMatriz(matrizMN, M, N);
    cout << "=" << endl;
    mostrarMatriz(matrizProducto, N, N);


    return 0;
}

int generarIntAleatorio(int inf, int sup) {
    return (rand()%(sup-inf+1))+inf;
}

void mostrarMatriz (int matriz[][100], int filas, int columnas) {
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

