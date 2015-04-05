/*
@Author aeg
@Archivo main.cpp
@03_09_2011
*/

#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Estrategias.h"
#include "Mundo.h"
#include "Territorio.h"

#define BUFFERSIZE 256
const int CANT_TERRITORIOS=10;

/** Declaracion de funciones auxiliares **/

void imprimirMundo(Mundo* m);
int obtenerLargoCamino(Camino* camino);
int* obtenerTerritoriosCamino(Camino* camino);



/** Fin de declaracion de funciones auxiliares **/
int main() {

printf("Obligatorio 2 - 2011 - Programacion 3\n\n");

Mundo* m = crearMundo(CANT_TERRITORIOS);

bool fin = false;
printf(">");

while ( !fin ) {
        char entrada[BUFFERSIZE] = {0};
        // leo los datos de entrada
        
        int i = 0;
        char ce;
        while ( (( ce = getchar() ) != EOF) && (ce != '\n') ) {
                entrada[i] = ce;
                i++;
        }
        //printf("        entrada->%s\n",entrada);
   
   if (strcmp(entrada,"")!=0) { //control de ingreso vacio
        
                // divido los datos de entrada en comando y parametro
                char *comando = strtok( entrada, " ");
                char *param1  = strtok( NULL," ");
                char *param2  = strtok( NULL," ");
                char *param3  = strtok( NULL," ");
                
               /* printf("        comando->%s\n",comando);
                printf("        param1->%s\n",param1);
                printf("        param2->%s\n",param2);
                printf("        param3->%s\n",param3);*/
                
        
                /*      0 - help */
                if ((strcmp (comando, "help") == 0) || (strcmp (comando, "0") == 0)) {
                    printf("Los parametros son separados por espacio \n  "
                            "* 1 ó hacerVecinos\n  * * \t param1: vecino_i-vecinoj;vecinos_m-vecino_n \n  "
                            "* 2 ó cantidadVecinos\n  * *     \t param1: id_territorio\n  "
                            "* 3 ó obtenerVecinos\n  * *      \t param1: id_territorio\n  "
                            "* 4 ó sonVecinos\n  * *      \t param1: id_territorio1\n  * *      \t param2: id_territorio2\n  "
                            "* 5 ó asignarNombre\n  * *      \t param1: id_territorio\n  * *      \t param2: nombre\n  "
                            "* 6 ó asignarComunidad\n  * *      \t param1: id_territorio\n  * *      \t param2: comunidad\n  "
                            "* 7 ó obtenerNombre\n   * *      \t param1: id_territorio\n  "
                            "* 8 ó obtenerComunidad\n  * *      \t param1: id_territorio\n  "
                            "* 9 ó obtenerDatos\n  * *      \t sin parametros\n  "
                            "* 10 ó esComunidadTerritorio\n  * *      \t param1: id_territorio\n  * *      \t param2: comunidad \n  "
                            "* 11 ó caminoCorto\n  * *      \t param1: id_territorio1\n  * *      \t param2: id_territorio2\n  * *     \t param3: nombre_comunidad_hostil\n  "
                            "* 12 ó pavimentar\n  * *      \t sin parametros\n  "
                            "* 13 ó mediador\n  * *      \t param1: nombre_comunidad1\n  * *      \t param2: nombre_comunidad2\n  "
                            "* 14 ó memoriaMundo\n  * *      \t sin parametros\n  "
                            "* 15 ó memoriaTerritorio\n  * *      \t sin parametros\n  "
                            "* salir\n >");

                } else if ((strcmp (comando, "hacerVecinos") == 0) || (strcmp (comando, "1") == 0) ) {
                                char * ID_territorios;
                                ID_territorios = strtok(param1, ";");
                                int ID_1,ID_2;
                                while(ID_territorios != NULL)
                                {
                                    ID_1 = atoi(ID_territorios);
                                        //printf("%i ",ID_1 );
                                        ID_territorios++;
                                        ID_territorios++;
                                        ID_2 = atoi(ID_territorios);
                                        //printf("%i\n", ID_2);
                                //        if (ID_1!=0 && ID_2!=0) {
                                            hacerVecinosTerritorios(m,ID_1,ID_2);
                                  //      }
                                        ID_territorios = strtok(NULL, ";");
                                }
                                printf("El mundo quedo de la siguiente manera:\n");
                                imprimirMundo(m);  
                                printf("\n\n>");                                        
                                
            }
            else if ((strcmp (comando, "cantidadVecinos") == 0) || (strcmp (comando, "2") == 0) ) {
                        printf("La cantidad de vecinos es %i.\n>", cantVecinosTerritorioMundo(m,atoi(param1)));
            }
            else if ((strcmp (comando, "obtenerVecinos") == 0) || (strcmp (comando, "3") == 0) ) {
                        printf("Los vecinos a %i son:", atoi(param1));
                        if (param1!=NULL) {
                                int primero;
                                ListaEnteros* l_adyacentes = obtenerVecinosTerritorioMundo(m,atoi(param1));
                                while (!esVaciaListaEnteros(l_adyacentes)) {
                                        primero = primeroListaEnteros(l_adyacentes);
                                        l_adyacentes = restoListaEnteros(l_adyacentes);
                                        printf(" %i-> ", primero);
                                }
                        printf(".\n>");
                        }
                        else {
                            printf("Falto ingresar el parametro.\n>");
                        }
                       
            }
            else if ((strcmp (comando, "sonVecinos") == 0) || (strcmp (comando, "4") == 0) ) {
                        if (param1!=NULL && param2!=NULL) {
                            if (sonVecinosMundo(m,atoi(param1),atoi(param2))) {
                                        printf("Son vecinos.\n>");
                            }
                            else {
                                        printf("No son vecinos.\n>");
                            }
                        } 
                        else {
                            printf("Falto ingresar alguno de los 2 parametros.\n>");
                        }
            }

            else if ((strcmp (comando, "asignarNombre") == 0) || (strcmp (comando, "5") == 0) ) {
                        if (param1!=NULL && param2!=NULL) {
                            if (atoi(param1)<cantTerritoriosMundo(m)) {
                                asignarNombreTerritorio(obtenerTerritorioMundo(m,atoi(param1)),param2); 
                                printf("El nombre asignado al territorio con id %i es: %s\n>",atoi(param1),param2);
                            }
                            else {
                                printf("El id del territorio es mayor que la cantidad de territorios.\n>");
                            }
                        }
                        else {
                            printf("Falto ingresar el alguno de los 2 parametros.\n>");
                        }
            }
            else if ((strcmp (comando, "asignarComunidad") == 0) || (strcmp (comando, "6") == 0) ) {
                        if (param1!=NULL && param2!=NULL) {
                            if (atoi(param1)<cantTerritoriosMundo(m)) {
                                asignarComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1)),param2); 
                                printf("La comunidad asignada al territorio con id %i es: %s\n>",atoi(param1),param2);
                            }
                            else {
                                printf("El id del territorio es mayor que la cantidad de territorios.\n>");
                            }
                        }
                        else {
                            printf("Falto ingresar alguno de los 2 parametros.\n>");
                        }
            }
            else if ((strcmp (comando, "obtenerNombre") == 0) || (strcmp (comando, "7") == 0) ) {
                        if (param1!=NULL) {
                            if (atoi(param1)<cantTerritoriosMundo(m)) {
                                printf("El nombre del territorio con id %i es: %s\n>",
                                        atoi(param1),obtenerNombreTerritorio(obtenerTerritorioMundo(m,atoi(param1))));
                            }
                            else {
                                printf("El id del territorio es mayor que la cantidad de territorios.\n>");
                            }
                        }
                        else {
                            printf("Falto ingresar el parametro.\n>");
                        }
            }
            else if ((strcmp (comando, "obtenerComunidad") == 0) || (strcmp (comando, "8") == 0) ) {
                        if (param1!=NULL) {
                            if (atoi(param1)<cantTerritoriosMundo(m)) {
                                obtenerComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1))); 
                                printf("La comunidad del territorio con id %i es: %s\n>",
                                        atoi(param1),obtenerComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1))));
                            }
                            else {
                                printf("El id del territorio es mayor que la cantidad de territorios.\n>");
                            }
                        }
                        else {
                            printf("Falto ingresar el parametro.\n>");
                        }
            }
            else if ((strcmp (comando, "obtenerDatos") == 0) || (strcmp (comando, "9") == 0) ) {
                        
                        printf("Los nombres de los territorios son: \n");
                        for (int i =0;i < cantTerritoriosMundo(m);i++) {
                                printf("Territorio %i  |  Nombre: %s  |  Comunidad: %s \n",                                               i,
                                                                                 obtenerNombreTerritorio(obtenerTerritorioMundo(m,i)),
                                                                          obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i)));
                                            
                        };
                        printf(".\n>");
            }
            else if ((strcmp (comando, "esComunidadTerritorio") == 0) || (strcmp (comando, "10") == 0) ) {
                 if (esComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1)), param2)) {
                     printf("La comunidad %s SIII habita el territorio %i\n>",
                             obtenerComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1))),atoi(param1));
                 }
                 else {
                     printf("La comunidad %s NOOOO habita el territorio %i\n>",
                             obtenerComunidadTerritorio(obtenerTerritorioMundo(m,atoi(param1))),atoi(param1));
                 }

            }
            else if ((strcmp (comando, "caminoCorto") == 0) || (strcmp (comando, "11") == 0) ) {
                       if (param1!=NULL && param2!=NULL && param3!=NULL) {
                           if ((atoi(param1) < cantTerritoriosMundo(m)) || (atoi(param2) < cantTerritoriosMundo(m))) {
                                Camino* camino = caminoMasCorto(m,atoi(param1),atoi(param2),param3);
                                printf("El camino mas corto es de largo %i es: \n>",obtenerLargoCamino(camino));
                                
                                int* territorios_camino = obtenerTerritoriosCamino(camino);
                                for (int i = 0; i < obtenerLargoCamino(camino);i++) {
                                    printf("%i----",territorios_camino[i]);
                                }
                                //delete camino;
                           }
                           else {
                               printf("Alguno de los 2 territorios no existe en el mundo.\n>");
                           }
                       } 
                        else {
                            printf("Falto ingresar por lo menos uno de los territorios.\n>");
                        }
                       printf(".\n>");
            }
            else if ((strcmp (comando, "pavimentar") == 0) || (strcmp (comando, "12") == 0) ) {
                        printf("\nEl mundo sin pavimentar es el siguiente: \n");
                        imprimirMundo(m);
                        Mundo* futuro = proyectoDePavimentacion(m);
                        printf("\nEl mundo pavimentado es el siguiente: \n");
                        imprimirMundo(futuro);
                        //m=futuro;
                        destruirMundo(futuro);
                        printf(".\n>");
            }
            else if ((strcmp (comando, "mediador") == 0) || (strcmp (comando, "13") == 0) ) {
                        if (param1!=NULL && param2!=NULL) {
                            if ( strcmp(param1,param2) != 0 ) {
                                printf("El identificador del territorio del mediador es: %i.\n>",
                                                                                                       territorioDelMediador( m,param1,param2));
                            }
                            else {
                                printf("Las comunidades son las mismas.\n>");
                            }
                            
                        }
                        else {
                            printf("Falto ingresar por lo menos una de las 2 comunidades");
                        }
            }
            else if ((strcmp (comando, "memoriaMundo") == 0) || (strcmp (comando, "14") == 0) ) {
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                destruirMundo(m);
                int cant_territorios = 1000;
                m = crearMundo(cant_territorios);
                
                const char* nombre = "nombre";
                const char* comunidad = "comunidad";
                
                for (int i = 0; i < cantTerritoriosMundo(m);i++){
                    asignarNombreTerritorio(obtenerTerritorioMundo(m,i),nombre);
                    asignarComunidadTerritorio(obtenerTerritorioMundo(m,i),comunidad);
                    for (int j = 0; j < cantTerritoriosMundo(m);j++){
                        hacerVecinosTerritorios(m,i,j);
                    }
                }
                destruirMundo(m);
                m = crearMundo(CANT_TERRITORIOS);
                printf("\n>");
            }
            else if ((strcmp (comando, "memoriaTerritorio") == 0) || (strcmp (comando, "15") == 0) ) {
                
                
                for(i=0;i<1000000;i++) {
                    Territorio* t = crearTerritorioVacio();
                    const char* nombre = "nombre";
                    const char* comunidad = "comunidad";
                    asignarNombreTerritorio(t,nombre);
                    asignarComunidadTerritorio(t,comunidad);
                    destruirTerritorio(t);

                    t = crearTerritorioVacio();
                    nombre = "nombre";
                    comunidad = "comunidad";
                    asignarNombreTerritorio(t,nombre);
                    asignarComunidadTerritorio(t,comunidad);
                    destruirTerritorio(t);

                 
                } 
                printf("\n>");
            }
            else if (strcmp (comando, "salir") == 0){
                        fin = true;
            }
            
            else {
                        printf("Comando no reconocido.\n>");
            }
      
       } // if de entrada vacia
              
    } //while
      

destruirMundo(m);
return 0;

} //principal


/** Implementacion de funciones auxiliares **/

void imprimirMundo (Mundo* m) {
        ListaEnteros* l_vecinos;                
        int primero;
        for (int i = 0; i< cantTerritoriosMundo(m); i++) {
                l_vecinos = obtenerVecinosTerritorioMundo(m,i);
                while (!esVaciaListaEnteros(l_vecinos))  {
                        primero = primeroListaEnteros(l_vecinos);
                        l_vecinos = restoListaEnteros(l_vecinos);
                        printf("( %i , %i )  ",i,primero);
                }
        }
} // fin imprimirMundo


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

/** fin de implementacion de funciones auxiliares **/
