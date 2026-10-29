#include "Hora.h"

// Constructor sin parametros.
Hora::Hora() {
    _hora = 0;
    _minuto = 0;
}

// Constructor con parametros.
Hora::Hora(int hora, int minuto) {
    _hora = hora;
    _minuto = minuto;
}

// Getters.
int Hora::getHora() const {
    return _hora;
}

int Hora::getMinuto() const {
    return _minuto;
}

// Setters.
void Hora::setHora(int hora) {
    _hora = hora;
}

void Hora::setMinuto(int minuto) {
    _minuto = minuto;
}

// Comprueba si el horario es valido.
bool Hora::esValida() const {
    return _hora >= 0 && _hora <= 23 &&
           _minuto >= 0 && _minuto <= 59;
}
