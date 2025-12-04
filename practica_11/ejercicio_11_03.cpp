// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

//Estructura Pizza
struct Pizza {
    int codigo;
    char nombre[30];
    int tipo;
    int tamanio;
    float precio;
    int cantidadVentas;
    bool eliminado;
};

struct VentaPizza {
    char ciCliente[10];
    int codigoPizza;
    int tamnioPizza;
    int cantidadVenta;
};

// Funciones
void menu();
int proporcionarCodigo();
void mostrarVectorComoMenu(vector<string> vectorAMostrar);
void adicionarPizza();
void mostrarListadoPizzas();
void modificarPrecio();
void eliminarPizza();
void adicionarVenta();
void actualizarCantidadVentas(int codigoPizza);

// VARIABLES CONSTANTES
string nombreArchivo = "PRODUCTO.bin";
string nombreArchivoTexto = "VENTAS.txt";
// TIPO
vector <string> tiposPizza = {"Tradicional", "Especial"}; // 0:trad, 1:esp
// TAMAÑOS
vector <string> tamaniosPizza = {"XS", "Mediana", "Grande", "Familiar", "Interminable"};

int main() {
    system("chcp 65001");
    // system("cls");

    menu();

    return 0;
}

void menu() {
    int opcion;
    do {
        system("cls");
        cout << "======= PIZZERÍA ELIS =======" << endl;
        cout << "\t1. Adicionar pizza\n";
        cout << "\t2. Listado de pizzas\n";
        cout << "\t3. Modificar el precio de la pizza\n";
        cout << "\t4. Eliminar una Pizza\n";
        cout << "\t5. Adicionar Venta de Pizzas\n";
        cout << "\t0. Salir\n";
        cout << "--> ";
        cin >> opcion;

        if (opcion == 1 ) {
            adicionarPizza();
        } else if (opcion == 2) {
            mostrarListadoPizzas();
        } else if (opcion == 3) {
            modificarPrecio();
        } else if (opcion == 4) {
            eliminarPizza();
        } else if (opcion==5) {
            adicionarVenta();
        } else if (opcion == 0) {
            cout << "Saliendo...";
        } else {
            cout << "Esa opción no existe, intenta de nuevo";
            system("pause");
        }
    } while (opcion != 0);
}

int proporcionarCodigo() {
    int contcodigo = 0;
    ifstream archivo;
    Pizza pizza;
    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        while (archivo.read((char*)(&pizza), sizeof(Pizza))) {
            contcodigo++;
        }
    } else {
        cout << "No se pudo abrir el archivo";
        return NULL;
    }
    archivo.close();
    return contcodigo;
}

void mostrarVectorComoMenu(vector<string> vectorAMostrar) {
    for (int i=0; i<vectorAMostrar.size(); i++) {
        cout << "\t" << i << ". " << vectorAMostrar[i] << endl;
    }
}

void adicionarPizza() {
    ofstream archivo;
    Pizza pizza;
    archivo.open(nombreArchivo, ios::binary | ios::app);
    if (archivo.is_open()) {
        cout << "== LLENAR DATOS DE LA PIZZA ==\n";
        pizza.codigo = proporcionarCodigo();
        cin.ignore();
        cout << "\tNombre: ";
        cin.getline(pizza.nombre,30);
        cout << "Tipo:\n";
        mostrarVectorComoMenu(tiposPizza);
        cin >> pizza.tipo;
        cout << "Tamaño:\n";
        mostrarVectorComoMenu(tamaniosPizza);
        cin >> pizza.tamanio;
        cout << "Precio: ";
        cin >> pizza.precio;
        pizza.cantidadVentas = 0;
        pizza.eliminado = false;
        archivo.write((char*)(&pizza), sizeof(Pizza));
    } else {
        cout << "No se pudo abrir el archivo";
    }
    archivo.close();
    cout << "Pizza añadida con éxito (^-^)\n";
    system("pause");
}


void mostrarListadoPizzas() {
    ifstream archivo;
    Pizza pizza;

    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        cout << "CÓDIGO\tNOMBRE\tTIPO\tTAMAÑO\tPRECIO\tCANTIDAD\tTOTAL\n";
        while(archivo.read((char*)(&pizza), sizeof(Pizza))) {
            if (!pizza.eliminado) {
                cout << pizza.codigo << "\t" << pizza.nombre << "\t";
                cout << tiposPizza[pizza.tipo] << "\t" << tamaniosPizza[pizza.tamanio] << "\t";
                cout << pizza.precio << "\t" << pizza.cantidadVentas << "\t";
                cout << pizza.cantidadVentas*pizza.precio << endl;
            }
        }
    } else {
        cout << "No se pudo abrir el archivo\n";
    }
    archivo.close();
    system("pause");
}

