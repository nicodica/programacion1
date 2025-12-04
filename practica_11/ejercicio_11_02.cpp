// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct Producto {
    int codigo;
    char nombre[20];
    int cantidadInicial;
    float precioUnitario;
    int cantidadVendida;
};

struct ventaProducto {
    char ciCliente[10];
    char nombreCliente[30];
    int codigoProducto;
    int cantidadComprada;
};

// variables globales
string nombreArchivo = "ProductosFarmacia.bin";
string nombreArchivoTexto = "VnetasFarmacia.txt";

// funciones
void menu();
Producto ingresarProducto();
void anadirProductoArchivo();
void buscarProductoPorCodigo();
void modificarProductoPorCodigo();
void adicionarVenta();
void listadoSimple();
void listadoDeVentas();

int main () {
    system("chcp 65001");
    system("cls");

    menu();

    return 0;
}

void menu() {
    system("cls");
    int opcion;
    do {
        cout << "=== MENÚ FARMACIAS CHAVEZ ===" << endl;
        cout << "\t1. Adicionar Producto" << endl;
        cout << "\t2. Listado de Prodcutos" << endl;
        cout << "\t3. Buscar un Producto" << endl;
        cout << "\t4. Modificar un Producto" << endl;
        cout << "\t5. Adicionar Ventas del Producto" << endl;
        cout << "\t0. Salir" << endl;
        cout << "--> ";
        cin >> opcion;

        if (opcion==1) {
            anadirProductoArchivo();
        } else if (opcion==2) {
            listadoDeVentas();
        } else if (opcion==3) {
            buscarProductoPorCodigo();
        } else if (opcion==4) {
            modificarProductoPorCodigo();
        } else if (opcion==5) {
            adicionarVenta();
        } else if (opcion==0){
            cout << "Saliendo...";
        } else {
            cout << "Opción no disponible";
        }
    } while(opcion != 0);
    
}

int proporcionarCodigo() {
    int contcodigo = 0;
    ifstream archivo;
    Producto product;
    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        while (archivo.read((char*)(&product), sizeof(Producto))) {
            contcodigo++;
        }
    } else {
        cout << "No se pudo abrir el archivo";
        return NULL;
    }
    archivo.close();
    return contcodigo;
}

Producto ingresarProducto() {
    Producto product;

    product.codigo = proporcionarCodigo();
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(product.nombre, 20);
    cout << "Cantidad Inicial: ";
    cin >> product.cantidadInicial;
    cout << "Precio Unitario: ";
    cin >> product.precioUnitario;
    product.cantidadVendida = 0;

    return product; 
}

void anadirProductoArchivo() {
    Producto product;
    ofstream archivo;
    
    archivo.open(nombreArchivo, ios::binary | ios::app);
    if (archivo.good()) {
        product = ingresarProducto();
        archivo.write((char*)(&product), sizeof(Producto));
        archivo.close();
        cout << "Producto añadido.\n";
        system("pause");
    } else {
        cout << "Error al añadir producto.\n";
    }
}

void listadoSimple() {
    Producto product;
    ifstream archivo;
    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&product), sizeof(Producto))) {
            cout << product.codigo << ". " <<  product.nombre << endl;
        }
        archivo.close();
    } else {
        cout << "Error en listado.\n";
    }
}

void buscarProductoPorCodigo() {
    ifstream archivo;
    Producto product;
    int codigoBuscado;
    bool encontrado = false;

    cout << "CODIGOS DE LOS PRODUCTOS\n";
    listadoSimple();
    cout << "Código del producto que busca: ";
    cin >> codigoBuscado;
    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&product), sizeof(Producto)) && encontrado==false) {
            if (codigoBuscado==product.codigo) {
                cout << "PRODUCTO ENCONTRADO\n";
                cout << "\tCódigo: " << product.codigo << endl;
                cout << "\tNombre: " << product.nombre << endl;
                cout << "\tCantidad Inicial: " << product.cantidadInicial << endl;
                cout << "\tPrecio Unitario: " << product.precioUnitario << endl;
                cout << "==============================================\n";
                encontrado = true;
                system("pause");
            }
        }
        if (encontrado==false) {
            cout << "No se encontró un prodcuto con ese código.\n";
            system("pause");
        }
        archivo.close();
    } else {
        cout << "Error al buscar el producto.\n";
    }
}

