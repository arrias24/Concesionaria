#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "./vista/style.cpp"
using namespace std;

//ESTRUCTURAS
struct Clientes {
    int id;
    string nombre;
    string apellido;
    string email;
    int edad;
};

struct Carros{
    int id;
    string marca;
    string modelo;
    int year;
    int id_vendido;
    int id_comprado;
    float precio_vendido;
    float precio_comprado;
};

int main()
{
    //ABRIMOS ARCHIVOS Y LEEMOS

    ifstream archivo_clientes, archivo_carros;
    archivo_clientes.open("../assets/clients.txt");archivo_carros.open("../assets/cars.txt");
    if(!archivo_clientes.is_open() || !archivo_carros.is_open())
    {
        cout<<endl;styleOutput("bold","red","[ERROR] No se ha podido abrir el archivo correctamente.");cout<<endl;
        return 0;
    }

    //GUARDAMOS DATOS DE CLIENTES Y CARROS EN SUS ESTRUCTURAS

    string encabezado_clientes, encabezado_carros;
    getline(archivo_clientes, encabezado_clientes,'\n'); getline(archivo_carros, encabezado_carros,'\n');

    Clientes clientes[2000]; Carros carros[2000];

    string linea; int numero_clientes = 0, numero_carros = 0;

    while(getline(archivo_clientes, linea, '\n')){
        stringstream stream(linea);
        string dato;
        getline(stream, dato, ';');
        clientes[numero_clientes].id = std::stoi(dato);
        getline(stream,dato,';');
        clientes[numero_clientes].nombre = dato;
        getline(stream,dato,';');
        clientes[numero_clientes].apellido = dato;
        getline(stream,dato,';');
        clientes[numero_clientes].email = dato;
        getline(stream,dato,' ');
        clientes[numero_clientes].edad = std::stoi(dato);
        numero_clientes++;
    }

    archivo_clientes.close();

    while(getline(archivo_carros, linea, '\n')){
        stringstream stream(linea);
        string dato;
        getline(stream, dato, ';');
        carros[numero_carros].id = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].marca = dato;
        getline(stream,dato,';');
        carros[numero_carros].modelo = dato;
        getline(stream,dato,';');
        carros[numero_carros].year = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].id_vendido = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].id_comprado = std::stoi(dato);
        getline(stream,dato,';');
        carros[numero_carros].precio_vendido = std::stof(dato);
        getline(stream,dato,'\n');
        carros[numero_carros].precio_comprado = std::stof(dato);            
        numero_carros++;
    }

    archivo_carros.close();

    //MOSTRAMOS OPERACIONES 

    bool reiniciar = true;
    while( reiniciar == true)
    {
        int operacion;cout<<endl;
        styleOutput("bold","","                    //// CONCESIONARIA ////                    ");cout<<endl<<endl;
        cout<<"1) ";styleOutput("subrayado","","Mostrar carros comprados y vendidos de un cliente.");cout<<endl;
        cout<<"2) ";styleOutput("subrayado","","Mostrar datos de un vendedor o comprador de un carro.");cout<<endl;
        cout<<"3) ";styleOutput("subrayado","","Agregar datos de un cliente.");cout<<endl;
        cout<<"4) ";styleOutput("subrayado","","Agregar datos de un carro.");cout<<endl;
        cout<<"5) ";styleOutput("subrayado","","Modificar datos de un carro.");cout<<endl;
        cout<<"6) ";styleOutput("subrayado","","Eliminar datos de un cliente.");cout<<endl;
        cout<<"7) ";styleOutput("subrayado","","Eliminar datos de un carro.");cout<<endl;
        cout<<"8) ";styleOutput("subrayado","","Mostrar ganancias o perdidas en la compra y venta de un carro.");cout<<endl<<endl;
        styleOutput("italic","yellow","[OPERACION] -->"); operacion = styleIputInt("yellow");

        switch (operacion)
        {
            default:{ //OPCION POR DEFECTO
                string decision;
                styleOutput("bold","red","[ERROR] Has ingresado una operacion invalida.");cout<<endl;
                styleOutput("italic","yellow","Deseas volver a intentarlo? (s/n):");decision = styleIputChar("yellow");
                lowercase(decision);

                if(decision == "n"){
                    reiniciar = false;
                    break;
                }
            }
        }
    }
    return 0;
}