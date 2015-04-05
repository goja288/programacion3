/* 4309187 4666259 4201206 */
#include "Estrategias.h"
#include "Mundo.h"
#include "Territorio.h"

#include "ColaEnteros.h"
#include "ListaEnteros.h"

#include <string.h>

/****************************************/
/** Declaracion de funciones auxiliares */
/****************************************/

void DFS_Visitar(Mundo* m,Mundo* &futuro,int id,int* &visitados);
void DFS_Vecinos_Componente (Mundo* m,Mundo* futuro,int id, 
               const char* comunidad1, const char* comunidad2,bool &perteneceC1, 
                                             bool &perteneceC2,int* &visitados);
bool esMediador (Mundo* m, Mundo* futuro, int id, const char* comunidad1, 
                                                        const char* comunidad2);

/*********************************************/
/** Fin declaracion de funciones auxiliares **/
/*********************************************/


/***********************************/
/** Implementacion de Estrategias **/
/***********************************/

Camino* caminoMasCorto(Mundo* m, int idTerritorio1, int idTerritorio2, 
                                                  const char* comunidadhostil) {     
    Camino *result      = new Camino;
    result->largo       = 0;
    result->territorios = NULL;
    int terrCount       = cantTerritoriosMundo(m);
    ColaEnteros *queue  = crearColaEnteros();
    bool goalFound      = false;
    bool *visited       = new bool[terrCount];
    int  *distance      = new int[terrCount];
    int  *ancestor      = new int[terrCount];
    for (int id = 0; id < terrCount; id++) {
    char *comunidad = obtenerComunidadTerritorio(obtenerTerritorioMundo(m, id));
    if (strcmp(comunidad, comunidadhostil) == 0) 
		visited[id] = true; 
    else 
		visited[id] = false;
	delete [] comunidad;
    }
    visited[idTerritorio1]  = true;
    distance[idTerritorio1] = 0;
    encolarColaEnteros(queue, idTerritorio1);
    while (!(esVaciaColaEnteros(queue) || goalFound)) {   
        int currentID          = desencolarColaEnteros(queue);
        ListaEnteros *adjIDs   = obtenerVecinosTerritorioMundo(m, currentID);
        while (!(esVaciaListaEnteros(adjIDs) || goalFound)) {         
            int adjID = primeroListaEnteros(adjIDs);
            adjIDs    = restoListaEnteros(adjIDs);
			if (!visited[adjID]) {     
				visited[adjID]  = true;
                distance[adjID] = distance[currentID] + 1;
                ancestor[adjID] = currentID;
                encolarColaEnteros(queue, adjID);
                if (adjID == idTerritorio2) {
					goalFound              = true;
                    int length             = distance[adjID];
                    result->largo          = length + 1;
                    result->territorios    = new int[length+1];
                    for (int step = length-1; step >= 0; step--) {
                        result->territorios[step] = ancestor[adjID];
                        adjID                     = ancestor[adjID];
                    }
					result->territorios[length] = idTerritorio2;
                }
            }
        }
    }
    delete [] visited;
    delete [] distance;
    delete [] ancestor;
	if(!esVaciaColaEnteros(queue))
		destruirColaEnteros (queue);
	//destruirColaEnteros (queue);
	return result;
}

int territorioDelMediador(Mundo* m, const char* comunidad1, 
                                                       const char* comunidad2) {
	int cantTerritorios = cantTerritoriosMundo(m);
	int* visitados = new int [cantTerritorios];
	bool es_mediador = false;
	int j = 0;
	do {
		Territorio* terr = obtenerTerritorioMundo(m, j);
		char* comunidadAux = obtenerComunidadTerritorio(terr);
		if ((strcmp (comunidadAux, comunidad1) != 0) 
                        && 
                    (strcmp (comunidadAux, comunidad2) != 0)){
                        Mundo* futuro = crearMundo(cantTerritorios);
			for (int i = 0; i < cantTerritorios; i++) {
				visitados[i] = 0;
			}
			DFS_Visitar(m, futuro, j, visitados);
			if (cantVecinosTerritorioMundo(futuro, j) > 1)
				es_mediador = esMediador (m, futuro, j, 
                                                        comunidad1, comunidad2);
			destruirMundo(futuro);
		}
		delete [] comunidadAux;
		j++;
	}
	while ((!es_mediador) && (j < cantTerritorios));
	delete [] visitados;
	if (es_mediador)
		return (j-1);
	else
		return NO_HAY_TERRITORIO_MEDIADOR;
} // fin territorioDelMediador

