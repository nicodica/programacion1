// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 13

#include <iostream>

using namespace std;

int main(){
    system ("chcp 65001");
    system ("cls");
    int N;
    int suma = 0;

    cout << "Ingresa un número: ";
    cin >> N;

    for (int i = 1; i<=N; i++) { // Inicializar i desde 1 para empezar a sumar
        suma += i;
    }

    cout << "RESULTADO = " << suma;

    return 0;
}