/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cuenta.hpp"
#include <iomanip>


using namespace std;



Cuenta::Cuenta(int id,float s){
    cout<<numeroDeOrden<<endl;
    nuevaCuenta = TRUE;
    saldo = s >= 0.0? s : 0.0;
    setIdCuenta(id);
    setCuentaIniciada();
    numeroDeOrden ++;

}

Cuenta::Cuenta(int id){
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
    return;
}
float Cuenta::getSaldo() const{
    return saldo;
}

int Cuenta::getIdCuenta() const{
    return idCuenta;
}

void Cuenta::operator +=(float credito){
    saldo += credito;
}

void Cuenta::acreditar(float credito){
    if(credito >= 0.0)
        saldo += credito;
}

void Cuenta::debitar(float debito){
    if(debito >= 0.0)
        saldo -= debito;
}

void Cuenta::operator -=(float debito){
    if(debito >= 0.0 && saldo - debito >= 0.0)//Corregir!!!
        saldo -= debito;
    else
        cout<<"Saldo insuficiente"<<endl;
}

void Cuenta::setIdCuenta(int id){
    if(nuevaCuenta == TRUE){
        string aux;
        aux = to_string(id);
        aux.append(to_string(numeroDeOrden));
        idCuenta = stoi(aux);
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
    salida << cuenta.getIdCuenta() <<","<<fixed<<setprecision(2)<< cuenta.getSaldo();
    return salida;
}

istream & operator >> (istream & entrada, Cuenta & cuenta){
    int id;
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
