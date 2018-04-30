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
// barrido de reservaciones
while(Reservaciones >>clave>>idCliente>>dia>>mes>>ano>>dias)
    {
        if(contReservaciones < 20)
        {
        Fecha FechaCont(dia,mes,ano);
        Reserva[contReservaciones].setClave(clave);
        Reserva[contReservaciones].setID(idCliente);
        Reserva[contReservaciones].setFechaContrato(FechaCont);
        Reserva[contReservaciones].setDuracion(dias);

        contReservaciones++;
    }else
        cout << "se acabo el espacio de reservaciones" << endl;
    }
    Reservaciones.close();
    //barrido de servicios
    while(!Servicios.eof())
    {
        Servicios >> clave >> Tipo>>CostoXdia;
        getline(Servicios,descripcion);
        int length = descripcion.length();
        //contar espacios en blanco
        int contblanc = 0;
        for(int i = 0; i < length-1; i++)
        {
            if(descripcion[i] == ' ')
                contblanc++;
        }
        int posblanco = 0;
        for(int i = 0, j = 0; i < length-1;i++)
        {
            if(descripcion[i] == ' ')
                j++;
            if(j == contblanc-1)
            {
                posblanco = i;
                break;
            }

        }
        // se separan los bool de chfer y blindado
        string secundario;
        secundario = descripcion.substr(posblanco);
        descripcion.erase(posblanco);
        secundario.erase(0,1);
        if(Tipo == 'S' || Tipo == 'M' || Tipo== 'T')
        {
            int pos = secundario.find(' ');
            string Sblindado = secundario.substr(pos+1);
            secundario.erase(pos);
            if(Sblindado[0] == '1')
                blindado = true;
            else
                blindado = false;
            if(secundario[0] == '1')
                chofer = true;
            else
                chofer = false;
                if(contServicios <6)
                {
            Serv[contServicios] = new Autos(clave,Tipo,CostoXdia,descripcion,chofer,blindado);
            contServicios++;
                }
                else
                    cout << "no hay mas espacio para servicios" << endl;
        }
        else
        {
            int pos = secundario.find(' ');
            string terciario = secundario.substr(pos);
            terciario.erase(0,1);
            secundario.erase(pos);
            //conversion de string a integro
            const char* personas = secundario.c_str();
            cantidPersonas = atoi(personas);

            const char* extra = terciario.c_str();
            adicional = atoi(extra);
            if(contServicios < 6)
            {
            Serv[contServicios] = new Aviones(clave,Tipo,CostoXdia,descripcion,cantidPersonas,adicional);
            contServicios++;
            }
                else
                    cout << "no hay mas espacio para servicios" << endl;



        }
    }


    return 0;
}


