// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>

using namespace std;

vector<string> encontrarNombresRepetidos(vector<string> vector1, vector<string> vector2);
void mostrarVectorStr (vector<string> vectorMostrado);


int main() {
    system("chcp 65001");
    system("cls");
    
    vector<string> listaA = {"Juan", "María", "Pedro", "Ana", "Luis"};
    vector<string> listaB = {"Ana", "Carlos", "Pedro", "Sofía", "Luis"};
    vector<string> nombreRepetidos;
    
    nombreRepetidos = encontrarNombresRepetidos(listaA, listaB);

    cout << "LISTA 1: ";
    mostrarVectorStr(listaA);
    cout << "LISTA 2: ";
    mostrarVectorStr(listaB);
    cout << "NOMBRES REPETIDOS: ";
    mostrarVectorStr(nombreRepetidos);

    return 0;
}

vector<string> encontrarNombresRepetidos(vector<string> vector1, vector<string> vector2) {
    vector<string> nombresRepetidos;
    int longitudMayor;
    vector<string> vectorMayor;
    vector<string> vectorMenor;
    string nombreBuscado; // Variable que se va a comparar entre los dos vectores para ver si está repetida

    // Encontrar el vector de mayor longitud si es que no son iguales
    if (vector1.size() > vector2.size()) {
        longitudMayor = vector1.size();
        vectorMayor = vector1;
        vectorMenor = vector2;
    } else { // si el vector 2 es mayor o son iguales
        longitudMayor = vector2.size();
        vectorMayor = vector2;
        vectorMenor = vector1; 
    }
    // recorrer vectores y buscar repetidos
    for (int i=0; i<longitudMayor; i++) {
        nombreBuscado = vectorMayor[i];
        for (int j=0; j<vectorMenor.size(); j++) { //Recorrido para el vector menor
            if (nombreBuscado == vectorMenor[j]) {
                nombresRepetidos.push_back(nombreBuscado);
            }
        }
    }
    return nombresRepetidos;
}

void mostrarVectorStr (vector<string> vectorMostrado) {
    for (int i=0; i<vectorMostrado.size(); i++) {
        cout << vectorMostrado[i] << "\t";
    }
    cout << endl;
}