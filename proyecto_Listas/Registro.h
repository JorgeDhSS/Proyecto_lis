/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.h
 * Author: Usuario
 *
 * Created on 11 de noviembre de 2020, 12:54 AM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Registro{
private:
    string claveP;
    int tipo;
    int cantidad;
public:
    Registro();
    Registro(int tipo, string clave, int cantidad);
    string getClaveP();
    int getTipo();
    int getCantidad();
    void setClaveP(string clave);
    void setTipo(int tipo);
    void setCantidad(int cantidad);
};
Registro::Registro(){
    this->claveP = "";
}
Registro::Registro(int tipo, string clave, int cantidad){
    this->tipo=tipo;
    this->claveP=clave;
    this->cantidad=cantidad;
}
string Registro::getClaveP(){ //get y set
    return this->claveP;
}
int Registro::getTipo(){
    return this->tipo;
}
int Registro::getCantidad(){
    return this->cantidad;
}
void Registro::setCantidad(int cantidad){
    this->cantidad = cantidad;
}
void  Registro::setTipo(int tipo){
    this->tipo = tipo;
}
void Registro::setClaveP(string clave){
    this->claveP = clave;
}

#endif /* REGISTRO_H */

