#include <iostream>
#include <string>
using namespace std;

struct styleText
{
    string inicio;
    string cierre;
};

styleText colores[10]; styleText estilos[5];

//IMPLEMENTACION DE FUNCIONES
void styleOutput(string, string);
void styleOutput(string, string, string);
void styleOutput(string, float);
void styleOutput(string, string, float);
int styleIputInt(string);
char styleIputChar(string);
string styleIputString(string);
void lowercase(string &variable);

//SELECTOR DEL COLOR DEL TEXTO
void styleOutput(string color, string text)
{
    //PALETA DE COLORES
    colores[0].inicio = "\x1B[0m"; colores[0].cierre = "\x1B[0m"; // BLANCO
    colores[1].inicio = "\x1B[31m"; colores[1].cierre = "\x1B[0m"; //ROJO
    colores[2].inicio = "\x1B[32m"; colores[2].cierre = "\x1B[0m"; //VERDE
    colores[3].inicio = "\x1B[33m"; colores[3].cierre = "\x1B[0m"; //AMARILLO
    colores[4].inicio = "\x1B[34m"; colores[4].cierre = "\x1B[0m"; //AZUL
    colores[5].inicio = "\x1B[35m"; colores[5].cierre = "\x1B[0m"; //MORADO
    colores[6].inicio = "\x1B[36m"; colores[6].cierre = "\x1B[0m"; //AGUA

    //TRANFORMACION A MINUSCULAS
    lowercase(color);

    //IMPRESORA DE TEXTO
    if (color == "rojo" || color == "red")
    {
        cout<<colores[1].inicio<<text<<colores[1].cierre<<" ";
    }else if (color == "verde" || color == "green")
    {
        cout<<colores[2].inicio<<text<<colores[2].cierre<<" ";

    }else if (color == "amarrillo" || color == "yellow")
    {
        cout<<colores[3].inicio<<text<<colores[3].cierre<<" ";

    }else if (color == "azul" || color == "blue")
    {
        cout<<colores[4].inicio<<text<<colores[4].cierre<<" ";
    }else if (color == "morado" || color == "purple")
    {
        cout<<colores[5].inicio<<text<<colores[5].cierre<<" ";
    }else if (color == "agua" || color == "aqua")
    {
        cout<<colores[6].inicio<<text<<colores[6].cierre<<" ";
    }else
    {
        cout<<text<<colores[0].cierre<<" ";
    }
}

//SELECTOR DEL TIPO DE TEXTO
void styleOutput(string style, string color, string text)
{
    //PALETA DE ESTILOS
    estilos[0].inicio = "\x1B[0m"; estilos[0].cierre = "\x1B[0m"; //NORMAL
    estilos[1].inicio = "\x1B[1m"; estilos[1].cierre = "\x1B[0m"; //NEGRITA
    estilos[2].inicio = "\x1B[3m"; estilos[2].cierre = "\x1B[0m"; //CURSIVA
    estilos[3].inicio = "\x1B[4m"; estilos[3].cierre = "\x1B[0m"; //SUBRAYADO


    //TRANFORMACION A MINUSCULAS
    lowercase(style);

    //IMPRESORA DE TEXTO
    if (style == "negrita" || style == "bold")
    {
        cout<<estilos[1].inicio; styleOutput(color, text);
    }else if (style == "cursiva" || style == "italic")
    {
        cout<<estilos[2].inicio; styleOutput(color, text);

    }else if (style == "subrayado" || style == "underline")
    {
        cout<<estilos[3].inicio; styleOutput(color, text);
    }else
    {
        styleOutput(color, text);
    }
}

