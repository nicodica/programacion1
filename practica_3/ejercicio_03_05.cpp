// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 5

#include <iostream>
#include <ctime>

using namespace std;

float promedioPonderado(float nota1, float nota2, float nota3, float nota4);

int main() {
    system ("chcp 65001");
    system ("cls");
    srand (time(NULL));

    float nota1 = rand()%101;
    float nota2 = rand()%101;
    float nota3 = rand()%101;
    float nota4 = rand()%101;

    cout << "NOTAS PARCIALES" << endl;
    cout << "1° Nota: " << nota1 << endl << "2° Nota: " << nota2 << endl << "3° Nota: " << nota3 << endl << "4° Nota: " << nota4 << endl;
    cout << "NOTA FINAL: " << promedioPonderado(nota1,nota2,nota3,nota4) << "/100";

    return 0;
}

float promedioPonderado(float nota1, float nota2, float nota3, float nota4) {
    nota1 *= 10.0;
    nota2 *= 20.0;
    nota3 *= 30.0;
    nota4 *= 40.0;

    float suma = nota1 + nota2 + nota3 + nota4;
    return suma/100.0; //Se adapta el promedio a la nota sobre 100
}