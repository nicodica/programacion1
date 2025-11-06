// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Pelicula {
    char titulo[30];
    char director[30];
    int duracion; // en minutos
    int anio_estreno;
    char genero[30];
};

Pelicula registrarPelicula();

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<Pelicula> ListaPeliculas;
    char generoBuscado[30];
    char directorBuscado[30];
    char generoAux[30]; // para comparar

    cout << "=== REGISTRO DE PELÍCULAS ===" << endl;
    cout << "Ingresa la cantidad de películas: ";
    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++) {
        cout << "PELÍCULA " << i+1 << endl;
        ListaPeliculas.push_back(registrarPelicula());
        cout << endl;
    }

    cout << "Películas registradas (^-^)" << endl << endl;

    cout << "=== BUSCAR POR GÉNERO ===" << endl;
    cout << "Ingrese el género: ";
    cin.getline(generoBuscado, 30);

    for (int i=0; i<N; i++) {
        if (strcmp(generoBuscado, ListaPeliculas[i].genero) == 0) {
            cout << endl << ListaPeliculas[i].titulo << endl;
            cout << "Dirigida por " << ListaPeliculas[i].director << endl;
            cout << "Duración: " << ListaPeliculas[i].duracion << endl;
            cout << "Año: " << ListaPeliculas[i].anio_estreno << endl;
        }
    }
    cout << endl;

    cout << "=== BUSCAR POR DIRECTOR ===" << endl;
    cout << "Ingrese el director: ";
    cin.getline(directorBuscado, 30);

    for (int i=0; i<N; i++) {
        if (strcmp(directorBuscado, ListaPeliculas[i].genero)) {
            cout << endl << ListaPeliculas[i].titulo << endl;
            cout << "Duración: " << ListaPeliculas[i].duracion << endl;
            cout << "Año: " << ListaPeliculas[i].anio_estreno << endl;
            cout << "Género: " << ListaPeliculas[i].director << endl;
        }
    }
    cout << endl;


    return 0;
}

Pelicula registrarPelicula() {
    Pelicula peli;
    cout << "Título: ";
    cin.getline(peli.titulo, 30);
    cout << "Director: ";
    cin.getline(peli.titulo, 30);
    cout << "Duración(minutos): ";
    cin >> peli.duracion;
    cout << "Año de estreno: ";
    cin >> peli.anio_estreno;
    cin.ignore();
    cout << "Género: ";
    cin.getline(peli.genero, 30);

    return peli;
}