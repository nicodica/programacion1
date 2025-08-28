// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 15

#include <iostream>

using namespace std;

int main(){
    system ("chcp 65001");
    system ("cls");

    float nota;
    float N;
    float promedio;
    float suma = 0;

    cout << "Ingresa el número de notas a promediar: ";
    cin >> N;

    for (int i=1; i<=N; i++){ // Iniciando desde 1 para poder decirle al usuario en qué número de nota está.
        cout << "Ingresa la " << i << "° nota: ";
        cin >> nota;

        suma += nota;
    }

    promedio = suma/N;
    cout << "El promedio de los " << N << " estudiantes es " << promedio;

    return 0;
}