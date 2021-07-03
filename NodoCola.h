//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_NODOCOLA_H
#define  TESTARBOL_NODOCOLA_H

#include <iostream>

class NodoCola {
    friend class Cola;

private:
    NodoCola *siguiente;
    int elemento;
public:
    NodoCola();

    NodoCola(int e, NodoCola *sig = NULL);

    ~NodoCola();

};

#endif //TESTARBOL_NODOCOLA_H
