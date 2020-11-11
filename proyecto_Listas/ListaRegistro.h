/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListasRegistro.h
 * Author: Usuario
 *
 * Created on 10 de noviembre de 2020, 07:42 PM
 */

#ifndef LISTASREGISTRO_H
#define LISTASREGISTRO_H
#include <iostream>
#include <cstring>
#include <string>
#include "NodoRegistro.h"

class ListaRegistro {
private:
    NodoRegistro *cabeza;
public:
    ListaRegistro();
    bool isEmpty();
    void agregarRegistro(Registro reg);
    void mostrar(int tipo);
};

ListaRegistro::ListaRegistro() {
    this->cabeza = NULL;
}

bool ListaRegistro::isEmpty(){
    return this->cabeza == NULL;
}

void ListaRegistro::agregarRegistro(Registro reg) {
    NodoRegistro *nuevoNodo = new NodoRegistro(reg);
    if (this->isEmpty()) {
        this->cabeza = nuevoNodo;
    } else {
        NodoRegistro *apuntador = cabeza;
        while (apuntador->getSiguiente() != NULL) {
            apuntador = apuntador->getSiguiente();
        }
        apuntador->setSiguiente(nuevoNodo);
    }
}

void ListaRegistro::mostrar(int tipo) {
    NodoRegistro *apuntador = this->cabeza;
    if (this->isEmpty()) {
        cout << "No hay entradas ni salidas" <<endl;
    } else {
        if (tipo == 1) {
            cout << "---------------------------------Entradas-------------------------------------" <<endl;
            NodoRegistro *apuntador = cabeza;
            while (apuntador->getSiguiente() != NULL) {
                if(apuntador->getRegistro().getTipo()==1){
                    cout << "Hubo una entrada de "<<apuntador->getRegistro().getCantidad()<<" pzas del producto con clave "<<apuntador->getRegistro().getClaveP()<<endl; 
                }
                apuntador = apuntador->getSiguiente();
            }
        }else{
            cout << "---------------------------------Salidas-------------------------------------" <<endl;
            NodoRegistro *apuntador = cabeza;
            while (apuntador->getSiguiente() != NULL) {
                if(apuntador->getRegistro().getTipo()==2){
                    cout << "Hubo una salida de "<<apuntador->getRegistro().getCantidad()<<" pzas del producto con clave "<<apuntador->getRegistro().getClaveP()<<endl; 
                }
                apuntador = apuntador->getSiguiente();
            }
        }
    }
}

#endif /* LISTASREGISTRO_H */
