// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 3

//Calcular el área de un triángulo pidiendo del usuario la base y la altura

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");
    int base = 0;
    int altura = 0;
    int area;

    cout << "ÁREA DE UN TRIÁNGULO ^_^" << endl << "Ingresa la base del triángulo: ";
    cin >> base;
    cout << "Ingresa la altura del triángulo: ";
    cin >> altura;

    area = (base*altura)/2;
    cout << "El area del triángulo con base " << base << " y altura " << altura << " es " << area;
    return 0;
}