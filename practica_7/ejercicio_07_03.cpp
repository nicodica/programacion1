// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>

using namespace std;

// Funciones
void mostrarMatriz34 (char matriz[3][4]);
int filasLibres (char matriz[][4]);
int columnasLibres (char matriz[][4]);
vector <pair<int,int>> puntosInfectadosCoordenadas (char matriz[][4]);
int totalMuertos (char matriz[][4]);
bool entrarAlComplejo (char matriz[][4]);

// Valores globales, tamaño de matriz
int nFilas = 3;
int nColumnas = 4;

int main() {
    system("chcp 65001");
    system("cls");

    char mapa [3][4] = {{'x','o','x','o'},{'o','o','o','o'}, {'o','o','x','o'}};
    int nFilasLibres=0;
    int nColumnasLibres=0;
    vector <pair<int, int>> muertosCoordenadas;
    int totalDeMuertos = 0;

    //a) Mostrar la matriz que describe el area
    cout <<  "a) Mostrar matriz" << endl;
    mostrarMatriz34(mapa);

    //b) Mostrar el número de filas y columnas 
    cout << "b) Columnas y filas libres" << endl;
    nFilasLibres = filasLibres(mapa);
    nColumnasLibres = columnasLibres(mapa);
    cout << "Filas libres: " << nFilasLibres << endl;
    cout << "Columnas libres: " << nColumnasLibres << endl;

    //c) Mostrar las coordenadas de lugares infectados
    muertosCoordenadas = puntosInfectadosCoordenadas(mapa);
    cout << "c) Puntos Infectados" << endl;
    for (int i=0; i<muertosCoordenadas.size(); i++) {
        cout << muertosCoordenadas[i].first << " -- " << muertosCoordenadas[i].second << endl;
    }

    //d) Mostrar total de muertos
    totalDeMuertos = totalMuertos(mapa);
    cout << "d) Total de muertos vivientes: " << totalDeMuertos << endl;

    //e) mOstrar si enntrar o no al complejo
    cout << "e) ";
    if (entrarAlComplejo) {
        cout << "Es posible entrar al complejo (^-^)!" << endl;
    } else {
        cout << "NO es posible entrar al complejo (O_O)!" << endl;
    }

    return 0;
}

void mostrarMatriz34 (char matriz[3][4]) {
    for (int i=0; i<nFilas; i++) {
        for (int j=0; j<nColumnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int filasLibres (char matriz[][4]) {
    int puntosInfectadosFila = 0;
    int filasNoInfectadas = 0;
    // filas
    for (int i=0; i<nFilas; i++) {
        for (int j=0; j<nColumnas; j++) {
            if (matriz[i][j]== 'x') {
                puntosInfectadosFila+=1;
            }
        }
        if (puntosInfectadosFila==0) {
            filasNoInfectadas +=1;
        }
        puntosInfectadosFila = 0; // Reiniciar los puntos infectados de las filas
    }
    return filasNoInfectadas;
}

int columnasLibres (char matriz[][4]) {
    int columnasNOInfectadas = 0;
    int puntosInfectadosColumna = 0;
    for (int i=0; i<nColumnas; i++) {
        for (int j=0; j<nFilas; j++) {
            if (matriz[i][j] == 'x') {
                puntosInfectadosColumna++;
            }
        }
        if (puntosInfectadosColumna==0) {
            columnasNOInfectadas++;
        }
        puntosInfectadosColumna = 0;
    }
    return columnasNOInfectadas;
}

vector <pair<int,int>> puntosInfectadosCoordenadas (char matriz[][4]) {
    vector<pair<int,int>> coordenadasMuertos;
    for (int i=0; i<nFilas; i++) {
        for (int j=0; j<nColumnas; j++) {
            if (matriz[i][j] == 'x') {
                coordenadasMuertos.push_back({i,j});
            }
        }
    }
    return coordenadasMuertos;
}

int totalMuertos (char matriz[][4]) {
    int nMuertos = 0;
    for (int i=0; i<nFilas; i++) {
        for (int j=0; j<nColumnas; j++) {
            if (matriz[i][j] == 'x') {
                nMuertos++;
            }
        }
    }
    return nMuertos;
}

bool entrarAlComplejo (char matriz[][4]) {
    int nInfectados = 0;
    for (int i=0; i<nColumnas; i++) {
        if (matriz[i][0] == 'x' ) {
            nInfectados++;
        }
    }
    if (nInfectados>=2) {
        return false;
    } else {
        return true;
    }
}

