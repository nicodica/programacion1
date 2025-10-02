// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>

using namespace std;

void mostrarVector3x3(vector<double> vectorAMostrar);

int main() {
    system("cls");

    vector<double> voltios = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};
    mostrarVector3x3(voltios);
    return 0;
}

void mostrarVector3x3(vector<double> vectorAMostrar) {
    for (int i=0; i<3; i++) {
        //Una condición para mostrar cada fila de 3 elementos de vector
        if (i==0) {
            for (int j=0; j<3; j++) {
                cout << vectorAMostrar[j] << "\t";
            }
        } else if (i==1){
            for (int k=3; k<6; k++) {
                cout << vectorAMostrar[k] << "\t";
            }
        } else {
            for (int l=6; l<9; l++) {
                cout << vectorAMostrar[l] << "\t";
            }
        }
        cout << endl;
    }
}