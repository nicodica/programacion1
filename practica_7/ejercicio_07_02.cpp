// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int generarIntAleatorio(int LimInf, int LimSup);
void mostrarMatrizSimetrica (int matriz[][100], int filasColumnas);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int matriz[100][100]; // Matriz
    int n; // filas y columnas
    int A,B; // Límite inf y sup de los números aleatorios
    int suma=0;
    int producto=1;
    int mayor, posicionFila, posicionColumna;
    double sumaGeneral=0.0;
    double promedio, desviacionEstandar;
    double sumaDesviaciones=0.0;

    cout << "Introduce el número de filas y columnas de la matriz: ";
    cin >> n;

    cout << "Introduce los límites de los enteros a generar:" << endl;
    cout << "Límite Inferior: ";
    cin >> A;
    cout << "Límite superior: ";
    cin >> B;

    // Llenar la matriz
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            matriz[i][j] = generarIntAleatorio(A,B);
        }
    }

    // Sumar la última columna
    for (int i=0; i<n; i++) {
        suma += matriz[i][n-1];
    }
    // Multiplicar la última fila
    for (int i=0; i<n; i++) {
        producto *= matriz[n-1][i];
    }
    // Obtener mayor valor
    mayor = matriz[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matriz[i][j]>mayor) {
                mayor = matriz[i][j];
                posicionFila = i;
                posicionColumna = j; 
            }
        }
    }
    // Calular desviación estándar
    //        SUMA
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sumaGeneral += matriz[i][j];
        }
    }
    //        PROMEDIO
    promedio = sumaGeneral/ double(n);
    //       DESVIACIÓN
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sumaDesviaciones = pow(matriz[i][j]-promedio,2);
        }
    }
    desviacionEstandar = sqrt(sumaDesviaciones/(double(n)-1.0));




    // MOSTRAR
    // Matriz
    mostrarMatrizSimetrica(matriz, n);
    // Suma Ultima Columna
    cout << "SUMA: " << suma << endl;
    // Producto última fila
    cout << "PRODUCTO: " << producto << endl;
    // Mayor y posicion
    cout << "MAYOR: " << mayor << " en la posición ["<<posicionFila<<"]["<<posicionColumna<<"]" << endl;
    // Desaviación Estándar
    cout << "DESVIACIÓN ESTÁNDAR: " << desviacionEstandar << endl;

    return 0;
}

int generarIntAleatorio(int LimInf, int LimSup) {
    return ((rand()%(LimSup-LimInf+1))+LimInf);
}

void mostrarMatrizSimetrica (int matriz[][100], int filasColumnas) {
    for (int i=0; i<filasColumnas; i++) {
        for (int j=0; j<filasColumnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
