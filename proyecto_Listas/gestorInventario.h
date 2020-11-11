/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gestorInventario.h
 * Author: Jorge Dh
 *
 * Created on 10 de noviembre de 2020, 12:47 PM
 */

#ifndef GESTORINVENTARIO_H
#define GESTORINVENTARIO_H

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "ListaRegistro.h"
#include "ListaInventario.h"
#include "Registro.h"

using namespace std;

class gestorInventario {
private:
    ListaInventario *li;
    ListaRegistro LR;
    
public:
    gestorInventario(ListaInventario *lis);
    void bajarRegistro(int cantidad, string clave);
    void subirRegistro(int cantidad, string clave);
    void registrar(int tipo, string clave, int cantidad);
};
gestorInventario::gestorInventario(ListaInventario *lis){
    this->li = lis;
}
void gestorInventario::bajarRegistro(int cantidad, string clave){
    if(li->salidas(clave, cantidad)){
        cout<<"Completado con éxito"<<endl;
    }else{
        cout<<"La salidas no fue completada"<<endl;
    }
}
void gestorInventario::subirRegistro(int cantidad, string clave){
    if(li->entradas(clave, cantidad)){
        cout<<"Completado con éxito"<<endl;
    }else{
        cout<<"La entrada no fue completada"<<endl;
    }
}
void gestorInventario::registrar(int tipo, string clave, int cantidad){
    Registro reg = Registro(tipo, clave, cantidad);
    LR.agregarRegistro(reg); 
}
#endif /* GESTORINVENTARIO_H */

