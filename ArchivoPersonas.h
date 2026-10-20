#ifndef ARCHIVOPERSONAS_H
#define ARCHIVOPERSONAS_H

#include "Persona.h"

class ArchivoPersonas {
private:
    char _nombreArchivo[100];

public:
    ArchivoPersonas();

    bool guardar(Persona registro);
    Persona leer(int posicion);
    bool modificar(Persona registro, int posicion);
    int contarRegistros();
    int buscarPorId(int idPersona);
    int buscarPorDni(const char* dni);
};

#endif
