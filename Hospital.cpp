//
// Created by Víctor Ortiz on 16/06/2021.
//

#include "Hospital.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Emergencias.h"
#include "Arbol.h"
#include <time.h>
#include "Cola.h"

Hospital::Hospital() {
}

Arbol ArbolR;
Arbol ArbolN;
Arbol ArbolV;
Arbol ArbolA;
pNodo3 ABN = NULL;
pNodo3 ABR = NULL;
pNodo3 ABA = NULL;
pNodo3 ABV = NULL;


std::string Hospital::leerDni() {
    std::string dniCliente;
    std::cout << "Introduce el DNI del paciente:" << endl;
    std::cin >> dniCliente;
    return dniCliente;
}


std::string Fecha() {
    string valorFecha = "";
    SYSTEMTIME fecha;
    GetSystemTime(&fecha);
    valorFecha = to_string(fecha.wYear) + "/" + to_string(fecha.wMonth) + "/" + to_string(fecha.wDay) + " " +
                 to_string(fecha.wHour + 1) + ":" + to_string(fecha.wMinute) + ":" + to_string(fecha.wSecond);
    return valorFecha;
}

//CASE0:
void Hospital::altaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    char arbol = 'S';
    while (!pilaPacientes.esVacia() && arbol != 'X') {
        int datoId = pilaPacientes.devolverId();
        std::string datoDni = (std::string) (pilaPacientes.devolverDni()).c_str();
        std::string datoNombre = (std::string) (pilaPacientes.devolverNombre()).c_str();
        std::string datoAp1 = (std::string) (pilaPacientes.devolverApellido1()).c_str();
        std::string datoAp2 = (std::string) (pilaPacientes.devolverApellido2()).c_str();
        int datoEdad = pilaPacientes.devolverEdad();
        char datoSexo = pilaPacientes.devolverSexo();
        std::cout << "ID: " << datoId << endl;
        std::cout << "DNI: " << datoDni << endl;
        std::cout << "Nombre: " << datoNombre << endl;
        std::cout << "Apellido 1: " << datoAp1 << endl;
        std::cout << "Apellido 2: " << datoAp2 << endl;
        std::cout << "Edad: " << datoEdad << endl;
        std::cout << "Sexo: " << datoSexo << endl;
        Emergencias *pacientei;
        do {
            std::cout
                    << "Introduce el arbol de emergencias(A/N/V/R) en el que desea dar de alta al paciente. Pulse X para dejar de dar de alta"
                    << endl;
            std::cin >> arbol;
            if (arbol == 'A') {
                pilaPacientes.mostrar(false);
                pacientei = new Emergencias(datoId, datoDni, Fecha());
                ArbolA.insertarNodo(pacientei, ABA);
            } else if (arbol == 'V') {
                pilaPacientes.mostrar(false);
                pacientei = new Emergencias(datoId, datoDni, Fecha());
                ArbolV.insertarNodo(pacientei, ABV);
            } else if (arbol == 'R') {
                pilaPacientes.mostrar(false);
                pacientei = new Emergencias(datoId, datoDni, Fecha());
                ArbolR.insertarNodo(pacientei, ABR);
            } else if (arbol == 'N') {
                pilaPacientes.mostrar(false);
                pacientei = new Emergencias(datoId, datoDni, Fecha());
                ArbolN.insertarNodo(pacientei, ABN);
            } else if (arbol != 'X') {
                std::cout << "La lista introducida no es correcta. Asegurese de que el dato introducido es válido"
                          << endl;
            }
        } while (arbol != 'A' && arbol != 'V' && arbol != 'N' && arbol != 'R' && arbol != 'X');
    }
}


//Apartado 11:
void Hospital::bajaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp) {

    std::string dni = leerDni();
    pilaPacientes.eliminarElemento(pilaPacientesTemp, pilaPacientes, dni);

    ArbolR.borrarNodo(dni, ABR, ArbolR.contar(ABR));
    ArbolN.borrarNodo(dni, ABN, ArbolN.contar(ABN));
    ArbolA.borrarNodo(dni, ABA, ArbolA.contar(ABA));
    ArbolV.borrarNodo(dni, ABV, ArbolV.contar(ABV));
}

