#include "Fecha.h"

// Constructor sin parametros.
Fecha::Fecha() {
    _dia = 1;
    _mes = 1;
    _anio = 2000;
}

// Constructor con parametros.
Fecha::Fecha(int dia, int mes, int anio) {
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

// Getters.
int Fecha::getDia() const {
    return _dia;
}

int Fecha::getMes() const {
    return _mes;
}

int Fecha::getAnio() const {
    return _anio;
}

// Setters.
void Fecha::setDia(int dia) {
    _dia = dia;
}

void Fecha::setMes(int mes) {
    _mes = mes;
}

void Fecha::setAnio(int anio) {
    _anio = anio;
}

// Comprueba si la fecha existe.
bool Fecha::esValida() const {
    if (_anio < 1 || _mes < 1 || _mes > 12) {
        return false;
    }

    int diasDelMes[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool esBisiesto = (_anio % 400 == 0) ||
                      (_anio % 4 == 0 && _anio % 100 != 0);

    if (esBisiesto) {
        diasDelMes[1] = 29;
    }

    return _dia >= 1 && _dia <= diasDelMes[_mes - 1];
}
