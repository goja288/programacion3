#ifndef _COLA_H
#define _COLA_H

struct Cola;

Cola* crearCola();
//devuelve la cola vacia

bool esVaciaCola(Cola* c);
//devuelve true si c es vacia

void encolar(Cola* &c, int i);
//agrega el elemento i en c

int desencolar(Cola* &c);
//devuelve el primer elemento de c
//Precondicion: !esVaciaCola(c)

void destruirCola(Cola* &c);
// libera toda la memoria ocupada por c

void cargarColaDeArchivo(Cola* &c, char* nomArchivo);
//carga los datos guardados en el archivo nomArchivo en la cola c
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.

void guardarColaAArchivo(Cola* c, char* nomArchivo);
//guarda la cola c en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.

#endif /* _COLA_H */

