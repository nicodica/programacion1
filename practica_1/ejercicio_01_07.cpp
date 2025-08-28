// Materia: Programación I, Paralelo 4
// Autor: Willy Edwin Tenorio Palza
// Carnet: 10901243 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 7

#include <iostream>

using namespace std;

int main(){
    
    system("chcp 65001");
    system("cls");

    char letra = 'a'; //Se inicializa la letra con una "a" momentaria
    cout << "Ingresa una letra: ";
    cin >> letra;
    
    if ((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')) {
        if  (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || 
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
            cout << "La letra " << letra << " es una vocal.";
        } else {
            cout << "La letra " << letra << " es una consonante.";
        }
    } else {
        cout << letra << " es un caracter es especial";
    }
    return 0;
}