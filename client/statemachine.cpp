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

void StateMachine::onIniciar(std::string mensaje) {

    size_t pos = mensaje.find("Emitir pregunta:");
    size_t signo = mensaje.find("?");
    int tamano = (pos - signo);
    size_t n = mensaje.size();

    if(pos == 0) {
        int interro = 0;
        for (int i=1;  i<n ; i++) {
            if (mensaje[i] == '?') {
            interro++;}    
            } 
        if (interro == 1) {
        _estado = Respuesta;
        _iniciar = mensaje.substr(7, tamano);
        }
    }
}

void StateMachine::onRespuesta(std::string mensaje) {

    size_t pos = mensaje.find("Responder pregunta:");
    size_t pos2 =mensaje.find("Finalizar");

    if(pos == 0) {
        _estado = Respuesta;
        _respuestas.push_back(mensaje.substr(19));
    }
    else if (pos2 ==0) {
    _estado = Cierre;
    }
    else {
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
            onIniciar(mensaje);
            break;
        case Respuesta:
            onRespuesta(mensaje);
            break;
        case Cierre:
            onCierre(mensaje);
            break;
        default:
            std::cout << "Error, mal programadodr \n\n";
    }
}