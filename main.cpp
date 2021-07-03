#include <cstdlib>
#include "Pila.h"
#include <string>
#include "Hospital.h"

#include "Emergencias.h"

using namespace std;

int main(int argc, char **argv) {
    Pacientes *paciente1 = new Pacientes(1, "99999991A", "Silvia", "Martos", "Esteve", 45, 'H');
    Pacientes *paciente2 = new Pacientes(2, "99999992B", "Mario", "Ruíz", "Sánchez", 28, 'V');
    Pacientes *paciente3 = new Pacientes(3, "99999993C", "María", "Setién", "Buendía", 60, 'H');
    Pacientes *paciente4 = new Pacientes(4, "99999994D", "Luis", "Domínguez", "Gracia", 4, 'V');
    Pacientes *paciente5 = new Pacientes(5, "99999995E", "Eva", "Navarro", "Hueste", 23, 'H');
    Pacientes *paciente6 = new Pacientes(6, "99999996F", "José", "Márquez", "Méndez", 15, 'V');
    Pacientes *paciente7 = new Pacientes(7, "99999997G", "Lucía", "Vindel", "Higuera", 80, 'H');
    Pacientes *paciente8 = new Pacientes(8, "99999998H", "Víctor", "Méndez", "Gimeno", 67, 'V');
    Pacientes *paciente9 = new Pacientes(9, "99999999J", "Elena", "Espinosa", "Moreno", 2, 'H');
    Pacientes *paciente10 = new Pacientes(10, "10000000K", "Manuel", "García", "Pérez", 87, 'V');
    Pila pilaPacientes;
    Pila *pPilaPacientes = &pilaPacientes;
    Pila pilaPacientesTemp;
    Pila *pPilaPacientesTemp = &pilaPacientesTemp;
    pilaPacientes.push(paciente1);
    pilaPacientes.push(paciente2);
    pilaPacientes.push(paciente3);
    pilaPacientes.push(paciente4);
    pilaPacientes.push(paciente5);
    pilaPacientes.push(paciente6);
    pilaPacientes.push(paciente7);
    pilaPacientes.push(paciente8);
    pilaPacientes.push(paciente9);
    pilaPacientes.push(paciente10);
    int opcion;
    std::string dni;
    while (opcion != 5) {
        Hospital *mostrar = new Hospital();
        std::cout << "------------------- TRIAJE DE MANCHESTER  --------------------------" << endl;
        std::cout << "|    Bienvenidos al sistema informático de gestión de emergencias  |     " << endl;
        std::cout << "---------------------------------------------------------------------" << endl;
        std::cout << "                                                                 " << endl;
        std::cout << "Introduce el número de la opción que desee ejecutar:" << endl;
        std::cout << "0. Dar de alta a un paciente en emergencia." << endl;
        std::cout << "1. Dar de baja a un paciente" << endl;
        std::cout << "2. Modificación o reasignación de pacientes a tipo emergencia." << endl;
        std::cout << "3. Consultas de pacientes o listas emergencias." << endl;
        std::cout << "4. Reiniciar el programa." << endl;
        std::cout << "5. Salir del programa." << endl;
        std::cout << "---------------------------------------------------------------------" << endl;
        std::cin >> opcion;
        switch (opcion) {
            case 0:

                mostrar->altaPacientes(pilaPacientes, pilaPacientesTemp);
                break;
            case 1:
                if (pilaPacientes.esVacia()) {
                    cout << "La pila se encuentra vacia, debe reiniciar o salir del programa:" << endl;
                    break;
                }
                mostrar->bajaPacientes(pilaPacientes, pilaPacientesTemp);
                break;
            case 2:

                mostrar->reasignacionArbol();
                break;
            case 3:
                mostrar->menuOpcion3(pilaPacientes, pilaPacientesTemp);
                break;
            case 4:
                while (!pilaPacientes.esVacia()) {
                    pilaPacientes.mostrar(false);
                }
                pilaPacientes.push(paciente1);
                pilaPacientes.push(paciente2);
                pilaPacientes.push(paciente3);
                pilaPacientes.push(paciente4);
                pilaPacientes.push(paciente5);
                pilaPacientes.push(paciente6);
                pilaPacientes.push(paciente7);
                pilaPacientes.push(paciente8);
                pilaPacientes.push(paciente9);
                pilaPacientes.push(paciente10);
                mostrar->vaciarArbol();
                system("cls");
                std::cout << "Se ha reiniciado el programa." << endl;
                break;
            case 5:
                std::cout << "Saliendo del programa..." << endl;
                std::cout << "Gracias por usar nuestros servicios informáticos" << endl;
                break;
        }
    }
    return 0;
}