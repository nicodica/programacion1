// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 09/09/2025 
// Número de ejercicio: 8

#include <iostream>

using namespace std;

int conversion (int cambio, int dinero);

int main() {
    system("chcp 65001");
    system("cls");

    int dineroAConvertir;
    int dineroConvertido;
    cout << "CONVERSOR DE DINERO" << endl << "Introduzca la cantidad de dinero a convertir: ";
    cin >> dineroAConvertir;

    dineroConvertido = conversion(200,dineroAConvertir);
    cout << "Billetes de 200: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*200;

    dineroConvertido = conversion(100,dineroAConvertir);
    cout << "Billetes de 100: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*100;

    dineroConvertido = conversion(50,dineroAConvertir);
    cout << "Billetes de 50: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*50;

    dineroConvertido = conversion(20,dineroAConvertir);
    cout << "Billetes de 20: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*20;

    dineroConvertido = conversion(10,dineroAConvertir);
    cout << "Billetes de 10: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*10;

    dineroConvertido = conversion(5,dineroAConvertir);
    cout << "Monedas de 5: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*5;

    dineroConvertido = conversion(2, dineroAConvertir);
    cout << "Monedas de 2: " << dineroConvertido << endl;
    dineroAConvertir -= dineroConvertido*2;

    dineroConvertido = conversion(1, dineroAConvertir);
    cout << "Monedas de 1: " << dineroConvertido << endl;

    return 0;
}

int conversion (int cambio, int dinero) {
    int cantidadDineroConvertido;
    if (dinero>=cambio) { //Verifica si el dinero es suficiente para la conversión
        cantidadDineroConvertido = dinero/cambio;
        return cantidadDineroConvertido;
    } else {
        return 0;
    }
}