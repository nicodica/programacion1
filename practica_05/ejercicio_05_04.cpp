// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>

using namespace std;

vector <int> crearVector (int longitudVector);
vector<int> vectorMultiplicado (vector<int> primerVector, vector<int> segundoVector);
void mostrarVector (vector<int> vectorAMostrar);

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3;
    
    cout << "MULTIPLICACIÓN DE VECTORES" << endl << "Ingrese la longitud de los vectores: ";
    cin >> N;
    cout << "Primer vector: " << endl;
    vector1 = crearVector(N);
    cout << "Segundo vector: " << endl;
    vector2 = crearVector(N);

    vector3 = vectorMultiplicado(vector1, vector2);

    cout << endl;
    mostrarVector(vector1);
    mostrarVector(vector2);
    mostrarVector(vector3);
    cout << endl;
    return 0;
}

vector <int> crearVector (int longitudVector) {
    vector<int> vectorDeEnteros(longitudVector);
    for (int i=0; i<longitudVector; i++) {
        cout << "Introduzca el " << i+1 << "° número: ";
        cin >> vectorDeEnteros[i];
    }
    return vectorDeEnteros;
}

vector<int> vectorMultiplicado (vector<int> primerVector, vector<int> segundoVector) {
    int n = primerVector.size(); //Ambos son del mismo tamaño, solo es necesaria la longitud de 1
    vector<int> vectorMult(n);
    for (int i=0; i<n; i++) {
        vectorMult[i] = primerVector[i]*segundoVector[i];
    }
    return vectorMult;
}

void mostrarVector (vector<int> vectorAMostrar) {
    int n = vectorAMostrar.size();
    for (int i=0; i<n; i++) {
        cout << vectorAMostrar[i] << "\t";
    }
    cout << endl;
}