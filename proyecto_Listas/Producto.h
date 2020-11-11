/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Jorge Dh
 *
 * Created on 31 de octubre de 2020, 01:15 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Producto{
private:
    string clave;
    string nombre;
    string descripcion;
    int precio;
    int cantidad;
public:
    Producto(){
        this->clave = "";
        this->nombre = "";
        this->descripcion = "";
        this->precio = 0;
        this->cantidad = 0;
    }
    Producto(string clave, string nombre, string descripcion, int precio, int cantidad) {
        this->clave = clave;
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->precio = precio;
        this->cantidad = cantidad;
    }

    void setClave(string clave) {
        this->clave = clave;
    }

    string getClave() {
        return clave;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    void setDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() {
        return descripcion;
    }

    void setPrecio(int precio) {
        this->precio = precio;
    }

    int getPrecio() {
        return precio;
    }

    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }

    int getCantidad() {
        return cantidad;
    }
/*
    void setProducto(nodoProducto *producto) {
        this->producto = producto;
    }

    nodoProducto* getProducto() {
        return producto;
    }*/
};

#endif /* PRODUCTO_H */

