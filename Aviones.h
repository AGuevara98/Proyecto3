//
//  Aviones.h
//  Proyecto 3
//
//  Created by Alejandro Guevara on 4/21/18.
//  Copyright © 2018 Alejandro Guevara. All rights reserved.
//

#ifndef Aviones_h
#define Aviones_h
#include "Servicio.h"
#include <string>
using namespace std;

class Aviones : public Servicio{
public:
    Aviones();
    Aviones(string clave, char tipo, double costo, string desc, int cant, int ad);
    //Acceso
    int getCantPersonas();
    int getAdicional();
    //Modificacion
    void setCantPersonas(int cant);
    void setAdicional(int ad);
    int calcularCosto(int diasDuracion);

    void muestra();

private:
    int cantPersonas, adicional;
};
Aviones::Aviones():Servicio(){

}
Aviones::Aviones(string clave, char tipo, double costo, string desc, int cant, int ad): Servicio(clave, tipo, costo, desc){
    cantPersonas=cant;
    adicional=ad;
}
//Acceso
int Aviones::getCantPersonas(){
    return cantPersonas;
}
int Aviones::getAdicional(){
    return adicional;
}
//Modificacion
void Aviones::setCantPersonas(int cant){
    cantPersonas=cant;
}
void Aviones::setAdicional(int ad){
    adicional=ad;
}
int Aviones::calcularCosto(int dias)
{
      int costo;
    if(tipo == 'H')
    {
        costo = 50000;
        if(cantPersonas > 6)
        {
            for(int i = cantPersonas; i > 6; i--)
            {
                costo = costo + costo * 0.04;
            }
        }
    }
    else if(tipo == 'J')
    {
        costo = 120000;
        if(cantPersonas > 20)
        {
            for(int i = cantPersonas; i > 20; i--)
            {
                costo = costo + costo * 0.04;
            }
        }
    }
    else if(tipo == 'A')
    {
        costo = 80000;
        if(cantPersonas > 10)
        {
            for(int i = cantPersonas; i > 10; i--)
            {
                costo = costo + costo * 0.04;
            }
        }
    }

    return costo * dias;

}
void Aviones::muestra(){
    cout << "Clave: " <<getClave() << endl;
    cout << "Tipo: " << getTipo() << endl;
    cout << "Costo por dia: " << getCostoXDia() << endl;
    cout << "Descripcion: " << getDescripcion() << endl;
    cout << "Cantidad de personas: " << getCantPersonas() << endl;
    cout << "Adicionales: " << getAdicional() << endl << endl;

}

#endif /* Aviones_h */
