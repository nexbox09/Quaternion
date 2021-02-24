#pragma once
#include <string>

enum Estado {
    Nombre,
    Edad,
    Color
};




class StateMachine
{
    public:
    void imprimirEstado();
    void nuevoMensaje(std::string mensaje);

    private:
    Estado _estado = Nombre;

};