void modificarProductoPorCodigo() {
    fstream archivo;
    Producto product;
    int codigoBuscado;
    bool encontrado = false;

    cout << "Código del producto que quiere modificar: ";
    cin >> codigoBuscado;
    archivo.open(nombreArchivo, ios::in | ios:: out | ios::binary);
    if (archivo.good()) {
        while(archivo.read((char*)(&product), sizeof(Producto)) && encontrado==false) {
            if (codigoBuscado==product.codigo) {
                cout << "PRODUCTO\n";
                cout << "\tCódigo: " << product.codigo << endl;
                cout << "\tNombre: " << product.nombre << endl;
                cout << "\tCantidad Inicial: " << product.cantidadInicial << endl;
                cout << "\tPrecio Unitario: " << product.precioUnitario << endl;
                cout << "==============================================\n";
                cout << "INGRESAR NUEVOS DATOS: ";
                archivo.seekp(-sizeof(Producto), ios::cur);
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(product.nombre, 20);
                cout << "Cantidad inicial: ";
                cin >> product.cantidadInicial;
                cout << "Precio Unitario: ";
                cin >> product.precioUnitario;
                encontrado = true;
                archivo.write((char*)(&product), sizeof(Producto));
            }
        }
        if (encontrado==false) {
            cout << "No se encontró un producto con ese código.\n";
            system("pause");
        }
        archivo.close();
    } else {
        cout << "Error al modificar producto.\n";
    }
}

void adicionarVenta() {
    ofstream archivoTexto;
    fstream archivo;
    Producto product;
    ventaProducto venta;
    bool encontrado = false;
    int codigoBuscado;

    cout << "Codigo del producto adicionar venta: ";
    cin >> codigoBuscado;

    archivo.open(nombreArchivo, ios::in | ios::out | ios::binary);
    if (archivo.good()) {
        while (archivo.read((char*)(&product), sizeof(Producto)) && encontrado==false) {
            if (codigoBuscado==product.codigo) {
                encontrado = true;
                archivoTexto.open(nombreArchivoTexto, ios::app);
                if (archivoTexto.is_open()) {
                    cin.ignore();
                    cout << "Carnet del cliente: ";
                    cin.getline(venta.ciCliente, 10);
                    cout << "Nombre del cliente: ";
                    cin.getline(venta.nombreCliente, 30);
                    cout << "Cantidad vendida: ";
                    cin >> venta.cantidadComprada;

                    archivoTexto << venta.ciCliente << ";"<< venta.nombreCliente << ";" << product.codigo <<";" << venta.cantidadComprada << "\n";
                    archivo.seekp(-sizeof(Producto), ios::cur);
                    product.cantidadVendida += venta.cantidadComprada;
                    archivo.write((char*)(&product), sizeof(Producto));
                    cout << "Venta agregada";
                    archivoTexto.close();
                    archivo.close();       
                    system("pause");
                } else {
                    cout << "No se pudo abrir el archivo de ventas";
                }
            }
        }
        if (encontrado==false) {
            cout << "No se encontró un producto ese codigo";
            system("pause");
        }
    } else {
        cout << "Error al adicionar venta";
        system("pause");
        return;
    }
}

void listadoDeVentas() {
    ifstream archivo;
    Producto product;

    archivo.open(nombreArchivo, ios::binary);
    if (archivo.good()) {
        cout << "CÓDIGO\tNOMBRE\tCANTIDAD INCIAL\tPRECIO\tCANTIDAD VENDIDA\tTOTAL\n";
        while(archivo.read((char*)(&product), sizeof(Producto))) {
            cout << product.codigo << "\t" << product.nombre << "\t";
            cout << product.cantidadInicial << "\t";
            cout << product.precioUnitario << "\t" << product.cantidadVendida << "\t";
            cout << product.cantidadVendida*product.precioUnitario << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo\n";
    }
    archivo.close();
    system("pause");
}