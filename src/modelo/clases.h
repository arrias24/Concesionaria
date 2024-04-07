#include <iostream>

#include "./estilos.h"
using namespace std;
#ifndef CLASES_H
#define CLASES_H
class Usuarios {

    public:
    //MIEMBROS
        int id;
        string nombre;
        string apellido;
        string email;
        int edad;
    //METODOS
        void mostrarDatos(int id, string nombre, string apellido, string email, int edad){
            cout<<"- ";styleOutput("Bold","","Id:");cout<<id<<endl;
            cout<<"- ";styleOutput("Bold","","Nombre:");cout<<nombre<<endl;
            cout<<"- ";styleOutput("Bold","","Apellido:");cout<<apellido<<endl;
            cout<<"- ";styleOutput("Bold","","Email:");cout<<email<<endl;
            cout<<"- ";styleOutput("Bold","","Edad:");cout<<edad<<endl;
        }
        void agregarDatosUsuarios(int numero_clientes, Usuarios clientes[], Usuarios agregar)
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
        
            //CERRAMOS ARCHIVO

            salida.close();
            styleOutput("bold","green","Datos del cliente se guardaron exitosamente!");cout<<endl<<endl;
        }
};

class Autos{

    public:
    //MIEMBROS
        int id;
        string marca;
        string modelo;
        int year;
        int id_vendido;
        int id_comprado;
        float precio_vendido;
        float precio_comprado;
    //METODOS
        void mostrarDatos(int id, string marca, string modelo, int year, int id_vendido, int id_comprado, float precio_vendido, float precio_comprado){
            cout<<"- ";styleOutput("Bold","","Id:");cout<<id<<endl;
            cout<<"- ";styleOutput("Bold","","Marca:");cout<<marca<<endl;
            cout<<"- ";styleOutput("Bold","","Modelo:");cout<<modelo<<endl;
            cout<<"- ";styleOutput("Bold","","Año:");cout<<year<<endl;
            cout<<"- ";styleOutput("Bold","","Id vendedor:");cout<<id_vendido<<endl;
            cout<<"- ";styleOutput("Bold","","Id comprador:");cout<<id_comprado<<endl;
            cout<<"- ";styleOutput("Bold","","Precio de compra:");cout<<precio_vendido<<endl;
            cout<<"- ";styleOutput("Bold","","Precio de venta:");cout<<precio_comprado<<endl;
        }

        void agregarDatosAutos(int numero_carros, Autos carros[], Autos agregar)
        {
            //ARCHIVO DE SALIDA

            ofstream salida;
            salida.open("../assets/cars.csv", ios::app);

            //GUARDAMOS DATOS DEL CARRO

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

            //CERRAMOS ARCHIVO

            salida.close();
            styleOutput("bold","green","Datos del carro se guardaron exitosamente!");cout<<endl<<endl;
        }
};
#endif