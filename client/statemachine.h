#pragma once

#include <string>
#include <vector>

class StateMachine
{
    public:
    void nuevoMensaje(std::string mensaje);

    private:
    std::vector<std::string> _respuestas = {};

    void Almacenar(std::string mensaje);
    void Recuperar(std::string mensaje);
    void Buscar(std::string mensaje);
};