#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

class Validaciones {
public:
    bool textoValido(const std::string& texto, int maximo);
    bool nombreValido(const std::string& texto, int maximo);
    bool soloDigitos(const std::string& texto, int maximo);
    bool correoValido(const std::string& correo);
};

#endif
