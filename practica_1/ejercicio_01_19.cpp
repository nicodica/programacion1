// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 19

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero;

    cout << "Ingresar un número: ";
    cin >> numero;
    
    cout << "TABLA DE MULTIPLICAR DEL NÚMERO " << numero << endl;
    for (int i=1; i<=10; i++){

        cout << numero << " x " << i << " = " << numero*i << endl; // Para que se vea con formato de tabla
    }
    return 0;
}