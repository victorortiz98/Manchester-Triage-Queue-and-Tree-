//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_NODOARBOL_H
#define  TESTARBOL_NODOARBOL_H

#include "Emergencias.h"

class NodoArbol {

private:
    Emergencias *dato;
    NodoArbol *izquierda;
    NodoArbol *derecha;

    friend class Arbol;

public:
    NodoArbol(Emergencias *dat, NodoArbol *izq = NULL, NodoArbol *der = NULL) {
        dato = dat;
        izquierda = izq;
        derecha = der;
    }
};

typedef NodoArbol *pNodo3;

#endif //TESTARBOL_NODOARBOL_H
