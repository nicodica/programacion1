// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 5/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Producto {
    char nombre[30];
    char codigo[30];
    float precio;
    int cantidad_en_inventario;
    char observaciones[50];
};

Producto registrarProducto();
void guardarProductos (vector<Producto> &products, int cantidad);
int encontrarIndiceProductoMasCaro (vector<Producto> products);
int calcularTotalProductos (vector<Producto> products);
void mostrarProductos(vector<Producto> products);

int main() {
    system("chcp 65001");
    system("cls");

    int N;
    vector<Producto> listaProductos;
    int indiceProductoMasCaro;
    int totalProductos;

    cout << "Cantidad de tipos de producto: ";
    cin >> N;
    cin.ignore();

    guardarProductos(listaProductos, N);

    //Encontrar el producto más caro
    indiceProductoMasCaro = encontrarIndiceProductoMasCaro(listaProductos);
    cout << "Producto más caro: " << listaProductos[indiceProductoMasCaro].nombre << endl;
    cout << "Código: " << listaProductos[indiceProductoMasCaro].codigo << endl;
    cout << "Precio: " << listaProductos[indiceProductoMasCaro].precio << endl;
    cout << "Stock: " << listaProductos[indiceProductoMasCaro].cantidad_en_inventario << endl;
    cout << endl;

    //Total Productos
    totalProductos = calcularTotalProductos(listaProductos);
    cout << "Total de porductos en Inventario: " << totalProductos << endl << endl;
    mostrarProductos(listaProductos);

    return 0;
}

Producto registrarProducto() {
    Producto product;
    cout << "Nombre: ";
    cin.getline(product.nombre, 30);
    cout << "Código: ";
    cin.getline(product.codigo, 30);
    cout << "Precio: ";
    cin >> product.precio;
    cout << "Stock: ";
    cin >> product.cantidad_en_inventario;
    cin.ignore();
    if (product.cantidad_en_inventario < 5) {
        strcpy(product.observaciones, "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO");
    } else {
        strcpy(product.observaciones, "");
    }

    return product;
}

void guardarProductos (vector<Producto> &products, int cantidad) {
    for (int i=0; i<cantidad; i++) {
        cout << "PRODUCTO " << i+1 << endl;
        products.push_back(registrarProducto());
        cout << endl;
    }
}

int encontrarIndiceProductoMasCaro (vector<Producto> products) {
    float precioMasCaro = products[0].precio;
    int indiceMasCaro = 0;
    for (int i=0; i<products.size(); i++) {
        if (products[i].precio > precioMasCaro) {
            precioMasCaro = products[i].precio;
            indiceMasCaro = i;
        }
    }
    return indiceMasCaro;
}

int calcularTotalProductos (vector<Producto> products) {
    int sumaTotal = 0;
    for (int i=0; i<products.size(); i++) {
        sumaTotal += products[i].cantidad_en_inventario;
    }
    return sumaTotal;
}

void mostrarProductos(vector<Producto> products) {
    cout << "=== PRODUCTOS ===";
    for (int i=0; i<products.size(); i++) {
        cout << endl << "Nombre: " << products[i].nombre << endl;
        cout << "Código: " << products[i].codigo << endl;
        cout << "Precio: " << products[i].precio << "Bs."<< endl;
        cout << "Stock: " << products[i].cantidad_en_inventario << endl;
        if (empty(products[i].observaciones)) {
            continue;
        } else {
            cout << "Observaciones: " << products[i].observaciones << endl;
        }
    }
}