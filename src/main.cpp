//GLOBALES
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

//PROTOTIPOS
#include "./modelo/clases.h"
#include "./modelo/estructuras.h"
#include "./modelo/binarySearch.h"

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
    //CREAMOS VARIABLE DE ARCHIVOS, ABRIMOS ARCHIVOS Y LEEMOS

    ifstream archivo_clientes, archivo_carros;
    abrirArchivoClientes(archivo_clientes, "../assets/clients.csv"); abrirArchivoCarros(archivo_carros, "../assets/cars.csv");

    //CREAMOS VARIABLES, GUARDAMOS DATOS DE CLIENTES Y CARROS EN OBJETOS
    
    Usuarios clientes[2000]; Autos carros[2000];
    int numero_clientes = 0, numero_carros = 0;
    string encabezado_clientes, encabezado_carros;
 
    guardarDatos(archivo_clientes, archivo_carros, encabezado_clientes, encabezado_carros,clientes, carros,  numero_clientes,  numero_carros);


    bool reiniciar = true;
    while( reiniciar == true)
    {
        //MOSTRAMOS OPERACIONES 
        
        int operacion = mostrarMenu(operacion);

        switch (operacion)
        {
            case 1:{  //CARROS COMPRADOS Y VENDIDOS POR UN CLIENTE

                //LLAMAMOS A LA FUNCION

                mostrarHistorialCliente(numero_clientes, numero_carros, clientes, carros, reiniciar);

                //FIN

                break;    
            }

            case 2:{ //HISTORIAL DE COMPRA Y VENTA DE UN CARRO

                //LLAMAMOS A LA FUNCION

                mostrarHistorialCarro(numero_clientes, numero_carros, clientes, carros, reiniciar);

                //FIN

                break;
            }

            case 3:{ //AGREGAR DATOS DE UN CLIENTE

                //LLAMAMOS A LA FUNCION

                agregarDatosCliente(numero_clientes, clientes, reiniciar);

                //FIN

                break;
            }

            case 4:{ //AGREGAR DATOS DE UN CARRO

                //LLAMAMOS A LA FUNCION

                agregarDatosCarro(numero_clientes, numero_carros,  carros, clientes, reiniciar);

                //FIN

                break;   
            }

            case 5:{ //MODIFICAR DATOS DE UN CARRO

                //LLAMAMOS A LA FUNCION

                agregarDatosCarro(numero_clientes, numero_carros,  carros, clientes, encabezado_clientes, reiniciar);

                //FIN

                break;
            }

            case 6:{ //BORRAR DATOS DE UN CLIENTE

                //LLAMAMOS A LA FUNCION

                borrarDatosCliente(encabezado_clientes, numero_clientes, clientes, reiniciar);

                //FIN

                break;
            }

            case 7:{ //BORRAR DATOS DE UN CARROS

                //LLAMAMOS A LA FUNCION

                borrarDatosCarro(encabezado_carros, numero_carros, carros, reiniciar);

                //FIN

                break;     
            }

            case 8:{ //GANANCIAS DE COMPRA Y VENTA DE UN CARRO

                //LLAMAMOS A LA FUNCION

                gananciasDeUnCarro(numero_clientes, numero_carros, carros, clientes, encabezado_clientes, reiniciar);

                //FIN

                break;  
            }

            case 9:{//ESTADO GLOBAL DE LA CONSECIONARIA
            
                float valencia_de_compra, valencia_de_venta, valencia_gobal;

                styleOutput("bold","yellow","Estado global de la concesionaria es el siguiente:");cout<<endl<<endl;
                for (int i = 0; i < numero_carros; i++)
                {
                    valencia_de_compra += carros[i].precio_comprado;
                    valencia_de_venta += carros[i].precio_vendido;
                }
                valencia_gobal = valencia_de_compra - valencia_de_venta;

                styleOutput("bold","","Numero de clientes:");styleOutput("bold", numero_clientes);cout<<endl;
                styleOutput("bold","","Numero de carros:");styleOutput("bold", numero_carros);cout<<endl<<endl;;

                if (valencia_gobal > 0)
                {
                    styleOutput("italic","green","[GANANCIA] -->");cout<<fixed<<setprecision(0);styleOutput("green", valencia_gobal);styleOutput("green","$");cout<<endl<<endl;
                    cout.unsetf(ios_base::floatfield);
                }else if (valencia_gobal <= 0)
                {
                    styleOutput("italic","red","[PERDIDA] -->");cout<<fixed<<setprecision(0);styleOutput("red", abs(valencia_gobal));styleOutput("red","$");cout<<endl<<endl;
                    cout.unsetf(ios_base::floatfield);
                }   
                reiniciar = false;
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