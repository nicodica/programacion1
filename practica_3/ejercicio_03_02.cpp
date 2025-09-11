// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 2

#include <iostream>
using namespace std;
float celsius_a_fahrenheit(float celsius);

int main() {
    system("chcp 65001");
    system("cls");

    float gradosCelsius;

    cout << "CELSIUS A FAHRENHEIT" << endl << "Ingresa los grados en Celsius: ";
    cin >> gradosCelsius;

    cout << gradosCelsius << "°C = " << celsius_a_fahrenheit(gradosCelsius) << "°F";

    return 0;
}

float celsius_a_fahrenheit(float celsius) { //función en float por si se necesita decimales
    float fahrenheit = celsius + 32.0;
    return fahrenheit;
}