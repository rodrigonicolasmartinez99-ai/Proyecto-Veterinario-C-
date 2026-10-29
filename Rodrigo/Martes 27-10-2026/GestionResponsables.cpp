#include <iostream>
#include <limits>
#include <string>
#include <ctime>
#include "GestionResponsables.h"
#include "ArchivoPersonas.h"
#include "Validaciones.h"

using namespace std;

//metodo de la clase

void GestionResponsables::registrarResponsable() {
    ArchivoPersonas archivo;
    Validaciones validaciones;

 /// INGRESO DEL DNI

string dni;

int posicion = -1;

do {
    cout << "Ingrese DNI sin puntos: ";

    if (!getline(cin, dni)) {
        return;
    }

if (dni.empty() ||
    dni.size() > 14 ||
    dni.find_first_not_of("0123456789") != string::npos) {

        cout << "DNI invalido: Ingrese los entre 1 y 14 sin puntos." << endl;

        // Mantiene el ciclo activo para pedir otro DNI.
        posicion = 0;
        continue;
    }

    posicion = archivo.buscarPorDni(dni.c_str());

    if (posicion != -1) {
        Persona persona = archivo.leer(posicion);

        cout << "El DNI ya esta registrado a nombre de: "
             << persona.getNombre() << " "
             << persona.getApellido() << endl;

        if (!persona.getActivo()) {
            cout << "Su registro esta dado de baja." << endl;
        }

        cout << "Ingrese otro DNI." << endl;
    }

} while (posicion != -1);

/// INGRESO DEL NOMBRE

string nombre;

do {
    cout << "Ingrese nombre: ";

    if (!getline(cin, nombre)) {
        return;
    }

    if (!validaciones.nombreValido(nombre, 29)) {
        cout << "Nombre invalido. Ingrese hasta 29 caracteres "
             << "y no lo deje vacio." << endl;
    }

} while (!validaciones.nombreValido(nombre, 29));

/// INGRESO DEL APELLIDO

string apellido;

do {
    cout << "Ingrese apellido: ";

    if (!getline(cin, apellido)) {
        return;
    }

    if (!validaciones.nombreValido(apellido, 29)) {
        cout << "Apellido invalido. Ingrese hasta 29 caracteres, "
             << "sin numeros y sin dejarlo vacio." << endl;
    }

} while (!validaciones.nombreValido(apellido, 29));

/// INGRESO DE LA FECHA DE NACIMIENTO

int dia, mes, anio;
Fecha nacimiento;
bool fechaCorrecta = false;
string fechaTexto;

time_t ahora = time(nullptr);
tm* actual = localtime(&ahora);

if (actual == nullptr) {
    cout << "No se pudo obtener la fecha actual." << endl;
    return;
}

int anioActual = actual->tm_year + 1900;
int mesActual = actual->tm_mon + 1;
int diaActual = actual->tm_mday;

do {
    cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";

    if (!getline(cin, fechaTexto)) {
        return;
    }

    // Comprobamos la longitud y la posicion de las barras.
    if (fechaTexto.size() != 10 ||
        fechaTexto[2] != '/' ||
        fechaTexto[5] != '/') {

        cout << "Formato invalido. Debe ingresar 2 digitos para el dia, 2 para el mes y 4 para el año. Ejemplo: 01/03/1999." << endl;
        continue;
    }

    // Comprobamos que las demas posiciones sean digitos.
    bool soloDigitos = true;

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {
            if (fechaTexto[i] < '0' || fechaTexto[i] > '9') {
                soloDigitos = false;
            }
        }
    }

    if (!soloDigitos) {
        cout << "El dia, mes y anio deben contener numeros.Debe ingresar 2 digitos para el dia, 2 para el mes y 4 para el año. Ejemplo: 01/03/1999." << endl;
        continue;
    }

    // Convertimos cada parte del texto a un numero.
    dia = stoi(fechaTexto.substr(0, 2));
    mes = stoi(fechaTexto.substr(3, 2));
    anio = stoi(fechaTexto.substr(6, 4));

    Fecha ingresada(dia, mes, anio);

    if (!ingresada.esValida()) {
        cout << "La fecha ingresada no existe." << endl;
        continue;
    }

    bool esFutura =
        anio > anioActual ||
        (anio == anioActual && mes > mesActual) ||
        (anio == anioActual && mes == mesActual && dia > diaActual);

    if (esFutura) {
        cout << "La fecha de nacimiento no puede ser futura." << endl;
        continue;
    }

    nacimiento = ingresada;
    fechaCorrecta = true;

} while (!fechaCorrecta);

/// INGRESO DEL TELEFONO

string telefono;

do {
    cout << "Ingrese telefono sin espacios ni guiones: ";

    if (!getline(cin, telefono)) {
        return;
    }

    if (!validaciones.soloDigitos(telefono, 19)) {
        cout << "Telefono invalido. Ingrese entre 1 y 19 digitos."
             << endl;
    }

} while (!validaciones.soloDigitos(telefono, 19));

/// INGRESO DEL MAIL

string mail;

do {
    cout << "Ingrese correo electronico: ";

    if (!getline(cin, mail)) {
        return;
    }

    if (!validaciones.correoValido(mail)) {
        cout << "Correo invalido. Debe contener una sola @, "
             << "texto a ambos lados y no tener espacios."
             << endl;
    }

} while (!validaciones.correoValido(mail));

/// INGRESO DEL DOMICILIO

string domicilio;


do {
    cout << "Ingrese domicilio: ";

    if (!getline(cin, domicilio)) {
        return;
    }

    if (!validaciones.textoValido(domicilio, 59)) {
        cout << "Domicilio invalido. Ingrese hasta 59 caracteres "
             << "y no lo deje vacio." << endl;
    }

} while (!validaciones.textoValido(domicilio, 59));

/// INGRESO DE LA LOCALIDAD

string localidad;

do {
    cout << "Ingrese localidad: ";

    if (!getline(cin, localidad)) {
        return;
    }

    if (!validaciones.textoValido(localidad, 39)) {
        cout << "Localidad invalida. Ingrese hasta 39 caracteres "
             << "y no la deje vacia." << endl;
    }

} while (!validaciones.textoValido(localidad, 39));


int cantidad = archivo.contarRegistros();

if (cantidad < 0) {
    cout << "No se pudo consultar el archivo." << endl;
    return;
}

int mayorId = 0;

for (int i = 0; i < cantidad; i++) {
    Persona registrada = archivo.leer(i);

    if (registrada.getIdPersona() == 0) {
        cout << "No se pudo leer un registro." << endl;
        return;
    }

    if (registrada.getIdPersona() > mayorId) {
        mayorId = registrada.getIdPersona();
    }
}

Persona nueva;

nueva.setIdPersona(mayorId + 1);
nueva.setDomicilio(domicilio.c_str());
nueva.setLocalidad(localidad.c_str());
nueva.setMail(mail.c_str());
nueva.setTelefono(telefono.c_str());
nueva.setFechaNacimiento(nacimiento);
nueva.setDni(dni.c_str());
nueva.setNombre(nombre.c_str());
nueva.setApellido(apellido.c_str());

if (archivo.guardar(nueva)) {
    cout << "Responsable guardado correctamente." << endl;
    cout << "ID asignado: " << nueva.getIdPersona() << endl;
} else {
    cout << "No se pudo guardar el responsable." << endl;
}
}
