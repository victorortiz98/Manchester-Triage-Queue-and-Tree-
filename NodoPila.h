//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_NODOPILA_H
#define  TESTARBOL_NODOPILA_H

#include <iostream>
#include "Pacientes.h"

using namespace std;

class NodoPila {
private:
    Pacientes *valor;
    NodoPila *siguiente;

    friend class Pila;

public:
    NodoPila();

    NodoPila(Pacientes *valor, NodoPila *sig = NULL);

    ~NodoPila();

};

typedef NodoPila *pnodo;

#endif //TESTARBOL_NODOPILA_H
