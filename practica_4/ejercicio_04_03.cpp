// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 3

#include <iostream>

using namespace std;

void ModificarValores(int valor1, int &valor2);

int main() {
    system ("chcp 65001");
    system ("cls");
    int num1, num2;

    cout << "Ingresar el primer parámetro (por valor): ";
    cin >> num1;
    cout << "Ingresar el segundo parámetro (por referencia): ";
    cin >> num2;

    ModificarValores(num1,num2);

    cout << "NUEVOS VALORES" << endl;
    cout << "1° " << num1 << " --> NO cambia" << endl;
    cout << "2° " << num2 << " --> SÍ cambia" << endl;
    return 0;
}

void ModificarValores(int valor1, int &valor2) {  //El valor 2 es el único que cambia por referencia
    valor1 *= 2;
    valor2 +=10; 
}