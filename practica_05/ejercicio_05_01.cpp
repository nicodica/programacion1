// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

double generarRandomDouble(double minimo, double maximo);

void mostrarVectorDouble (vector<double> vectorMostrado);
void mostrarVectorInt (vector<int> vectorMostrado);
void mostrarVectorChar (vector<char> vectorMostrado);

vector<double> generar100Voltajes();
vector<double> generar50Temperaturas();
vector<char> generar30CaracteresAlfanumericos();
vector<int> generar100Anios();
vector<double> generar32Velocidades();
vector<double> generar1000Distancias();


int main() {
    system ("chcp 65001");
    system ("cls");
    srand(time(NULL));

    vector<double> voltajes;
    vector<double> temperaturas;
    vector<char> caracteresAlfanumericos;
    vector<int> anios;
    vector<double> velocidades;
    vector<double> distancias;

    voltajes = generar100Voltajes();
    temperaturas = generar50Temperaturas();
    caracteresAlfanumericos = generar30CaracteresAlfanumericos();
    anios = generar100Anios();
    velocidades = generar32Velocidades();
    distancias = generar1000Distancias();

    cout << "Voltajes:" << endl;
    mostrarVectorDouble(voltajes);
    cout << endl;

    cout << "Temperaturas:" << endl;
    mostrarVectorDouble(temperaturas);
    cout << endl;

    cout << "Caracteres Alfanuméricos:" << endl;
    mostrarVectorChar(caracteresAlfanumericos);
    cout << endl;

    cout << "Años:" << endl;
    mostrarVectorInt(anios);
    cout << endl;

    cout << "Velocidades:" << endl;
    mostrarVectorDouble(velocidades);
    cout << endl;

    cout << "Distancias:" << endl;
    mostrarVectorDouble(distancias); 
    cout << endl;

    return 0;
}


// FUNCIONES

double generarRandomDouble(double minimo, double maximo) {
    double numeroRandom = ((((double) rand())/RAND_MAX)*(maximo-minimo))+minimo; //Fórmula para generar números aleatorios double
    return numeroRandom;
}

vector<double> generar100Voltajes() {
    vector<double> voltajes;
    double voltaje;
    for (int i=0; i<100; i++) {
        voltaje = generarRandomDouble(20.0,220.0);
        voltajes.push_back(voltaje);
    }
    return voltajes;
}

vector<double> generar50Temperaturas() {
    vector<double> temperaturas;
    for (int i=0; i<50; i++) {
        temperaturas.push_back(generarRandomDouble(0.0, 100.0));
    }
    return temperaturas;
}

vector<char> generar30CaracteresAlfanumericos() {
    vector<char> caracteres;
    char caracter;
    int contador = 0;
    while (contador<30) {
        caracter = (rand()%(122-48+1))+48;
        if ((caracter>=48 && caracter<=57) || (caracter>=65 && caracter<=90) || (caracter>=97 && caracter<=122)) {
            caracteres.push_back(caracter);
            contador++;
        }
    }
    return caracteres;
}

vector<int> generar100Anios() {
    vector<int> anios;
    for (int i=0; i<100; i++) {
        anios.push_back((rand()%(2025-1990+1))+1990);
    }
    return anios;
}

vector<double> generar32Velocidades() {
    vector<double> velocidades;
    for (int i=0; i<32; i++) {
        velocidades.push_back(generarRandomDouble(10.0, 300.0));
    }
    return velocidades;
}

vector<double> generar1000Distancias() {
    vector<double> distancias;
    for (int i=0; i<1000; i++) {
        distancias.push_back(generarRandomDouble(1.0, 1000.0));
    }
    return distancias;
}




void mostrarVectorDouble (vector<double> vectorMostrado) {
    int n = vectorMostrado.size();
    for (int i=0; i<n; i++) {
        cout << vectorMostrado[i] << " - ";
    }
    cout << endl;
}

void mostrarVectorInt (vector<int> vectorMostrado) {
    int n = vectorMostrado.size();
    for (int i=0; i<n; i++) {
        cout << vectorMostrado[i] << " - ";
    }
    cout << endl;
}

void mostrarVectorChar (vector<char> vectorMostrado) {
    int n = vectorMostrado.size();
    for (int i=0; i<n; i++) {
        cout << vectorMostrado[i] << " - ";
    }
    cout << endl;
}