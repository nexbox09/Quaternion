#include "statemachine.h"
#include <iostream>
#include <vector>

void StateMachine::imprimirEstado() {
    std::cout << "Estado: " << _estado << "\n";
    if (_estado == Cierre) {
    std::cout << _iniciar << "\n";
   int numerorespuestas = 1;
    for (std::string str: _respuestas) {
        std::cout << "Respuesta #" << numerorespuestas << ": " <<str << "\n";
        numerorespuestas++;    
    }
    std::cout << "Pregunta finalizada \n"; 
    }
}

void StateMachine::oniniciar(std::string mensaje) {

    size_t pos = mensaje.find("Emitir pregunta:");
    size_t signo = mensaje.find("?");
    int tamano = (pos - signo);

    if(pos == 0) {
        _estado = Respuesta;
        _iniciar = mensaje.substr(7, tamano);
    }
}

void StateMachine::onRespuesta(std::string mensaje) {

    size_t pos = mensaje.find("Responder pregunta:");

    if(pos == 0) {
        _estado = Respuesta;
        _respuestas.push_back(mensaje.substr(19));
    }
    else {
    _estado = Finalizar;
    }
}

 void StateMachine::onFinalizar(std::string mensaje) {

    size_t pos = mensaje.find("Finalizar pregunta");

    if(pos == 0) {
        _estado = Cierre ;
    }

} 

 void StateMachine::onCierre(std::string mensaje) {

     size_t pos = mensaje.find("Reiniciar");
    if(pos == 0) {
        _estado = Iniciar ;
    }
    else {
        _estado = Cierre;

 }
 }

  void StateMachine::nuevoMensaje(std::string mensaje) {

    switch(_estado) {

        case Iniciar:
            oniniciar(mensaje);
            break;
        case Respuesta:
            onRespuesta(mensaje);
            break;
        case Finalizar:
            onFinalizar(mensaje);
            break;
        case Cierre:
            onCierre(mensaje);
            break;
        default:
            std::cout << "Error, mal programadodr \n\n";
    }
}