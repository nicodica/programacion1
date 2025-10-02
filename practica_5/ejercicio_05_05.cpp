// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>

using namespace std;

vector<int> crearVector(int longitud);
vector<int> combinarVectores(vector<int> vector1, vector<int> vector2);
void mostrarVector(vector<int> vectorMostrado);

int main() {
    system ("chcp 65001");
    system ("cls");

    int N;
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vectorCombinado;
    
    cout << "COMBINACIÓN DE VECTORES" << endl;
    cout << "Introduce el tamaño de los vectores: ";
    cin >> N;

    cout << "Primer vector: " << endl;
    vector1 = crearVector(N);
    cout << "Segundo vector: " << endl;
    vector2 = crearVector(N);

    vectorCombinado = combinarVectores(vector1, vector2);

    mostrarVector(vector1);
    mostrarVector(vector2);
    mostrarVector(vectorCombinado);

    return 0;
}

vector<int> crearVector(int longitud) {
    vector<int> vectorCreado(longitud);
    for (int i=0; i<longitud; i++) {
        cout << "Introducir el " << i+1 << "° elemento: ";
        cin >> vectorCreado[i];
    }
    return vectorCreado;
}

vector<int> combinarVectores(vector<int> vector1, vector<int> vector2) {
    int n1 = vector1.size();
    int n2 = vector2.size();
    vector<int> vectorCombinado;

    //Insertar elementos del primer vector
    for (int i=0; i<n1; i++) {
        vectorCombinado.push_back(vector1[i]);
    }
    //Insertar elementos del segundo vector
    for (int i=0; i<n2; i++) {
        vectorCombinado.push_back(vector2[i]);
    }
    return vectorCombinado;
}

void mostrarVector(vector<int> vectorMostrado) {
    int n = vectorMostrado.size();
    for (int i = 0; i<n; i++) {
        cout << vectorMostrado[i] << "\t";
    }
    cout << endl;
}