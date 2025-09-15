// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 2

#include <iostream>
#include <cmath>

using namespace std;

// FUNCIÓN
float calcularVolumen(float radio, float altura);

int main () {
    system ("cls");
    float radioCilindro;
    float alturaCilindro;

    cout << "VOLUMEN DE UN CILINDRO" << endl << "Ingresa el radio (m): ";
    cin >> radioCilindro;
    cout << "Ingresa la altura (m): ";
    cin >> alturaCilindro;

    cout << "El volumen es (m^3)= " << calcularVolumen(radioCilindro,alturaCilindro);

    return 0;
}

float calcularVolumen(float radio, float altura = 10.0) {
    const float pi = 3.1416; //Definir pi como constante para que no cambie
    return pi*(pow(radio,2.0))*(altura);
}