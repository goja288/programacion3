#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mundo.h"
#include "Territorio.h"
#include "ListaEnteros.h"

using namespace std;

int main()
{
    cout << endl << endl << "Vamos a arrancar las pruebas !!!" << endl << endl;

    Territorio* terr = crearTerritorioVacio();
    asignarNombreTerritorio(terr, "Uruguay");
    asignarComunidadTerritorio(terr, "uruguayos");

    cout << "El nombre del territorio es: " << obtenerNombreTerritorio(terr) << endl << endl;
    cout << "El nombre de la comunidad es: " << obtenerComunidadTerritorio(terr) << endl << endl;

    return 0;
}
