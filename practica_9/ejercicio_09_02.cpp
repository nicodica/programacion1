// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 4/11/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>

using namespace std;

struct Atleta {
    char nombre[30];
    char pais[30];
    int edad;
    int mejor_tiempo; //En segundos
};

Atleta ingresarDatosAtleta();
int tiempoMayor(vector<Atleta>);


int main() {
    system("chcp 65001");
    system("cls");

    int N;
    Atleta atletaInd;
    vector<Atleta> atletasRegistro;
    int mejorTIndice;
    
    cout <<  "Ingrese el numero de atletas: ";
    cin >> N;
    cin.ignore();
    
    for (int i=0; i<N; i++) {
        cout << endl <<  "ATLETA " << i+1 << endl;
        atletaInd = ingresarDatosAtleta();
        atletasRegistro.push_back(atletaInd);
    }
    mejorTIndice = tiempoMayor(atletasRegistro);
     
    cout << endl << "MEJOR TIEMPO REGISTRADO"<< endl;
    cout << atletasRegistro[mejorTIndice].mejor_tiempo << " segundos, " << atletasRegistro[mejorTIndice].nombre << " de " << atletasRegistro[mejorTIndice].pais;
     
    return 0;
}

Atleta ingresarDatosAtleta() {
    Atleta atletaIndividual;

    cout << "Nombre: ";
    cin.getline(atletaIndividual.nombre, 30);
    cout << "Pais: ";
    cin.getline(atletaIndividual.pais, 30);
    cout << "Edad: ";
    cin >> atletaIndividual.edad;
    cout << "Mejor Tiempo (segundos): ";
    cin >> atletaIndividual.mejor_tiempo;
    cin.ignore();
    return atletaIndividual;
}

int tiempoMayor(vector<Atleta> atletas) {
    int tMayor = atletas[0].mejor_tiempo;
    int tMayorIndice;
    for (int i=0; i<atletas.size(); i++) {
         if(atletas[i].mejor_tiempo<tMayor) {
              tMayor = atletas[i].mejor_tiempo;
              tMayorIndice = i;
          }
     }
     return tMayorIndice;
}