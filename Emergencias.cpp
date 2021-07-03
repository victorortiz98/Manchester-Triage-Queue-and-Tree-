//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Emergencias.h"
#include <iostream>
#include <string>

Emergencias::Emergencias(int id, std::string dni, std::string fecha) {
    IdPaciente = id;
    Dni = dni;
    Fecha = fecha;
}

int Emergencias::getIdPaciente() {
    return IdPaciente;
}

std::string Emergencias::getDni() {
    return Dni;
}

std::string Emergencias::getFecha() {
    return Fecha;
}

Emergencias::~Emergencias() {
}
