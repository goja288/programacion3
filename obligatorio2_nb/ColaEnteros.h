#ifndef COLAENTEROS_H
#define	COLAENTEROS_H

struct ColaEnteros;

ColaEnteros* crearColaEnteros();
//devuelve la cola vacia

bool esVaciaColaEnteros(ColaEnteros* c);
//devuelve true si c es vacia
//Precondición: c fue previamente creada

void encolarColaEnteros(ColaEnteros* &c, int i);
//agrega el elemento i en c
//Precondición: c fue previamente creada

int desencolarColaEnteros(ColaEnteros* &c);
//devuelve el primer elemento de c
//Precondición: c fue previamente creada
//Precondicion: !esVaciaColaEnteros(c);

void destruirColaEnteros(ColaEnteros* &c);
//libera toda la memoria ocupada por c
//Precondicion: c fue previamente creada.


#endif	/*COLAENTEROS_H */