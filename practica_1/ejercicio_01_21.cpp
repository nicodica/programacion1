// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 21

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero1;
    int numero2;
    int resultadoSuma = 0;

    cout << "Ingresar dos números para multiplicar: " << endl;
    cin >> numero1 >> numero2;

    for (int i=0; i<numero2; i++){
        resultadoSuma += numero1; // Se suma el número2 las veces que representa el número2
    }

    cout << numero1 << " x " << numero2 << " = " << resultadoSuma;

    return 0;
}
