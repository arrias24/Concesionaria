#include <iostream>
#include "../modelo/clases.h"
#include "../modelo/binarySearch.h"
#include "../modelo/estilos.h"
using namespace std;

void buscarCliente(int& id_cliente, int numero_clientes, Usuarios* clientes, bool estado)
{
    int low = 0, high = numero_clientes - 1;
    id_cliente = binarySearch(low, high, clientes, id_cliente, estado);

    if(id_cliente == -1){
        styleOutput("bold","rojo","""[ERROR]: No existe un cliente con el ID ingresado.");cout<<endl<<endl;
        exit(0);
    }
}

void buscarCarro(int& id_carro, int numero_carros, Autos* carros, bool estado)
{
    int low = 0, high = numero_carros - 1;
    id_carro = binarySearch(low, high, carros, id_carro, estado);

    if(id_carro == -1){
        styleOutput("bold","rojo","""[ERROR]: No existe un carro con el ID ingresado.");cout<<endl<<endl;
        exit(0);
    }
}

void buscarID(int numero_clientes, int numero_carros,  Autos* carros, Usuarios* clientes, Autos agregar, int& id1, int& id2, int id_vendido, int id_comprado, bool estado)
{
    id1 = -1;
    id2 = -1;

    for(int i = 0; i < numero_clientes; i++){
        if(clientes[i].id == id_vendido){
            id1 = i;
            break;
        }
    }

    if(id1 == -1){
        styleOutput("bold","rojo","""[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
        estado = false;
        exit(0);
    }

    for(int i = 0; i < numero_clientes; i++){
        if(clientes[i].id == id_comprado){
            id2 = i;
            break;
        }
    }

    if(id2 == -1){
        styleOutput("bold","rojo","[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
        estado = false;
        exit(0);
    }
}