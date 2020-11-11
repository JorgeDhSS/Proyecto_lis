/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoProducto.h
 * Author: Jorge Dh
 *
 * Created on 1 de noviembre de 2020, 01:31 AM
 */

#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include <iostream>
#include <cstring>
#include <string>
#include "Producto.h"

class NodoProducto {
public:
    NodoProducto(Producto pro);
    Producto getProducto();
    void setProducto(Producto pro);
    NodoProducto * getSiguiente();
    void setSiguiente(NodoProducto *siguiente);
private:
    Producto producto;
    NodoProducto *siguiente;

};

NodoProducto::NodoProducto(Producto pro) {
    this->producto = pro;
    this->siguiente = nullptr;//NULL 
}

Producto NodoProducto::getProducto(){
    return this->producto;
}

void NodoProducto::setProducto(Producto pro){
    this->producto = pro;
}
   
NodoProducto * NodoProducto::getSiguiente(){
    return siguiente;
}

void NodoProducto::setSiguiente(NodoProducto* siguiente){
    this->siguiente = siguiente;
}
#endif /* NODOPRODUCTO_H */

