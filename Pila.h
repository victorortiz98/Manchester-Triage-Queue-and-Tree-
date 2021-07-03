//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_PILA_H
#define  TESTARBOL_PILA_H

#include "NodoPila.h"

class Pila {
private:
    pnodo cima;
public:
    Pila();

    ~Pila();

    bool esVacia();

    void push(Pacientes *v);

    void pop();

    int mostrar(bool escribir);

    void buscarDni(Pila &pilaPacientes, string dni);

    int devolverId();

    string devolverDni();

    string devolverNombre();

    string devolverApellido1();

    string devolverApellido2();

    int devolverEdad();

    char devolverSexo();

    void eliminarElemento(Pila &pilaPacientesTemp, Pila &pilaPacientes, string dni);

    void invertirPila(Pila &pilaPacientesTemp, Pila &pilaPacientes);


};

#endif //TESTARBOL_PILA_H
