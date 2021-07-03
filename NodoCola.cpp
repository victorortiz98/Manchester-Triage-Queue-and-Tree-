//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "NodoCola.h"

NodoCola::NodoCola() {
    elemento = 0;
    siguiente = NULL;
}

NodoCola::NodoCola(int e, NodoCola *sig) {
    elemento = e;
    siguiente = sig;
}

NodoCola::~NodoCola() {
}
