// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 27/08/2025
// Número de ejercicio: 17

#include <iostream>

using namespace std;

int main(){
    system("chcp 65001");
    system("cls");

    int numero1;
    int numero2;
    int sumaDivisores = 0;

    cout << "Ingresa dos números: " << endl;
    cin >> numero1 >> numero2;

    for (int i=1; i<=numero1; i++){
        if (numero1%i == 0 && numero1 != i){ // Se descartan no divisores y el propio número
            sumaDivisores += i;
        }
    }

    if (sumaDivisores == numero2){
        cout << "Los números " << numero1 << " y " << numero2 << " son amigos.";
    } else {
        cout << "Los números " << numero1 << " y " << numero2 << " no son amigos.";
    }

    return 0;
}