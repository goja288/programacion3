/* 4666259 */

/*
@Author Gonzalo Javiel
@Archivo Pila.cpp
@26_08_2011 0704 (fing)
*/

#include "Pila.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFERSIZE 256

typedef struct Pila {
    int dato;
    Pila *sig;
} Pila;

/**Funciones auxiliares**/
/*bool pertenecePila(Pila *p,int i);*/
Pila* invertirPila(Pila* p) ;
/**************************/

//devuelve la pila vacia
Pila* crearPila() {

    return (NULL);
}

//devuelve true si s es vacio
bool esVaciaPila(Pila* p){

    return (p==NULL);
}

//inserta el elemento i en la pila p
void apilar(Pila* &p, int i) {
/*    if (!pertenecePila(p,i)) {*/
        Pila *nuevo_nodo = new Pila;
        nuevo_nodo->dato = i;
        nuevo_nodo->sig = p;
        p = nuevo_nodo;
/*    }*/
}

//devuelve el primer elemento de la pila p
//Precondicion: !esVaciaPila(p)
int desapilar(Pila* &p){

    int elem = p->dato;
    Pila *aBorrar = p;
    p = p->sig;
    delete(aBorrar);

    return elem;
}

// libera toda la memoria ocupada por p
void destruirPila(Pila* &p) {

        
    while (!esVaciaPila(p)) {
        /*Pila *aBorrar = p;
        p=p->sig;
        delete(aBorrar);*/
        desapilar(p);
    }
    p=NULL; // no si es necesario ya esVaciaPila pregunta si es NULL pero con el abb pasa lo mismo
}

//carga los datos guardados en el archivo nomArchivo en la pila p
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.
void cargarPilaDeArchivo(Pila* &p, char* nomArchivo) {

    FILE *archivo;
        archivo = fopen(nomArchivo, "r");
            if (archivo) {
                char* lectura = new char[BUFFERSIZE];
                fscanf(archivo, "%s\n", lectura);
                int dato;
                while (strcmp(lectura, "FIN") != 0) {

                    dato = atoi(lectura);
                    apilar(p,dato);
                    fscanf(archivo, "%s\n", lectura);
                }
                p = invertirPila(p);
                fclose(archivo);
            }
}

//guarda la pila p en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.
void guardarPilaAArchivo(Pila* p, char* nomArchivo){

    FILE *archivo;
    archivo = fopen(nomArchivo, "w");
    if (archivo) {
        Pila *pila_aux = p;
        while (!esVaciaPila(pila_aux)) {
                fprintf(archivo,"%i\n",pila_aux->dato);
                pila_aux = pila_aux->sig;
        }
        fprintf(archivo,"%s", "FIN");
        fclose(archivo);
    }
}


/**Declaracion de funciones auxiliares**/

//Invierte la pila destruyendo la original
Pila* invertirPila(Pila* p)  {

    Pila *pila_aux = crearPila();
    int dato;
    while (!esVaciaPila(p)) {
        dato = desapilar(p);
        apilar(pila_aux,dato);
    }
    destruirPila(p);
    return (pila_aux);
}
/*
bool pertenecePila(Pila *p,int i) {

    while ( !esVaciaPila(p) && (p->dato != i) ) {
        p=p->sig;
    }

    return (!esVaciaPila(p));
}
*/
