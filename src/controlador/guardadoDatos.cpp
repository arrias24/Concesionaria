#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../modelo/clases.h"
#include "../modelo/estilos.h"
using namespace std;

void guardarDatos(ifstream& archivo_clientes,ifstream& archivo_carros, string& encabezado_clientes, string& encabezado_carros, Usuarios clientes[], Autos carros[],  int& numero_clientes, int&  numero_carros){

    getline(archivo_clientes, encabezado_clientes, '\n');
    getline(archivo_carros, encabezado_carros,'\n');
    
    string linea; 
    while(getline(archivo_clientes, linea, '\n')){
        stringstream stream(linea);
        string dato;
        getline(stream, dato, ';');
        clientes[numero_clientes].id = std::stoi(dato);
        getline(stream,dato,';');
        clientes[numero_clientes].nombre = dato;
        getline(stream,dato,';');
        clientes[numero_clientes].apellido = dato;
        getline(stream,dato,';');
        clientes[numero_clientes].email = dato;
        getline(stream,dato,' ');
        clientes[numero_clientes].edad = std::stoi(dato);
        numero_clientes++;
    }
    archivo_clientes.close();

    while(getline(archivo_carros, linea, '\n')){
        stringstream stream(linea);
        string dato;
        getline(stream, dato, ';');
        carros[numero_carros].id = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].marca = dato;
        getline(stream,dato,';');
        carros[numero_carros].modelo = dato;
        getline(stream,dato,';');
        carros[numero_carros].year = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].id_vendido = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].id_comprado = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].precio_vendido = std::stof(dato);
        getline(stream,dato,'\n');
        carros[numero_carros].precio_comprado = std::stof(dato);            
        numero_carros++;
    }
    archivo_carros.close();
}