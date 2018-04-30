//
//  main.cpp
//  Proyecto 3
//
//  Created by Alejandro Guevara on 4/21/18.
//  Copyright © 2018 Alejandro Guevara. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include "Reserva.h"
#include "Autos.h"
#include "Aviones.h"

void desplejarMenu()
{
    cout << "--------------------------------MENU------------------------------------------" << endl;
    cout << "a) consultar Servicios" << endl;
    cout << "b)Consultar reservaciones" << endl;
    cout << "c) Consulatr las reservas de un servicio dado" << endl;
    cout << "d) Consultar reservas de una fecha especifica " << endl;
    cout << "e) hacer una reservacion" << endl;
    cout << "f) Terminar" << endl;
}

using namespace std;
int main() {
//OBJETOS
ifstream Servicios;
ifstream Reservaciones;
Servicio *Serv[6];
Reserva Reserva[20];
//VARIABLES
//reservacion
string clave;
int idCliente;
//fechas
int dia,mes,ano;
//dias duracion
int dias;
//servicio
char Tipo;
int cantidPersonas,adicional;
double CostoXdia;
string descripcion;
bool chofer,blindado;
//contadores para los dso archivos de texto
int contReservaciones = 0, contServicios = 0;


Reservaciones.open("Reserva.txt");
Servicios.open("Servicio.txt");
if(Servicios.is_open())
{
    cout << "Se accedio a la db de Servicios Correctamente "<< endl;
}
else
    cout << "fallo al accedar a db de servicios";
if(Reservaciones.is_open())
{
    cout << "Se accedio a la db de Reservaciones Correctamente "<< endl;

}
else
    cout << "fallo al accedar a db de Reservaciones";

while(Reservaciones >>clave>>idCliente>>dia>>mes>>ano>>dias)
    {
        Fecha FechaCont(dia,mes,ano);
        Reserva[contReservaciones].setClave(clave);
        Reserva[contReservaciones].setID(idCliente);
        Reserva[contReservaciones].setFechaContrato(FechaCont);
        Reserva[contReservaciones].setDuracion(dias);
        contReservaciones++;
    }
    Reservaciones.close();
    desplejarMenu();
    while(!Servicios.eof())
    {
        string todo;
        Servicios >> clave >> Tipo>>CostoXdia;
        getline(Servicios,todo);
        cout << todo << endl;
        int length = todo.length();
        //contar espacios en blanco
        int contblanc = 0;
        for(int i = 0; i < length-1; i++)
        {
            if(todo[i] == ' ')
                contblanc++;
        }
        for(int i, j = 0; j+1 == contblanc;i++)
        {

        }
        cout << contblanc << endl;



    }


    return 0;
}


