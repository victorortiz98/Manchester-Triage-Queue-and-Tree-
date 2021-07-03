//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Arbol.h"
#include "Emergencias.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <valarray>
#include "Cola.h"
#include "NodoCola.h"

using namespace std;


void Arbol::podar(pNodo3 &nodo) {
    if (nodo) {
        podar(nodo->izquierda); // Podar el nodo izquierdo
        podar(nodo->derecha); // Podar el nodo derecho
        delete nodo; // Eliminar nodo
        nodo = NULL;
    }
}

bool Arbol::buscarNodo(Emergencias *dat) {
    actual = raiz;
    while (!esVacio(actual)) {
        if (dat == actual->dato) return true;
        else if (dat > actual->dato) actual = actual->derecha;
        else if (dat < actual->dato) actual = actual->izquierda;
    }
    return false;
}

void Arbol::insertarNodo(Emergencias *dat, pNodo3 &ABB) {
    if (ABB == NULL) {
        ABB = new NodoArbol(dat);
        raiz = ABB;
        return;
    } else {
        esRaiz();
        if (ABB->derecha != NULL) {
            insertarNodo(dat, ABB->derecha);
        } else {
            insertarNodo(dat, ABB->izquierda);
        }
    }
}

void Arbol::borrarNodo(std::string dni, pNodo3 &ABB, int cont) {
    Emergencias *max;
    pNodo3 aux;

    if (!ABB == NULL) {
        if (dni == ABB->dato->getDni()) {
            if ((ABB->izquierda == NULL) && (ABB->derecha == NULL)) {

                if (cont == 1) {
                    raiz = NULL;
                }
                delete ABB;
                ABB = NULL;

            } else {
                if (ABB->izquierda == NULL) {
                    aux = ABB;
                    ABB = ABB->derecha;
                    delete (aux);

                } else {
                    if (ABB->derecha == NULL) {
                        aux = ABB;
                        ABB = ABB->izquierda;
                        delete (aux);

                    } else {
                        max = maximo(ABB->izquierda);
                        borrarNodo(max->getDni(), ABB->izquierda, cont);
                        ABB->dato = max;
                    }
                }
            }
        } else {
            borrarNodo(dni, ABB->izquierda, cont);
            borrarNodo(dni, ABB->derecha, cont);


        }
    }

}

void Arbol::vaciarArbol(pNodo3 &ABB) {
    pNodo3 aux;
    while (!ABB == NULL) {
        if ((ABB->izquierda == NULL) && (ABB->derecha == NULL)) {
            delete ABB;
            ABB = NULL;
            raiz = NULL;
        } else {
            if (ABB->izquierda == NULL) {
                aux = ABB;
                ABB = ABB->derecha;
                delete (aux);
            } else {
                if (ABB->derecha == NULL) {
                    aux = ABB;
                    ABB = ABB->izquierda;
                    delete (aux);
                }
            }
        }
    }
}

Emergencias *Arbol::maximo(pNodo3 &ABB) {
    Emergencias *e;
    if (ABB == NULL) {
        std::cout << "El árbol está vacio";

    } else {
        if (ABB->derecha == NULL) {
            e = ABB->dato;

        } else {
            e = maximo(ABB->derecha);
        }
    }
}

void Arbol::postOrden(int nodos, pNodo3 &ABB, char arb, int horaActual, int minutoActual, int segundoActual) {

    if (ABB == NULL) {
        return;
    } else {
        postOrden(nodos + 1, ABB->izquierda, arb, horaActual, minutoActual, segundoActual);
        bool mostrar = false;
        std::string valorHora = "";
        std::string valorMinutos = "";
        std::string valorSegundos = "";
        int numVariables = 0;
        std::string caracter;
        for (int i = 0; i < ABB->dato->getFecha().size(); i++) {
            caracter = ABB->dato->getFecha().substr(i, 1);
            if (caracter == "/" || caracter == ":" || caracter == " ") {
                numVariables++;
            } else if (numVariables == 3) {
                valorHora = valorHora + caracter;
            } else if (numVariables == 4) {
                valorMinutos = valorMinutos + caracter;
            } else if (numVariables == 5) {
                valorSegundos = valorSegundos + caracter;
            }
        }
        if (horaActual < atoi(valorHora.c_str())) {
            horaActual = horaActual + 24;
        }
        int segTrans = atoi(valorSegundos.c_str());
        int minTrans = atoi(valorMinutos.c_str()) * 60;
        int horTrans = atoi(valorHora.c_str()) * 3600;
        int tiempoActual = (((horaActual) * 3600) + (minutoActual * 60) + segundoActual);
        int valorTiempo = horTrans + minTrans + segTrans;
        int tiempoTrans = tiempoActual - valorTiempo;
        if (arb == 'R') {
            if (tiempoTrans > 0) {
                mostrar = true;
            }
        } else if (arb == 'N') {
            if (tiempoTrans > 900) {
                mostrar = true;
            }
        } else if (arb == 'A') {
            if (tiempoTrans > 3600) {
                mostrar = true;
            }
        } else if (arb == 'V') {

            if (tiempoTrans > 7200) {
                mostrar = true;
            }
        }
        if (mostrar) {
            std::cout << ABB->dato->getIdPaciente() << " " << ABB->dato->getDni() << " " << tiempoTrans
                      << " segundos transcurridos" << "\n";
        }
        postOrden(nodos + 1, ABB->derecha, arb, horaActual, minutoActual, segundoActual);
    }
}

