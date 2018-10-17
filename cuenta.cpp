/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cuenta.hpp"
using namespace std;


int Cuenta::numeroDeOrden = 0;

Cuenta::Cuenta(string id,float s){
    nuevaCuenta = TRUE;
    saldo = s >= 0? s : 0.0;
    setIdCuenta(id);
    setCuentaIniciada();
    numeroDeOrden ++;
}

Cuenta::Cuenta(string id){
    setIdCuenta(id);
    saldo = 0.0;
    nuevaCuenta = TRUE;
    numeroDeOrden ++;
}
Cuenta::Cuenta(){
    saldo = 0.0;
    nuevaCuenta = TRUE;
    numeroDeOrden ++;
}

Cuenta::~Cuenta(){
    numeroDeOrden --;
}
float Cuenta::getSaldo() const{
    return saldo;
}

string Cuenta::getIdCuenta() const{
    return idCuenta;
}

void Cuenta::operator +=(float credito){
    if(credito >= 0)
        saldo += credito;
}

void Cuenta::operator -=(float debito){
    if(debito >= 0 && saldo - debito >= 0)//Corregir!!!
        saldo -= debito;
    else
        cout<<"Saldo insuficiente"<<endl;
}

void Cuenta::setIdCuenta(string id){
    if(nuevaCuenta == TRUE){
        idCuenta = to_string(numeroDeOrden);
        idCuenta.append(id);
        setCuentaIniciada();
    }
}

void Cuenta::setSaldo(float s){
    if(nuevaCuenta == TRUE){
        saldo = s;
    }
}

void Cuenta::setCuentaIniciada(){
    nuevaCuenta = FALSE;
}

ostream & operator << (ostream & salida, Cuenta & cuenta){
    salida << cuenta.getIdCuenta() <<","<< cuenta.getSaldo();
    return salida;
}

istream & operator >> (istream & entrada, Cuenta & cuenta){
    string id;
    float s;
    entrada >> id;
    entrada >> s;
    if(cuenta.nuevaCuenta == TRUE){
        cuenta.setIdCuenta(id);
        cuenta.setSaldo(s);
        cuenta.setCuentaIniciada();
    }
    return entrada;
}
