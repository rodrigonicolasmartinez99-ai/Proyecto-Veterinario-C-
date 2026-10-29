#include <iostream>
#include <limits>
#include <cstdlib>
#include "MenuResponsables.h"
#include "GestionResponsables.h"

using namespace std;
//Significa queestamos implementando el metodo mostrar que pertenece a la clase MenuResponsable

//sub menu, se ejecuta cuando cargamos el Mun principal
void MenuResponsables::mostrar() {
    GestionResponsables gestion;
    int opcion = -1;

do {

system("cls");

cout<<"Gestionar Responsables"<<endl;
cout << "1. Registrar responsable" << endl;
cout << "2. Consultar responsable" << endl;
cout << "3. Modificar responsable" << endl;
cout << "4. Dar de baja" << endl;
cout << "5. Listar responsables" << endl;
cout << "0. Salir" << endl;
cout << "Seleccione una opcion: ";

//validar opcion
if(!(cin>>opcion)){
        //cin.eof() detecta si terminó la entrada de datos
    if(cin.eof()){
        return;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    opcion = -1;
    cout<<"Debe ingresar un numero." <<endl;
    continue;
}
cin.ignore(numeric_limits<streamsize>::max(),'\n');
switch(opcion){
case 1:
    system("cls");
    gestion.registrarResponsable();

    cout << "\nPresione Enter para volver al menu...";
    cin.get();

    break;
case 0:
    cout<<"Saliendo del menu. "<<endl;
    break;
default:
    cout<<"Opcion no disponible. "<<endl;
    break;
    }
} while(opcion !=0);

}
