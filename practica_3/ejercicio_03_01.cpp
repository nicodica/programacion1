// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 1

#include <iostream>

using namespace std;

bool esPar(int numero);

int main() {
    system ("chcp 65001");
    system ("cls");

    int num;
    cout << "¿ES PAR O IMPAR?" << endl;
    cout << "Ingresa un número: ";
    cin >> num;

    if (esPar(num)) {
        cout << "El número " << num << " es par.";
    } else {
        cout << "El número " << num << " es impar.";
    }

    return 0;
}

bool esPar(int numero) { //Función que devuelve un valor boolenao
    bool par;
    if (numero%2 == 0) {
        par = true;
    } else {
        par = false;
    }
    return par;
}