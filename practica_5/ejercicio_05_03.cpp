// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 01/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double sumaCalificaciones(vector<double> vectorCalificaciones);
double promedioCalificaciones(double suma, int n);
vector<double> LlenarVectorDesviaciones(vector<double> vectorCalificaciones, double promedio);
double calcularVarianza(vector<double> vectorDesviaciones);

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    double nota;
    double sumaDeNotas;
    double promedioDeNotas;
    double varianza;
    vector<double> calificaciones;
    vector<double> desviaciones;

    cout << "CALIFICACIONES" << endl << "Introduce el número de calificaciones: ";
    cin  >> N;

    //Introducir notas al vector
    for (int i=0; i<N; i++) {
        cout << "Introduce la " << i+1 << "° nota: ";
        cin >> nota;
        calificaciones.push_back(nota);
    }

    //Suma
    sumaDeNotas = sumaCalificaciones(calificaciones);

    //Promedio
    promedioDeNotas = promedioCalificaciones(sumaDeNotas,N);
    
    //Desviaciones
    desviaciones = LlenarVectorDesviaciones(calificaciones, promedioDeNotas);

    //Varianza
    varianza = calcularVarianza(desviaciones);

    // Imprimir resultados
    cout << endl;
    cout << "Suma = " << sumaDeNotas << endl;
    cout << "Promedio = " << promedioDeNotas << endl;
    cout << "Calificaciones \t Desviaciones" << endl;
    for (int i=0; i<N; i++) {
        cout << "     " << calificaciones[i] << " \t \t" << desviaciones[i] << endl;
    }
    cout << "Varianza = " << varianza;

    return 0;
}


double sumaCalificaciones(vector<double> vectorCalificaciones) {
    int n = vectorCalificaciones.size(); //Obtener la número de elementos en el Vector
    double sumCalificaciones = 0;

    for (int i=0; i<n; i++) {
        sumCalificaciones += vectorCalificaciones[i];
    }

    return sumCalificaciones;
}

double promedioCalificaciones(double suma, int n) {
    return suma/n;
}

vector<double> LlenarVectorDesviaciones(vector<double> vectorCalificaciones, double promedio) {
    int n = vectorCalificaciones.size();
    vector<double> vectorDesviaciones;
    for (int i=0; i<n; i++) {
        vectorDesviaciones.push_back(vectorCalificaciones[i]-promedio);
    }
    return vectorDesviaciones;
}

double calcularVarianza(vector<double> vectorDesviaciones) {
    int numeroDesviaciones = vectorDesviaciones.size();
    double SumaDesviacionesCuadradas = 0;
    for (int i=0; i<numeroDesviaciones; i++) {
        SumaDesviacionesCuadradas += pow(vectorDesviaciones[i],2);
    }

    return SumaDesviacionesCuadradas/numeroDesviaciones;
}

