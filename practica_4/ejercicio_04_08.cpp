// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/09/2025
// Número de ejercicio: 8

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

float precioFacturado (float precio);
float descuento (float precio);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int n;
    float precioProducto;
    float precioMasIVA;
    float sumaTotal = 0;
    float pagoIVA = 0;

    cout << "LA ESTRELLA" << endl << "Ingrese la cantida de productos vendidos: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        precioProducto = (rand()%(50-20+1))+20; //Precio entre 20 y 50 Bs.
        precioMasIVA = precioFacturado(precioProducto);

        pagoIVA += (precioMasIVA - precioProducto);
        sumaTotal += precioMasIVA;
    }

    if (sumaTotal>2500.0) {
        sumaTotal -= descuento(sumaTotal);
    }

    cout << "Productos vendidos: " << n << endl;
    cout << "Monto Ganado: " << sumaTotal << " Bs." << endl;
    cout << "Pago de IVA a Impuestos Nacionales: " << pagoIVA << " Bs." << endl;

    return 0;
}

float precioFacturado (float precio) {
    return precio+(precio*0.13); //IVA del 13% para cada producto
}

float descuento (float suma) {
    return suma-(suma*0.05); //Descuento del 5% para precio final
}
