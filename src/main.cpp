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
                int id_valance_de_venta;
                styleOutput("italic","yellow","Ingresa el 'ID' del carro para mostrar el valance de ganancia:"); id_valance_de_venta = styleIputInt("yellow");

                //BUSCAMOS EL CARRO POR SU ID Y LUEGO VERIFICAMOS SU GANANCIA
                bool carroExiste = false;
                for (size_t i = 0; i < numero_carros; i++)
                {
                    if(carros[i].id == id_valance_de_venta)
                    {
                        carroExiste = true;
                        break;
                    }
                }

                if (carroExiste)
                {
                    float valance_de_venta;
                    for (size_t i = 0; i < numero_clientes; i++)
                    {
                        if(carros[id_valance_de_venta].id_comprado == clientes[i].id)
                        {
                            valance_de_venta = carros[id_valance_de_venta].precio_comprado - carros[id_valance_de_venta].precio_vendido;
                        }
                    }
                
                    if (valance_de_venta > 0)
                    {
                        for(int i = 0; i < numero_clientes; i++)
                        {
                            if(carros[id_valance_de_venta].id_comprado == clientes[i].id)
                            {
                                styleOutput("bold","","Marca:");cout<<carros[id_valance_de_venta].marca<<endl;
                                styleOutput("bold","","Modelo:");cout<<carros[id_valance_de_venta].modelo<<endl;
                                styleOutput("bold","","Año:");cout<<carros[id_valance_de_venta].year<<endl<<endl;
                                styleOutput("bold","","Precio de venta:");cout<<carros[id_valance_de_venta].precio_vendido<<endl;
                                styleOutput("bold","","Precio de compra:");cout<<carros[id_valance_de_venta].precio_comprado<<endl<<endl;
                                styleOutput("italic","green","[GANANCIA] -->");styleOutput("green",valance_de_venta);styleOutput("green","$");cout<<endl<<endl;
                            }         
                        }
                    }else if (valance_de_venta <= 0)
                    {
                        for(int i = 0; i < numero_clientes; i++)
                        {
                            if(carros[id_valance_de_venta].id_comprado == clientes[i].id)
                            {
                                styleOutput("bold","","Marca:");cout<<carros[id_valance_de_venta].marca<<endl;
                                styleOutput("bold","","Modelo:");cout<<carros[id_valance_de_venta].modelo<<endl; 
                                styleOutput("bold","","Año:");cout<<carros[id_valance_de_venta].year<<endl<<endl;
                                styleOutput("bold","","Precio de venta:");cout<<carros[id_valance_de_venta].precio_vendido<<endl;
                                styleOutput("bold","","Precio de compra:");cout<<carros[id_valance_de_venta].precio_comprado<<endl<<endl;
                                styleOutput("italic","red","[PERDIDA] -->");styleOutput("red",abs(valance_de_venta));styleOutput("red","$");cout<<endl<<endl;
                            }         
                        }
                    }

                }else
                {
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del carro seleccionado.");cout<<endl<<endl;
                    return 1;
                    break;
                }
                reiniciar = false;
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