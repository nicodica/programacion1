// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 10

#include <iostream>

using namespace std;

int main(){
    system ("chcp 65001");
    system ("cls");

    short int nota; // SHORT INT para consumir menos memoria
    string calificacion = "a"; // variable para mostrar la calificación

    cout << "Introduzca la nota del estudiante: ";
    cin >> nota;

    if (nota >= 51 && nota <= 100) {
        if (nota < 60){
            calificacion = "C";
        } else if (nota < 70) {
            calificacion = "C+";
        } else if (nota < 80){
            calificacion = "B";
        } else if (nota < 90) {
            calificacion = "B+";
        } else if (nota < 95) {
            calificacion = "A";
        } else if (nota <= 100) {
            calificacion = "A+";
        }

        cout << "La calificación del estudiante es " << calificacion << ".";
    } else {
        if (nota < 0 || nota > 100) {
            cout << "Nota inválida.";
        } else {
            cout << "El estudiante ha reprobado.";
        }
    }
    return 0;
}