//Apartado 2:
void Hospital::reasignacionArbol() {
    std::string dni = leerDni();
    char arbolEmergencia;
    do {
        std::cout << "Introduce el arbol de emergencias (R/N/V/A) en el que esta asignado el paciente:" << endl;
        std::cin >> arbolEmergencia;
        if (arbolEmergencia != 'R' && arbolEmergencia != 'N' && arbolEmergencia != 'V' && arbolEmergencia != 'A') {
            std::cout << "El árbol introducido no es correcto. Asegurese de que el dato introducido es válido" << endl;
        }
    } while (arbolEmergencia != 'R' && arbolEmergencia != 'N' && arbolEmergencia != 'V' && arbolEmergencia != 'A');
    char nuevoArbol;
    do {
        std::cout << "Introduce el nuevo arbol de emergencia(R/N/V/A) en el que se va a reasignar el paciente:" << endl;
        std::cin >> nuevoArbol;
        if (nuevoArbol != 'R' && nuevoArbol != 'N' && nuevoArbol != 'V' && nuevoArbol != 'A') {
            std::cout << "El árbol introducido no es correcto. Asegurese de que el dato introducido es válido" << endl;
        }
    } while (nuevoArbol != 'R' && nuevoArbol != 'N' && nuevoArbol != 'V' && nuevoArbol != 'A');
    int idPaci;
    bool localizado;
    if (arbolEmergencia == 'R') {
        localizado = ArbolR.buscarDni(dni, ABR);
    } else if (arbolEmergencia == 'N') {
        localizado = ArbolN.buscarDni(dni, ABN);
    } else if (arbolEmergencia == 'V') {
        localizado = ArbolV.buscarDni(dni, ABV);
    } else if (arbolEmergencia == 'A') {
        localizado = ArbolA.buscarDni(dni, ABA);
    }
    if (localizado) {
        if (arbolEmergencia == 'R') {
            idPaci = ArbolR.devolverId(dni);
            ArbolR.borrarNodo(dni, ABR, ArbolR.contar(ABR));
        } else if (arbolEmergencia == 'N') {
            idPaci = ArbolR.devolverId(dni);
            ArbolN.borrarNodo(dni, ABN, ArbolN.contar(ABN));
        } else if (arbolEmergencia == 'V') {
            idPaci = ArbolR.devolverId(dni);
            ArbolV.borrarNodo(dni, ABV, ArbolV.contar(ABV));
        } else if (arbolEmergencia == 'A') {
            idPaci = ArbolR.devolverId(dni);
            ArbolA.borrarNodo(dni, ABA, ArbolA.contar(ABA));
        }
        Emergencias *pacientei = new Emergencias(idPaci, dni, Fecha());
        if (nuevoArbol == 'R') {
            ArbolR.insertarNodo(pacientei, ABR);
        } else if (nuevoArbol == 'N') {
            ArbolN.insertarNodo(pacientei, ABN);
        } else if (nuevoArbol == 'V') {
            ArbolV.insertarNodo(pacientei, ABV);
        } else if (nuevoArbol == 'A') {
            ArbolA.insertarNodo(pacientei, ABA);
        }
    } else {
        std::cout << "El DNI introducido no se ha encontrado en el arbol." << endl;
    }
}

//Apartado 3
void Hospital::menuOpcion3(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    int opc;
    bool comprobar = false;
    while (!comprobar) {
        comprobar = true;
        std::cout << "Elige una opción:" << endl;
        std::cout << "--------------------------------------------" << endl;
        std::cout << "											  " << endl;
        std::cout << "1. Consulta de pacientes." << endl;
        std::cout << "2. Consulta de emergencias." << endl;
        std::cout << "3. Mostrar tiempos de emergencia superados." << endl;
        std::cin >> opc;
        if (opc == 1) {
            bool comprobar1 = false;
            int opcion1;
            while (!comprobar1) {
                comprobar1 = true;
                std::cout << "Elige un tipo de consulta:" << endl;
                std::cout << "--------------------------------------------" << endl;
                std::cout << "											  " << endl;
                std::cout << "1. Mostrar paciente indicando su dni." << endl;
                std::cout << "2. Mostrar todos los pacientes." << endl;
                std::cin >> opcion1;
                if (opcion1 < 1 || opcion1 > 2) {
                    comprobar1 = false;
                    std::cout << "La opción introducida no es correcta. Asegurese de que el dato introducido es válido"
                              << endl;
                }
                if (opcion1 == 1) {
                    verificarDni(pilaPacientes, pilaPacientesTemp);
                } else {
                    mostrarTodos(pilaPacientes, pilaPacientesTemp);
                }
            }
        } else if (opc == 2) {
            bool comprobar2 = false;
            int opcion2;
            while (!comprobar2) {
                comprobar2 = true;
                std::cout << "Elige un tipo de consulta:" << endl;
                std::cout << "--------------------------------------------" << endl;
                std::cout << "											  " << endl;
                std::cout << "1. Mostrar emergencia indicando el ID." << endl;
                std::cout << "2. Mostrar todas las emergencias." << endl;
                std::cout << "3. Mostrar grafico de arboles y colas." << endl;
                std::cin >> opcion2;
                if (opcion2 < 1 || opcion2 > 3) {
                    comprobar2 = false;
                    std::cout << "La opción introducida no es correcta. Asegurese de que el dato introducido es válido"
                              << endl;
                }
                if (opcion2 == 1) {
                    verificarId();
                } else if (opcion2 == 2) {
                    mostrarEmergencias();
                } else if (opcion2 == 3) {
                    mostrarGrafico();
                }
            }
        } else if (opc == 3) {
            consultarTiempos();

        } else {
            std::cout << "La opción introducida no es correcta. Asegurese de que el dato introducido es válido" << endl;
            comprobar = false;
        }
    }
}

