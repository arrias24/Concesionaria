#include <iostream>
using namespace std;
#ifndef MANIPULAR_ARCHIVOS_H
#define MANIPULAR_ARCHIVOS_H
void abrirArchivoClientes(ifstream& archivo_clientes, string ruta);
void abrirArchivoClientes(ofstream& archivo_clientes, string ruta);
void abrirArchivoCarros(ifstream& archivo_carros, string ruta);
void abrirArchivoCarros(ofstream& archivo_carros, string ruta);
#endif