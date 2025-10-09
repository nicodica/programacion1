// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>

using namespace std;

vector<int> llenarVectorInt (int numeroElementos);
vector<int> rotarVectorKElementosDerecha (vector<int> VectorOriginal, int numeroElementos, int numeroEspaciosRotados);
void mostrarVectorInt(vector<int> vectorMostrado);

int main() {
    system ("chcp 65001");
    system("cls");

    vector<int> numerosOriginal;
    vector<int> numerosRotado;
    int N;
    int K;

    cout << "Ingrese cuántos elementos tendrá su vector: ";
    cin >> N;
    numerosOriginal = llenarVectorInt(N); //Se llena el vector con los elementos
    mostrarVectorInt(numerosOriginal);

    cout << endl << "Ingrese cuantos espacios quiere recorrer el vector: ";
    cin >> K;
    numerosRotado = rotarVectorKElementosDerecha(numerosOriginal,N,K);
    mostrarVectorInt(numerosRotado);

    return 0;
}

vector<int> llenarVectorInt (int numeroElementos) {
    vector<int> vectorLleno;
    int elemento;
    for (int i=0; i<numeroElementos; i++) {
        cout << "Ingrese el " << i+1 << "° entero: ";
        cin >> elemento;
        vectorLleno.push_back(elemento);
    }
    return vectorLleno;
}


vector<int> rotarVectorKElementosDerecha (vector<int> VectorOriginal, int numeroElementos, int numeroEspaciosRotados) {
    vector<int> vectorRotado(numeroElementos);
    for (int i=0; i<numeroElementos; i++) {
        vectorRotado[(i+numeroEspaciosRotados)%numeroElementos] = VectorOriginal[i];
    }


    /*for (int i=0; i<numeroEspaciosRotados; i++) {
        vectorRotado.push_back(VectorOriginal[i+numeroEspaciosRotados]);
    }
    for (int i=0; i<(numeroElementos-numeroEspaciosRotados); i++) {
        vectorRotado.push_back(VectorOriginal[i]);
    } */

    /*for (int i=0; i<numeroElementos; i++) {
        if (encontrarIndiceInt(VectorOriginal, VectorOriginal[i]) < (numeroElementos-numeroEspaciosRotados)) {
            vectorRotado.push_back(VectorOriginal[i+numeroEspaciosRotados]);
        } else {
            vectorRotado.push_back(VectorOriginal[i-numeroEspaciosRotados]);
        }
    }*/
    return vectorRotado;
}

void mostrarVectorInt(vector<int> vectorMostrado) {
    for (int i=0; i<vectorMostrado.size(); i++) {
        cout << vectorMostrado[i] << "\t";
    }
    cout << endl;
}