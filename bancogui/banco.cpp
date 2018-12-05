/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "banco.hpp"
#include "wx/msgdlg.h"
#include <algorithm>

/* Constructor de la Clase BANCO su funcion basicamente es inicializar los archivos
del programa si es que estos no existe. Para ello utiliza los atributos fstream (clientes
cuentas y movimientos) del objeto Banco*/
Banco::Banco()
{
    // Probamos si podemos abrir el archivo clientes.txt
    clientes.open("clientes.txt", fstream::in);
    // Si el archivo clientes.txt no se abre
    if(!clientes.is_open())
    {
        //Creamos el archivo clientes, cuentas y movimientos (por la combinacion out y trunc)
        clientes.open("clientes.txt",fstream::out | fstream::trunc);
        cuentas.open("cuentas.txt",fstream::out | fstream::trunc);
        movimientos.open("movimientos.txt",fstream::out | fstream::trunc);
        // Cerramos los archivos creados para pasar a ...
        clientes.close();
        cuentas.close();
        movimientos.close();
        //... el modo de lectura
        clientes.open("clientes.txt", fstream::in);
        cuentas.open("cuentas.txt", fstream::in);
        // el fstream movimientos pasa al modo append
        movimientos.open("movimientos.txt", fstream::out | fstream::app);
        // Si ocurrio todo esto es la primera vez que abrimos banco por lo tanto mostramos un bonito cartel.
        wxMessageBox(wxT("Ejecutando por primera vez Banco CrisNaMa\nEmpiece creando un cliente."),wxT("Atención"));
    }
    // Ahora veamos que cuando los archivos EXISTEN, simplemente los abro.
    else
    {
        cuentas.open("cuentas.txt", fstream::in);
        movimientos.open("movimientos.txt", fstream::out | fstream::app);
    }

}

/* Destructor de Banco. Basicamente cierra los archivos abiertos */
Banco::~Banco()
{
    clientes.close();
    cuentas.close();
    movimientos.close();
}


/* Es el mmetodo de guardado principal, al que se invoca cada vez que se quiere guaradar cambios en
el disco. Es realmente la manera en la que persiste el estado del Banco invocado al cerrar la ventana,
pero tambien de forma arbitraria cuando lo desee el cliente. */
void Banco::escribirEstadoAArchivos()
{
    //Escribimos todos los clientes, para ello primero cerramos el archivo clientes que habia quedado en modo lectura
    clientes.close();
    // Lo abrimos en modo truncar o sea, pisamos lo que sea que este en el archivo. Total vamos a guardar lo que esta en memoria
    clientes.open("clientes.txt", fstream::out | fstream::trunc);
    // Por cada cliente en clientesActivos
    for(int i = 0; i < clientesActivos.size(); i ++)
    {
        // escribo el cliente i del vector al archivo
        clientes << clientesActivos[i];
        // Si el cliente NO es el ultimo
        if(i < clientesActivos.size() - 1)
            // Pongo un enter al final del cliente (esto se hace para evitar un ultimo enter que me arruina el contar clientes)
            clientes << endl;
    }
    // Cierro el archivo clientes
    clientes.close();
    // Lo vuelvo a abrir en modo lectura asi el sistema vuelve al estado inicial
    clientes.open("clientes.txt",fstream::in);

    //Ahora vamos a escribir las cuentas, cerrarmos el filestream cuentas que esta en modo lectura
    cuentas.close();
    // Lo abrimos en modo truncar o sea, pisamos lo que sea que este en el archivo. Total vamos a guardar lo que esta en memoria
    cuentas.open("cuentas.txt", fstream::out | fstream::trunc);
    // Contamos la cantidad total de cuentasTotalesEnMemoria enmemoria, lo necesitamos para saber cuando va a terminar este algoritmo
    int cuentasTotales = cuentasTotalesEnMemoria();
    //Para cada cliente:
    for(int i = 0; i < clientesActivos.size(); i ++)
    {
        //Si el cliente tiene cuentas:
        if(clientesActivos[i].contarCuentasCliente() != 0)
        {
            //cout << "Escribiendo cuentas para: " << clientesActivos[i] << endl;
            //Recorremos cada cuenta
            //cout << "Tiene cuentas activas: " << clientesActivos[i].contarCuentas() << endl;
            for(int j = 0; j < clientesActivos[i].contarCuentasCliente(); j++)
            {
                //La escribimos en el disco
                cuentas << clientesActivos[i][j];
                // Decrementamos el contador de cuentasTotales
                cuentasTotales --;
                // Si la cuenta no es la ultima y todavia quedan cuentas en memoria (de cualquier cliente)
                if(j < clientesActivos[i].contarCuentasCliente() && cuentasTotales > 0)
                    // Coloco un salto de linea (Enter) al final :P
                    cuentas << endl;
            }
        }
    }
    //Cierro el archivo de cuentas
    cuentas.close();
    // Lo vuelvo a abrir en modo lectura para volver el sistema al estado inicial.
    cuentas.open("cuentas.txt", fstream::in);
}

