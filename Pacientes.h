//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_PACIENTES_H
#define  TESTARBOL_PACIENTES_H

#include <iostream>
#include <string>

class Pacientes {
public:
    Pacientes(int id, std::string dni, std::string nombre, std::string apellido1, std::string apellido2, int edad,
              char sexo);

    Pacientes();

    int getIdPaciente();

    std::string getDni();

    std::string getNombre();

    std::string getApellido1();

    std::string getApellido2();

    int getEdad();

    char getSexo();

    ~Pacientes();

private:
    int IdPaciente, Edad;
    std::string Dni, Nombre, Apellido1, Apellido2;
    char Sexo;

};

#endif //TESTARBOL_PACIENTES_H
