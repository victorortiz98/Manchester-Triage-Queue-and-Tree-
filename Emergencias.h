//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_EMERGENCIAS_H
#define  TESTARBOL_EMERGENCIAS_H

#include <iostream>
#include <string>
#include <ctime>

class Emergencias {
public:
    Emergencias(int id, std::string dni, std::string fecha);

    Emergencias();

    int getIdPaciente();

    std::string getDni();

    std::string getFecha();

    ~Emergencias();

private:
    int IdPaciente;
    std::string Dni;
    std::string Fecha;

};

#endif //TESTARBOL_EMERGENCIAS_H
