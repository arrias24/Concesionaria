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