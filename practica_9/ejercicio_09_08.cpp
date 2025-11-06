// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 8

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;


struct Atleta {
    char nombre[20];
    char departamento[20];
    char deporte[20];
    int medallas;
};

int generarIntAleatorio(int min, int max);
Atleta registrarAtleta();
void MostrarAtletas(vector<Atleta> atletas);
void mostrarMedalleroFinal(vector<Atleta> atletas);


int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    vector<string> deportes = {"Tiro con Arco", "Atletismo", "Boxeo", "Ciclismo", "Natación", "Esgrima"};
    vector<string> departamentos {"La Paz", "Cochabamba", "Santa Cruz", "Tarija", "Potosí", "Oruro", "Beni", "Pando", "Chuquisaca"};
    
    int N;
    vector<Atleta> listaAtletas;

    cout << "Número de atletas a registrar: ";
    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++) {
        cout << "ATLETA " << i+1 << endl;
        listaAtletas.push_back(registrarAtleta());
        cout << endl;
    }

    MostrarAtletas(listaAtletas);

    mostrarMedalleroFinal(listaAtletas);

    return 0;
}

int generarIntAleatorio(int min, int max) {
    return (rand()%(max-min+1))+min;
}


Atleta registrarAtleta() {
    Atleta atlethe;

    cout << "Nombre: ";
    cin.getline(atlethe.nombre, 20);
    cout << "Departamento: ";
    cin.getline(atlethe.departamento, 20);
    cout << "Deporte: ";
    cin.getline(atlethe.deporte, 20);

    atlethe.medallas = rand()%50;

    return atlethe;
}

void MostrarAtletas(vector<Atleta> atletas) {
    cout << "=== ATLETAS ===" << endl;
    for (int i=0; i<atletas.size(); i++) {
        cout << "Nombre: " << atletas[i].nombre << endl;
        cout << "Departamento: " << atletas[i].departamento << endl;
        cout << "Deporte: " << atletas[i].deporte << endl;
        cout << "Medallas: " << atletas[i].medallas << endl;
        cout << endl;
    }
}

void mostrarMedalleroFinal(vector<Atleta> atletas) {
    // solo se simulará en tres departamentos
    int medallaLPZ = 0;
    int medallaSCZ = 0;
    int medallaCBBA = 0;

    cout << "=== MEDALLERO FINAL ===" << endl;
    for (int i=0; i<atletas.size(); i++) {
        if (strcmp(atletas[i].departamento, "LA PAZ")) {
            medallaLPZ+= atletas[i].medallas;
        } else if (strcmp(atletas[i].departamento, "COCHABAMBA")) {
            medallaCBBA+= atletas[i].medallas;
        } else if (strcmp(atletas[i].departamento, "SANTA CRUZ")) {
            medallaSCZ+= atletas[i].medallas;
        }
    }
    cout << "LA PAZ: " << medallaLPZ << endl;
    cout << "COCHABAMBA: " << medallaCBBA << endl;
    cout << "SANTA CRUZ: " << medallaSCZ << endl;
}

