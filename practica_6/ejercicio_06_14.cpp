// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 08/10/2025
// Número de ejercicio: 14

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> contarVocales (string texto);

int main () {
    system ("chcp 65001");
    system ("cls");

    string texto;
    vector<int> numeroDeVocales;
    vector<char> nombreVocales = {'A', 'E', 'I', 'O', 'U'};
    
    cout << "Ingresa tu texto: ";
    getline(cin, texto);

    numeroDeVocales = contarVocales(texto);

    for (int i=0; i<5; i++) {
        cout << nombreVocales[i] << ": " << numeroDeVocales[i] << endl;
    }
    
    return 0;
}

vector<int> contarVocales (string texto) {
    vector<int> nVocales(5,0); // 0=a,1=e,2=i,3=o,4=u
    for (int i=0; i<texto.size(); i++) {
        if(texto[i] == 'a' || texto[i] == 'A'){
            nVocales[0]++;
        } else if (texto[i] == 'e' || texto[i] == 'E'){
            nVocales[1]++;
        } else if (texto[i] == 'i' || texto[i] == 'I'){
            nVocales[2]++;
        } else if (texto[i] == 'o' || texto[i] == 'O'){
            nVocales[3]++;
        } else if (texto[i] == 'u' || texto[i] == 'U'){
            nVocales[4]++;
        } 
    }
    return nVocales;
}
