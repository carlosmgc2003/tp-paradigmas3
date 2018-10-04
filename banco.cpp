/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.h"
using namespace std;


Banco::Banco(){
    clientes.open("clientes.txt", fstream::out | fstream::in | fstream::app);
    cuentas.open("cuentas.txt", fstream::out | fstream::in | fstream::app);
    movimientos.open("movimientos.txt", fstream::out | fstream::in | fstream::app);
}

Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}

void Banco::escribirArchivo(string registro,int archivo){
    int tamanioRegistro = registro.size() + 1;
    char * buffer = new char[tamanioRegistro];
    for(int i = 0;i < registro.size();i ++)
        buffer[i] = registro[i];
    buffer[tamanioRegistro - 1] = '\n';
    switch(archivo){
        case 1:
            clientes.write(buffer,tamanioRegistro);
            break;
        case 2:
            cuentas.write(buffer,tamanioRegistro);
            break;
        case 3:
            movimientos.write(buffer,tamanioRegistro);
    }
    delete[] buffer;
}


void Banco::leerArchivos(){
    if(clientes){
        clientes.seekg(0,clientes.end);//desplaza el cabezal al final del archivo.
        int largoarchivo = clientes.tellg();//da la posicion del final.
        clientes.seekg(0,clientes.beg);//desplaza el cabezal al principio del archivo nuevamente.
        char * bufferClientes = new char[largoarchivo];//genera un buffer para guardar el contenido "entero" del archivo
        cout<<"Se leeran: "<<largoarchivo<<" bytes."<<endl;
        clientes.read(bufferClientes,largoarchivo);
        if(clientes)
            cout<<"El archivo ha sido leido correctamente"<<endl;
        else
            cout<<"error: solo"<<clientes.gcount()<<" han sido leidos!"<<endl;
        //aca debe agregarse la creacion de las instancias de cliente.
        string contenidoClientes(bufferClientes);
        cout<<"Lo leido fue: "<<contenidoClientes<<endl;
        delete[] bufferClientes;//se libera la memora asignada para el buffer.
        cuentas.seekg(0,cuentas.end);
        largoarchivo = cuentas.tellg();
        cuentas.seekg(0,cuentas.beg);
        char * bufferCuentas = new char[largoarchivo];
        cout<<"Se leeran: "<<largoarchivo<<" bytes."<<endl;
        cuentas.read(bufferCuentas,largoarchivo);
        if(cuentas)
            cout<<"El archivo ha sido leido correctamente"<<endl;
        else
            cout<<"error: solo"<<cuentas.gcount()<<" han sido leidos!"<<endl;
        //aca debe agregarse la creacion de las instancias de cuenta.
        string contenidoCuentas(bufferCuentas);
        cout<<"Lo leido fue: "<<contenidoCuentas<<endl;
        delete[] bufferCuentas;
    }

}
