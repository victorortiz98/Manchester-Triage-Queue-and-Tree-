//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Pila.h"
#include "NodoPila.h"
#include "Pacientes.h"
#include "Hospital.h"

Pila::Pila() {
    cima = NULL;
}

Pila::~Pila() {
    while (cima) pop();
}

bool Pila::esVacia() { return cima == NULL; }

void Pila::push(Pacientes *v) {
    pnodo nuevo = new NodoPila(v,
                               cima);
    //comienzo de la pila nevo nodo
    cima = nuevo;
}

void Pila::pop() {
    pnodo nodo; //Creamos un puntero auxiliar para poder manipular el nodo
    if (cima)
        nodo = cima;
    cima = nodo->siguiente;
    delete nodo;
}

int Pila::mostrar(bool escribir) {
    if (escribir) {
        cout << "--------------------------------------------" << endl;
        cout << "Paciente :" << cima->valor->getIdPaciente() << endl;
        cout << "DNI:" << cima->valor->getDni() << endl;
        cout << "Nombre:" << cima->valor->getNombre() << endl;
        cout << "Apellido1:" << cima->valor->getApellido1() << endl;
        cout << "Apellido2:" << cima->valor->getApellido2() << endl;
        cout << "Edad:" << cima->valor->getEdad() << endl;
        cout << "Sexo:" << cima->valor->getSexo() << endl;
        cout << "--------------------------------------------" << endl;
    }
    cima = cima->siguiente;

    return 0;

}

void Pila::buscarDni(Pila &pilaPacientes, string dni) {
    pnodo nodo;
    while (!esVacia()) {
        nodo = cima;

        if (cima->valor->getDni() == dni) {
            pilaPacientes.mostrar(true);

        } else {
            cima = cima->siguiente;
        }


    }
}

int Pila::devolverId() {
    pnodo nodo;
    nodo = cima;
    int devolver = cima->valor->getIdPaciente();
    return devolver;
}

string Pila::devolverDni() {
    pnodo nodo;
    nodo = cima;
    string devolver = cima->valor->getDni();
    return devolver;
}

string Pila::devolverNombre() {
    pnodo nodo;
    nodo = cima;
    string devolver = cima->valor->getNombre();
    return devolver;
}

string Pila::devolverApellido1() {
    pnodo nodo;
    nodo = cima;
    string devolver = cima->valor->getApellido1();
    return devolver;
}

string Pila::devolverApellido2() {
    pnodo nodo;
    nodo = cima;
    string devolver = cima->valor->getApellido2();
    return devolver;
}

int Pila::devolverEdad() {
    pnodo nodo;
    nodo = cima;
    int devolver = cima->valor->getEdad();
    return devolver;
}

char Pila::devolverSexo() {
    pnodo nodo;
    nodo = cima;
    char devolver = cima->valor->getSexo();
    return devolver;
}

void Pila::invertirPila(Pila &pilaPacientesTemp, Pila &pilaPacientes) {
    int id = cima->valor->getIdPaciente();
    std::string DNI = cima->valor->getDni();
    std::string nom = cima->valor->getNombre();
    std::string ape1 = cima->valor->getApellido1();
    std::string ape2 = cima->valor->getApellido2();
    int edad = cima->valor->getEdad();
    char sexo = cima->valor->getSexo();
    Pacientes *pa1 = new Pacientes(id, DNI, nom, ape1, ape2, edad, sexo);
    pilaPacientesTemp.push(pa1);
    pilaPacientes.mostrar(true);
}

//Eliminar nodo de la pila conservando los nodos anteriores
// top es el puntero al nodo superior de la pila, top2 es un nodo buffer para almacenar datos de manera temporal
void Pila::eliminarElemento(Pila &pilaPacientesTemp, Pila &pilaPacientes, string dni) {

    pnodo nodo;

    cout << "Baja paciente :" << endl;

    bool encontrado = true;
    cout << "Desapilamos pilaPacientes y lo pasamos a PilaPacientesTemp:" << endl;
    while (encontrado && !esVacia()) {
        nodo = cima;
        bool eli = false;
        if (cima->valor->getDni() == dni) {
            cout << "Paciente ELIMINAD0: " << endl;
            pilaPacientes.mostrar(true);
            encontrado = false;
            eli = true;
        }
        if (eli == false) {
            pilaPacientes.invertirPila(pilaPacientesTemp, pilaPacientes);
        }
    }
    while (!esVacia()) {
        pilaPacientes.invertirPila(pilaPacientesTemp, pilaPacientes);
    }
    cout << "Introducimos los valores de pilaPacientesTemp a pilaPacientes y se limpia pilaPacientesTemp:" << endl;
    while (!pilaPacientesTemp.esVacia()) {
        pilaPacientesTemp.invertirPila(pilaPacientes, pilaPacientesTemp);
    }


}
