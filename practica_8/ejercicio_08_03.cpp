// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/10/2025
// Número de ejercicio: 3

#include <iostream>

using namespace std;

int fibonacciRecursiva(int);

int main() {
    system ("chcp 65001");
    system("cls");

    int n;
    cout << "Ingresa qué número de la serie Fibonacci deseas ver: "; //Tomando el primer número como 0
    cin >> n;

    cout << "--> " << fibonacciRecursiva(n);

    return 0;
}

int fibonacciRecursiva(int n) {
    if (n==1) {
        return 1;
    } else if (n==0) {
        return 0;
    } else {
        return fibonacciRecursiva(n-1) + fibonacciRecursiva(n-2);
    }
}