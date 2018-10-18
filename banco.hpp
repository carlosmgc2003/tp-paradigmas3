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
#include "cliente.hpp"
#include "cuenta.hpp"
using namespace std;

class Banco{
public:
    Banco();//inicia los archivos o append si ya estan creados.
    ~Banco();//solo cierra los archivos
    Cliente * leerArchivos();//lee todos los archivos del programa y carga en memoria los clientes y cuentas.
    int contarClientes();
    void escribirCliente(Cliente &);
    void escribirCuenta(Cuenta );//Legacy no debe usarse;
    void escribirMovimiento(Cliente ,Cuenta ,const float);
private:
    fstream clientes;//puntero a file donde se guardan los clientes.
    fstream clientesindex;
    fstream cuentas;//puntero a file donde se guardan las cuentas.
    fstream cuentasindex;
    fstream movimientos;//puntero a file donde se llevan los movimientos del banco
};



#endif /* BANCO_HPP */

