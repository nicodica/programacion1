// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 4

#include <iostream>
#include <cmath> //Importar librería c math para usar pow()

using namespace std;

float IMC(float peso, float altura);

int main() {
    system ("chcp 65001");
    system ("cls");
    float peso;
    float altura;

    cout << "Ingresa el peso en kilogramos: ";
    cin >> peso;
    cout << "Ingresa la altura en metros: ";
    cin >> altura;

    cout << "IMC = " << IMC(peso,altura);
    return 0;
}

float IMC(float pesoKg, float alturaM) {
    float imc = pesoKg/(pow(alturaM,2));
    return imc;
}