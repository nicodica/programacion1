// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/09/2025
// Número de ejercicio: 1

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int num;
    float n; //Se usa float en n para que al dividir el resultado tenga decimales
    float sumPar = 0.0;
    float frecuenciaPar;

    cout << "Ingresa el número de veces que se lanzará el dado: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        num = (rand()%6) + 1;
        if (num%2==0) {
            sumPar += 1.0;
        }
    }
    
    frecuenciaPar = sumPar/n;
    cout << "La frecuencia de números pares en un dado de 6 caras es de " << frecuenciaPar << " de " << n << ".";
    return 0;
}