/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.hpp"

Banco::Banco(){
    clientes.open("clientes.dat", fstream::out |fstream::in);
    if(clientes.is_open())
        cout<<"Archivo clientes abierto"<<endl;
    clientesindex.open("clientes.idx", fstream::out |fstream::in);
    if(clientesindex.is_open())
        cout<<"Archivo de indices abierto"<<endl;
    cuentas.open("cuentas.dat", fstream::out |fstream::in);
    if(cuentas.is_open())
        cout<<"Archivo cuentas abierto"<<endl;
    cuentasindex.open("cuentas.idx", fstream::out |fstream::in);
    if(cuentasindex.is_open())
        cout<<"Archivo de indices de cuentas abierto"<<endl;
    movimientos.open("movimientos.txt", fstream::out |fstream::in);
    if(movimientos.is_open())
        cout<<"Archivo movimientos abierto"<<endl;
}

Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}



void Banco::escribirCliente(Cliente instanciaCliente){
    clientes << instanciaCliente << endl;
    clientesindex << clientes.tellp() << endl;
    for(int i = 0; i < instanciaCliente.contarCuentas(); i ++){
        Cuenta aux = instanciaCliente[i];
        cuentas << aux << endl;
        cuentasindex << cuentas.tellp() << endl;
    }
}

void Banco::escribirCuenta(Cuenta instanciaCuenta){
    cuentas << instanciaCuenta << endl;
}

void Banco::leerArchivos(){
    int cantidadRegistros;
    int dato, i = 0;
    while(!clientesindex.eof()){
        clientesindex >> dato;
        cout<<i<<". "<<dato<<endl;
        i++;
        clientesindex >> dato;
    }
    return;
}
