/* 4666259 */

/*
@Author Gonzalo Javiel
@Archivo ABB.cpp
@26_08_2011 0704 (fing)
*/

#include "ABB.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 256

typedef struct ABB {
	int dato;
	ABB *izq;
	ABB *der;
} ABB;

/**Funciones auxiliares**/
void guardarABBAArchivo_aux(FILE* &archivo, ABB *abb);
/**************************/

//devuelve el arbol vacio
ABB* crearABB() {

	return (NULL);
}

//agrega el elemento i en abb si este no pertenece al arbol
void agregarABB(ABB* &abb, int i){

 	if (abb==NULL){
        	ABB* nuevo_nodo = new ABB;
        	nuevo_nodo->dato = i;
        	nuevo_nodo->izq = NULL;
        	nuevo_nodo->der = NULL;
       		abb = nuevo_nodo;
  	} else if (i < abb->dato){
        	agregarABB(abb->izq, i);
	} else if (i > abb->dato){
        	agregarABB(abb->der, i);
    }
}

//devuelve true si abb es vacio
bool esVacioABB(ABB* abb){

	return (abb==NULL);
}

//devuelve el valor de la raiz de abb
//Precondicion: !esVacioABB(abb)
int valorABB(ABB* abb){

	return (abb->dato);
}

//devuelve el subarbol izquierdo de abb
//Precondicion: !esVacioABB(abb)
ABB* arbolIzquierdo(ABB* abb){

	return (abb->izq);
}

//devuelve el subarbol derecho de abb
//Precondicion: !esVacioABB(abb)
ABB* arbolDerecho(ABB* abb){

	return (abb->der);
}

//devuelve el minimo valor de abb
//Precondicion: !esVacioABB(abb)
int menorABB(ABB* &abb) {

    int menor;
    if (esVacioABB(arbolIzquierdo(abb))) {
        ABB* aBorrar = abb;
        abb = arbolDerecho(abb);
        menor = valorABB(aBorrar);
        delete(aBorrar);
    }
    else {
        menor = menorABB(abb->izq);
    }

    return menor;
}

//devuelve el maximo valor de abb
//Precondicion: !esVacioABB(abb)
int mayorABB(ABB* &abb) {

    int mayor;
    if (esVacioABB(arbolDerecho(abb))) {
        ABB* aBorrar = abb;
        abb = arbolIzquierdo(abb);
        mayor = valorABB(aBorrar);
        delete(aBorrar);
    }
    else {
        mayor = mayorABB(abb->der);
    }

    return mayor;
}

// libera toda la memoria ocupada por abb
void destruirABB(ABB* &abb) {

	if (!esVacioABB(abb)) {
		destruirABB(abb->izq);
		destruirABB(abb->der);
		delete(abb);
	}
    abb = NULL;
}

//carga los datos guardados en el archivo nomArchivo en el ABB abb
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.
void cargarABBDeArchivo(ABB* &abb, char* nomArchivo) {

	FILE *archivo;
	archivo = fopen(nomArchivo, "r");
        if (archivo) {
            char* lectura = new char[BUFFERSIZE];
            fscanf(archivo, "%s\n", lectura);
            int n;
            while (strcmp(lectura, "FIN") != 0) {
                    if (strcmp(lectura, "NULL") != 0) {
                        
                        n = atoi(lectura);
                        agregarABB(abb, n);
                    }
                    fscanf(archivo, "%s\n", lectura);
            }
            fclose(archivo);
        }
}

//guarda el ABB abb en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.
void guardarABBAArchivo(ABB* abb, char* nomArchivo) {

	FILE *archivo;
    	archivo = fopen(nomArchivo, "w");
        if (archivo) {
ABB* ARBOL_NUEVO = abb;    
	//     if (abb!=NULL) {
                    guardarABBAArchivo_aux(archivo, ARBOL_NUEVO);
    //        }
            fprintf(archivo,"%s", "FIN");
            fclose(archivo);
        }
		else {
			printf("No pudo ser guardado");
		}
}


/**Declaracion de funciones auxiliares**/

void guardarABBAArchivo_aux(FILE* &archivo, ABB *abb) {

	if (abb==NULL){
        	fprintf(archivo,"%s\n","NULL");
	}
	else {
		fprintf(archivo, "%i\n", abb->dato);
		guardarABBAArchivo_aux(archivo, abb->izq);
       	guardarABBAArchivo_aux(archivo, abb->der);
    }
}
