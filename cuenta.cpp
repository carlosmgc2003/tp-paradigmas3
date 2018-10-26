/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cuenta.hpp"
#include <iomanip>


using namespace std;



Cuenta::Cuenta(int id,float s){
    nuevaCuenta = TRUE;
    saldo = s >= 0.0? s : 0.0;
    setdniDuenio(id);
    setCuentaIniciada();

}

Cuenta::Cuenta(int id){
    setdniDuenio(id);
    saldo = 0.0;
    nuevaCuenta = TRUE;
}
Cuenta::Cuenta(){
    nuevaCuenta = TRUE;
}

Cuenta::~Cuenta(){
    return;
}
float Cuenta::getSaldo() const{
    return saldo;
}

int Cuenta::getdniDuenio() const{
    return dniDuenio;
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

void Cuenta::setdniDuenio(int id){
    if(nuevaCuenta == TRUE){
        dniDuenio = id;
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
    salida << cuenta.getdniDuenio() <<","<<fixed<<setprecision(2)<< cuenta.getSaldo();
    return salida;
}

istream & operator >> (istream & entrada, Cuenta & cuenta){
    int numeroParadniDuenio;
    float numeroParaSaldo;
    string aux;
    entrada >> aux;
    size_t pos = aux.find(',');
    numeroParadniDuenio = stoi(aux.substr(0,pos));
    cuenta.setdniDuenio(numeroParadniDuenio);
    numeroParaSaldo = stof(aux.substr(pos + 1,aux.size() - (pos + 1)));
    cout << fixed << setprecision(2) << numeroParaSaldo << endl;
    cuenta.setSaldo(numeroParaSaldo);
    cuenta.setCuentaIniciada();
    return entrada;
}
