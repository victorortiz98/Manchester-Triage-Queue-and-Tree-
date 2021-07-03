//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_HOSPITAL_H
#define  TESTARBOL_HOSPITAL_H

#include "Pila.h"
#include <iostream>
#include <list>
#include "Arbol.h"

class Hospital {
public:
    Hospital();

    ~Hospital();

    void verificarDni(Pila &pilaPacientes, Pila &pilaPacientesTemp);

    void mostrarTodos(Pila &pilaPacientes, Pila &pilaPacientesTemp);

    void verificarId();

    void mostrarEmergencias();

    void altaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp);

    void bajaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp);

    void reasignacionArbol();

    void vaciarArbol();

    void mostrarGrafico();

    void consultarTiempos();

    std::string leerDni();

    void menuOpcion3(Pila &pilaPacientes, Pila &pilaPacientesTemp);

    void diferenciaHoras(std::string horaI);

private:

};


#endif //TESTARBOL_HOSPITAL_H