void modificarPrecio() {
    fstream archivo;
    Pizza pizza;
    int condigoBuscado;
    bool encontrado = false;
    cout << "Código de la pizza que busca: ";
    cin >> condigoBuscado;

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&pizza), sizeof(Pizza)) && encontrado!=true) {
            if (condigoBuscado==pizza.codigo && !pizza.eliminado) {
                cout << "CÓDIGO\tNOMBRE\tTIPO\tTAMAÑO\tPRECIO\n";
                cout << pizza.codigo << "\t" << pizza.nombre << "\t" << tiposPizza[pizza.tipo] << "\t";
                cout << tamaniosPizza[pizza.tamanio] << "\t" << pizza.precio << endl;
                encontrado = true;
                
                archivo.seekp(-sizeof(Pizza), ios::cur);
                cout << "Nuevo Precio: ";
                cin >> pizza.precio;
                archivo.write((char*)(&pizza), sizeof(Pizza));
            }
        }
        if (encontrado==false) {
            cout << "No se encontró una pizza con ese código\n";
            system("pause");
        }
    } else {
        cout << "Error al modificar el precio";
        system("pause");
        return;
    }
    archivo.close();
}

void eliminarPizza() {
    fstream archivo;
    Pizza pizza;
    int condigoBuscado;
    bool encontrado = false;
    cout << "Código de la pizza que desea eliminar: ";
    cin >> condigoBuscado;

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&pizza), sizeof(Pizza)) && encontrado!=true) {
            if (condigoBuscado==pizza.codigo && pizza.eliminado!=true) {
                cout << "CÓDIGO\tNOMBRE\tTIPO\tTAMAÑO\tPRECIO\n";
                cout << pizza.codigo << "\t" << pizza.nombre << "\t" << tiposPizza[pizza.tipo] << "\t";
                cout << tamaniosPizza[pizza.tamanio] << "\t" << pizza.precio << endl;
                encontrado = true;
                
                archivo.seekp(-sizeof(Pizza), ios::cur);
                pizza.eliminado = true;
                archivo.write((char*)(&pizza), sizeof(Pizza));
                cout << "Pizza eliminada\n";
            }
        }
        if (encontrado==false) {
            cout << "No se encontró una pizza con ese código";
            system("pause");
        }
    } else {
        cout << "Error al eliminar pizza";
        system("pause");
        return;
    }
    archivo.close();
    system("pause");
}

void adicionarVenta() {
    ofstream archivoTexto;
    fstream archivo;
    Pizza pizza;
    VentaPizza venta;
    bool encontrado = false;
    int codigoBuscado;

    cout << "Codigo para adicionar venta: ";
    cin >> codigoBuscado;

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while (archivo.read((char*)(&pizza), sizeof(Pizza)) && encontrado==false) {
            if (codigoBuscado==pizza.codigo && pizza.eliminado==false) {
                encontrado = true;
                archivoTexto.open(nombreArchivoTexto, ios::app);
                if (archivoTexto.is_open()) {
                cin.ignore();
                cout << "Carnet del cliente: ";
                cin.getline(venta.ciCliente, 10);
                archivo.seekp(-sizeof(Pizza), ios::cur);
                venta.tamnioPizza = pizza.tamanio;
                cout << "Cantidad de pizzas vendidas: ";
                cin >> venta.cantidadVenta;

                archivoTexto << venta.ciCliente << ";" << pizza.codigo << ";" << tamaniosPizza[venta.tamnioPizza] << ";" << venta.cantidadVenta << "\n";
                cout << "Venta agregada";
                archivoTexto.close();

                // agregar venta al bin
                pizza.cantidadVentas += venta.cantidadVenta;
                archivo.write((char*)(&pizza), sizeof(Pizza));
                archivo.close();       
                
                system("pause");
            } else {
                cout << "No se pudo abrir el archivo de ventas";
            }
            } 
            if (encontrado==false) {
                cout << "No se encontró una pizza con ese codigo";
            }
        }
    } else {
        cout << "Error al adicionar venta";
        system("pause");
        return;
    }
}