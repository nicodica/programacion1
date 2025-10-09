// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<double> generarCalificaciones1_100(int nCalificaciones);
double convertirAPorcentaje (double suma, int cantidad);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int N;
    vector<double> calificaciones;
    //rangos
    double nReprobados, nRegulares, nBuenos, nExcelentes = 0.0;

    // Generar calificaciones
    cout << "Ingresa el número de calificaciones a simular: ";
    cin >> N;
    calificaciones = generarCalificaciones1_100(N);

    //Clasificar las calificaciones
    for (int i=0; i<N; i++) {
        if (calificaciones[i] <= 59) {
            nReprobados+=1.0;
        } else if (calificaciones[i]>=60 && calificaciones[i]<=79) {
            nRegulares+=1.0;
        } else if (calificaciones[i]>=80 && calificaciones[i]<=89) {
            nBuenos+=1.0;
        } else {
            nExcelentes+=1.0;
        }
    }

    cout << "CALIFICACIONES" << endl;
    for (int i=0; i<N; i++) {
        cout << calificaciones[i] << "\t";
    }
    cout << endl;

    cout << "Reprobados: " << convertirAPorcentaje(nReprobados,N) << "%" << endl;
    cout << "Regulares: " << convertirAPorcentaje(nRegulares,N) << "%" << endl;
    cout << "Buenos: " << convertirAPorcentaje(nBuenos,N) << "%" << endl;
    cout << "Excelentes: " << convertirAPorcentaje(nExcelentes,N)<< "%" << endl;

    return 0;
}

vector<double> generarCalificaciones1_100(int nCalificaciones) {
    vector<double> calificacionesSimuladas;
    for (int i=0; i<nCalificaciones; i++) {
        calificacionesSimuladas.push_back(rand()%101);
    }
    return calificacionesSimuladas;
}

double convertirAPorcentaje (double suma, int cantidad) {
    if (suma==0.0) {
        return 0.0;
    } else {
    return (suma/cantidad)*100;
    }
}