/* Metodo que al invocarse lee los archivos de clientes y cuentas existentes e intenta cargar en memoria en forma
de vectores todos ellos. Empieza cargando los clientes, leyendo linea a linea el archivo y agregandolos a un vector
de cliente dependiente de la instancia de Banco. Una vez finalizado el archivo de cliente se inicia la lectura linea
a linea del archivo de cuentas, con cada cuenta leida se busca la posicion del cliente a la cual pertenece mediante
la comparacion del DNI del cliente con el DNI de la cuenta */
void Banco::leerArchivos()
{
    // Contamos la cantidad de lineas (Clientes) que tiene el archivo de clientes
    int cantClientes = contarClientesDeArchivos();
    //Si hay lineas (Clientes):
    if(cantClientes > 0)
    {
        // Creamos una variable Tipo Cliente auxiliar
        Cliente auxCliente;
        // Posicionamos el cursor de lectura al principio del archivo.
        clientes.seekg(clientes.beg);
        // Mientras queden lineas por lleer
        while(!clientes.eof())
        {
            // Leo una linea y la ingreso en el auxiliar
            clientes >> auxCliente;
            // Guardo el cliente en el vector de clientes del banco
            insertarClienteOrdenado(auxCliente);
            // Si se termino el archivo corto el while(para evitar errores)
            if(clientes.eof())
                break;
        }
        // Contamos la cantidad de lineas (Cuentas) que contiene el archivo de cuentas
        int cantCuentas = contarCuentasDeArchivos();
        // Si hay cuentas
        if(cantCuentas > 0)
        {
            // Posicionamos el cursor de lectura en el principio del archivo
            cuentas.seekg(cuentas.beg);
            // Establecemos la variable auxiliar mayorId, la cual utilizaremos para inicializar el int static generador de numeros
            int mayorId = 1;
            // Mientras queden lineas por leer
            while(!cuentas.eof())
            {
                // Creamos una variable de tipo Cuenta
                Cuenta auxCuenta;
                // Leemos una linea del archivo
                cuentas >> auxCuenta;
                // Si el numero unico del auxCuenta es mayor que el mayorId
                if(auxCuenta.getnumeroUnico() > mayorId)
                    //Guardamos el numero unico en mayorId
                    mayorId = auxCuenta.getnumeroUnico();
                // Para cada clienteActivo en el banco
                for(int i = 0; i < clientesActivos.size(); i ++)
                {
                    // Si el dni de la cuenta es igual al dni del cliente comparado
                    if(clientesActivos[i].getDni() == auxCuenta.getdniDuenio())
                    {
                        // Agregamos la cuenta al vector cuenta de ese cliente
                        clientesActivos[i].agregarCuenta(auxCuenta);
                        break;
                    }
                }
                // Si se termino el archivo cortamos las iteraciones
                if(cuentas.eof())
                    break;
            }
            // Con el numero mayorId recabado inicializamos la variable static generadora de numeros unicos
            Cuenta::inicializarGenerador(mayorId + 1);
        }
    }

}


/* Metodo que cuenta la cantidad de lineas (Para nosotros clientes) del archivo de clientes */
int Banco::contarClientesDeArchivos()
{
    // Inicialiamos una variable contador de tipo int
    int contador = 0;
    // Creamos una cadena auxiliar para almacenar el contenido de la linea leida del archivo de clientes
    string aux;
    // Posicionamos el cursor de lectura en el principio del archivo
    clientes.seekg(clientes.beg);
    // Mientras no se llegue al final del archivo
    while(!clientes.eof())
    {
        // Guardamos el contenido de la linea en la cadena auxiliar (esto es para que no caiga en saco roto)
        clientes >> aux;
        // Filtramos cadenas que sean solo un salto de linea que causarian errores
        if(aux.size() > 1)
        {
            contador ++;
        }
        // Si el archivo termino cortamos las iteraciones
        if(clientes.eof())
            break;
    }
    // Devolvemos el valor del contador
    return contador;
}

/* Metodo que cuenta la cantidad de lineas (Para nosotros cuentas) del archivo de cuentas */
int Banco::contarCuentasDeArchivos()
{
    // Inicialiamos una variable contador de tipo int
    int contador = 0;
    // Creamos una cadena auxiliar para almacenar el contenido de la linea leida del archivo de clientes
    string aux;
    // Posicionamos el cursor de lectura en el principio del archivo
    cuentas.seekg(cuentas.beg);
    // Mientas no se llegue al final del archivo
    while(!cuentas.eof())
    {
        // Guardamos el contenido de la linea en la cadena auxiliar (esto es para que no caiga en saco roto)
        cuentas >> aux;
        // Filtramos cadenas que sean solo un salto de linea que causarian errores
        if(aux.size() > 1)
        {
            contador ++;
        }
        // Si el archivo termino cortamos las iteraciones
        if(cuentas.eof())
            break;
    }
    // Devolvemos el valor del contador
    return contador;
}

/* Metodo que devuelve la cantidad de cuentas totales en memoria recorriendo todo el vector de clientes (cliente
por cliente). Sirve para saber cuando va a terminar la escritura de cuentas */
int Banco::cuentasTotalesEnMemoria() const
{
    // Inicializamos un contador en cero
    int contador = 0;
    // Para cada clienteActivo en el banco
    for(int i = 0; i < clientesActivos.size(); i ++)
    {
        // le sumamos al contador el tamaño del vector de cuentas del cliente
        contador += clientesActivos[i].contarCuentasCliente();
    }
    // Devolvemos el valor acumulado en el contador
    return contador;
}


bool ordenarApellidos(Cliente & A,Cliente & B)
{
    return (A.getApellido() < B.getApellido());
}

void Banco::insertarClienteOrdenado(Cliente nuevo)
{
    clientesActivos.push_back(nuevo);
    sort(clientesActivos.begin(),clientesActivos.end(),ordenarApellidos);
}
