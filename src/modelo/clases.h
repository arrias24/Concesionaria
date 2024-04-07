#include <iostream>
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
            cout<<"- Id: "<<id<<endl;
            cout<<"- Nombre: "<<nombre<<endl;
            cout<<"- Apellido: "<<apellido<<endl;
            cout<<"- Email: "<<email<<endl;
            cout<<"- Edad: "<<edad<<endl;
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
            cout<<"- Id: "<<id<<endl;
            cout<<"- Marca: "<<marca<<endl;
            cout<<"- Modelo: "<<modelo<<endl;
            cout<<"- Ano: "<<year<<endl;
            cout<<"- Id vendedor: "<<id_vendido<<endl;
            cout<<"- Id comprador: "<<id_comprado<<endl;
            cout<<"- Precio de compra: "<<precio_vendido<<endl;
            cout<<"- Precio de venta: "<<precio_comprado<<endl<<endl;
        }
};
#endif