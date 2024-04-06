#include <iostream>
#include "./clases.h"
using namespace std;
#ifndef MANIPULAR_DATOS_H
#define MANIPULAR_DATOS_H

void buscarCliente(int& id_cliente, int numero_clientes, Usuarios clientes[], bool estado);
void buscarCarro(int& id_carro, int numero_carros, Autos carros[], bool estado);

#endif