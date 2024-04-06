#include <iostream>
#include "../modelo/clases.h"
#include "../modelo/binarySearch.h"
#include "../modelo/estilos.h"
using namespace std;

void buscarCliente(int& id_cliente, int numero_clientes, Usuarios clientes[], bool estado){
    styleOutput("italic", "yellow","Ingresa el 'ID' del cliente para buscar su informacion:");
    id_cliente = styleIputInt("yellow");

    int low = 0, high = numero_clientes - 1;
    id_cliente = binarySearch(low, high, clientes, id_cliente, estado);

    if(id_cliente == -1){
        styleOutput("","rojo","""[ERROR]: No existe un cliente con el ID ingresado.");
        exit(0);
    }
}

void buscarCarro(int& id_carro, int numero_carros, Autos carros[], bool estado){
    styleOutput("italic", "yellow","Ingresa el 'ID' del carro para buscar su informacion:");
    id_carro = styleIputInt("yellow");

    int low = 0, high = numero_carros - 1;
    id_carro = binarySearch(low, high, carros, id_carro, estado);

    if(id_carro == -1){
        styleOutput("","rojo","""[ERROR]: No existe un carro con el ID ingresado.");
        exit(0);
    }
}