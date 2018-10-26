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



void Banco::escribirClientes(){
    clientes.close();
    clientes.open("clientes.txt", fstream::out | fstream::trunc);
    for(int i = 0; i < clientesActivos.size(); i ++){
        clientes << clientesActivos[i];
        if(i < clientesActivos.size() - 1)
            clientes << endl;
    }
    clientes.close();
    clientes.open("clientes.txt",fstream::in);
//    cuentas.close();
//    cuentas.open("cuentas.txt", fstream::out | fstream::trunc);
//    for(int i = 0; i < clientesActivos.size(); i ++){
//        for(int j = 0;j < clientesActivos[i].contarCuentas(); j++){
//            cuentas << clientesActivos[i][j];
//            if(j < clientesActivos[i].contarCuentas() - 1)
//                cuentas << endl;
//        }
//        cuentas << endl;
//    }
//    cuentas.close();
//    cuentas.open("cuentas.txt", fstream::in);
}

void Banco::escribirCuenta(Cuenta instanciaCuenta){
    cuentas << instanciaCuenta << endl;
}

void Banco::leerArchivos(){
    int cantClientes = contarClientes();
    cout << "Contados: " << cantClientes << endl;
    int j = 0;
    Cliente aux;
    clientes.seekg(clientes.beg);
    while(!clientes.eof()){
        clientes >> aux;
        clientesActivos.push_back(aux);
        j ++;
        if(clientes.eof())
            break;
    }
    clientes.flush();
    clientes.seekp(clientes.beg);
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