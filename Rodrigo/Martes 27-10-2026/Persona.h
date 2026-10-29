#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"

class Persona {
private:
    int _idPersona;
    char _dni[15];
    char _nombre[30];
    char _apellido[30];
    Fecha _fechaNacimiento;
    char _telefono[20];
    char _mail[50];
    char _domicilio[60];
    char _localidad[40];
    bool _activo;

public:
    Persona();

    int getIdPersona() const;
    const char* getDni() const;
    const char* getNombre() const;
    const char* getApellido() const;
    Fecha getFechaNacimiento() const;
    const char* getTelefono() const;
    const char* getMail() const;
    const char* getDomicilio() const;
    const char* getLocalidad() const;
    bool getActivo() const;

    void setIdPersona(int valor);
    void setDni(const char* valor);
    void setNombre(const char* valor);
    void setApellido(const char* valor);
    void setFechaNacimiento(Fecha valor);
    void setTelefono(const char* valor);
    void setMail(const char* valor);
    void setDomicilio(const char* valor);
    void setLocalidad(const char* valor);
    void setActivo(bool valor);
};

#endif
