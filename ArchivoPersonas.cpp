#include "ArchivoPersonas.h"
#include <cstdio>
#include <cstring>

ArchivoPersonas::ArchivoPersonas() {
    std::strcpy(_nombreArchivo, "Personas.dat");
}

// Agrega una persona al final del archivo.
bool ArchivoPersonas::guardar(Persona registro) {
    FILE* archivo = std::fopen(_nombreArchivo, "ab");

    if (archivo == nullptr) {
        return false;
    }

    bool guardado = std::fwrite(
        &registro, sizeof(Persona), 1, archivo
    ) == 1;

    std::fclose(archivo);
    return guardado;
}

// Lee un registro por su posicion, comenzando en 0.
Persona ArchivoPersonas::leer(int posicion) {
    Persona registro;
    registro.setActivo(false);

    if (posicion < 0) {
        return registro;
    }

    FILE* archivo = std::fopen(_nombreArchivo, "rb");

    if (archivo == nullptr) {
        return registro;
    }

    long desplazamiento =
        static_cast<long>(posicion) *
        static_cast<long>(sizeof(Persona));

    if (std::fseek(archivo, desplazamiento, SEEK_SET) != 0) {
        std::fclose(archivo);
        return registro;
    }

    bool leido = std::fread(
        &registro, sizeof(Persona), 1, archivo
    ) == 1;

    std::fclose(archivo);

    if (!leido) {
        Persona vacia;
        vacia.setActivo(false);
        return vacia;
    }

    return registro;
}

// Reemplaza un registro existente.
bool ArchivoPersonas::modificar(Persona registro, int posicion) {
    int cantidad = contarRegistros();

    if (posicion < 0 || posicion >= cantidad) {
        return false;
    }

    FILE* archivo = std::fopen(_nombreArchivo, "rb+");

    if (archivo == nullptr) {
        return false;
    }

    long desplazamiento =
        static_cast<long>(posicion) *
        static_cast<long>(sizeof(Persona));

    if (std::fseek(archivo, desplazamiento, SEEK_SET) != 0) {
        std::fclose(archivo);
        return false;
    }

    bool modificado = std::fwrite(
        &registro, sizeof(Persona), 1, archivo
    ) == 1;

    std::fclose(archivo);
    return modificado;
}

// Incluye registros activos e inactivos.
int ArchivoPersonas::contarRegistros() {
    FILE* archivo = std::fopen(_nombreArchivo, "rb");

    if (archivo == nullptr) {
        return 0;
    }

    if (std::fseek(archivo, 0, SEEK_END) != 0) {
        std::fclose(archivo);
        return -1;
    }

    long tamanio = std::ftell(archivo);
    std::fclose(archivo);

    if (tamanio < 0) {
        return -1;
    }

    return static_cast<int>(
        tamanio / static_cast<long>(sizeof(Persona))
    );
}

int ArchivoPersonas::buscarPorId(int idPersona) {
    FILE* archivo = std::fopen(_nombreArchivo, "rb");

    if (archivo == nullptr) {
        return -1;
    }

    Persona registro;
    int posicion = 0;

    while (std::fread(&registro, sizeof(Persona), 1, archivo) == 1) {
        if (registro.getIdPersona() == idPersona) {
            std::fclose(archivo);
            return posicion;
        }

        posicion++;
    }

    std::fclose(archivo);
    return -1;
}

int ArchivoPersonas::buscarPorDni(const char* dni) {
    if (dni == nullptr) {
        return -1;
    }

    FILE* archivo = std::fopen(_nombreArchivo, "rb");

    if (archivo == nullptr) {
        return -1;
    }

    Persona registro;
    int posicion = 0;

    while (std::fread(&registro, sizeof(Persona), 1, archivo) == 1) {
        if (std::strcmp(registro.getDni(), dni) == 0) {
            std::fclose(archivo);
            return posicion;
        }

        posicion++;
    }

    std::fclose(archivo);
    return -1;
}
