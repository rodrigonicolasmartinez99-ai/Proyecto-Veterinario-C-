#include <iostream>
#include "FuncionesGlobales.h"
#include <limits>
#include <string>
#include "ArchivoPersonas.h"
#include <ctime>

using namespace std;

// Implementacion de la funcion.
void menuResponsables() {
    int opcion = -1;

    do {
        cout << "\nGESTIONAR RESPONSABLES" << endl;
        cout << "1. Registrar responsable" << endl;
        cout << "2. Consultar responsable" << endl;
        cout << "3. Modificar responsable" << endl;
        cout << "4. Dar de baja" << endl;
        cout << "5. Listar responsables" << endl;
        cout << "0. Salir" << endl;

        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            opcion = -1;
            cout << "Debe ingresar un numero." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1:
            registrarResponsable();
            break;

        case 0:
            cout << "Saliendo del menu." << endl;
            break;

        default:
            cout << "Opcion no disponible por el momento." << endl;
            break;
        }

    } while (opcion != 0);
}

void registrarResponsable() {
    ArchivoPersonas archivo;
    string dni;

    cout << "Ingrese DNI sin puntos: ";
    getline(cin, dni);

    if (dni.empty() ||
        dni.size() > 14 ||
        dni.find_first_not_of("0123456789") != string::npos) {

        cout << "DNI invalido: use entre 1 y 14 digitos." << endl;
        return;
    }

    int posicion = archivo.buscarPorDni(dni.c_str());

    if (posicion != -1) {
        Persona persona = archivo.leer(posicion);

        cout << "La persona ya esta registrada: "
             << persona.getNombre() << " "
             << persona.getApellido() << endl;

        if (!persona.getActivo()) {
            cout << "Su registro esta dado de baja." << endl;
        }

        return;
    }

    string nombre;
string apellido;

cout << "Ingrese nombre: ";
getline(cin, nombre);

cout << "Ingrese apellido: ";
getline(cin, apellido);

if (nombre.find_first_not_of(" \t") == string::npos ||
    apellido.find_first_not_of(" \t") == string::npos) {

    cout << "El nombre y apellido son obligatorios." << endl;
    return;
}

if (nombre.size() > 29 || apellido.size() > 29) {
    cout << "Nombre y apellido admiten hasta 29 caracteres cada uno."
         << endl;
    return;
}

 int dia, mes, anio;

cout << "Ingrese fecha de nacimiento (dia mes anio): ";

if (!(cin >> dia >> mes >> anio)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Debe ingresar tres numeros." << endl;
    return;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');

Fecha nacimiento(dia, mes, anio);

if (!nacimiento.esValida()) {
    cout << "La fecha ingresada no existe." << endl;
    return;
}

time_t ahora = time(nullptr);
tm* actual = localtime(&ahora);

if (actual == nullptr) {
    cout << "No se pudo obtener la fecha actual." << endl;
    return;
}

int anioActual = actual->tm_year + 1900;
int mesActual = actual->tm_mon + 1;
int diaActual = actual->tm_mday;

bool esFutura =
    anio > anioActual ||
    (anio == anioActual && mes > mesActual) ||
    (anio == anioActual && mes == mesActual && dia > diaActual);

if (esFutura) {
    cout << "La fecha de nacimiento no puede ser futura." << endl;
    return;
}

string telefono;

cout << "Ingrese telefono sin espacios ni guiones: ";
getline(cin, telefono);

if (telefono.empty() ||
    telefono.size() > 19 ||
    telefono.find_first_not_of("0123456789") != string::npos) {

    cout << "Telefono invalido: use entre 1 y 19 digitos." << endl;
    return;
}
string mail;

cout << "Ingrese correo electronico: ";
getline(cin, mail);

size_t arroba = mail.find('@');

if (mail.empty() ||
    mail.size() > 49 ||
    arroba == string::npos ||
    arroba == 0 ||
    arroba == mail.size() - 1 ||
    mail.find('@', arroba + 1) != string::npos ||
    mail.find_first_of(" \t") != string::npos) {

    cout << "Correo invalido: debe contener una sola @,"
         << " texto a ambos lados y no tener espacios." << endl;
    return;
}

string domicilio;
string localidad;

cout << "Ingrese domicilio: ";
getline(cin, domicilio);

if (domicilio.find_first_not_of(" \t") == string::npos ||
    domicilio.size() > 59) {

    cout << "Ingrese un domicilio de hasta 59 caracteres." << endl;
    return;
}

cout << "Ingrese localidad: ";
getline(cin, localidad);

if (localidad.find_first_not_of(" \t") == string::npos ||
    localidad.size() > 39) {

    cout << "Ingrese una localidad de hasta 39 caracteres." << endl;
    return;
}
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
