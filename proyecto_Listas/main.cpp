/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jorge Dh
 *
 * Created on 31 de octubre de 2020, 12:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "ListaInventario.h"
#include "Producto.h"
#include "gestorInventario.h"
using namespace std;

/*
 * 
 */
string pedirClave(){
    string clave;
    cout<<"Ingresa la clave: ";
    cin>>clave;
    fflush(stdin);
    return clave;
}

string pedirNombre(){
    string name;
    cout<<"Ingresa el nombre: ";
    fflush(stdin);
    cin>>name;
    return name;
}
string pedirDescripcion(){
    string descrip;
    cout<<"Ingresa la descripción: "<<endl;
    fflush(stdin);
    getline(cin, descrip);
    return descrip;
}
int pedirPrecio(){
    int precio;
    cout<<"Ingresa el precio: ";
    cin>>precio;
    cin.ignore();
    return precio;
}
int pedirCantidad(){
    int cantidad;
    cout<<"Ingresa la cantidad: ";
    cin>>cantidad;
    return cantidad;
}
int pedirPosicion(){
    int pos;
    cout<<"Ingresa la posición a elegir ";
    cin>>pos;
    return pos;
}
int main(int argc, char** argv) {
    int opcion;
    ListaInventario LI;
    ListaInventario *lista;
    lista = &LI;
    gestorInventario gI(lista);
    while(opcion!=8){
        cout<<"______________BIENNVENIDO______________"<<endl;
        cout<<"Elige una opción:"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Eliminar producto"<<endl;
        cout<<"3. Modificar producto"<<endl;
        cout<<"4. Buscar producto"<<endl;
        cout<<"5. Mostrar productos"<<endl;
        cout<<"6. Salidas del inventario"<<endl;
        cout<<"7. Entradas al inventario"<<endl;
        cout<<"8. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
            {
                Producto pro(pedirClave(), pedirNombre(), pedirDescripcion(), pedirPrecio(), pedirCantidad());
                LI.agregarProducto(pro);
            }
                break;
            case 2:
                LI.eliminar(pedirPosicion());
                break;
            case 3:
            {
                cout<<"Ingresa nuevos datos"<<endl;
                Producto pro(pedirClave(), pedirNombre(), pedirDescripcion(), pedirPrecio(), pedirCantidad());
                LI.modificar(pedirPosicion(), pro);
            }
                break;
            case 4:
                if(LI.buscar(pedirClave())==-1){
                    cout<<"Elemento no encontrado"<<endl;
                }
                break;
            case 5:
                LI.mostrar();
                break;
            case 6:
                gI.bajarRegistro(pedirCantidad(), pedirClave());
                break;
            case 7:
                gI.subirRegistro(pedirCantidad(), pedirClave());
                break;
            case 8:
                cout<<"Gracias por usar el sistema :)"<<endl;
                break;
            default:
                cout<<"Error, elige una opción correcta"<<endl;
                break;
        }
    }
    return 0;
}

