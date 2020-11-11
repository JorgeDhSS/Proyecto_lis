/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoRegistro.h
 * Author: Usuario
 *
 * Created on 10 de noviembre de 2020, 07:54 PM
 */

#ifndef NODOREGISTRO_H
#define NODOREGISTRO_H

#include <iostream>
#include <cstring>
#include <string>
#include "Registro.h"

class NodoRegistro {
public:
    NodoRegistro(Registro reg);
    Registro getRegistro();
    void setRegistro(Registro reg);
    NodoRegistro * getSiguiente();
    void setSiguiente(NodoRegistro *siguiente);
private:
    Registro reg;
    NodoRegistro *siguiente;

};
NodoRegistro::NodoRegistro(Registro reg){
    this->reg = reg;
    this->siguiente = NULL;
}
Registro NodoRegistro::getRegistro(){
    return this->reg;
}
void NodoRegistro::setRegistro(Registro reg){
    this->reg = reg;
}
void NodoRegistro::setSiguiente(NodoRegistro* siguiente){
    this->siguiente = siguiente;
}
NodoRegistro * NodoRegistro::getSiguiente(){
    return this->siguiente;
}
#endif /* NODOREGISTRO_H */
