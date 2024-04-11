//GLOBALES
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

//PROTOTIPOS
#include "./modelo/binarySearch.h"
#include "./modelo/clases.h"
#include "./modelo/estructuras.h"

//IMPLEMENTACIONES
#include "./controlador/estilos.cpp"
#include "./controlador/manipularArchivos.cpp"
#include "./controlador/guardarDatos.cpp"
#include "./controlador/manipularDatos.cpp"
#include "./controlador/binarySearch.cpp"
#include "./controlador/operaciones.cpp"
#include "./vista/menu.cpp"

using namespace std;

int main()
{
    bool reiniciar = true;
    while( reiniciar == true)
    {
    //CREAMOS VARIABLE DE ARCHIVOS, ABRIMOS ARCHIVOS Y LEEMOS

    ifstream archivo_clientes, archivo_carros;
    abrirArchivoClientes(archivo_clientes, "../assets/clients.csv"); abrirArchivoCarros(archivo_carros, "../assets/cars.csv");

    //CREAMOS VARIABLES, CONTAMOS CLIENTES Y USUARIOS, GUARDAMOS DATOS DE CLIENTES Y CARROS EN OBJETOS
    
    int capacidad_clientes = leerCantidad(archivo_clientes); int capacidad_carros = leerCantidad(archivo_carros);
    abrirArchivoClientes(archivo_clientes, "../assets/clients.csv"); abrirArchivoCarros(archivo_carros, "../assets/cars.csv");
    

    Usuarios* clientes = new Usuarios[capacidad_clientes];
    Autos* carros = new Autos[capacidad_carros];
    int numero_clientes = 0, numero_carros = 0;
    string encabezado_clientes, encabezado_carros;
 
    guardarDatosClientes(archivo_clientes, encabezado_clientes, clientes, numero_clientes, capacidad_clientes);
    guardarDatosCarros(archivo_carros, encabezado_carros, carros, numero_carros, capacidad_carros);

    //OPERACIONES 


        //LLAMAMOS A LA FUNCION
        
        int operacion = mostrarMenu(operacion);

        switch (operacion)
        {
            case 1:{  //CARROS COMPRADOS Y VENDIDOS POR UN CLIENTE
                mostrarHistorialCliente(numero_clientes, numero_carros, clientes, carros, reiniciar);
                bucle(reiniciar);

                break;
            }

            case 2:{ //HISTORIAL DE COMPRA Y VENTA DE UN CARRO

                //LLAMAMOS A LA FUNCION

                mostrarHistorialCarro(numero_clientes, numero_carros, clientes, carros, reiniciar);
                bucle(reiniciar);

                //FIN

                break;
            }

            case 3:{ //AGREGAR DATOS DE UN CLIENTE

                //LLAMAMOS A LA FUNCION

                agregarDatosCliente(numero_clientes, clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break;
            }

            case 4:{ //AGREGAR DATOS DE UN CARRO

                //LLAMAMOS A LA FUNCION

                agregarDatosCarro(numero_clientes, numero_carros,  carros, clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break;   
            }

            case 5:{ //MODIFICAR DATOS DE UN CARRO

                //LLAMAMOS A LA FUNCION

                agregarDatosCarro(numero_clientes, numero_carros,  carros, clientes, encabezado_clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break;
            }

            case 6:{ //BORRAR DATOS DE UN CLIENTE
                
                //LLAMAMOS A LA FUNCION

                borrarDatosCliente(encabezado_clientes, numero_clientes, clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break;
            }

            case 7:{ //BORRAR DATOS DE UN CARROS

                //LLAMAMOS A LA FUNCION

                borrarDatosCarro(encabezado_carros, numero_carros, carros, reiniciar);
                bucle(reiniciar);

                //FIN

                break;    
            }

            case 8:{ //GANANCIAS DE COMPRA Y VENTA DE UN CARRO

                //LLAMAMOS A LA FUNCION

                gananciasDeUnCarro(numero_clientes, numero_carros, carros, clientes, encabezado_clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break;  
            }

            case 9:{ //ESTADO GLOBAL DE LA CONSECIONARIA
            
                //LLAMAMOS A LA FUNCION

                estadoGlobal(numero_clientes, numero_carros,  carros, clientes, encabezado_clientes, reiniciar);
                bucle(reiniciar);

                //FIN

                break; 
            }

            default:{ //OPCION POR DEFECTO

                //LLAMAMOS A LA FUNCION

                mostrarMenuError(reiniciar);
            }
        }
    }
    return 0;
}