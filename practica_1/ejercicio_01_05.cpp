// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 5

//Grados centígrados a Kelvin

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system ("cls");
    float gradosC = 0;
    float gradosK = 0;
    
    cout << "CONVERSOR DE GRADOS CENTÍGRADOS A KELVIN" << endl << "Ingresa los grados centígrados: "; //Título para indicar el tipo de conversor
    cin >> gradosC;
    gradosK = gradosC + 273.15;

    cout << gradosC << "°C es igual a " << gradosK << "°K.";
    return 0;
}
