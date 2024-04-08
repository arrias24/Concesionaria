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

//CASO 3 - AGREGAR DATOS DE UN CLIENTE

void agregarDatosCliente(int numero_clientes, Usuarios clientes[], bool& reiniciar)
{
    //VARIABLES A UTILIZAR

    Usuarios agregar; int x = 0;

    //NUEVOS DATOS CLIENTE

    agregar.id = (numero_clientes + 1);
    styleOutput("bold","","Ingrese los datos del cliente:");cout<<endl<<endl;
    styleOutput("italic","yellow","Nombre:");cin>>agregar.nombre;
    styleOutput("italic","yellow","Apellido:");cin>>agregar.apellido;
    styleOutput("italic","yellow","E-mail:");cin>>agregar.email;
    styleOutput("italic","yellow","Edad:");cin>>agregar.edad;cout<<endl;

    //DETECTOR DE CLIENTE REPETIDO

    x = buscarClientePorNombre(numero_clientes, clientes, agregar, reiniciar);

    if (x == numero_clientes)
    {
        clientes[numero_clientes].agregarDatosUsuarios(numero_clientes, clientes, agregar);
        reiniciar = false;
    } 
}

//CASO 4 - AGREGAR DATOS DE UN CARRO

void agregarDatosCarro(int numero_clientes, int numero_carros,  Autos carros[], Usuarios clientes[], bool& reiniciar)
{
    Autos agregar; int id_vendido, id_comprado;
    agregar.id = (numero_carros + 1);
            
    //NUEVOS DATOS CARRO

    styleOutput("bold","","Ingrese los datos del carro:");cout<<endl<<endl;
    styleOutput("italic","yellow","Marca:");cin.ignore();getline(cin, agregar.marca);
    styleOutput("italic","yellow","Modelo:");getline(cin, agregar.modelo);
    styleOutput("italic","yellow","Año:");cin>>agregar.year;
    styleOutput("italic","yellow","ID del vendedor:");cin>>agregar.id_vendido;
    styleOutput("italic","yellow","ID del comprador:");cin>>agregar.id_comprado;
    styleOutput("italic","yellow","Precio de compra:");cin>>agregar.precio_vendido;
    styleOutput("italic","yellow","Precio de venta:");cin>>agregar.precio_comprado;cout<<endl;

    //DETECTOR DE CLIENTE AUSENTE

    buscarID(numero_clientes, numero_carros, carros, clientes, agregar, id_vendido, id_comprado, agregar.id_vendido, agregar.id_comprado, reiniciar);

    //GUARDAMOS DATOS DEL CARRO

    if (reiniciar == true)
    {
        carros[numero_carros + 1].agregarDatosAutos(numero_carros, carros, agregar);
        reiniciar = false;
    }
}

//CASO 5 - MODIFICAR DATOS DE UN CARRO

void agregarDatosCarro(int numero_clientes, int numero_carros,  Autos carros[], Usuarios clientes[], string encabezado_clientes, bool& reiniciar)
{
    //VARIABLES A UTILIZAR

    int id_modificar = 0, id_vendido = 0, id_comprado = 0; Autos modificar;

    //BUSCAMOS EL CARRO

    styleOutput("italic","yellow","Ingresa el 'ID' del carro para modificar sus datos:");id_modificar = styleIputInt("yellow");
    buscarCarro(id_modificar, numero_carros, carros, reiniciar);

    styleOutput("italic","yellow","ID del nuevo vendedor:");cin>>modificar.id_vendido;
    styleOutput("italic","yellow","ID del nuevo comprador:");cin>>modificar.id_comprado;
    styleOutput("italic","yellow","Precio de venta:");cin>>modificar.precio_vendido;
    styleOutput("italic","yellow","Precio de compra:");cin>>modificar.precio_comprado;cout<<endl;

    //ARCHIVO DE SALIDA

    ofstream salida;

    //GUARDAMOS DATOS DEL CARRO

    carros[id_modificar].id_vendido = modificar.id_vendido;
    carros[id_modificar].id_comprado = modificar.id_comprado;
    carros[id_modificar].precio_vendido = modificar.precio_vendido;
    carros[id_modificar].precio_comprado = modificar.precio_comprado;

    //BUSCAMOS EL CLIENTE
    
    buscarID(numero_clientes, numero_carros, carros, clientes, modificar, id_vendido, id_comprado, modificar.id_vendido, modificar.id_comprado, reiniciar);

    //GUARDAMOS DATOS DE EL ARCHIVO

    salida.open("../assets/cars.csv");
    salida<<encabezado_clientes<<endl;
    for (int i = 0; i < numero_carros; i++)
    {
        salida<<carros[i].id<<";"<<carros[i].marca<<";"<<carros[i].modelo<<";"<<carros[i].year<<";"<<carros[i].id_vendido<<";"<<carros[i].id_comprado<<";"<<carros[i].precio_vendido<<";"<<carros[i].precio_comprado<<endl;
    }

    //CERRAMOS ARCHIVO

    salida.close();
    styleOutput("bold","green","Datos del carro se modificaron exitosamente!");cout<<endl<<endl;
    reiniciar = false;
}

//CASO 6 - BORRAR DATOS DE UN CLIENTE

void borrarDatosCliente(string encabezado_clientes, int numero_clientes, Usuarios clientes[], bool& reiniciar)
{
    int id_borrar;
    styleOutput("italic","yellow","Ingresa el 'ID' del cliente para borrar sus datos:"); id_borrar = styleIputInt("yellow");

    //ARCHIVO DE SALIDA

    ofstream salida;
    abrirArchivoClientes(salida, "../assets/clients.csv");

    //GUARDAMOS DATOS DE LOS CLIENTES EXCEPTO DE QUIEN SE HA DE ELIMINAR

    salida<<encabezado_clientes<<endl;
    for(int i = 0; i < numero_clientes; i++)
    {
        if(clientes[i].id != id_borrar)
        {
            salida<<clientes[i].id<<";"<<clientes[i].nombre<<";"<<clientes[i].apellido<<";"<<clientes[i].email<<";"<<clientes[i].edad<<endl;
        }
    }

    //CERRAMOS ARCHIVO

    salida.close();
    styleOutput("bold","green","Datos del cliente borrado exitosamente!");cout<<endl<<endl;
    reiniciar = false;
}

//CASO 7 - BORRAR DATOS DE UN CARRO.

void borrarDatosCarro(string encabezado_carros, int numero_carros, Autos carros[], bool& reiniciar){

    int id_borrar;
    styleOutput("italic","yellow","Ingresa el 'ID' del carro para borrar sus datos:"); id_borrar = styleIputInt("yellow");

    //ARCHIVO DE SALIDA

    ofstream salida;
    abrirArchivoCarros(salida, "../assets/cars.csv");

    //GUARDAMOS DATOS DE LOS CARROS EXCEPTO DEL CUAL SE HA DE ELIMINAR

    salida<<encabezado_carros<<endl;
    for(int i = 0; i < numero_carros; i++)
    {
        if(carros[i].id != id_borrar){
            salida<<carros[i].id<<";"<<carros[i].marca<<";"<<carros[i].modelo<<";"<<carros[i].year<<";"<<carros[i].id_vendido<<";"<<carros[i].id_comprado<<";"<<carros[i].precio_vendido<<";"<<carros[i].precio_comprado<<endl;
        }
    }

    //CERRAMOS ARCHIVO

    salida.close();
    styleOutput("bold","green","Datos del carro borrado exitosamente!");cout<<endl<<endl;
    reiniciar = false;
}