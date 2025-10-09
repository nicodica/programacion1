// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> inferior;
vector<int> superior;

vector<int> generarVectorValores(int numeroValores);
void generarLimites ();
vector<int> contarPixeles (vector<int> numerosRandom);
void mostrarVectorInt(vector<int> vectorClasificaciones);

int main() {
    system("chcp 65001");
    system("cls");
    srand(time(NULL));

    int N;
    vector<int> valores;
    vector<int> valoresClasificados;

    cout << "Ingresa el número de valores a generar: ";
    cin >> N;
    valores = generarVectorValores(N);

    //Contar los pixeles en segmentos de 10;

    generarLimites();
    valoresClasificados = contarPixeles(valores);
    mostrarVectorInt(valoresClasificados);

    return 0;
}

vector<int> generarVectorValores(int numeroValores) {
    vector<int> vectorValores;
    for (int i=0; i<numeroValores; i++) {
        vectorValores.push_back(rand()%256);
    }
    return vectorValores;
}

void generarLimites (){
    int inf = 0;
    int sup = 9;

    while(inf <= 250){
        inferior.push_back(inf);
        inf += 10;
    }
    
    while(sup < 250){
        superior.push_back(sup);
        sup += 10;
    }
    superior.push_back(255);
}

vector<int> contarPixeles (vector<int> numerosRandom){
    int n = inferior.size();
    vector<int> seg (n, 0);
    int l = numerosRandom.size();
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            if(numerosRandom[i] >= inferior[j] && numerosRandom[i] <= superior[j]){
                seg[j]++;
            }
        }
    }
    
    return seg;
}

void mostrarVectorInt(vector<int> vectorClasificaciones){
    int n = vectorClasificaciones.size();
    for(int i = 0; i < n; i++){
        cout << inferior[i] << " - " << superior[i] << ": " << vectorClasificaciones[i] << " pixel(es)" << endl;
    }
}


