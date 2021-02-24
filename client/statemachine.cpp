#include "statemachine.h"
#include <iostream>

void StateMachine::imprimirEstado() {



    std::cout << "El estado es" << _estado << "\n\n" ;
} 

void StateMachine::nuevoMensaje(std::string mensaje) {


    switch(_estado) {

        case Nombre:
            _estado = Edad;
            break;
        case Edad:
            _estado = Color;
            break;
        case Color:
            _estado = Nombre;
            break;
        default:
        std::cout << "Error, mal programador \n\n";
    }
            
}