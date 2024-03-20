#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
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
    archivo_clientes.open("../assets/clients.csv");archivo_carros.open("../assets/cars.csv");
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
        cout<<"8) ";styleOutput("subrayado","","Mostrar ganancias o perdidas en la compra y venta de un carro.");cout<<endl;
        cout<<"9) ";styleOutput("subrayado","","Estado global de la concensionaria.");cout<<endl<<endl;
        styleOutput("italic","yellow","[OPERACION] -->"); operacion = styleIputInt("yellow");

        switch (operacion)
        {
            case 1:{  //CARROS COMPRADOS Y VENDIDOS POR UN CLIENTE
                int id_cliente, carros_vendidos = 0, carros_comprados = 0; bool estado = false;
                string marca_carros_vendidos[2000], modelo_carros_vendidos[2000], year_carros_vendidos[2000];
                string marca_carros_comprados[2000], modelo_carros_comprados[2000], year_carros_comprados[2000];

                //GUARDAMOS INFORMACION DE LOS CARROS VENDIDOS Y COMRPRADOS POR EL CLIENTE
                styleOutput("italic", "yellow","Ingrese el ID del cliente para mostar informacion de compras y ventas:");id_cliente = styleIputInt("yellow");
                for(int i = 0; i < numero_clientes; i++){
                    if(clientes[i].id == id_cliente){
                        id_cliente = i;
                        estado = true;
                    }
                }

                if(estado == false){
                     styleOutput("","rojo","""[ERROR]: No existe un cliente con el ID ingresado");
                     reiniciar = false;
                     break;
                }

                for(int i = 0; i < numero_carros; i++){
                    if(clientes[id_cliente].id == carros[i].id_vendido){
                        marca_carros_vendidos[i] = carros[i].marca;
                        modelo_carros_vendidos[i] = carros[i].modelo;
                        year_carros_vendidos[i] = std::to_string(carros[i].year);
                        carros_vendidos++;
                    }
                    if(clientes[id_cliente].id == carros[i].id_comprado)
                    {
                        marca_carros_comprados[i] = carros[i].marca;
                        modelo_carros_comprados[i] = carros[i].modelo;
                        year_carros_comprados[i] = std::to_string(carros[i].year);
                        carros_comprados++;
                    }
                }

                //MOSTRAMOS LOS CARROS COMPRADOS Y VENIDOS POR EL CLIENTE
                styleOutput("bold","","Cliente:");cout<<clientes[id_cliente].id<<" "<<clientes[id_cliente].nombre<<" "<<clientes[id_cliente].apellido<<" "<<clientes[id_cliente].email<<" "<<clientes[id_cliente].edad<<endl<<endl;
                styleOutput("bold","","Carros vendidos:");cout<<carros_vendidos<<endl<<endl;
                for(int i = 0; i < numero_carros; i++){
                    if(clientes[id_cliente].id == carros[i].id_vendido)
                    {
                        styleOutput("bold","","Marca:");cout<<marca_carros_vendidos[i]<<endl;
                        styleOutput("bold","","Modelo:");cout<<modelo_carros_vendidos[i]<<endl;
                        styleOutput("bold","","""year:");cout<<year_carros_vendidos[i]<<endl<<endl;
                    }
                }

                styleOutput("bold","","Carros comprados:");cout<<carros_comprados<<endl<<endl;
                for(int i = 0; i < numero_carros; i++){
                    if(clientes[id_cliente].id == carros[i].id_comprado){
                    styleOutput("bold","","Marca:");cout<<marca_carros_comprados[i]<<endl;
                    styleOutput("bold","","Modelo:");cout<<modelo_carros_comprados[i]<<endl;
                    styleOutput("bold","","Año:");cout<<year_carros_comprados[i]<<endl<<endl;
                    }
                }
            reiniciar = false;    
            break;    
            }

            case 2:{ //HISTORIAL DE COMPRA Y VENTA DE UN CARRO
                int id_carro; bool estado = false;
                styleOutput("italic", "yellow","Ingresa el 'ID' del carro para buscar su informacion:");id_carro = styleIputInt("yellow");

                for(int i = 0; i < numero_carros; i++){
                    if(carros[i].id == id_carro){
                        id_carro = i;
                        estado = true;
                        }
                    }

                if(estado == false){
                     styleOutput("","rojo","""[ERROR]: No existe un carro con el ID ingresado");
                    reiniciar = false;
                     return 1;
                }    

                //BUSCAMOS EL CARRO POR SU ID Y LUEGO COMPARAMOS A SU COMPRADOR Y VENDEDOR
                for(int i = 0; i < numero_clientes; i++){
                    if(carros[id_carro].id_comprado == clientes[i].id){
                        styleOutput("bold","","Marca:");cout<<carros[id_carro].marca<<endl;
                        styleOutput("bold","","Modelo:");cout<<carros[id_carro].modelo<<endl;
                        styleOutput("bold","","Año:");cout<<carros[id_carro].year<<endl<<endl;
                        styleOutput("bold","","Comprado a:");cout<<clientes[i].id<<" "<<clientes[i].nombre<<" "<<clientes[i].apellido<<" "<<clientes[i].email<<" "<<clientes[i].edad<<endl<<endl;
                    }         
                }
                for(int i = 0; i < numero_clientes; i++){
                    if(carros[id_carro].id_vendido == clientes[i].id){
                        styleOutput("bold","","Vendido a:");cout<<clientes[i].id<<" "<<clientes[i].nombre<<" "<<clientes[i].apellido<<" "<<clientes[i].email<<" "<<clientes[i].edad<<endl<<endl;
                    }       
                }
                reiniciar = false;
                break;
            }

            case 3:{ //AGREGAR DATOS DE UN CLIENTE
                Clientes agregar;
                agregar.id = (numero_clientes);
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
                Carros agregar;
                agregar.id = (numero_carros);

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
                Carros modificar;
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