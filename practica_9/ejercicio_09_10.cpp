// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 6/11/2025
// Número de ejercicio: 10

#include <iostream>
#include <vector>

using namespace std;

struct Fraccion{
    int numerador;
    int denominador;
};

int MCD (int n1, int n2);
Fraccion reducirFraccion (Fraccion fraccionOriginal);

int main() {
    system("chcp 65001");
    system("cls");

    Fraccion fraccion;
    Fraccion fraccionSimplificada;

    cout << "Introduce el numerador: ";
    cin >> fraccion.numerador;
    cout << "Introduce el denominador: ";
    cin >> fraccion.denominador;

    fraccionSimplificada = reducirFraccion(fraccion);

    cout << fraccion.numerador << "/" << fraccion.denominador << " --> ";
    cout << fraccionSimplificada.numerador << "/" << fraccionSimplificada.denominador << endl;
    
    return 0;
}

int MCD (int n1, int n2) {
    int res = 1;
    while (res != 0) {
        res = n1%n2;
        n1 = n2;
        n2 = res;
    }
    return n1;
}

Fraccion reducirFraccion (Fraccion fraccionOriginal) {
    Fraccion fraccionSimple;
    int mcd = MCD(fraccionOriginal.numerador, fraccionOriginal.denominador);

    fraccionSimple.numerador = fraccionOriginal.numerador/mcd;
    fraccionSimple.denominador = fraccionOriginal.denominador/mcd;

    return fraccionSimple;
}