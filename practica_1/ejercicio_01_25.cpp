// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 25

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero;
    char eleccion = 's'; //Empieza en sí



    while (eleccion != 'n'){
        cout << "Ingresa un número: ";
        cin >> numero;

        cout << "TABLA DEL " << numero << endl;

        for (int i=1; i<=10; i++) {
            cout << numero << " x " << i << " = " << numero*i << endl;
        } 
        cout << endl; //Dar un espacio para mejor lectura
        cout << "¿Desea continuar? (s/n)" << endl;
        cin >> eleccion;
    }
    return 0;
}