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
#include "banco.hpp"

using namespace std;

int Cuenta::numeroDeOrden = 1;

int main() {
    Banco A;
    A.leerArchivos();
    Cliente carlos("Carlos","Maceira",32956544);
    Cliente analia("Analia","Saavedra",27014855);
    carlos.agregarCuenta(15000.00);
    carlos.agregarCuenta(1999.01);
    analia.agregarCuenta(12000.00);
    analia.agregarCuenta(3000.00);
    carlos[0].acreditar(1234.0);
    analia[0].debitar(1234.0);
    A.escribirCliente(carlos);
    A.escribirCliente(analia);
    return 0;
}

