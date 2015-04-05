#ifndef _ABB_H
#define _ABB_H

struct ABB;

ABB* crearABB();
//devuelve el arbol vacio

void agregarABB(ABB* &abb, int i);
//agrega el elemento i en abb

bool esVacioABB(ABB* abb);
//devuelve true si abb es vacio

int valorABB(ABB* abb);
//devuelve el valor de la raiz de abb
//Precondicion: !esVacioABB(abb)

ABB* arbolIzquierdo(ABB* abb);
//devuelve el subarbol izquierdo de abb
//Precondicion: !esVacioABB(abb)

ABB* arbolDerecho(ABB* abb);
//devuelve el subarbol derecho de abb
//Precondicion: !esVacioABB(abb)

int menorABB(ABB* &abb);
//devuelve el minimo valor de abb
//Precondicion: !esVacioABB(abb)

int mayorABB(ABB* &abb);
//devuelve el maximo valor de abb
//Precondicion: !esVacioABB(abb)

void destruirABB(ABB* &abb);
// libera toda la memoria ocupada por abb

void cargarABBDeArchivo(ABB* &abb, char* nomArchivo);
//carga los datos guardados en el archivo nomArchivo en el ABB abb
//Precondicion: Existe un archivo con el nombre nomArchivo y tiene el formato correcto.

void guardarABBAArchivo(ABB* abb, char* nomArchivo);
//guarda el ABB abb en el archivo de nombre nomArchivo.
//Si existe el archivo nomArchivo lo sobrescribe.

#endif /* _ABB_H */

