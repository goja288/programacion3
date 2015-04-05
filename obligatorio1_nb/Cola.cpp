/* 4666259 */

/*
@Author Gonzalo Javiel
@Archivo Cola.cpp
@26_08_2011 0704 (fing)
*/

#include "Cola.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFERSIZE 256

typedef struct nodo_cola {
    int dato;
    nodo_cola* sig;
} nodo_cola;

typedef struct Cola {
    nodo_cola* primer;
    nodo_cola* ultimo;
} Cola;

/**Funciones auxiliares**/
/*bool perteneceCola(Cola *c,int i);*/
/**************************/

//devuelve la cola vacia
Cola* crearCola() {

	Cola* c = new Cola;
    c->primer = NULL;
    c->ultimo = NULL;

	return c;
}

//devuelve true si c es vacia
bool esVaciaCola(Cola* c) {

    return (c->primer == NULL);
}

//agrega el elemento i en c
void encolar(Cola* &c, int i) {
    nodo_cola* nuevo_nodo_cola = new nodo_cola;
	nuevo_nodo_cola->dato = i;
	nuevo_nodo_cola->sig = NULL;

	if (esVaciaCola(c)) {
		c->primer = nuevo_nodo_cola;
		c->ultimo = nuevo_nodo_cola;
	}
	else {
		c->ultimo->sig = nuevo_nodo_cola;
		c->ultimo = c->ultimo->sig;
    }
}

//devuelve el primer elemento de c
//Precondicion: !esVaciaCola(c)
int desencolar(Cola* &c) {
	int elem = c->primer->dato;
	nodo_cola* aBorrar = c->primer;

	if (c->primer == c->ultimo) { //tiene un solo elemento o es vacia(pero como tiene precondicion de que no es vacia no importa)
		c->ultimo = c->primer->sig;
		c->primer = c->primer->sig;
	}
	else {
		c->primer = c->primer->sig;
	}
	delete(aBorrar);

	return elem;
}

// libera toda la memoria ocupada por c
void destruirCola(Cola* &c) {

	while (!esVaciaCola(c)){
                desencolar(c);
        }
	//c=crearCola(); //el desencolar hace todo el trabajo de no dejarlo desreferenciado
	}

//carga los datos guardados en el archivo nomArchivo en la cola c
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.
void cargarColaDeArchivo(Cola* &c, char* nomArchivo) {
	FILE *archivo;
   	archivo = fopen(nomArchivo, "r");
        if (archivo) {
            char* lectura = new char[BUFFERSIZE];
            fscanf(archivo, "%s\n", lectura);
            int dato;
            while (strcmp(lectura, "FIN")!=0) {
                dato = atoi(lectura);
                encolar(c, dato);
                fscanf(archivo, "%s\n", lectura);
            }
            fclose(archivo);
        }
}

//guarda la cola c en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.
void guardarColaAArchivo(Cola* c, char* nomArchivo) {
        FILE *archivo;
        archivo = fopen(nomArchivo, "w");
        if (archivo) {        
            int dato;
            nodo_cola * cola_aux = c->primer;
            while (!(cola_aux == NULL)) {
                dato = cola_aux->dato;/*desencolar(c);*/
                fprintf(archivo, "%i\n", dato);
                cola_aux=cola_aux->sig;
            }
            fprintf(archivo,"%s", "FIN");
            fclose(archivo);
        }
		else {
			printf("No pudo ser guardado");
		}
}

/****************************************************************************************/
/*
bool perteneceCola(Cola *c,int i) {

    while (!esVaciaCola(c) && (c->dato != i) ) {
        c->primer = c->primer->sig;
    }

    return (!esVaciaCola(c));
}
*/
