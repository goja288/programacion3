#ifndef LISTAENTEROS_H
#define LISTAENTEROS_H

struct ListaEnteros;

ListaEnteros* crearListaEnteros();
// Crea una lista de nodos vacia. 

bool esVaciaListaEnteros(ListaEnteros* l);
// Devuelve true si la lista es vacia y false en caso contrario. 
// Precondición: l fue previamente creada

void agregarListaEnteros(ListaEnteros* &l, int n);
// Agrega el elemento n a la lista  l.
// Precondición: l fue previamente creada

int primeroListaEnteros(ListaEnteros* l);
// Devuelve el primer elemento de la lista. 
// Precondicion: !esVaciaListaEnteros(l).
// Precondición: l fue previamente creada

ListaEnteros* restoListaEnteros(ListaEnteros* l);
// Devuelve un alias al resto de la lista.
// Precondicion: !esVaciaListaEnteros(l).
// Precondición: l fue previamente creada

void destruirListaEnteros(ListaEnteros* &l);
// libera la memoria asociada a la lista.
// Precondición: l fue previamente creada 

#endif /* LISTAENTEROS_H */