Mundo* proyectoDePavimentacion(Mundo* m) {

        int *visitados = new int[cantTerritoriosMundo(m)];
        Mundo* futuro = crearMundo(cantTerritoriosMundo(m));
        for (int i = 0; i < cantTerritoriosMundo(m); i++  ) {
                visitados[i] = 0;
                // copio los nombres y comunidades del mundo pasadado al futuro
                
				char* comunidadAux = obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i));
				char* nombreAux = obtenerNombreTerritorio(obtenerTerritorioMundo(m,i));
				asignarComunidadTerritorio(obtenerTerritorioMundo(futuro,i),
                       comunidadAux);
                asignarNombreTerritorio(obtenerTerritorioMundo(futuro,i),
                          nombreAux);
				delete [] comunidadAux;
				delete [] nombreAux;
        }
        DFS_Visitar(m,futuro,0,visitados);
		delete [] visitados;
        return futuro;

} // fin proyectoDePavimentacion

/***************************************/
/** Fin implementacion de Estrategias **/
/***************************************/


/********************************************/
/** Implementacion de funciones auxiliares **/
/********************************************/

/** funcion que devuelve un grafo de enteros en la varible futuro **/
void DFS_Visitar(Mundo* m,Mundo* &futuro,int id,int* &visitados) {
    
    visitados[id]=1;
    ListaEnteros* l_adyacentes =  obtenerVecinosTerritorioMundo(m,id);
    while(!esVaciaListaEnteros(l_adyacentes)) {
        int primero = primeroListaEnteros(l_adyacentes);
        if (!visitados[primero]) {
                hacerVecinosTerritorios(futuro,id,primero);
                DFS_Visitar(m,futuro,primero,visitados);
        }
        l_adyacentes = restoListaEnteros(l_adyacentes);
    }
} // fin DFS_Visitar

/** funcion que devuelve uno si las comunidades en conflicto comparten una 
 * componente **/
void DFS_Vecinos_Componente (Mundo* m,Mundo* futuro,int id, 
                             const char* comunidad1, const char* comunidad2, 
                             bool &perteneceC1, bool &perteneceC2, 
                                                              int* &visitados) {
	Territorio* terr = obtenerTerritorioMundo(m, id);
	char* comunidadAux = obtenerComunidadTerritorio(terr);
	if (strcmp (comunidadAux, comunidad1) == 0)
		perteneceC1 = true;
	if (strcmp (comunidadAux, comunidad2) == 0)
		perteneceC2 = true;
	visitados[id]=1;
	ListaEnteros* adyacentes =  obtenerVecinosTerritorioMundo(m,id);
	while (!esVaciaListaEnteros(adyacentes) && 
               !(perteneceC1 && perteneceC2)) {
		int primero = primeroListaEnteros(adyacentes);
		if (!visitados[primero])
			DFS_Vecinos_Componente (m, futuro, primero, comunidad1,
                               comunidad2, perteneceC1, perteneceC2, visitados);
		adyacentes = restoListaEnteros(adyacentes);
	}
	delete(comunidadAux);
} // fin DFS_vecinos_Componente

bool esMediador (Mundo* m, Mundo* futuro, int id, const char* comunidad1, 
                                                       const char* comunidad2) {
	int cantTerritorios = cantTerritoriosMundo(m);
	int* visitados = new int [cantTerritorios];
	bool vecinos_componente = false;
	ListaEnteros* adyacentes =  obtenerVecinosTerritorioMundo(futuro,id);
	while (!esVaciaListaEnteros(adyacentes) && (!vecinos_componente)) {
		int primero = primeroListaEnteros(adyacentes);
		for (int i = 0; i < cantTerritorios; i++) {
			visitados[i] = 0;
		}
		bool perteneceC1 = false;
		bool perteneceC2 = false;
		visitados[id] = 1;
		DFS_Vecinos_Componente (m, futuro, primero, comunidad1, 
                               comunidad2, perteneceC1, perteneceC2, visitados);
		vecinos_componente = (perteneceC1 && perteneceC2);
		adyacentes = restoListaEnteros(adyacentes);
	}
	delete [] visitados;
	return (!vecinos_componente);
} // fin esMediador

/************************************************/
/** fin implementacion de funciones auxiliares **/
/************************************************/
