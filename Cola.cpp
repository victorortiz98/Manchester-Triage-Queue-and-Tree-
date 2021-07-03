//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Cola.h"

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}


Cola::~Cola() {
}

void Cola::queue(int elemento) {
    NodoCola *nuevo_nodo = new
            NodoCola(elemento);
    if (esVacia()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

int Cola::dequeue() {
    if (!esVacia()) {
        int elemento = primero->elemento;
        NodoCola *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL)) {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete (aux);
        } else {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete (aux);
        }
        longitud--;
        return elemento;
    }
}

int Cola::head() {
    if (!esVacia()) {
        return primero->elemento;
    }
}

int Cola::tail() {
    if (!esVacia()) {
        return ultimo->elemento;
    }
}

int Cola::get_longitud() {
    return longitud;
}

bool Cola::esVacia() {
    return ((primero == NULL) && (ultimo == NULL));
}

/*void Cola::mostrarCola(){
    NodoCola *aux = primero;
    if (esVacia()) {std::cout<<"Cola Vacía: " <<"\n";}
    else {
        std::cout<<"Datos de la Cola: "<<"\n";
        while (aux){
            std::cout << aux->elemento+"\n";
            aux = aux->siguiente;
        }
    }
}*/
void Cola::mostrarCola() {
    NodoCola *aux = primero;
    while (aux) {
        std::cout << aux->elemento << " ";
        aux = aux->siguiente;
    }
}