void Arbol::mostrar(pNodo3 &ABB) {
    if (ABB == NULL) {
        return;
    } else {
        mostrar(ABB->derecha);
        std::cout << ABB->dato->getIdPaciente() << " " << ABB->dato->getDni() << " " << ABB->dato->getFecha() << "\n";
        mostrar(ABB->izquierda);
    }
}

bool Arbol::mostrarDni(int id, pNodo3 &ABB) {
    if (ABB == NULL) {
        return false;
    } else {
        mostrarDni(id, ABB->derecha);
        if (id == ABB->dato->getIdPaciente()) {
            std::cout << "El DNI del paciente es: " << ABB->dato->getDni() << "\n";
            return true;
        } else {
            mostrarDni(id, ABB->izquierda);
        }


    }
}

int Arbol::devolverId(std::string dni) {
    int id = atoi((dni.substr(7, 1)).c_str());
    if (id == 0) {
        id = 10;
    }
    return id;
}

bool Arbol::buscarDni(std::string dni, pNodo3 &ABB) {
    bool r = false;
    if (ABB == NULL) {
        return r;
    } else {
        if (dni == ABB->dato->getDni()) {
            r = true;
            return r;
        } else {
            if (ABB->izquierda == NULL) {
                r = buscarDni(dni, ABB->derecha);
            } else {
                if (ABB->derecha == NULL) {
                    r = buscarDni(dni, ABB->izquierda);
                }
            }
        }
    }
    return r;
}

void Arbol::mostrarRaiz(pNodo3 &ABB) {
    esRaiz();
    if (ABB->izquierda != NULL) {
        std::cout << "/ ";
    } else {
        std::cout << "|" << "\n";
    }
}

bool Arbol::resto(pNodo3 &ABB) {
    if (ABB->izquierda == NULL && ABB->derecha == NULL) {
        return true;
    } else {
        return false;
    }
}

void Arbol::contarLineas(pNodo3 &ABB) {
    if (ABB != NULL) {
        contarLineas(ABB->derecha);
        if (ABB->izquierda != actual) {
            if (ABB->izquierda != NULL) {
                std::cout << " | ";
            } else {
                std::cout << " %" << "\n";
            }
        }
        contarLineas(ABB->izquierda);
    }
}

void Arbol::mostrarIds(pNodo3 &ABB) {
    if (ABB != NULL) {
        mostrarIds(ABB->izquierda);
        std::cout << ABB->dato->getIdPaciente() << "  ";
        mostrarIds(ABB->derecha);
    }
}

Cola Arbol::devIds(pNodo3 &ABB, Cola colaPacientesUrgTemp) {
    if (ABB != NULL) {
        devIds(ABB->derecha, colaPacientesUrgTemp);
        colaPacientesUrgTemp.queue(ABB->dato->getIdPaciente());
        devIds(ABB->izquierda, colaPacientesUrgTemp);
    }
    return colaPacientesUrgTemp;
}

int Arbol::contar(Arbol a) {
    return a.contar(raiz);
}

int Arbol::contar(pNodo3 &ABB) {
    if (ABB != NULL) {
        int izq = contar(ABB->izquierda);
        int der = contar(ABB->derecha);
        int medio = 1;
        return izq + der + medio;
    }
    return 0;
}
