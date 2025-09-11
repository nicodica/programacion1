// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 10/09/2025 
// Número de ejercicio: 9

#include <iostream>

using namespace std;

float horasExtraoMenosTrabajo (float minutosTrabajados);
void imprimirHoras();

int main() {
    system("chcp 65001");
    system("cls");
    imprimirHoras(); //Llamar la función
    return 0;
}

float horasExtraoMenosTrabajo (float minutosTrabajados) {
    return (minutosTrabajados/60.0)-8.0;
}

void imprimirHoras() {
    float minutosTr;
    float horasExtra;
    cout << "Ingrese la cantidad de minutos trabajados: ";
    cin >> minutosTr;
    horasExtra = horasExtraoMenosTrabajo(minutosTr);

    if (horasExtra>0) {
        cout << "Trabajó " << horasExtra << " horas extra." << endl;
    } else if (horasExtra==0) {
        cout << "Trabajó exactamente 8 horas.";
    } else {
        cout << "Debe " << (-1)*horasExtra << " horas de trabajo." << endl; //Se coloca *(-1) para volver a la deuda positiva en pantalla
    }
}