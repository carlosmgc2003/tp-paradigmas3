/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   banco.h
 * Author: carlos
 *
 * Created on 3 de octubre de 2018, 04:34
 */

#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Banco{
public:
    Banco();//inicia los archivos o append si ya estan creados.
    ~Banco();//solo cierra los archivos
    void escribirArchivo(string,int);//escribe registros en archivos, sirve para todos los archivos del programa
    void leerArchivos();//lee todos los archivos del programa y carga en memoria los clientes y cuentas.
private:
    fstream clientes;//puntero a file donde se guardan los clientes.
    fstream cuentas;//puntero a file donde se guardan las cuentas.
    fstream movimientos;//puntero a file donde se llevan los movimientos del banco
};

class Cuenta{
private:
    float saldo;
    int idcuenta;
};

class Cliente{
public:
    Cliente(string,string,string);
private:
    string nombre;
    string apellido;
    string dni;
    vector<Cuenta> cartera;
};


#endif /* BANCO_H */

