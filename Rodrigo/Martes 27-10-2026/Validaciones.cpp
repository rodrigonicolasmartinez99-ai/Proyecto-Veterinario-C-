#include "Validaciones.h"

bool Validaciones::textoValido(const std::string& texto, int maximo) {
    if (maximo < 1) {
        return false;
    }

    if (texto.find_first_not_of(" \t") == std::string::npos) {
        return false;
    }
    /*
    find_first_not_of(" \t") busca un carácter que no sea espacio ni tabulación.
    npos indica que no encontró ninguno.
    */
    if (texto.size() > static_cast<std::string::size_type>(maximo)) {
        return false;
    }
    /*
    static_cast convierte maximo al tipo que devuelve texto.size(),
    para poder comparar ambos valores.
    */
    return true;
}
bool Validaciones::nombreValido(const std::string& texto, int maximo) {
    if (!textoValido(texto, maximo)) {
        return false;
    }

    for (char caracter : texto) {
        if ((caracter >= '0' && caracter <= '9')) {
            return false;
        }
    }

    return true;
}

bool Validaciones::soloDigitos(const std::string& texto, int maximo) {
    if (!textoValido(texto, maximo)) {
        return false;
    }

    for (char caracter : texto) {
        if (caracter < '0' || caracter > '9') {
            return false;
        }
    }

    return true;
}

bool Validaciones::correoValido(const std::string& correo) {
    if (!textoValido(correo, 49)) {
        return false;
    }

    std::string::size_type arroba = correo.find('@');

    if (arroba == std::string::npos ||
        arroba == 0 ||
        arroba == correo.size() - 1) {
        return false;
    }

    if (correo.find('@', arroba + 1) != std::string::npos) {
        return false;
    }

    if (correo.find_first_of(" \t\r\n") != std::string::npos) {
        return false;
    }

    return true;
}
