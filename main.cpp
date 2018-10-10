/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 3 de octubre de 2018, 04:34
 */

#include <cstdlib>
#include <iostream>
#include "banco.h"

using namespace std;

int main(int argc, char** argv) {
    Banco A;
    Cuenta prueba1("132956544",100.00);
    Cuenta prueba2("232956544",150.00);
    A.escribirCuenta(prueba1);
    A.escribirCuenta(prueba2);
    Cliente persona1("Carlos","Maceira",32956544);
    Cliente persona2("Analia","Saavedra",27014855);
    A.escribirCliente(persona1);
    A.escribirCliente(persona2);
    return 0;
}

