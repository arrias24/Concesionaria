#include <iostream>
#include <string>
#include <fstream>

#include "../modelo/clases.h"
#include "../modelo/estructuras.h"
#include "../modelo/binarySearch.h"
#include "../modelo/estilos.h"
#include "../modelo/manipularDatos.h"
#include "../modelo/manipularArchivos.h"


using namespace std;

//CASO 1 - CARROS COMPRADOS Y VENDIDOS POR UN CLIENTE

void mostrarHistorialCliente(int numero_clientes, int numero_carros, Usuarios clientes[], Autos carros[], bool& reiniciar)
{
    //VARIABLES A UTILIZAR

    int id_cliente, carros_vendidos = 0, carros_comprados = 0; bool estado;

    //BUSCAMOS EL CLIENTE
                
    styleOutput("italic", "yellow","Ingresa el 'ID' del cliente para buscar su informacion:");
    id_cliente = styleIputInt("yellow");
    buscarCliente(id_cliente, numero_clientes, clientes, estado);
                
    // BUSCAMOS LOS CARROS COMPRADOS Y VENDIDOS DEL CLIENTE

    for (int i = 0; i < numero_carros; i++)
    {
        if (clientes[id_cliente].id == carros[i].id_vendido)
        {
            carros_vendidos++;
        }
                        
        if (clientes[id_cliente].id == carros[i].id_comprado) 
        {
            carros_comprados++;
        }
    }

    //MOSTRAMOS LOS CARROS COMPRADOS Y VENIDOS POR EL CLIENTE

    styleOutput("bold","","Cliente:");cout<<endl<<endl;clientes[id_cliente].mostrarDatos(clientes[id_cliente].id, clientes[id_cliente].nombre, clientes[id_cliente].apellido, clientes[id_cliente].email, clientes[id_cliente].edad);cout<<endl<<endl;
    styleOutput("bold","","Carros vendidos:");cout<<carros_vendidos<<endl<<endl;
    for(int i = 0; i < numero_carros; i++)
    {
        if(clientes[id_cliente].id == carros[i].id_vendido)
            {
                carros[i].mostrarDatos(carros[i].id, carros[i].marca, carros[i].modelo, carros[i].year, carros[i].id_comprado, carros[i].id_vendido, carros[i].precio_comprado, carros[i].precio_vendido);cout<<endl;
            }
        }

    styleOutput("bold","","Carros comprados:");cout<<carros_comprados<<endl<<endl;
    for(int i = 0; i < numero_carros; i++)
    {
        if(clientes[id_cliente].id == carros[i].id_comprado){
            carros[i].mostrarDatos(carros[i].id, carros[i].marca, carros[i].modelo, carros[i].year, carros[i].id_comprado, carros[i].id_vendido, carros[i].precio_comprado, carros[i].precio_vendido);cout<<endl;
        }
    }

    reiniciar = false;    
}

//CASO 2 - MOSTRAR DATOS DEL VENDEDOR Y COMPRADOR DE UN CARRO

void mostrarHistorialCarro(int numero_clientes, int numero_carros, Usuarios clientes[], Autos carros[], bool& reiniciar)
{
    //VARIABLES A UTILIZAR

    int id_carro; bool estado = false;

    //BUSCAMOS EL ID DEL CARRO

    styleOutput("italic", "yellow","Ingresa el 'ID' del carro para buscar su informacion:");
    id_carro = styleIputInt("yellow");
    buscarCarro(id_carro, numero_carros, carros, estado);

    //BUSCAMOS EL CARRO POR SU ID Y LUEGO COMPARAMOS A SU COMPRADOR Y VENDEDOR

    for(int i = 0; i < numero_clientes; i++)
    {
        if(carros[id_carro].id_comprado == clientes[i].id)
        {
            styleOutput("Bold","","Datos del carro:");cout<<endl<<endl;
            carros[i].mostrarDatos(carros[i].id, carros[i].marca, carros[i].modelo, carros[i].year, carros[i].id_comprado, carros[i].id_vendido, carros[i].precio_comprado, carros[i].precio_vendido);cout<<endl;
            styleOutput("Bold","","Datos del comprador:");cout<<endl<<endl;
            clientes[i].mostrarDatos(clientes[i].id, clientes[i].nombre, clientes[i].apellido, clientes[i].email, clientes[i].edad);cout<<endl<<endl;   
        }         
    }

    for(int i = 0; i < numero_clientes; i++)
    {
        if(carros[id_carro].id_vendido == clientes[i].id)
        {
            styleOutput("Bold","","Datos del vendedor:");cout<<endl<<endl;
            clientes[i].mostrarDatos(clientes[i].id, clientes[i].nombre, clientes[i].apellido, clientes[i].email, clientes[i].edad);cout<<endl<<endl;   
        }       
    }
    reiniciar = false;
}
