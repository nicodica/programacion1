// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 1

#include <iostream>

using namespace std;

void intercambiarValores(int &num1, int &num2);
int main() {
    system ("cls");
    int n1, n2;

    cout << "INTERCAMBIO DE VALORES" << endl << "Ingresa el primer valor: ";
    cin >> n1;
    cout << "Ingresa el segundo valor: ";
    cin >> n2;

    cout << "VALORES INICIALES" << endl << "Valor 1: " << n1 << endl << "Valor 2: " << n2 << endl;
    intercambiarValores(n1,n2);
    cout << "VALORES INTERCAMBIADOS" << endl << "Valor 1: " << n1 << endl << "Valor 2: " << n2;
    return 0;
}

void intercambiarValores(int &num1, int &num2) {
    int aux; 
    aux = num1;    //Auxiliar almacena el valor 1
    num1 = num2;  // Se da el valor de 2 a 1
    num2 = aux;   // El valor 2 agarra el antiguo valor de 1 desde el auxiliar
}