//SELECTOR DEL COLOR DEL VARIABLE
void styleOutput(string color, float variable)
{
    //PALETA DE COLORES
    colores[0].inicio = "\x1B[0m"; colores[0].cierre = "\x1B[0m"; // BLANCO
    colores[1].inicio = "\x1B[31m"; colores[1].cierre = "\x1B[0m"; //ROJO
    colores[2].inicio = "\x1B[32m"; colores[2].cierre = "\x1B[0m"; //VERDE
    colores[3].inicio = "\x1B[33m"; colores[3].cierre = "\x1B[0m"; //AMARILLO
    colores[4].inicio = "\x1B[34m"; colores[4].cierre = "\x1B[0m"; //AZUL
    colores[5].inicio = "\x1B[35m"; colores[5].cierre = "\x1B[0m"; //MORADO
    colores[6].inicio = "\x1B[36m"; colores[6].cierre = "\x1B[0m"; //AGUA

    //TRANFORMACION A MINUSCULAS
    lowercase(color);

    //IMPRESORA DE TEXTO
    if (color == "rojo" || color == "red")
    {
        cout<<colores[1].inicio<<variable<<colores[1].cierre;
    }else if (color == "verde" || color == "green")
    {
        cout<<colores[2].inicio<<variable<<colores[2].cierre;

    }else if (color == "amarrillo" || color == "yellow")
    {
        cout<<colores[3].inicio<<variable<<colores[3].cierre;

    }else if (color == "azul" || color == "blue")
    {
        cout<<colores[4].inicio<<variable<<colores[4].cierre;
    }else if (color == "morado" || color == "purple")
    {
        cout<<colores[5].inicio<<variable<<colores[5].cierre;
    }else if (color == "agua" || color == "aqua")
    {
        cout<<colores[6].inicio<<variable<<colores[6].cierre;
    }else
    {
        cout<<variable<<colores[0].cierre;
    }
}

//SELECTOR DEL TIPO DE VARIABLE
void styleOutput(string style, string color, float variable)
{
    //PALETA DE ESTILOS
    estilos[0].inicio = "\x1B[0m"; estilos[0].cierre = "\x1B[0m"; //NORMAL
    estilos[1].inicio = "\x1B[1m"; estilos[1].cierre = "\x1B[0m"; //NEGRITA
    estilos[2].inicio = "\x1B[3m"; estilos[2].cierre = "\x1B[0m"; //CURSIVA
    estilos[3].inicio = "\x1B[4m"; estilos[3].cierre = "\x1B[0m"; //SUBRAYADO


    //TRANFORMACION A MINUSCULAS
    lowercase(style);

    //IMPRESORA DE TEXTO
    if (style == "negrita" || style == "bold")
    {
        cout<<estilos[1].inicio; styleOutput(color, variable);
    }else if (style == "cursiva" || style == "italic")
    {
        cout<<estilos[2].inicio; styleOutput(color, variable);

    }else if (style == "subrayado" || style == "underline")
    {
        cout<<estilos[3].inicio; styleOutput(color, variable);
    }else
    {
        styleOutput(color, variable);
    }
}

//SELECTOR DE COLOR PARA AL INGRESO DE DATOS INT
int styleIputInt(string color)
{
    //PALETA DE COLORES
    colores[0].inicio = "\x1B[0m"; colores[0].cierre = "\x1B[0m"; // BLANCO
    colores[1].inicio = "\x1B[31m"; colores[1].cierre = "\x1B[0m"; //ROJO
    colores[2].inicio = "\x1B[32m"; colores[2].cierre = "\x1B[0m"; //VERDE
    colores[3].inicio = "\x1B[33m"; colores[3].cierre = "\x1B[0m"; //AMARILLO
    colores[4].inicio = "\x1B[34m"; colores[4].cierre = "\x1B[0m"; //AZUL
    colores[5].inicio = "\x1B[35m"; colores[5].cierre = "\x1B[0m"; //MORADO
    colores[6].inicio = "\x1B[36m"; colores[6].cierre = "\x1B[0m"; //AGUA

    //TRANFORMACION A MINUSCULAS
    lowercase(color);

    int variable;

    //CASILLA DE OPCION
    if (color == "rojo" || color == "red")
    {
        cout<<colores[1].inicio; cin>>variable; cout<<colores[1].cierre;
    }else if (color == "verde" || color == "green")
    {
        cout<<colores[2].inicio; cin>>variable; cout<<colores[2].cierre<<endl;
    }else if (color == "amarrillo" || color == "yellow")
    {
        cout<<colores[3].inicio; cin>>variable; cout<<colores[3].cierre<<endl;
    }else if (color == "azul" || color == "blue")
    {
        cout<<colores[4].inicio; cin>>variable; cout<<colores[4].cierre<<endl;
    }else if (color == "morado" || color == "purple")
    {
        cout<<colores[5].inicio; cin>>variable; cout<<colores[5].cierre<<endl;
    }else if (color == "agua" || color == "aqua")
    {
        cout<<colores[6].inicio; cin>>variable; cout<<colores[6].cierre<<endl;
    }else
    {
        cout<<colores[0].inicio; cin>>variable; cout<<colores[0].cierre<<endl;
    }
    
    return variable;
}

