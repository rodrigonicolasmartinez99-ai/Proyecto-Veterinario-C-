#include "Persona.h"
#include <cstring>

// Constructor.
Persona::Persona() {
    _idPersona = 0;

    std::memset(_dni, 0, sizeof(_dni));
    std::memset(_nombre, 0, sizeof(_nombre));
    std::memset(_apellido, 0, sizeof(_apellido));
    std::memset(_telefono, 0, sizeof(_telefono));
    std::memset(_mail, 0, sizeof(_mail));
    std::memset(_domicilio, 0, sizeof(_domicilio));
    std::memset(_localidad, 0, sizeof(_localidad));

    // _fechaNacimiento utiliza el constructor de Fecha.
    _activo = true;
}

// Getters.
int Persona::getIdPersona() const {
    return _idPersona;
}

const char* Persona::getDni() const {
    return _dni;
}

const char* Persona::getNombre() const {
    return _nombre;
}

const char* Persona::getApellido() const {
    return _apellido;
}

Fecha Persona::getFechaNacimiento() const {
    return _fechaNacimiento;
}

const char* Persona::getTelefono() const {
    return _telefono;
}

const char* Persona::getMail() const {
    return _mail;
}

const char* Persona::getDomicilio() const {
    return _domicilio;
}

const char* Persona::getLocalidad() const {
    return _localidad;
}

bool Persona::getActivo() const {
    return _activo;
}

// Setters.
void Persona::setIdPersona(int valor) {
    _idPersona = valor;
}

void Persona::setDni(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_dni)) {
        return;
    }

    std::strcpy(_dni, valor);
}

void Persona::setNombre(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_nombre)) {
        return;
    }

    std::strcpy(_nombre, valor);
}

void Persona::setApellido(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_apellido)) {
        return;
    }

    std::strcpy(_apellido, valor);
}

void Persona::setFechaNacimiento(Fecha valor) {
    if (valor.esValida()) {
        _fechaNacimiento = valor;
    }
}

void Persona::setTelefono(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_telefono)) {
        return;
    }

    std::strcpy(_telefono, valor);
}

void Persona::setMail(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_mail)) {
        return;
    }

    std::strcpy(_mail, valor);
}

void Persona::setDomicilio(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_domicilio)) {
        return;
    }

    std::strcpy(_domicilio, valor);
}

void Persona::setLocalidad(const char* valor) {
    if (valor == nullptr ||
        std::strlen(valor) >= sizeof(_localidad)) {
        return;
    }

    std::strcpy(_localidad, valor);
}

void Persona::setActivo(bool valor) {
    _activo = valor;
}
