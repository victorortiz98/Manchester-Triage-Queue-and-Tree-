cmake_minimum_required(VERSION 3.19)
project(TESTARBOL)

set(CMAKE_CXX_STANDARD 14)

add_executable(TESTARBOL main.cpp Arbol.cpp Arbol.h Cola.cpp Cola.h Emergencias.cpp Emergencias.h Hospital.cpp Hospital.h NodoArbol.h NodoCola.cpp NodoCola.h NodoPila.cpp NodoPila.h Pacientes.cpp Pacientes.h Pila.cpp Pila.h)