//Apartado 3.1.1
void Hospital::verificarDni(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    pilaPacientesTemp = pilaPacientes;
    string dni;
    std::cout << "Introduce un DNI para comprobar si es válido" << endl;
    std::cin >> dni;
    pilaPacientes.buscarDni(pilaPacientes, dni);
    pilaPacientes = pilaPacientesTemp;
    while (!pilaPacientesTemp.esVacia()) {
        pilaPacientesTemp.mostrar(false);
    }
}

//Apartado 3.1.2
void Hospital::mostrarTodos(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    pilaPacientesTemp = pilaPacientes;
    while (!pilaPacientes.esVacia()) {
        pilaPacientes.mostrar(true);
    }
    pilaPacientes = pilaPacientesTemp;
    while (!pilaPacientesTemp.esVacia()) {
        pilaPacientesTemp.mostrar(false);
    }
}

//Apartado 3.2.1
void Hospital::verificarId() {
    int id;
    std::cout << "Introduce el ID del paciente para comprobar a que árbol pertenece:" << endl;
    std::cin >> id;
    if (ArbolR.mostrarDni(id, ABR)) {
        std::cout << "El ID introducido pertenece al arbol R" << endl;
    } else if (ArbolN.mostrarDni(id, ABN)) {
        std::cout << "El ID introducido pertenece al arbol N" << endl;
    } else if (ArbolV.mostrarDni(id, ABV)) {
        std::cout << "El ID introducido pertenece al arbol V" << endl;
    } else if (ArbolA.mostrarDni(id, ABA)) {
        std::cout << "El ID introducido pertenece al arbol A" << endl;
    } else {
        std::cout << "El ID introducido no se ha encontrado" << endl;
    }
}


//Apartado 3.2.2
void Hospital::mostrarEmergencias() {
    std::cout << "ARBOL R:" << endl;
    if (ArbolR.esVacio(ABR)) {
        std::cout << "Vacia" << endl;
        std::cout << "" << endl;
    } else {
        ArbolR.mostrar(ABR);
    }
    std::cout << "ARBOL N:" << endl;
    if (ArbolN.esVacio(ABN)) {
        std::cout << "Vacia" << endl;
        std::cout << "" << endl;
    } else {
        ArbolN.mostrar(ABN);
    }
    std::cout << "ARBOL V:" << endl;
    if (ArbolV.esVacio(ABV)) {
        std::cout << "Vacia" << endl;
        std::cout << "" << endl;
    } else {
        ArbolV.mostrar(ABV);
    }
    std::cout << "ARBOL A:" << endl;
    if (ArbolA.esVacio(ABA)) {
        std::cout << "Vacia" << endl;
        std::cout << "" << endl;
    } else {
        ArbolA.mostrar(ABA);
    }
}

