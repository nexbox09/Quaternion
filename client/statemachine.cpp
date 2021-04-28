#include "statemachine.h"
#include <iostream>
#include <vector>

void StateMachine::nuevoMensaje(std::string mensaje) {

    size_t pos = mensaje.find("Almacenar");
    size_t pos2 =mensaje.find("Recuperar");
    size_t pos3 =mensaje.find("Buscar");

    if(pos == 0){
        Almacenar(mensaje);
    }
    if(pos2 == 0){
        Recuperar(mensaje);
    }
    if(pos3 == 0){
        Buscar(mensaje);
    }

}

void StateMachine::Almacenar(std::string mensaje) {


std::string texto = mensaje.substr(11);
size_t n = texto.size();
int espacios;

    for (int i=1;  i<n ; i++) {
        if(texto[i] != ','){
            
        espacios++
            }
        }

std::string indice = mensaje.substr(11,espacios);
std::string valor = mensaje.substr((espacios+1));


}

void StateMachine::Recuperar(std::string mensaje) {

}

void StateMachine::Buscar(std::string mensaje) {

}
