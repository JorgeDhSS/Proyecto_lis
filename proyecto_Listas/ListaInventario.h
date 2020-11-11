/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaInventario.h
 * Author: Jorge Dh
 *
 * Created on 1 de noviembre de 2020, 01:32 AM
 */

#ifndef LISTAINVENTARIO_H
#define LISTAINVENTARIO_H

#include <iostream>
#include <cstring>
#include <string>
#include "NodoProducto.h"

class ListaInventario {
private:
    NodoProducto *cabeza;
public:
    ListaInventario();
    bool isEmpty(); //está vacia
    void agregarProducto(Producto producto);
    void eliminar(int posicion);
    void modificar(int posicion, Producto producto);
    void mostrar();
    int buscar(string clave);
    bool salidas(string clave, int cantidad);
    bool entradas(string clave, int cantidad);
};

ListaInventario::ListaInventario() {
    this->cabeza = NULL;
}

void ListaInventario::agregarProducto(Producto producto) {
    NodoProducto *nuevoNodo = new NodoProducto(producto);
    if (this->isEmpty()) {
        this->cabeza = nuevoNodo;
    } else {
        NodoProducto *apuntador = cabeza;
        while (apuntador->getSiguiente() != NULL) {
            apuntador->getSiguiente();
            apuntador = apuntador->getSiguiente();
        }
        apuntador->setSiguiente(nuevoNodo);
    }
}

void ListaInventario::eliminar(int posicion) {
    if (this->isEmpty()) {
        cout <<""<<endl;

    } else {
        int contador=1;
        NodoProducto *apuntador = this->cabeza;
        while (contador < posicion - 1) {
            apuntador = apuntador->getSiguiente();
            contador++;
        }
        NodoProducto *aEliminar=apuntador->getSiguiente();
        apuntador->setSiguiente(aEliminar->getSiguiente());
        delete (aEliminar);
    }
}

void ListaInventario::modificar(int posicion, Producto producto) {
      if (this->isEmpty()) {
        cout <<"Está vacía"<<endl;

    } else {
        int contador=1;
        NodoProducto *apuntador = this->cabeza;
        while (contador < posicion) {
            apuntador = apuntador->getSiguiente();
            contador++;
        }
        apuntador->setProducto(producto);
    }
}



int ListaInventario::buscar(string clave) {
    int encontrado = -1;
    if (this->isEmpty()) {
        cout << "Pila vacía" << endl;
    } else {
        NodoProducto* apuntador = this->cabeza;
        int posicion = 1;
        while ((encontrado == -1)&&(apuntador->getSiguiente() != NULL)) {
            if (apuntador->getProducto().getClave() == clave) {
                encontrado = posicion;
                cout << "Elemento encontrado en la posición " << posicion << endl;
                cout << "Nombre: " << apuntador->getProducto().getNombre() << endl;
                cout << "Descripción: " << apuntador->getProducto().getDescripcion() << endl;
                cout << "Cantidad: " << apuntador->getProducto().getCantidad() << endl;
                cout << "Precio: " << apuntador->getProducto().getPrecio() << endl;
            }
            apuntador = apuntador->getSiguiente();
            posicion++;
        }
    }
    return encontrado;
}

void ListaInventario::mostrar() {
    NodoProducto *apuntador = cabeza;
    while (apuntador != NULL) {
        cout << "clave: " << apuntador->getProducto().getClave() << endl;
        cout << "Nombre: " << apuntador->getProducto().getNombre() << endl;
        cout << "Descripción: " << apuntador->getProducto().getDescripcion() << endl;
        cout << "Cantidad: " << apuntador->getProducto().getCantidad() << endl;
        cout << "Precio: " << apuntador->getProducto().getPrecio() << endl;
        apuntador = apuntador->getSiguiente();
    }
}

bool ListaInventario::isEmpty() {
    return cabeza == NULL;
}
bool ListaInventario::salidas(string clave, int cantidad){
    bool hecho = false; 
    if(this->isEmpty()){
        cout<<"Error, lisita vacía"<<endl;
    }else{
        bool encontrado = false;
        NodoProducto *apuntador = this->cabeza;
        while(!encontrado||apuntador->getSiguiente()!=NULL){
            cout<<apuntador->getProducto().getClave()<<endl;
            if(apuntador->getProducto().getClave()==clave){
                encontrado = true;
            }else{
                apuntador = apuntador->getSiguiente();
            }
        }
        if(encontrado){
            cout<<"Encontrado"<<endl;
            if(apuntador->getProducto().getCantidad()<cantidad){
                cout<<"apuntador->getProducto().getCantidad()"<<endl;
                apuntador->getProducto().setCantidad(apuntador->getProducto().getCantidad()-cantidad);
                hecho = true;
            }        
        }
    }
    return hecho;
}
bool ListaInventario::entradas(string clave, int cantidad){
    bool hecho = false; 
    if(this->isEmpty()){
        cout<<"Error, lista vacía"<<endl;
    }else{
        bool encontrado = false;
        NodoProducto *apuntador = this->cabeza;
        while(!encontrado||apuntador->getSiguiente()!=NULL){
            if(apuntador->getProducto().getClave()==clave){
                encontrado = true;
            }else{
                apuntador = apuntador->getSiguiente();
            }
        }
        if(encontrado){
            apuntador->getProducto().setCantidad(apuntador->getProducto().getCantidad()+cantidad);
            hecho = true;        
        }
    }
    return hecho;
}

#endif /* LISTAINVENTARIO_H */

