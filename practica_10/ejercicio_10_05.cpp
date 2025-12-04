// Materia: Programación I, Paralelo 4 
// Autor: Diana Melisa Callejas Paco
// Fecha creación: 12/11/2025 
// Número de ejercicio: 5

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> extraerTextoLineas();
void actualizarPrecio(string producto, vector<string> &lineas);

int main() {
    system("chcp 65001");
    system("cls");

    vector <string> productosEnLinea;
    productosEnLinea = extraerTextoLineas();
    string nombreProdActualizar;

    cout << "=== LISTA DE PRODUCTOS ===" << endl;
    for (int i=0; i<productosEnLinea.size(); i++) {
        cout << productosEnLinea[i] << endl;
    }

    cout << "Ingrese el nombre del producto que quiera modificar: ";
    getline(cin, nombreProdActualizar);
    actualizarPrecio(nombreProdActualizar, productosEnLinea);


    return 0;
}

vector <string> extraerTextoLineas() {
    vector<string> lineas;
    ifstream archivo;
    string lineaText;

    archivo.open("productos.txt");
    while (getline(archivo, lineaText)) {
        lineas.push_back(lineaText);
    }
    archivo.close();
    return lineas;
}

void actualizarPrecio(string producto, vector<string> &lineas) { // actualizar el vector
    ofstream archivo;
    string precioNuevo;
    bool compararLetras = true;
    bool productoEncontrado = false;

    for (int i=0; i<lineas.size(); i++) {
        compararLetras = true;
        for (int j=0; j<producto.length(); j++) {
            if (j>= lineas[i].length()) {
                compararLetras = false;
            } else {
                if (lineas[i][j] != producto[j]) {
                    compararLetras = false;
                }
            }
        }
        if (compararLetras && lineas[i][producto.length()]==' ') {
            cout << "Ingrese el precio nuevo: ";
            getline(cin, precioNuevo);

            lineas[i] = producto + " " + precioNuevo;
            productoEncontrado = true;
        } else if (productoEncontrado==false){
            cout << "Ese producto no está en la lista";
            archivo.close();
            return;
        }

        archivo.open("productos.txt");
        for (int i=0; i<lineas.size(); i++) {
            archivo << lineas[i] << "\n";
        }
        archivo.close();
    }

}