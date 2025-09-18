// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/09/2025
// Número de ejercicio: 9

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

float sueldoBasicoMasAntiguedad(float anios);
float numeroVentas();
float comision(float precioProducto, float cantidad);

int main() {
    system ("chcp 65001");
    system ("cls");

    srand(time(NULL));

    int n;
    float nVentas;
    float precioProduct;
    float sueldoTotal;
    float comisionGanada;
    float aniosAntiguedad;

    cout << " COSMÉTICOS " << endl << "Introduzca la cantidad de vendedoras: ";
    cin >> n;

    for (int i=1; i<=n; i++) {
        //Se genera el numero de productos vendidos
        nVentas = numeroVentas();
    
        cout << endl << i << "° VENDEDORA" << endl;
        cout << "Introduzca los años de antigüedad: ";
            cin >> aniosAntiguedad;
        if (nVentas > 0) {
            cout << "Introduzca el precio del producto que vendió: ";
            cin >> precioProduct;

            sueldoTotal = sueldoBasicoMasAntiguedad(aniosAntiguedad);
            comisionGanada = comision (precioProduct,nVentas); 
        } else {
            sueldoTotal = sueldoBasicoMasAntiguedad(aniosAntiguedad);
            comisionGanada = comision(precioProduct,nVentas);
        }

        cout << "SUELDO = " << sueldoTotal << "Bs." << endl;
        cout << "COMISIÓN = " << comisionGanada << "Bs." << endl;
        if (nVentas>0) {
            cout << "SUELDO + COMISIÓN = " << sueldoTotal+comisionGanada << "Bs." << endl;
        }
        cout << "Número de Ventas: " << nVentas << endl;
    }


}

float sueldoBasicoMasAntiguedad(float anios) {
    float sueldoBase = 2750; // Salario mínimo en Bolivia
    //Diganmos que por año se aumenta un 10% del sueldo base
    return sueldoBase+(sueldoBase*0.1);
}

// Número de ventas generado aleatoriamente
float numeroVentas() {
    return rand()%11;
}

float comision(float precioProducto, float cantidad) {
    return (precioProducto*0.1)*cantidad;
}