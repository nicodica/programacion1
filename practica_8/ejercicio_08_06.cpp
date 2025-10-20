// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>

using namespace std;

vector<int> llenarVectorInt (int cantidad);
bool sonIgualesRecursiva (vector<int> v1, vector<int> v2, int indice);

int main() {
    system("chcp 65001");
    system("cls");

    int n1;
    vector<int> v1;
    int n2;
    vector<int> v2;
    bool comprobante;
    vector<int> aux;

    cout << "Ingrese la longitud del primer vector: ";
    cin >> n1;
    v1 = llenarVectorInt(n1);
    cout << "Ingrese la longitud del segundo vector: ";
    cin >> n2;
    v2 = llenarVectorInt(n2);

    if (n1<n2) { //Cambiar de lugar los vectores por si el primero es más pequeño
        aux = v1;
        v1 = v2;
        v2 = aux;
    }

    comprobante = sonIgualesRecursiva(v1, v2, 0);

    if (comprobante==true) {
        cout << "Los vectores son iguales" << endl;
    } else {
        cout << "Los vectores no son iguales." << endl;
    }

    return 0;
}

vector<int> llenarVectorInt (int cantidad) {
    vector<int> vectorInt;
    int num;
    for (int i=0; i<cantidad; i++) {
        cout << "Ingrese el " << i << "° entero: ";
        cin >> num;
        vectorInt.push_back(num);
    }
    return vectorInt;
}

bool sonIgualesRecursiva (vector<int> v1, vector<int> v2, int indice) {
    if (v1.size() != v2.size()) {
        return false;
    }
    if (indice == v1.size() && v1[indice]==v2[indice]) {
        return true;
    }

    if (v1[indice]== v2[indice]) {
        return sonIgualesRecursiva(v1, v2, indice+1);
    } else {
        return false;
    }

}