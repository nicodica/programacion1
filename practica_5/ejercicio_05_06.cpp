// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>

using namespace std;

vector<int> crearVectorN5();
vector<int> sumarVectoresN5(vector<int> primerVector, vector<int> segundoVector);
void mostrarVectorN5(vector<int> vectorN5);

int main() {
    system("chcp 65001");
    system("cls");

    int n = 5;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3; //Será la suma de v1 y v2

    cout << "SUMA DE VECTORES DE 5 ENTEROS" << endl;
    cout << "Vector 1:" << endl;
    vector1 = crearVectorN5();
    cout << "Vector 2:" << endl;
    vector2 = crearVectorN5();
    vector3 = sumarVectoresN5(vector1, vector2);

    mostrarVectorN5(vector1);
    mostrarVectorN5(vector2);
    mostrarVectorN5(vector3);

    return 0;
}

vector<int> crearVectorN5() { // El vector solo será de 5 enteros
    vector<int> vectorCreado(5);
    for (int i=0; i<5; i++) {
        cout << "Introduzca el " << i+1 << "° entero: ";
        cin >> vectorCreado[i];
    }
    return vectorCreado;
}

vector<int> sumarVectoresN5(vector<int> primerVector, vector<int> segundoVector) {
    vector<int> vectorSumado(5);
    for (int i=0; i<5; i++) {
        vectorSumado[i] = primerVector[i] + segundoVector[i];
    }
    return vectorSumado;
}

void mostrarVectorN5(vector<int> vectorN5) {
    for (int i=0; i<5; i++) {
        cout << vectorN5[i] << "\t";
    }
    cout << endl;
}