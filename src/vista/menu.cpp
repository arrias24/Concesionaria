#include <iostream>
#include "../modelo/estilos.h"
using namespace std;

int mostrarMenu(int operacion){
    cout<<endl;styleOutput("bold","","                    //// CONCESIONARIA ////                    ");cout<<endl<<endl;
    cout<<"1) ";styleOutput("subrayado","","Mostrar carros comprados y vendidos de un cliente.");cout<<endl;
    cout<<"2) ";styleOutput("subrayado","","Mostrar datos de un vendedor o comprador de un carro.");cout<<endl;
    cout<<"3) ";styleOutput("subrayado","","Agregar datos de un cliente.");cout<<endl;
    cout<<"4) ";styleOutput("subrayado","","Agregar datos de un carro.");cout<<endl;
    cout<<"5) ";styleOutput("subrayado","","Modificar datos de un carro.");cout<<endl;
    cout<<"6) ";styleOutput("subrayado","","Eliminar datos de un cliente.");cout<<endl;
    cout<<"7) ";styleOutput("subrayado","","Eliminar datos de un carro.");cout<<endl;
    cout<<"8) ";styleOutput("subrayado","","Mostrar ganancias o perdidas en la compra y venta de un carro.");cout<<endl;
    cout<<"9) ";styleOutput("subrayado","","Estado global de la concensionaria.");cout<<endl<<endl<<endl;
    styleOutput("italic","yellow","[OPERACION] -->"); operacion = styleIputInt("yellow");
    return operacion;
}

void mostrarMenuError(bool& reiniciar){
    string decision;
    styleOutput("bold","red","[ERROR] Has ingresado una operacion invalida.");cout<<endl<<endl;
    styleOutput("italic","yellow","Deseas volver a intentarlo? (s/n):");decision = styleIputChar("yellow");
    lowercase(decision);

    if(decision == "n"){
        reiniciar = false;
    }
}

void bucle(bool& reiniciar){
    string decision;
    styleOutput("italic","yellow","Deseas volver a usar el programa? (s/n):");decision = styleIputChar("yellow");
    lowercase(decision);

    if(decision == "n"){
        reiniciar = false;
    }
}