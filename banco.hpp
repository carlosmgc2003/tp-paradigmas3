/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   banco.hpp
 * Author: cmaceira
 *
 * Created on 16 de octubre de 2018, 12:42
 */

#ifndef BANCO_HPP
#define BANCO_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
enum value {FALSE,TRUE};





class Banco{
public:
    Banco();//inicia los archivos o append si ya estan creados.
    ~Banco();//solo cierra los archivos
    void leerArchivos();//lee todos los archivos del programa y carga en memoria los clientes y cuentas.
    void escribirCliente(const Cliente );
    void escribirCuenta(const Cuenta );
    void escribirMovimiento(Cliente ,Cuenta ,const float);
private:
    fstream clientes;//puntero a file donde se guardan los clientes.
    fstream cuentas;//puntero a file donde se guardan las cuentas.
    fstream movimientos;//puntero a file donde se llevan los movimientos del banco
};



#endif /* BANCO_HPP */

