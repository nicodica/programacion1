// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 2

#include <iostream>

using namespace std;

int main(){
    system("cls");
    int variable1 = 0; 
    int variable2 = 0;
    cout << "Valor inicial de Variable1 = " << variable1 << endl;
    cout << "Valor inicial de Variable2 = " << variable2 << endl;
    cout << endl << "Ingresa un nuevo valor para la Variable1: "; // endl para agregar una separación
    cin >> variable1;
    cout << "Ingresa un nuevo valor para la Variable2: ";
    cin >> variable2;
    cout << endl << "Nuevo valor de la Variable1: " << variable1 << endl << "Nuevo valor de la Variable2: " << variable2;

    return 0;
}