//CASE 3.2.3
void Hospital::mostrarGrafico() {
    Cola colaPacientesUrg;
    Cola colaPacientesUrgTemp;
    bool resto;
    if (!ArbolR.esVacio(ABR)) {
        std::cout << "Arbol R:" << endl;
        ArbolR.mostrarRaiz(ABR);
        resto = ArbolR.resto(ABR);
        if (!resto) {
            ArbolR.contarLineas(ABR);
        }
        ArbolR.mostrarIds(ABR);
    }
    if (!ArbolN.esVacio(ABN)) {
        std::cout << "" << endl;
        std::cout << "Arbol N:" << endl;
        ArbolN.mostrarRaiz(ABN);
        resto = ArbolN.resto(ABN);
        if (!resto) {
            ArbolN.contarLineas(ABN);
        }
        ArbolN.mostrarIds(ABN);
    }

    if (!ArbolA.esVacio(ABA)) {
        std::cout << "" << endl;
        std::cout << "Arbol A:" << endl;
        ArbolA.mostrarRaiz(ABA);
        resto = ArbolA.resto(ABA);
        if (!resto) {
            ArbolA.contarLineas(ABA);
        }
        ArbolA.mostrarIds(ABA);
    }

    if (!ArbolV.esVacio(ABV)) {
        std::cout << "" << endl;
        std::cout << "Arbol V:" << endl;
        ArbolV.mostrarRaiz(ABV);
        resto = ArbolV.resto(ABV);
        if (!resto) {
            ArbolV.contarLineas(ABV);
        }
        ArbolV.mostrarIds(ABV);
    }
    std::cout << "" << endl;
    std::cout << "Cola: ";
    if (!ArbolV.esVacio(ABV)) {
        colaPacientesUrg = ArbolV.devIds(ABV, colaPacientesUrgTemp);
        colaPacientesUrg.mostrarCola();
    }
    if (!ArbolA.esVacio(ABA)) {
        colaPacientesUrg = ArbolA.devIds(ABA, colaPacientesUrgTemp);
        colaPacientesUrg.mostrarCola();
    }
    if (!ArbolN.esVacio(ABN)) {
        colaPacientesUrg = ArbolN.devIds(ABN, colaPacientesUrgTemp);
        colaPacientesUrg.mostrarCola();
    }
    if (!ArbolR.esVacio(ABR)) {
        colaPacientesUrg = ArbolR.devIds(ABR, colaPacientesUrgTemp);
        colaPacientesUrg.mostrarCola();
    }
    std::cout << "" << endl;
}

//CASE 3.3
void Hospital::consultarTiempos() {
    int horaActual = 0;
    int minutoActual = 0;
    int segundoActual = 0;
    int opcion = 0;
    while (opcion != 1 && opcion != 2) {
        std::cout << "Elige una opcion:" << "\n";
        std::cout << "--------------------------------------------" << endl;
        std::cout << "											  " << endl;
        std::cout << "1. Hora actual." << "\n";
        std::cout << "2. Elegir hora." << "\n";
        std::cin >> opcion;
        if (opcion == 1) {
            SYSTEMTIME fecha1;
            GetSystemTime(&fecha1);
            horaActual = fecha1.wHour + 1;
            minutoActual = fecha1.wMinute;
            segundoActual = fecha1.wSecond;
        } else if (opcion == 2) {
            bool error = true;
            while (error) {
                error = false;
                std::cout << "Introduce la hora en el formato (horas:minutos:segundos):" << endl;
                std::string horaElegida;
                std::cin >> horaElegida;
                int numElementos = 0;
                for (int i = 0; i < horaElegida.size(); i++) {
                    std::string caracter = horaElegida.substr(i, 1);
                    if (caracter != "1" && caracter != "2" && caracter != "3" && caracter != "4" && caracter != "5" &&
                        caracter != "6" && caracter != "7" && caracter != "8" && caracter != "9" && caracter != "0" &&
                        caracter != ":") {
                        error = true;
                    }
                    if (caracter == ":") {
                        numElementos++;
                    } else {
                        if (numElementos == 0) {
                            horaActual = (horaActual * 10) + atoi(caracter.c_str());
                        } else if (numElementos == 1) {
                            minutoActual = (minutoActual * 10) + atoi(caracter.c_str());
                        } else if (numElementos = 2) {
                            segundoActual = (segundoActual * 10) + atoi(caracter.c_str());
                        }
                    }
                }
                if (horaActual < 0 || horaActual > 23 || minutoActual < 0 || minutoActual > 59 || segundoActual < 0 ||
                    segundoActual > 59) {
                    error = true;
                }
                if (error) {
                    std::cout << "La hora introducida no es correcta" << endl;
                    horaActual = 0;
                    minutoActual = 0;
                    segundoActual = 0;
                }
            }
        } else {
            std::cout << "La opción introducida no es correcta. Asegurese de que el dato introducido es válido" << "\n";
        }
    }
    std::cout << "ARBOL R:" << endl;
    ArbolR.postOrden(0, ABR, 'R', horaActual, minutoActual, segundoActual);
    std::cout << "ARBOL N:" << endl;
    ArbolN.postOrden(0, ABN, 'N', horaActual, minutoActual, segundoActual);
    std::cout << "ARBOL V:" << endl;
    ArbolV.postOrden(0, ABV, 'V', horaActual, minutoActual, segundoActual);
    std::cout << "ARBOL A:" << endl;
    ArbolA.postOrden(0, ABA, 'A', horaActual, minutoActual, segundoActual);

}


//CASE 4
void Hospital::vaciarArbol() {
    ArbolR.vaciarArbol(ABR);
    ArbolN.vaciarArbol(ABN);
    ArbolA.vaciarArbol(ABA);
    ArbolV.vaciarArbol(ABV);

}

Hospital::~Hospital() {
}
