/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.hpp"

Banco::Banco(){
    clientes.open("clientes.txt", fstream::in);
    if(clientes.is_open())
        cout<<"Archivo clientes abierto"<<endl;
    cuentas.open("cuentas.txt", fstream::in);
    if(cuentas.is_open())
        cout<<"Archivo cuentas abierto"<<endl;
    movimientos.open("movimientos.txt", fstream::in);
    if(movimientos.is_open())
        cout<<"Archivo movimientos abierto"<<endl;
}

Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}



void Banco::escribirClientes(Cliente * arrayClientes,int cantClientes){
    clientes.close();
    clientes.open("clientes.txt", fstream::out | fstream::trunc);
    for(int i = 0; i < cantClientes; i ++){
        clientes << arrayClientes[i];
        if(i < cantClientes - 1)
            clientes << endl;
    }
    clientes.close();
    clientes.open("clientes.txt",fstream::in);
//    for(int i = 0; i < instanciaCliente.contarCuentas(); i ++){
//        Cuenta aux = instanciaCliente[i];
//        cuentas << aux << endl;
//    }
}

void Banco::escribirCuenta(Cuenta instanciaCuenta){
    cuentas << instanciaCuenta << endl;
}

Cliente * Banco::leerArchivos(){
    int cantClientes = contarClientes();
    cout << "Contados: " << cantClientes << endl;
    Cliente * datos; 
    datos = new Cliente[cantClientes];
    int j = 0;
    clientes.seekg(clientes.beg);
    while(!clientes.eof()){
        clientes >> datos[j];
        j ++;
        if(clientes.eof())
            break;
    }
    clientes.flush();
    clientes.seekp(clientes.beg);
    return datos;
}

int Banco::contarClientes(){
    int i = 0;
    string aux;
    clientes.seekg(clientes.beg);
    while(!clientes.eof()){
        i++;
        clientes >> aux;
        if(clientes.eof())
            break;
    }
    return i;
}