#pragma once

#include <string>
#include <vector>

enum Estado {
    Iniciar,
    Respuesta,
    Finalizar,
    Cierre
};

class StateMachine
{
    public:
    void imprimirEstado();
    void nuevoMensaje(std::string mensaje);

    private:
    Estado _estado = Iniciar;
    std::string _iniciar;
    std::vector<std::string> _respuestas = {};
    int fin = 0;

    void oniniciar(std::string mensaje);
    void onRespuesta(std::string mensaje);
    void onFinalizar(std::string mensaje);
    void onCierre(std::string mensaje);
};