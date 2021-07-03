//
// Created by Víctor Ortiz on 16/06/2021.
//

#ifndef TESTARBOL_ARBOL_H
#define  TESTARBOL_ARBOL_H


#include "NodoArbol.h"
#include "Cola.h"
#include "NodoCola.h"

class Arbol {
private:
    pNodo3 raiz, actual = NULL;
    int contador, altura;

    void podar(pNodo3 &nodo);

    void auxContador(pNodo3 nodo);

    void auxAltura(pNodo3 nodo, int a);

    void mostrarArbol(int &d);

public:
    Arbol() : raiz(NULL), actual(NULL) {}

    ~Arbol() { podar(raiz); }

    bool buscarNodo(Emergencias *v);

    void insertarNodo(Emergencias *dat, pNodo3 &ABB);

    void borrarNodo(std::string dni, pNodo3 &ABB, int cont);

    bool esVacio(pNodo3 nodo) { return raiz == NULL; }

    bool esHoja(pNodo3 nodo) { return !nodo->derecha && !nodo->izquierda; }

    int numeroNodos();

    int getAlturaArbol();

    Emergencias *getValorActual() { return actual->dato; }

    void esRaiz() { actual = raiz; }

    void inOrden(pNodo3 *nodo);

    void preOrden(pNodo3 *nodo);

    void postOrden(int nodos, pNodo3 &ABB, char arb, int horaActual, int minutoActual, int segundoActual);

    void mostrar(pNodo3 &ABB);

    Emergencias *maximo(pNodo3 &ABB);

    bool mostrarDni(int id, pNodo3 &ABB);

    void mostrarRaiz(pNodo3 &ABB);

    bool resto(pNodo3 &ABB);

    void contarLineas(pNodo3 &ABB);

    void mostrarIds(pNodo3 &ABB);

    Cola devIds(pNodo3 &ABB, Cola colaPacientesUrgTemp);

    int contar(Arbol a);

    int contar(pNodo3 &ABB);

    void vaciarArbol(pNodo3 &ABB);

    int devolverId(std::string dni);

    bool buscarDni(std::string dni, pNodo3 &ABB);
};

#endif //TESTARBOL_ARBOL_H
