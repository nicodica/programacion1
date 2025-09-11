// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 08/09/2025 
// Número de ejercicio: 7

#include <iostream>
#include <cstdlib> //Importar librerías para generar números aleatorios
#include <ctime>

using namespace std;

bool mayor18(int edad);
bool mayor175cm(float altura);
void edad_estatura();

int main() {
    system("chcp 65001");
    system("cls");
    edad_estatura();
    return 0;
}

bool mayor18(int edad) {
    if (edad>18) {
        return true;
    } else {
        return false;
    }
}

bool mayor175cm(float altura) {
    if (altura>175) {
        return true;
    } else {
        return false;
    }
}

void edad_estatura() { //función que no devolverá nada, pero pedirá los datos y mostrará los resultados en pantalla
    srand(time(NULL));
    int n;
    int edad;
    float estatura;
    int sumEdad = 0;
    float sumEstatura = 0.0;
    int nGente18 = 0;
    int nMayora175cm = 0;

    cout << "Ingresar el número de estudiantes: ";
    cin >> n;
    for (int i=1; i<=n; i++) {
        edad = (rand()%35) + 1;
        estatura = (rand()%(200-120+1)) + 120;

        cout << i << "° estudiante: " << edad << " años y " << estatura << "cm." << endl;

        sumEdad += edad;
        sumEstatura += estatura;

        if (mayor18(edad)) {
            nGente18 += 1;
        }

        if (mayor175cm(estatura)) {
            nMayora175cm += 1;
        }
    }
    cout << "Edad media: " << sumEdad/n << endl;
    cout << "Estatura media: " << sumEstatura/n << endl;
    cout << "Gente mayor a 18 años: " << nGente18 << endl;
    cout << "Gente que mide más de 175 cm: " << nMayora175cm << endl;
}