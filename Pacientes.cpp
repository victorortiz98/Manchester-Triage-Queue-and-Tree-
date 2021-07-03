//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Pacientes.h"
#include <iostream>
#include <string>

Pacientes::Pacientes(int id, std::string dni, std::string nombre, std::string apellido1, std::string apellido2,
                     int edad, char sexo) {
    IdPaciente = id;
    Dni = dni;
    Nombre = nombre;
    Apellido1 = apellido1;
    Apellido2 = apellido2;
    Edad = edad;
    Sexo = sexo;
}

int Pacientes::getIdPaciente() {
    return IdPaciente;
}

std::string Pacientes::getDni() {
    return Dni;
}

std::string Pacientes::getNombre() {
    return Nombre;
}

std::string Pacientes::getApellido1() {
    return Apellido1;
}

std::string Pacientes::getApellido2() {
    return Apellido2;
}

int Pacientes::getEdad() {
    return Edad;
}

char Pacientes::getSexo() {
    return Sexo;
}

Pacientes::~Pacientes() {
}

