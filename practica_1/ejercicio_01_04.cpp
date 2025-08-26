// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

int main(){
    system("cls");
    float radio = 0.0;
    float volumen = 0.0;
    float pi = 3.1416; //constante pi

    cout << "VOLUMEN DE UNA ESFERA :]" << endl << "Ingresa el radio de la esfera: ";
    cin >> radio;
    volumen = (4.0/3.0)*pi*(radio*radio*radio); //Se multiplica radio tres veces en lugar de usar exponente pow()

    cout << "El volumen de la esfera es " << volumen;

    return 0;
}