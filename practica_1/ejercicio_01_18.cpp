// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 18

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int contadorPrimos = 0;
    int numeros = 1; // Para mostrar los números primos

    while (contadorPrimos < 100) { // Como empieza del 0, debe ser menor a 100
        int contDivisores = 0; //Se vuelve a inicializar en 0 al contador de divisores en cada vuelta

        for (int i=1; i<=numeros; i++) {
            if (numeros%i == 0) {
                contDivisores += 1;
            }
        }
        if (contDivisores == 2) {
            contadorPrimos += 1;
            cout << numeros << " - ";
        }

        numeros += 1;
    }
    return 0;
}