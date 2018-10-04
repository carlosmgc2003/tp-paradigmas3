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
    A.leerArchivos();
    A.escribirArchivo("Carlos Maceira",1);
    A.escribirArchivo("Caja de Ahorro",2);
    A.escribirArchivo("Debito $500",3);
    return 0;
}

