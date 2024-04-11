#include <iostream>
using namespace std;
#include "../modelo/clases.h"


int binarySearch (int low, int high, Usuarios* clientes, int id_cliente, bool estado){
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(clientes[mid].id == id_cliente) {
                estado = true;
                return mid;
            } 
        else if (clientes[mid].id < id_cliente) {
            low = mid + 1;
            } 
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearch (int low, int high, Autos* carros, int id_cliente, bool estado){
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(carros[mid].id == id_cliente) {
                estado = true;
                return mid;
            } 
        else if (carros[mid].id < id_cliente) {
            low = mid + 1;
            } 
        else{
            high = mid - 1;
        }
    }
    return -1;
}