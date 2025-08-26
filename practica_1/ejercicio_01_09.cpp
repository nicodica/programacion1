// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 9

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");
    short int edad = 0;
    string clasificacion = ""; // Determinar una variable para clasificar al ususario según su edad

    cout << "Ingrese su edad: ";
    cin >> edad;

    if (edad <= 0){ // Si el usuario llega ingresar cero o un número negativo para su edad.
        cout << "Edad inválida";
    } else {
        if (edad <= 12){
            clasificacion = "niño";
        } else if (edad <= 18) {
            clasificacion = "adolescente";
        } else if (edad > 18 && edad < 60) {
            clasificacion = "mayor de edad";
        } else if (edad >= 60) {
            clasificacion = "adulto mayor";
        }
        cout << "El usuario es " << clasificacion << ".";
    }
    return 0;
}