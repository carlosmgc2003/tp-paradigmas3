/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.hpp"
#include "wx/msgdlg.h"
Banco::Banco(){
    clientes.open("clientes.txt", fstream::in);
    if(!clientes.is_open()){
        clientes.open("clientes.txt",fstream::out | fstream::trunc);
        cuentas.open("cuentas.txt",fstream::out | fstream::trunc);
        movimientos.open("movimientos.txt",fstream::out | fstream::trunc);
        clientes.close();
        cuentas.close();
        movimientos.close();
        clientes.open("clientes.txt", fstream::in);
        cuentas.open("cuentas.txt", fstream::in);
        movimientos.open("movimientos.txt", fstream::in);
        wxMessageBox(_("Ejecutando por primera vez Banco CrisNaMa"),_("Atención"));
    }
    else{
        cuentas.open("cuentas.txt", fstream::in);
        movimientos.open("movimientos.txt", fstream::in);
    }

}

Banco::~Banco(){
    clientes.close();
    cuentas.close();
    movimientos.close();
}



void Banco::escribirClientes(){
    //Escribimos todos los clientes
    clientes.close();
    clientes.open("clientes.txt", fstream::out | fstream::trunc);
    for(int i = 0; i < clientesActivos.size(); i ++){
        clientes << clientesActivos[i];
        if(i < clientesActivos.size() - 1)
            clientes << endl;
    }
    clientes.close();
    clientes.open("clientes.txt",fstream::in);
    //Ahora vamos a escribir las cuentas

    cuentas.close();
    cuentas.open("cuentas.txt", fstream::out | fstream::trunc);
    //Para cada cliente:
    int cuentasTotales = cuentasActivas();
    for(int i = 0; i < clientesActivos.size(); i ++){
        //Si el cliente tiene cuentas:
        if(clientesActivos[i].contarCuentas() != 0){
            //cout << "Escribiendo cuentas para: " << clientesActivos[i] << endl;
            //Recorremos cada cuenta
            //cout << "Tiene cuentas activas: " << clientesActivos[i].contarCuentas() << endl;
            for(int j = 0;j < clientesActivos[i].contarCuentas(); j++){
                //La escribimos en el disco
                //cout << "Escribimos la cuenta:" << clientesActivos[i][j] << endl;
                cuentas << clientesActivos[i][j];
                cuentasTotales --;
                if(j < clientesActivos[i].contarCuentas() && cuentasTotales > 0)
                    cuentas << endl;
            }
        }
    }

    cuentas.close();
    cuentas.open("cuentas.txt", fstream::in);
}

void Banco::escribirCuenta(Cuenta instanciaCuenta){
    cuentas << instanciaCuenta << endl;
}

void Banco::leerArchivos(){
    int cantClientes = contarClientes();
    if(cantClientes > 0){
        Cliente auxCliente;
        clientes.seekg(clientes.beg);
        while(!clientes.eof()){
            clientes >> auxCliente;
            clientesActivos.push_back(auxCliente);
            if(clientes.eof())
                break;
        }
        int cantCuentas = contarCuentas();
        if(cantCuentas > 0){
            cuentas.seekg(cuentas.beg);
            while(!cuentas.eof()){
                Cuenta auxCuenta;
                cuentas >> auxCuenta;
                //cout << "Leida la cuenta: " << auxCuenta << " en posicion: " << cuentas.tellg() <<endl;
                for(int i = 0; i < clientesActivos.size();i ++){
                    if(clientesActivos[i].getDni() == auxCuenta.getdniDuenio()){
                        clientesActivos[i].agregarCuenta(auxCuenta);
                        //cout <<"Se agrego cuenta: " << auxCuenta << " a " << clientesActivos[i] << " en posicion " << i << endl;
                        break;
                    }
                }
                if(cuentas.eof())
                    break;
            }
        }
    }

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


//FIX: que hacer con los benditos saltos de linea al final del archivo
int Banco::contarCuentas(){
    int i = 0;
    string aux;
    cuentas.seekg(cuentas.beg);
    while(!cuentas.eof()){
        cuentas >> aux;
        cout << aux;
        i++;
        if(cuentas.eof())
            break;
    }
    return i;
}

int Banco::cuentasActivas(){
    int contador = 0;
    for(int i = 0; i < clientesActivos.size();i ++){
        contador += clientesActivos[i].contarCuentas();
    }
    return contador;
}