//SELECTOR DE COLOR PARA AL INGRESO DE DATOS CHAR
char styleIputChar(string color)
{
    //PALETA DE COLORES
    colores[0].inicio = "\x1B[0m"; colores[0].cierre = "\x1B[0m"; // BLANCO
    colores[1].inicio = "\x1B[31m"; colores[1].cierre = "\x1B[0m"; //ROJO
    colores[2].inicio = "\x1B[32m"; colores[2].cierre = "\x1B[0m"; //VERDE
    colores[3].inicio = "\x1B[33m"; colores[3].cierre = "\x1B[0m"; //AMARILLO
    colores[4].inicio = "\x1B[34m"; colores[4].cierre = "\x1B[0m"; //AZUL
    colores[5].inicio = "\x1B[35m"; colores[5].cierre = "\x1B[0m"; //MORADO
    colores[6].inicio = "\x1B[36m"; colores[6].cierre = "\x1B[0m"; //AGUA

    //TRANFORMACION A MINUSCULAS
    lowercase(color);

    char variable;

    //CASILLA DE OPCION
    if (color == "rojo" || color == "red")
    {
        cout<<colores[1].inicio; cin>>variable; cout<<colores[1].cierre;
    }else if (color == "verde" || color == "green")
    {
        cout<<colores[2].inicio; cin>>variable; cout<<colores[2].cierre<<endl;
    }else if (color == "amarrillo" || color == "yellow")
    {
        cout<<colores[3].inicio; cin>>variable; cout<<colores[3].cierre<<endl;
    }else if (color == "azul" || color == "blue")
    {
        cout<<colores[4].inicio; cin>>variable; cout<<colores[4].cierre<<endl;
    }else if (color == "morado" || color == "purple")
    {
        cout<<colores[5].inicio; cin>>variable; cout<<colores[5].cierre<<endl;
    }else if (color == "agua" || color == "aqua")
    {
        cout<<colores[6].inicio; cin>>variable; cout<<colores[6].cierre<<endl;
    }else
    {
        cout<<colores[0].inicio; cin>>variable; cout<<colores[0].cierre<<endl;
    }
    return variable;
}

//SELECTOR DE COLOR PARA AL INGRESO DE DATOS STRING
string styleIputString(string color)
{
    //PALETA DE COLORES
    colores[0].inicio = "\x1B[0m"; colores[0].cierre = "\x1B[0m"; // BLANCO
    colores[1].inicio = "\x1B[31m"; colores[1].cierre = "\x1B[0m"; //ROJO
    colores[2].inicio = "\x1B[32m"; colores[2].cierre = "\x1B[0m"; //VERDE
    colores[3].inicio = "\x1B[33m"; colores[3].cierre = "\x1B[0m"; //AMARILLO
    colores[4].inicio = "\x1B[34m"; colores[4].cierre = "\x1B[0m"; //AZUL
    colores[5].inicio = "\x1B[35m"; colores[5].cierre = "\x1B[0m"; //MORADO
    colores[6].inicio = "\x1B[36m"; colores[6].cierre = "\x1B[0m"; //AGUA

    //TRANFORMACION A MINUSCULAS
    lowercase(color);

    string variable;

    //CASILLA DE OPCION
    if (color == "rojo" || color == "red")
    {
        cout<<colores[1].inicio; cin>>variable; cout<<colores[1].cierre;
    }else if (color == "verde" || color == "green")
    {
        cout<<colores[2].inicio; cin>>variable; cout<<colores[2].cierre<<endl;
    }else if (color == "amarrillo" || color == "yellow")
    {
        cout<<colores[3].inicio; cin>>variable; cout<<colores[3].cierre<<endl;
    }else if (color == "azul" || color == "blue")
    {
        cout<<colores[4].inicio; cin>>variable; cout<<colores[4].cierre<<endl;
    }else if (color == "morado" || color == "purple")
    {
        cout<<colores[5].inicio; cin>>variable; cout<<colores[5].cierre<<endl;
    }else if (color == "agua" || color == "aqua")
    {
        cout<<colores[6].inicio; cin>>variable; cout<<colores[6].cierre<<endl;
    }else
    {
        cout<<colores[0].inicio; cin>>variable; cout<<colores[0].cierre<<endl;
    }
    return variable;
}

//CONVERSOR DE MINUSCULAS
void lowercase(string &variable)
{
    for(int i = 0; i < variable.length(); i++)
    {
        variable[i] = tolower(variable[i]);
    }
}