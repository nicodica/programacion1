// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 6

#include <iostream>

using namespace std;

bool esPrimo(int);
int sumaDigitos(int);

int main () {
    system("chcp 65001");
    system("cls");

    int numero;
    int sumaDeDigitos;
    cout << "Ingresa un número entero: ";
    cin >> numero;

    sumaDeDigitos = sumaDigitos(numero);

    if (esPrimo(sumaDeDigitos) == true) {
        cout << "La suma de los dígitos del número " << numero << " es " << sumaDeDigitos << " y es primo.";
    } else {
        cout << "La suma de los dígitos del número " << numero << " es " << sumaDeDigitos << " y NO es primo.";
    }

    return 0;
}

bool esPrimo(int num) {
    int contDivisores = 0;
    for (int i=1; i<=num; i++) {
        if (num%i==0) {
            contDivisores++;
        }
    }    
    if (contDivisores==2) {
            return true;
        } else {
            return false;
        }
}

int sumaDigitos(int num) {
    int suma = 0;
    int ultDig;
    while (num>0) {
        ultDig = num%10;
        suma += ultDig;
        num /= 10; //Reduce el número un dígito a la vez
    }
    return suma;
}