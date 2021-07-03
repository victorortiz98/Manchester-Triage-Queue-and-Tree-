//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "NodoPila.h"

NodoPila::NodoPila() {
    valor = 0;
    siguiente = NULL;
}

NodoPila::NodoPila(Pacientes *pct, NodoPila *sig) {
    valor = pct;
    siguiente = sig;
}

NodoPila::~NodoPila() {
}
