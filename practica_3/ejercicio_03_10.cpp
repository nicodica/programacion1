// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/09/2025 
// Número de ejercicio: 10

#include <iostream>

using namespace std;
double calcularTarifa(double kmRecorridos);
int main() {
    system("chcp 65001");
    system("cls");

    double kmRecorridos;
    cout << "Ingresar la distancia recorrida en kilometros: ";
    cin >> kmRecorridos;
    
    cout << "La tarifa por " << kmRecorridos << "Km es " << calcularTarifa(kmRecorridos) << "Bs.";
    return 0;
}

double calcularTarifa(double kmRecorridos) {
    double tarifa = 10.0; //a 10 bs inciales se le va sumando según el recorrido
    tarifa += kmRecorridos*2.0;
    if (kmRecorridos>10) {
        tarifa -= tarifa*0.1;
    }
    return tarifa;
}