// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 11

#include <iostream>

using namespace std;

int main(){
    system ("chcp 65001");
    system ("cls");

    short int mesNumero;
    string mesLiteral;

    cout << "-- MESES --" << endl << "Ingresa un número del 1 al 12: ";
    cin >> mesNumero;

    if (mesNumero < 13 && mesNumero > 0) { // Verificar que no se pase del rango 1-12
        if (mesNumero == 1) {
            mesLiteral = "Enero";
        } else if (mesNumero == 2) {
            mesLiteral = "Febrero";
        } else if (mesNumero == 3) {
            mesLiteral = "Marzo";
        } else if (mesNumero == 4) {
            mesLiteral = "Abril";
        } else if (mesNumero == 5) {
            mesLiteral == "Mayo";
        } else if (mesNumero == 6) {
            mesLiteral = "Junio";
        } else if (mesNumero == 7) {
            mesLiteral = "Julio";
        } else if (mesNumero == 8) {
            mesLiteral = "Agosto";
        } else if (mesNumero == 9) {
            mesLiteral = "Septiembre";
        } else if (mesNumero == 10) {
            mesLiteral = "Octubre";
        } else if (mesNumero == 11) {
            mesLiteral = "Noviembre";
        } else if (mesNumero == 12) {
            mesLiteral = "Diciembre";
        }
        cout << mesLiteral;

    } else {
        cout << "Número de mes inválido.";
    }
    return 0;
}