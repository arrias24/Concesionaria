#include <iostream>
#include <fstream>
#include "../modelo/clases.h"
#include "../modelo/estilos.h"
using namespace std;

void abrirArchivoClientes(ifstream& archivo_clientes, string ruta){
    archivo_clientes.open(ruta);
    if(!archivo_clientes.is_open()){
        cout<<endl;styleOutput("bold","red","[ERROR] No se ha podido abrir el archivo correctamente.");cout<<endl;
    }
}

void abrirArchivoClientes(ofstream& archivo_clientes, string ruta){
    archivo_clientes.open(ruta);
    if(!archivo_clientes.is_open()){
        cout<<endl;styleOutput("bold","red","[ERROR] No se ha podido abrir el archivo correctamente.");cout<<endl;
    }
}

void abrirArchivoCarros(ifstream& archivo_carros, string ruta){
    archivo_carros.open(ruta);
    if(!archivo_carros.is_open()){
        cout<<endl;styleOutput("bold","red","[ERROR] No se ha podido abrir el archivo correctamente.");cout<<endl;
    }
}

void abrirArchivoCarros(ofstream& archivo_carros, string ruta){
    archivo_carros.open(ruta);
    if(!archivo_carros.is_open()){
        cout<<endl;styleOutput("bold","red","[ERROR] No se ha podido abrir el archivo correctamente.");cout<<endl;
    }
}