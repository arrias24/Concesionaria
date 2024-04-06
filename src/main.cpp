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
                Usuarios agregar;
                agregar.id = (numero_clientes + 1);
                styleOutput("bold","","Ingrese los datos del cliente:");cout<<endl<<endl;
                styleOutput("italic","yellow","Nombre:");cin>>agregar.nombre;
                styleOutput("italic","yellow","Apellido:");cin>>agregar.apellido;
                styleOutput("italic","yellow","E-mail:");cin>>agregar.email;
                styleOutput("italic","yellow","Edad:");cin>>agregar.edad;cout<<endl;

                //DETECTOR DE CLIENTE REPETIDO
                int x;
                for (int i = 0; i < numero_clientes; i++)
                {
                    if (agregar.nombre == clientes[i].nombre)
                    {
                        for (int j = 0; j < numero_clientes; j++)
                        {
                            if (agregar.apellido == clientes[j].apellido)
                            {
                                styleOutput("bold","red","[Error] El cliente ya se encuentra en la base de datos.");cout<<endl<<endl;
                                return 1;
                            }
                        }
                    }
                    x += 1;         
                }

                if (x == numero_clientes)
                {
                    //ARCHIVO DE SALIDA
                    ofstream salida;
                    salida.open("../assets/clients.csv", ios::app);

                    //GUARDAMOS DATOS DEL CLIENTE
                    numero_clientes += 1;
                    clientes[numero_clientes].id = agregar.id;
                    clientes[numero_clientes].nombre = agregar.nombre;
                    clientes[numero_clientes].apellido = agregar.apellido;
                    clientes[numero_clientes].email = agregar.email;
                    clientes[numero_clientes].edad = agregar.edad;

                    salida<<clientes[numero_clientes].id<<";"<<clientes[numero_clientes].nombre<<";"<<clientes[numero_clientes].apellido<<";"<<clientes[numero_clientes].email<<";"<<clientes[numero_clientes].edad<<endl;
                    styleOutput("bold","green","Datos del cliente se guardaron exitosamente!");cout<<endl<<endl;

                }
                reiniciar = false;   
                break; 
            }

            case 4:{ //AGREGAR DATOS DE UN CARRO
                Autos agregar;
                agregar.id = (numero_carros + 1);

                styleOutput("bold","","Ingrese los datos del carro:");cout<<endl<<endl;
                styleOutput("italic","yellow","Marca:");cin.ignore();getline(cin, agregar.marca);
                styleOutput("italic","yellow","Modelo:");getline(cin, agregar.modelo);
                styleOutput("italic","yellow","Año:");cin>>agregar.year;
                styleOutput("italic","yellow","ID del vendedor:");cin>>agregar.id_vendido;
                styleOutput("italic","yellow","ID del comprador:");cin>>agregar.id_comprado;
                styleOutput("italic","yellow","Precio de venta:");cin>>agregar.precio_vendido;
                styleOutput("italic","yellow","Precio de compra:");cin>>agregar.precio_comprado;cout<<endl;
                
                //DETECTOR DE CLIENTE AUSENTE
                if (agregar.id_vendido > numero_clientes) 
                {
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
                    return 1;
                }else if (agregar.id_comprado > numero_clientes) {
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
                    return 1;
                }
                
                bool flag = true;
                for (int i = 0; i < numero_clientes; i++)
                {
                    if (clientes[i].id == agregar.id_vendido)
                    {
                        flag = false;
                    }
                }if (flag == true) {
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
                    return 1;
                }for (int i = 0; i < numero_clientes; i++)
                {
                    if (clientes[i].id == agregar.id_comprado)
                    {
                        flag = false;
                    }
                }if (flag ==  true){
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
                    return 1;
                }
                    
                //GUARDAMOS DATOS DEL CARRO               
                if (flag == false)
                {
                    //ARCHIVO DE SALIDA
                    ofstream salida;
                    salida.open("../assets/cars.csv", ios::app);

                    numero_carros += 1;
                    carros[numero_carros].id = agregar.id;
                    carros[numero_carros].marca = agregar.marca;
                    carros[numero_carros].modelo = agregar.modelo;
                    carros[numero_carros].year = agregar.year;
                    carros[numero_carros].id_vendido = agregar.id_vendido;
                    carros[numero_carros].id_comprado = agregar.id_comprado;
                    carros[numero_carros].precio_vendido = agregar.precio_vendido;
                    carros[numero_carros].precio_comprado = agregar.precio_comprado;
            
                    salida<<carros[numero_carros].id<<";"<<carros[numero_carros].marca<<";"<<carros[numero_carros].modelo<<";"<<carros[numero_carros].year<<";"<<carros[numero_carros].id_vendido<<";"<<carros[numero_carros].id_comprado<<";"<<carros[numero_carros].precio_vendido<<";"<<carros[numero_carros].precio_comprado<<endl;
                    styleOutput("bold","green","Datos del carro se guardaron exitosamente!");cout<<endl<<endl;
                }
                reiniciar = false;
                break;
            }

            case 5:{ //MODIFICAR DATOS DE UN CARRO
                int id_modificar;
                Autos modificar;
                styleOutput("italic","yellow","Ingresa el 'ID' del carro para modificar sus datos:");id_modificar = styleIputInt("yellow");

                //BUSCAMOS EL CARRO POR SU ID
                bool carroExiste = false;
                for (size_t i = 0; i < numero_carros; i++)
                {
                    if(carros[i].id == id_modificar)
                    {
                        carroExiste = true;
                        break;
                    }
                }

                if (carroExiste)
                {
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

                    //DETECTOR DE CLIENTE AUSENTE
                    if (modificar.id_vendido > numero_clientes) 
                    {
                        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
                        return 1;
                    }else if (modificar.id_comprado > numero_clientes) {
                        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
                        return 1;
                    }

                    bool flag = false;
                    for (int i = 0; i < numero_clientes; i++)
                    {
                        if (clientes[i].id == modificar.id_vendido)
                        {
                            flag = true;
                        }
                    }if (flag == false) {
                        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del vendedor seleccionado.");cout<<endl<<endl;
                        return 1;
                    }for (int i = 0; i < numero_clientes; i++)
                    {
                        if (clientes[i].id == modificar.id_comprado)
                        {
                            flag = true;
                        }
                    }if (flag ==  false){
                        styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del comprador seleccionado.");cout<<endl<<endl;
                        return 1;
                    }

                    //GUARDAMOS DATOS DE EL ARCHIVO
                    salida.open("../assets/cars.csv");
                    salida<<encabezado_clientes<<endl;
                    for (int i = 1; i < numero_carros; i++)
                    {
                        salida<<carros[i].id<<";"<<carros[i].marca<<";"<<carros[i].modelo<<";"<<carros[i].year<<";"<<carros[i].id_vendido<<";"<<carros[i].id_comprado<<";"<<carros[i].precio_vendido<<";"<<carros[i].precio_comprado<<endl;
                    }
                    styleOutput("bold","green","Datos del carro se modificaron exitosamente!");cout<<endl<<endl;
                }
                else
                {
                    styleOutput("bold", "red", "[ERROR] No se encontró el 'ID' del carro seleccionado.");
                    cout<<endl<<endl;
                    return 1;
                }
                reiniciar = false;
                break;
            }

            case 6:{ //BORRAR DATOS DE UN CLIENTE
                int id_borrar;
                styleOutput("italic","yellow","Ingresa el 'ID' del cliente para borrar sus datos:"); id_borrar = styleIputInt("yellow");

                //ARCHIVO DE SALIDA
                ofstream salida;
                salida.open("../assets/clients.csv");

                //GUARDAMOS DATOS DE LOS CLIENTES EXCEPTO DE QUIEN SE HA DE ELIMINAR
                salida<<encabezado_clientes<<endl;
                for(int i = 0; i < numero_clientes; i++){
                    if(clientes[i].id != id_borrar){
                        salida<<clientes[i].id<<";"<<clientes[i].nombre<<";"<<clientes[i].apellido<<";"<<clientes[i].email<<";"<<clientes[i].edad<<endl;
                    }
                }

                //CERRAMOS ARCHIVO
                salida.close();
                styleOutput("bold","green","Datos del cliente borrado exitosamente!");cout<<endl<<endl;
                reiniciar = false;
                break;
            }

            case 7:{ //BORRAR DATOS DE UN CARROS
                int id_borrar;
                styleOutput("italic","yellow","Ingresa el 'ID' del carro para borrar sus datos:"); id_borrar = styleIputInt("yellow");

                //ARCHIVO DE SALIDA
                ofstream salida;
                salida.open("../assets/cars.csv");

                //GUARDAMOS DATOS DE LOS CARROS EXCEPTO DEL CUAL SE HA DE ELIMINAR
                salida<<encabezado_carros<<endl;
                for(int i = 0; i < numero_carros; i++)
                    {
                        if(carros[i].id != id_borrar)
                        {
                            salida<<carros[i].id<<";"<<carros[i].marca<<";"<<carros[i].modelo<<";"<<carros[i].year<<";"<<carros[i].id_vendido<<";"<<carros[i].id_comprado<<";"<<carros[i].precio_vendido<<";"<<carros[i].precio_comprado<<endl;
                        }
                    }

                //CERRAMOS ARCHIVO
                salida.close();
                styleOutput("bold","green","Datos del carro borrado exitosamente!");cout<<endl<<endl;
                reiniciar = false;
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

            case 9:{//Estado global de la concensionaria
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