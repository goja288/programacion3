#ifndef MUNDO_H
#define MUNDO_H

#include "Territorio.h"
#include "ListaEnteros.h"

struct Mundo;

//***** Constructores *****//

Mundo* crearMundo(int cantTerritorios);
// Crea un Mundo con cantTerritorios Territorios vacios.
// Reserva la memoria para la estructura mundo y los territorios.

void hacerVecinosTerritorios(Mundo* m, int IDterritorio1, int IDterritorio2);
// Conecta los dos territorios mediante caminos directos
// Precondicion: El mundo m fue creado


//***** Selectores *****//

Territorio* obtenerTerritorioMundo(Mundo* m, int IDterritorio);
// Devuelve una referencia al Territorio con identificador IDterritorio en el Mundo m.
// Precondicion: El mundo m fue creado
// Precondicion: 0 <= IDterritorio < cantTerritoriosMundo(m)

int cantTerritoriosMundo(Mundo* m);
// Devuelve la cantidad de territorios del mundo m
// Precondicion: El mundo m fue creado

ListaEnteros* obtenerVecinosTerritorioMundo(Mundo* m, int IDterritorio);
// Devuelve una lista ordenada con los identificadores de 
// los territorios vecinos del territorio IDterritorio.
// Precondición: 0 <= IDterritorio < cantTerrenosTerritorio(m)
// Precondicion: El mundo m fue creado

//***** Predicados *****//

bool sonVecinosMundo(Mundo* m, int IDterritorio1, int IDterritorio2);
// Devuelve true si los terrenos IDterritorio1 e IDterritorio2 estan directamente conectados.
// Precondicion: 0 <= IDterritorio1 < cantTerritoriosMundo(m)
// Precondicion: 0 <= IDterritorio2 < cantTerritoriosMundo(m)
// Precondicion: El mundo m fue creado

int cantVecinosTerritorioMundo(Mundo* m, int IDterritorio);
// Devuelve la cantidad de vecinos del territorio IDterritorio.
// Precondición: 0 <= IDterritorio < cantTerrenosTerritorio(m)
// Precondicion: El mundo m fue creado

//***** Destructores *****//

void destruirMundo(Mundo* m);
// Libera la memoria del Mundo m y la memoria asociada a los Territorios
// Precondicion: El mundo m fue creado

#endif /* MUNDO_H */