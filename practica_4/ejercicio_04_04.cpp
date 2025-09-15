// Materia: Programación I, Paralelo 4
// Autor: Diana Melisa Callejas Paco
// Carnet: 10901243
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/09/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

float ConvertirCelsiusAFahrenheit (float);
float MayorTemperatura (float, float);

int main() {
    system("chcp 65001");
    system("cls");
    float temp1C = 0, temp2C = 0; // Variables para la temperatura en Celsius
    float temp1F, temp2F; // Variables para la temperatura en Fahrenheit
    int opcion;
    float mayorTemp = 0;

    cout << "Ingresa dos temperaturas en Celsius" << endl << "1° Temperatura: ";
    cin >> temp1C;
    cout << "2° Temperatura: ";
    cin >> temp2C;
    
    cout << "CELSIUS A FAHRENHEIT" << endl;
    temp1F = ConvertirCelsiusAFahrenheit(temp1C);
    temp2F = ConvertirCelsiusAFahrenheit(temp2C);
    cout << temp1C << "°C = " << temp1F << "°F" << endl;
    cout << temp2C << "°C = " << temp2F << "°F" << endl;

    cout << "MAYOR TEMPERATURA" << endl;
    mayorTemp = MayorTemperatura(temp1C,temp2C);
    if (mayorTemp != 0){
        cout << "La mayor temperatura es " << mayorTemp << "°C";
    } else {
        cout << "Las temperaturas son iguales.";
    }
    return 0;
}

float ConvertirCelsiusAFahrenheit (float gradosCelsius) {
    return (gradosCelsius*(9.0/5.0)) + 32.00;
}

float MayorTemperatura (float temperatura1, float temperatura2) {
    if (temperatura1>temperatura2) {
        return temperatura1;
    } else if (temperatura2>temperatura1) {
        return temperatura2;
    } else {
        return 0;
    }
}