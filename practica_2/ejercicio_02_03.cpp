// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 3

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int num = (rand()%10)+1; //Generar un número entre 1 y 10
    int nFactorial = 1;

    for (int i=1; i<=num; i++) {
        nFactorial *= i;
    }

    cout << "El factorial de " << num << " es " << nFactorial;
    return 0;
}