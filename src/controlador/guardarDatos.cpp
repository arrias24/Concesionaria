#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../modelo/clases.h"
#include "../modelo/estilos.h"
#include "../modelo/manipularDatos.h"
using namespace std;

void guardarDatosClientes(ifstream& archivo_clientes, string& encabezado_clientes, Usuarios*& clientes,  int& numero_clientes, int& capacidad_clientes)
{
    getline(archivo_clientes, encabezado_clientes, '\n');
    
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
    if(numero_clientes == capacidad_clientes)
    {
        capacidad_clientes *= 2;
        Usuarios* temp = new Usuarios[capacidad_clientes];
        for(int i = 0; i < numero_clientes; i++)
        {
            temp[i] = clientes[i];
        }
        delete[] clientes;
        clientes = temp;
            
        guardarDatosClientes(archivo_clientes, encabezado_clientes, clientes, numero_clientes, capacidad_clientes);
    }
    archivo_clientes.close();
}

void guardarDatosCarros(ifstream& archivo_carros, string& encabezado_carros, Autos*& carros, int&  numero_carros, int& capacidad_carros)
{
    getline(archivo_carros, encabezado_carros,'\n');
    
    string linea; 
    while(getline(archivo_carros, linea, '\n'))
    {
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
    if(numero_carros == capacidad_carros)
    {
        capacidad_carros *= 2;
        Autos* temp = new Autos[capacidad_carros];
        for(int i = 0; i < numero_carros; i++){
            temp[i] = carros[i];
        }
        delete[] carros;
        carros = temp;
        guardarDatosCarros(archivo_carros, encabezado_carros, carros, numero_carros, capacidad_carros);
    }
    archivo_carros.close();
}

void imprimirDatosClientes(Usuarios* clientes, int& numero_clientes) {
    cout << "Datos de los clientes:" << endl<<endl;
    for(int i = 0; i < numero_clientes; i++) {
        cout<< clientes[i].id << ";" << clientes[i].nombre << ";" << clientes[i].apellido << ";" << clientes[i].email << ";" << clientes[i].edad << endl;
    }
}

void imprimirDatosCarros(Autos* carros, int& numero_carros) {
    cout << "Datos de los carros:" << endl<<endl;
    for(int i = 0; i < numero_carros; i++) {
        cout<< carros[i].id << ";" << carros[i].marca << ";" << carros[i].modelo << ";" << carros[i].year << ";" << carros[i].id_vendido << ";" << carros[i].id_comprado << ";" << carros[i].precio_vendido << ";" << carros[i].precio_comprado << endl;
    }
}