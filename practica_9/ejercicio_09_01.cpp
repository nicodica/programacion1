// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 4/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// estructura
struct Libro {
    char titulo[30];
    char autor[30];
    int anio_publicacion;
    bool disponible;
};

// funciones
Libro ingresarLibro();
// void agregarLibroAColeccion(vector<Libro>& librosColeccion, int n);

int main() {
    system("chcp 65001");
    system("cls");
    Libro libroIngresado;
    vector <Libro> librosColeccion;

    Libro libro1 = {"NO EN MÍ NI EN TI", "MASADORA", 2021, true};
    Libro libro2 = {"BELLADONA", "NEPHENTES", 2020, true};
    Libro libro3 = {"CHAINSAW MAN", "TATSUKI FUJIMOTO", 2018, false};
    Libro libro4 = {"DON QUIJOTE", "MIGUEL DE CERVANTES", 1605, true};
    Libro libro5 = {"1984", "GEORGE ORWELL", 1947, false};
    librosColeccion = {libro1, libro2, libro3, libro4, libro5};

    cout << "Ingrese el libro que busca (EN MAYÚSCULAS)" << endl;
    libroIngresado = ingresarLibro();

    for (int i=0; i<librosColeccion.size(); i++) {
        if (strcmp(libroIngresado.titulo, librosColeccion[i].titulo) == 0) {
            cout << endl;
            cout << librosColeccion[i].titulo << endl;
            cout << "Autor: " << librosColeccion[i].autor << endl;
            cout << "Publicado en: " << librosColeccion[i].anio_publicacion << endl;
            if ((librosColeccion[i].disponible)) {
                cout << "El libro está disponible" << endl;
            } else {
                cout << "El libro NO está disponible" << endl;
            }
        }
    }
    


    return 0;
}

Libro ingresarLibro() {
    Libro libro;
    cout << "Título: ";
    cin.getline(libro.titulo, 30, '\n');
    cout << "Autor: ";
    cin.getline(libro.autor, 30, '\n');
    cout << "Año de Publicación: ";
    cin >> libro.anio_publicacion;
    cin.ignore();  /*
    cout << "Disponibilidad(s/n): ";
    cin >> disponible_SN;
    if (disponible_SN=='s' || disponible_SN=='S') {
        libro.disponible = true;
    } else {
        libro.disponible = false;
    } */
    return libro;
} 

/* void agregarLibroAColeccion(vector<Libro>& librosColeccion, int n) {
    for (int i=0; i<n; i++) {
        librosColeccion.push_back(ingresarLibro());
    }
} */