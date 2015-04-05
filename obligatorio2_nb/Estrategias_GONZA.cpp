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
bool compartenComponente(Mundo* m,Mundo* componente,const char* comunidad1,
                                         const char* comunidad2,int* visitados);

int obtenerLargoCamino(Camino* camino);
int* obtenerTerritoriosCamino(Camino* camino);

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
        if (strcmp(obtenerComunidadTerritorio(obtenerTerritorioMundo(m, id)), 
                                                          comunidadhostil) == 0) 
            visited[id] = true; 
        else 
            visited[id] = false;
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
                    result->territorios    = new int[length];
                    result->territorios[0] = idTerritorio2;
                    for (int step = 1; step < length; step++) {
                        result->territorios[step] = ancestor[adjID];
                        adjID                     = ancestor[adjID];
                    }
                    result->territorios[length] = idTerritorio1;
                }
            }
        }
    }
    delete(visited);
    delete(distance);
    delete(ancestor);
    return result;
}

int territorioDelMediador(Mundo* m, const char* comunidad1, 
                                                       const char* comunidad2) {

    int mediador = NO_HAY_TERRITORIO_MEDIADOR;
    int idTerritorio = 0;

    while (idTerritorio < cantTerritoriosMundo(m) 
            && 
           (mediador == NO_HAY_TERRITORIO_MEDIADOR)) {
        
        // Lo descarto si tiene un solo vecino ya que no es punto de 
        // articulacion y tambien si no es neutral
        if ((cantVecinosTerritorioMundo(m,idTerritorio) > 1) 
                &&
            (strcmp(obtenerComunidadTerritorio(
                      obtenerTerritorioMundo(m,idTerritorio)),comunidad1)!=0)
                &&       
            (strcmp(obtenerComunidadTerritorio(
                      obtenerTerritorioMundo(m,idTerritorio)),comunidad2)!=0)) {

            bool terr_descartado=false;
            ListaEnteros* l_adyacentes = obtenerVecinosTerritorioMundo(m,
                                                                  idTerritorio);
          
            while (!esVaciaListaEnteros(l_adyacentes) && !terr_descartado) {
                
                Mundo* componente = crearMundo(cantTerritoriosMundo(m));
                int* visitados = new int[cantTerritoriosMundo(m)];
                for (int i = 0; i < cantTerritoriosMundo(m); i++  ) {
                        visitados[i] = 0;
                }
                // Lo marco como visitado asi en el DFS me devuelve un grafo 
                // partido o sea una componente
                visitados[idTerritorio] = 1; 
            
                int primer_vecino = primeroListaEnteros(l_adyacentes);
                DFS_Visitar(m,componente,primer_vecino,visitados);

                // Me fijo si en la componente hay dos comunidades en conflicto 
                // si las hay descarto este punto de articulacion como mediador
                if (compartenComponente(m,componente,comunidad1,comunidad2,
                                                                   visitados)) {
                    terr_descartado = true;
                }
                l_adyacentes = restoListaEnteros(l_adyacentes);
                
                delete(visitados);
                destruirMundo(componente);
            }
            if (!terr_descartado) {
                mediador = idTerritorio;
            }
        }
        idTerritorio++;

    } // while    

    return mediador;
    
} // fin territorioDelMediador

Mundo* proyectoDePavimentacion(Mundo* m) {

        int *visitados = new int[cantTerritoriosMundo(m)];
        Mundo* futuro = crearMundo(cantTerritoriosMundo(m));
        for (int i = 0; i < cantTerritoriosMundo(m); i++  ) {
                visitados[i] = 0;
                // copio los nombres y comunidades del mundo pasadado al futuro
                asignarComunidadTerritorio(obtenerTerritorioMundo(futuro,i),
                       obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i)));
                asignarNombreTerritorio(obtenerTerritorioMundo(futuro,i),
                          obtenerNombreTerritorio(obtenerTerritorioMundo(m,i)));

        }
        DFS_Visitar(m,futuro,0,visitados);
        destruirMundo(m);
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
bool compartenComponente(Mundo* m,Mundo* componente,const char* comunidad1,
                                        const char* comunidad2,int* visitados) {
        int iter_componente = 0;
        bool perteneceC1 = false;
        bool perteneceC2 = false;
        
        while ((iter_componente < cantTerritoriosMundo(componente)) 
                        && 
                !(perteneceC1 && perteneceC2)) {
            if (visitados[iter_componente] == 1) {
                if (strcmp(obtenerComunidadTerritorio(obtenerTerritorioMundo(m,
                                             iter_componente)),comunidad1)==0) {
                    perteneceC1 = true;
                }
                else if (strcmp(obtenerComunidadTerritorio(
                      obtenerTerritorioMundo(m,iter_componente)),
                                                               comunidad2)==0) {
                    perteneceC2 = true;
                }
           }
           iter_componente++;
        }

        return (perteneceC1 && perteneceC2);

} // fin compartenComponente


/****ESTOS HAY QUE BORRARLOS SON DEL CAMINO PARA DEBUGUEAR */
int obtenerLargoCamino(Camino* camino) {
    return ( camino->largo );

} // fin obtenerLargoCamino

int* obtenerTerritoriosCamino(Camino* camino) {
    return ( camino->territorios);

} //fin obtenerTerritoriosCamino

/************************************************/
/** fin implementacion de funciones auxiliares **/
/************************************************/
