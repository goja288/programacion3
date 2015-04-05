/* 4666259 */

/*
@Author Gonzalo Javiel
@Archivo principal.cpp
@26_08_2011 0704 (fing)
*/

#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "Cola.h"
#include "Pila.h"
#include "ABB.h"

#define BUFFERSIZE 256

int main() {

printf("Obligatorio 1 - 2011 - Programacion 3\n\n");
ABB* abb = crearABB();
Cola*  cola = crearCola();
Pila* pila = crearPila();


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
    
    if (strcmp(entrada,"")!=0) { //control de ingreso vacio
        
        // divido los datos de entrada en comando y parametro
        char *comando = strtok( entrada, " ");
	char *param1  = strtok( NULL," ");
             
        if (param1 == NULL ) { //comandos sin parametros
            
            /*	1 - pilaObtener */
            if ((strcmp (comando, "pilaObtener") == 0) && (!esVaciaPila(pila))) {
                    int dato = desapilar(pila);
                    printf("%s %d.\n>","El tope de la pila es",dato);
            }
            else {
            /*	2 - colaObtener	*/
            if ((strcmp (comando, "colaObtener") == 0) && (!esVaciaCola(cola))) {
                    int dato = desencolar(cola);
                    printf("%s %d.\n>","El primer elemento de la cola es",dato);
            }
            else {
            /*	3 - abbMinimo	*/
            if ((strcmp (comando, "abbMinimo") == 0) && (!esVacioABB(abb))) {
                    int dato = menorABB(abb);
                    printf("%s %d.\n>","El minimo elemento del abb es",dato);
            }
            else {
            /*	4 - abbMaximo	*/
            if ((strcmp (comando, "abbMaximo") == 0) && (!esVacioABB(abb))) {
                    int dato = mayorABB(abb);
                    printf("%s %d.\n>","El maximo elemento del abb es",dato);
            }
            else {
            /*	5 - salir       */
            if ( strcmp (comando, "salir") == 0 ) {
                    fin = true;
                    destruirABB(abb);
                    destruirCola(cola);
                    destruirPila(pila);
            }
            else {
                    printf("Comando no reconocido.\n>");
            }}}}}
        }
        else { // comandos con 1 parametro

            /*	1 - pilaAgregar	*/
            if (strcmp (comando, "pilaAgregar") == 0) {
                    int dato = atoi(param1);
                    apilar(pila,dato);
                    printf("%s %i %s\n>","El elemento",dato,"se ha agregado en la pila.");
            }
            else {
            /*	2 - colaAgregar	*/
            if (strcmp (comando, "colaAgregar") == 0) {
                    int dato = atoi(param1);
                    encolar(cola,dato);
                    printf("%s %i %s\n>","El elemento",dato,"se ha agregado en la cola.");
            }
            else {
            /*	3 - abbAgregar	*/
            if (strcmp (comando, "abbAgregar") == 0) {
                    int dato = atoi(param1);
                    agregarABB(abb,dato);
                    printf("%s %i %s\n>","El elemento",dato,"se ha agregado en el abb.");
            }
            else {
            /*	4 - cargar      */
            if (strcmp (comando, "cargar") == 0) { 
                    destruirABB(abb);
                    destruirCola(cola);
                    destruirPila(pila);

                    char* nom_completo_abb = new char[BUFFERSIZE];
                    char* nom_completo_cola = new char[BUFFERSIZE];
                    char* nom_completo_pila = new char[BUFFERSIZE];

                    strcpy(nom_completo_abb, param1);
                    strcat(nom_completo_abb, "_abb.txt");
                    cargarABBDeArchivo(abb,nom_completo_abb);

                    strcpy(nom_completo_cola, param1);
                    strcat(nom_completo_cola, "_cola.txt");
                    cargarColaDeArchivo(cola,nom_completo_cola);

                    strcpy(nom_completo_pila, param1);
                    strcat(nom_completo_pila, "_pila.txt");
                    cargarPilaDeArchivo(pila,nom_completo_pila);

                    printf("Estructuras cargadas con exito.\n>");
            }
            else {
            /*	5 - guardar     */
            if (strcmp (comando, "guardar") == 0) {
                    char* nom_completo_abb = new char[BUFFERSIZE];
                    char* nom_completo_cola = new char[BUFFERSIZE];
                    char* nom_completo_pila = new char[BUFFERSIZE];

                    strcpy(nom_completo_abb, param1);
                    strcat(nom_completo_abb, "_abb.txt");
                    guardarABBAArchivo(abb,nom_completo_abb);

                    strcpy(nom_completo_cola, param1);
                    strcat(nom_completo_cola, "_cola.txt");
                    guardarColaAArchivo(cola,nom_completo_cola);

                    strcpy(nom_completo_pila, param1);
                    strcat(nom_completo_pila, "_pila.txt");
                    guardarPilaAArchivo(pila,nom_completo_pila);

                    printf("Estructuras guardadas con exito.\n>");
            }
            else {
                    printf("Comando no reconocido.\n>");
            }}}}}

        } // else comando con parametros
                
    } // if de entrada vacia
      
} //while
        
return 0;

} //principal
