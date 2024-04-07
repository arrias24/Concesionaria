#include <iostream>
#include "../modelo/clases.h"
#include "../modelo/binarySearch.h"
#include "../modelo/estilos.h"
using namespace std;

void buscarCliente(int& id_cliente, int numero_clientes, Usuarios clientes[], bool estado)
{
    int low = 0, high = numero_clientes - 1;
    id_cliente = binarySearch(low, high, clientes, id_cliente, estado);

    if(id_cliente == -1){
        styleOutput("bold","rojo","""[ERROR]: No existe un cliente con el ID ingresado.");cout<<endl<<endl;
        exit(0);
    }
}

void buscarCarro(int& id_carro, int numero_carros, Autos carros[], bool estado)
{
    int low = 0, high = numero_carros - 1;
    id_carro = binarySearch(low, high, carros, id_carro, estado);

    if(id_carro == -1){
        styleOutput("bold","rojo","""[ERROR]: No existe un carro con el ID ingresado.");cout<<endl<<endl;
        exit(0);
    }
}

int buscarClientePorNombre(int numero_clientes, Usuarios clientes[], Usuarios agregar, bool& estado)
{
    int x = 0;
    for (int i = 0; i < numero_clientes; i++)
    {
        if (agregar.nombre == clientes[i].nombre)
        {
            for (int j = 0; j < numero_clientes; j++)
            {
                if (agregar.apellido == clientes[j].apellido)
                {
                    styleOutput("bold","red","[Error] El cliente ya se encuentra en la base de datos.");cout<<endl<<endl;
                    estado = false;
                    return 1;
                }
            }
        }
        x += 1;
    }
    return x;
}

void buscarID(int numero_clientes, int numero_carros,  Autos carros[], Usuarios clientes[], Autos agregar, int& id1, int& id2, int id_vendido, int id_comprado, bool estado)
{
    if (agregar.id_vendido > numero_clientes) 
    {
        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
        estado =false;
        exit(0);
    }else if (agregar.id_comprado > numero_clientes) {
        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
        estado =false;
        exit(0);
    }

    int low = 0, high = numero_clientes - 1;
    id1 = binarySearch(low, high, clientes, id_vendido, estado);

    if(id1 == -1){
        styleOutput("bold","rojo","""[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
        exit(0);
    }

    low = 0; high = numero_clientes - 1;
    id2 = binarySearch(low, high, clientes, id_comprado, estado);

    if(id2 == -1){
        styleOutput("bold","rojo","[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
        exit(0);
    }
}