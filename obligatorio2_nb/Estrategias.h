#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#define NO_HAY_TERRITORIO_MEDIADOR -1

#include "Mundo.h"

//Estructura para almacenar un camino
struct Camino
{
	//largo de la secuencia de territorios del camino
	int largo;
	
	//arreglo que contiene la secuencia de los identificadores 
	//de los territorios por los que pasa el camino
	int* territorios;
	
	//territorios[0] es el origen del camino, territorios[largo-1] es el destino del camino
	//si largo = 0 entonces no hay camino
};

Camino* caminoMasCorto(Mundo* m, int idTerritorio1, int idTerritorio2, const char* comunidadhostil);
// Devuelve el camino mas corto entre el territorio idTerritorio1 y el territorio idTerritorio2,
// sin pasar por aquellos territorios con habitantes de la comunidad comunidadhostil.
// En caso que no exista un camino que cumpla la condicion, retorna un camino cuyo largo es 0 
// y territorios es NULL.
// Precondicion: 0 <= idTerritorio1 < cantTerritoriosMundo(m);
// Precondicion: 0 <= idTerritorio2 < cantTerritoriosMundo(m);
// Precondicion: El mundo m ya fue creado.

int territorioDelMediador(Mundo* m, const char* comunidad1, const char* comunidad2);
// Devuelve el identificador de un territorio tal que no haya forma de llegar de un territorio donde
// habita comunidad1 hasta un territorio donde habita comunidad2, sin pasar por el territorio del mediador.
// En caso que no exista territorio que cumpla la condicion, retorna el valor NO_HAY_TERRITORIO_MEDIADOR.
// Precondicion: comunidad1 != NULL y comunidad2 != NULL
// Precondicion: comunidad1 y comunidad2 son diferentes
// Precondicion: El mundo m ya fue creado.


Mundo* proyectoDePavimentacion(Mundo* m);
// Devuelve un mundo con todos los territorios del mundo m, representando solamente las calles pavimentadas
// Precondicion: El mundo m ya fue creado.

#endif /* ESTRATEGIAS_H */

