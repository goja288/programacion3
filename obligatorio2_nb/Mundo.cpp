/* 4309187 4666259 4201206 */
#include "Territorio.h"
#include "ListaEnteros.h"

#include <stdlib.h>

struct Nodo{
    Territorio* territorio;
    ListaEnteros* adyacentes;
};

struct Mundo{
    Nodo* nodos;
    int cantTerritorios;
};


bool sonVecinosMundo(Mundo* m, int IDterritorio1, int IDterritorio2);

//***** Constructores *****//

Mundo* crearMundo(int cantTerritorios){
    Mundo* res = new Mundo;
    res->nodos = new Nodo[cantTerritorios];
    
    for (int i=0; i< cantTerritorios; i++)
    {
        res->nodos[i].territorio = crearTerritorioVacio();
        res->nodos[i].adyacentes = crearListaEnteros();
    }
    res->cantTerritorios = cantTerritorios;
    return res;
};
// Crea un Mundo con cantTerritorios Territorios vacios.
// Reserva la memoria para la estructura mundo y los territorios.

void hacerVecinosTerritorios(Mundo* m, int IDterritorio1, int IDterritorio2){
    if (!sonVecinosMundo(m,IDterritorio1,IDterritorio2)) {
        agregarListaEnteros(m->nodos[IDterritorio1].adyacentes, IDterritorio2);
        agregarListaEnteros(m->nodos[IDterritorio2].adyacentes, IDterritorio1);
    }
};
// Conecta los dos territorios mediante caminos directos
// Precondicion: El mundo m fue creado


//***** Selectores *****//

Territorio* obtenerTerritorioMundo(Mundo* m, int IDterritorio){
    return (m->nodos[IDterritorio].territorio);
}
// Devuelve una referencia al Territorio con identificador IDterritorio en el Mundo m.
// Precondicion: El mundo m fue creado
// Precondicion: 0 <= IDterritorio < cantTerritoriosMundo(m)

int cantTerritoriosMundo(Mundo* m){
    return (m->cantTerritorios);
}
// Devuelve la cantidad de territorios del mundo m
// Precondicion: El mundo m fue creado

ListaEnteros* obtenerVecinosTerritorioMundo(Mundo* m, int IDterritorio){
    return (m->nodos[IDterritorio].adyacentes);
}
// Devuelve una lista ordenada con los identificadores de
// los territorios vecinos del territorio IDterritorio.
// Precondici�n: 0 <= IDterritorio < cantTerrenosTerritorio(m)
// Precondicion: El mundo m fue creado

//***** Predicados *****//

bool sonVecinosMundo(Mundo* m, int IDterritorio1, int IDterritorio2){
    ListaEnteros* lista = m->nodos[IDterritorio1].adyacentes;
    while (!esVaciaListaEnteros(lista) && (IDterritorio2 !=primeroListaEnteros(lista))) {
        lista = restoListaEnteros(lista);
    }
    return (!esVaciaListaEnteros(lista));
}
// Devuelve true si los terrenos IDterritorio1 e IDterritorio2 estan directamente conectados.
// Precondicion: 0 <= IDterritorio1 < cantTerritoriosMundo(m)
// Precondicion: 0 <= IDterritorio2 < cantTerritoriosMundo(m)
// Precondicion: El mundo m fue creado

int cantVecinosTerritorioMundo(Mundo* m, int IDterritorio){
    int contador = 0;
    ListaEnteros* lista = m->nodos[IDterritorio].adyacentes;
    while (! esVaciaListaEnteros(lista)){
        lista = restoListaEnteros(lista);
        contador++;
    }
    return contador;
}
// Devuelve la cantidad de vecinos del territorio IDterritorio.
// Precondici�n: 0 <= IDterritorio < cantTerrenosTerritorio(m)
// Precondicion: El mundo m fue creado

//***** Destructores *****//

void destruirMundo(Mundo* m){
    int cantTerritorios = m->cantTerritorios;
    for (int i=0; i< cantTerritorios; i++)
    {
        destruirTerritorio(m->nodos[i].territorio);
        destruirListaEnteros(m->nodos[i].adyacentes);
    }
    delete [] m->nodos;
	delete m;
    m = NULL;
}
// Libera la memoria del Mundo m y la memoria asociada a los Territorios
// Precondicion: El mundo m fue creado
