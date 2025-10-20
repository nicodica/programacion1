// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/10/2025
// Número de ejercicio: 1

#include <iostream>

using namespace std;

int sumaDigitosRecursiva (int numero);

int main () {
    system("chcp 65001");
    system("cls");

    int numero;
    int sumDig;

    cout << "Introduzca el número a sumar: ";
    cin >> numero;

    sumDig = sumaDigitosRecursiva(numero);
    cout << "La suma de sus dígitos es: " << sumDig << endl;
    return 0;
}

int sumaDigitosRecursiva (int numero) {
    // caso base
    if (numero==0) {
        return 0;
    } else if (numero==1) {
        return 1;
    }
    return numero%10 + sumaDigitosRecursiva(numero/10);
}