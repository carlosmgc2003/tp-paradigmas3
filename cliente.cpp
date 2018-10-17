/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cliente.hpp"

Cliente::Cliente(string n,string a,int id){
    setNombre(n);
    setApellido(a);
    setDni(id);
}

void Cliente::setNombre(string n){
    if(n.size() > 20)
        n.resize(20);
    else
        nombre = n;
}

void Cliente::setApellido(string a){
    if(a.size() > 20)
        a.resize(20);
    else
        apellido = a;
}

void Cliente::setDni(int id){
    dni = id >= 1000000? id : 0;
}

int Cliente::getDni() const{
    return dni;
}

string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getApellido() const{
    return apellido;
}

void Cliente::agregarCuenta(float){
    string id = to_string(dni);
    Cuenta nueva(id);
    cartera.push_back(nueva);
}

ostream & operator << (ostream & salida, Cliente & instanciaCliente){
    salida << instanciaCliente.getDni();
    salida << ",";
    salida << instanciaCliente.getNombre();
    salida << ",";
    salida << instanciaCliente.getApellido();
    return salida;
}

istream & operator >> (istream & entrada, Cliente & instanciaCliente){
    int numero;
    string cadena1, cadena2;
    char colon;
    entrada >> numero >> colon >> cadena1 >> colon >> cadena2 >> colon;
    instanciaCliente.setDni(numero);
    instanciaCliente.setApellido(cadena2);
    instanciaCliente.setApellido(cadena1);
    return entrada;
}
