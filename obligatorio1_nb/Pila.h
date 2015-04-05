#ifndef _PILA_H
#define _PILA_H

struct Pila;

Pila* crearPila();
//devuelve la pila vacia

bool esVaciaPila(Pila* p);
//devuelve true si s es vacio

void apilar(Pila* &p, int i);
//inserta el elemento i en la pila p

int desapilar(Pila* &p);
//devuelve el primer elemento de la pila p
//Precondicion: !esVaciaPila(p)

void destruirPila(Pila* &p);
// libera toda la memoria ocupada por p

void cargarPilaDeArchivo(Pila* &p, char* nomArchivo);
//carga los datos guardados en el archivo nomArchivo en la pila p
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.

void guardarPilaAArchivo(Pila* p, char* nomArchivo);
//guarda la pila p en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.

#endif /* _PILA_H */
