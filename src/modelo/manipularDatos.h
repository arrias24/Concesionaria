#include <iostream>
using namespace std;
#ifndef MANIPULAR_DATOS_H
#define MANIPULAR_DATOS_H

void buscarCliente(int& id_cliente, int numero_clientes, Usuarios clientes[], bool estado);
void buscarCarro(int& id_carro, int numero_carros, Autos carros[], bool estado);
int buscarClientePorNombre(int numero_clientes, Usuarios clientes[], Usuarios agregar);
void buscarID(int numero_clientes, int numero_carros,  Autos carros[], Usuarios clientes[], Autos agregar, int& id1, int& id2, int id_vendido, int id_comprado, bool estado);

#endif