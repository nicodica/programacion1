// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 04/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> generarVectorString10 ();
vector<int> generarVectorInt10 ();
string mostrarStringRandom(vector<string> vectorString);
int mostrarIntRandom(vector<int> vectorInt);

int main() {
    system ("chcp 65001");
    system ("cls");
    srand (time(NULL));

    vector<string> nombres;
    vector<string> apellidos;
    vector<int> edades;
    int N;

    // Llenar cada vector con 10 elementos
    cout << "NOMBRES" << endl;
    nombres = generarVectorString10();
    cout << "APELLIDOS" << endl;
    apellidos = generarVectorString10();
    cout << "EDADES" << endl;
    edades = generarVectorInt10();

    // Establecer un número de veces a mostrar resultados en pantalla
    cout << "¿Cuántas veces quiere desplegar los nombres, apellidos y edades?: ";
    cin >> N;

    for (int i=0; i<N; i++) {
        cout << endl;
        cout << "NOMBRE: " << mostrarStringRandom(nombres) << endl;
        cout << "APELLIDO: " << mostrarStringRandom(apellidos) << endl;
        cout << "EDAD: " << mostrarIntRandom(edades) << endl;
    }

    return 0;
}

vector<string> generarVectorString10 () {
    vector<string> vectorGenerado;
    string elemento;
    for (int i=0; i<10; i++) {
        cout << "Ingresa el " << i+1 << "° elemento: ";
        getline(cin,elemento);
        vectorGenerado.push_back(elemento);
    }
    cout << endl;
    return vectorGenerado;
}

vector<int> generarVectorInt10 () {
    vector<int> vectorGenerado;
    int elemento;
    for (int i=0; i<10; i++) {
        cout << "Ingresa el " << i+1 << "° elemento: ";
        cin >> elemento;
        vectorGenerado.push_back(elemento);
    }
    cout << endl;
    return vectorGenerado;
}

string mostrarStringRandom(vector<string> vectorString) {
    return vectorString[rand()%10];
}

int mostrarIntRandom(vector<int> vectorInt) {
    return vectorInt[rand()%10];
}