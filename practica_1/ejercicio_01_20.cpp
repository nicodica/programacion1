// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 20

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero;
    int contadorDigitos = 0;

    cout << "Ingresa un número entero: ";
    cin >> numero;
    int auxNum = numero; //Auxiliar para mostrar resultado

    while (numero>0) {
        numero /= 10; //Se reduce el valor del número
        contadorDigitos += 1;
    }

    if (contadorDigitos != 1){
        cout << "El número " << auxNum << " tiene " << contadorDigitos << " dígitos.";
    } else {
        cout << "El número " << auxNum << " tiene " << contadorDigitos << " dígito";
    }
    return 0;
}