// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <vector>

using namespace std;

struct AlumnoNotas {
    float T1;
    float T2;
    float T3;
    float T4;
    float EF;
    float notaFinal;
};

AlumnoNotas registrarNotas ();
float calcularNotaFinal (float n1, float n2, float n3, float n4, float fin);
void mostrarNotasFinales(vector<AlumnoNotas> notas);
float calcularPromedio(vector<AlumnoNotas> notas);
int encontrarIndiceMayorNota(vector<AlumnoNotas> notas);
int encontrarIndiceMenorNota(vector<AlumnoNotas> notas);


int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<AlumnoNotas> notasColeccion;
    float promedioNotas; // total
    int indexNotaMaxima; // De la nota final de todos los alumnos;
    int indexNotaMinima; // De todos los alumnos

    cout << "Ingrese el número de Alumnos: ";
    cin >> N;

    for (int i=0; i<N; i++) {
        cout << i+1 << "° ALUMNO" << endl;
        notasColeccion.push_back(registrarNotas());
        cout << endl;
    }
    
    mostrarNotasFinales(notasColeccion);

    //Promedio
    promedioNotas = calcularPromedio(notasColeccion);
    cout << "=== Promedio ===" << endl << promedioNotas << endl;

    //Maxima nota
    indexNotaMaxima = encontrarIndiceMayorNota(notasColeccion);
    cout << "=== MAYOR NOTA ===" << endl;
    cout << notasColeccion[indexNotaMaxima].notaFinal << endl;

    //Minima nota
    indexNotaMinima = encontrarIndiceMenorNota(notasColeccion);
    cout << "=== MENOR NOTA ===" << endl;
    cout << notasColeccion[indexNotaMinima].notaFinal << endl;

    return 0;
}

AlumnoNotas registrarNotas () {
    AlumnoNotas notas;
    cout << "1° Parcial: ";
    cin >> notas.T1;
    cout << "2° Parcial: ";
    cin >> notas.T2;
    cout << "3° Parcial: ";
    cin >> notas.T3;
    cout << "4° Parcial: ";
    cin >> notas.T4;
    cout << "Evaluación Final: ";
    cin >> notas.EF;
    // Nota final
    notas.notaFinal = calcularNotaFinal(notas.T1,notas.T2,notas.T3,notas.T4,notas.EF);

    return notas;
}

float calcularNotaFinal (float n1, float n2, float n3, float n4, float fin) {
    float NP; //parcial
    float NF; //final
    NP = (n1+n2+n3+n4)/4;
    NF = 0.7*NP + 0.3*fin;
    return NF;
}

void mostrarNotasFinales(vector<AlumnoNotas> notas) {
    cout << "=== NOTAS FINALES ===" << endl;
    for (int i=0; i<notas.size(); i++){
        cout << i+1 << "°: " <<  notas[i].notaFinal << endl;
    }
}

float calcularPromedio(vector<AlumnoNotas> notas) {
    float suma = 0;
    for (int i=0; i<notas.size(); i++) {
        suma += notas[i].notaFinal;
    }
    return suma/notas.size();
}

int encontrarIndiceMayorNota(vector<AlumnoNotas> notas) {
    float MayorNota = notas[0].notaFinal;
    int indMayorNota = 0;
    for (int i=0; i<notas.size(); i++) {
        if (MayorNota<notas[i].notaFinal) {
            MayorNota = notas[i].notaFinal;
            indMayorNota = i;
        }
    }
    return indMayorNota;
}

int encontrarIndiceMenorNota(vector<AlumnoNotas> notas) {
    float MenorNota = notas[0].notaFinal;
    int indMenorNota = 0;
    for (int i=0; i<notas.size(); i++) {
        if (MenorNota>notas[i].notaFinal) {
            MenorNota = notas[i].notaFinal;
            indMenorNota = i;
        }
    }
    return indMenorNota;
}