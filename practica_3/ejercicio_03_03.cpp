// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 3

#include <iostream>

using namespace std;
bool isCapicua(int num);

int main() {
    system("chcp 65001");
    system("cls");

    int numero;
    cout << "Ingresa el número: ";
    cin >> numero;

    if (isCapicua(numero) == true) {
        cout << "El número " << numero << " es capicúa.";
    } else {
        cout << "El número " << numero << " NO es capicúa.";
    }

    return 0;
}

bool isCapicua(int num){
    int numReves = 0;
    int numAux = num; //Número auxiliar para comparar
    while (num>0) {
        numReves += (num%10);
        numReves *= 10;
        num /= 10;
    }
    numReves /= 10;
    if (numReves == numAux) {
        return true;
    } else {
        return false;
    }
}