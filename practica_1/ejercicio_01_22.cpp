// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 22

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero1;
    int numero2;

    cout << "Ingresa dos números para revisar: " << endl;
    cin >> numero1 >> numero2;

    if (numero2%numero1 == 0){ //Revisar si el segundo es multiplo del primero
        cout << numero2 << " es multiplo de " << numero1 << endl; 
    } else {
        cout << numero2 << " NO es multiplo de " << numero1 << endl;
    }

    if (numero1&numero2 == 0){ // Revisar si el primero es multiplo del segundo
        cout << numero1 << " es multiplo de " << numero2 << endl;
    } else {
        cout << numero1 << " NO es multiplo de " << numero2 << endl;
    }

    return 0;
}
