//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_COLA_H
#define TESTARBOL_COLA_H

#include "NodoCola.h"

class Cola {
private:
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;
public:
    Cola();

    ~Cola();

    void queue(int elemento);

    int head(); //Indica el primer elemento de la cola
    int tail(); //Indica el último elemento de la cola
    int dequeue();

    bool esVacia();

    void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
    int get_longitud();

};

#endif //TESTARBOL_COLA_H
