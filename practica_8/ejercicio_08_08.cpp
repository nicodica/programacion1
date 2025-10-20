// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 20/10/2025
// Número de ejercicio: 8

#include <iostream>
#include <vector>

using namespace std;

int conjeturaUllmanRecursiva(int num);

int main() {
    system("chcp 65001");
    system("cls");

    int num;
    vector<int> numeros;
    cout << "Ingresa el número: ";
    cin >> num;

    conjeturaUllmanRecursiva(num);

    return 0;
}

int conjeturaUllmanRecursiva(int num) {
    if (num==1) {
        cout << num; // Imprime el último número 1
        return 1;
    } else {
        cout << num << "\t";
        if (num%2==0) {
            return conjeturaUllmanRecursiva(num/2);
        } else {
            return conjeturaUllmanRecursiva((num*3)+1);
        }
    }
}