#ifndef UTILS_H
#define UTILS_H

#include "Territorio.h"
#include "Mundo.h"
#include "Estrategias.h"

extern char STR_ERRORS[15][1024];

#define CHECK_OK 0
/* Camino mas corto */
#define CHECK_CAMINO_LARGO 1
#define CHECK_CAMINO_ID1 2
#define CHECK_CAMINO_ID2 3
#define CHECK_CAMINO_NOTNULL 4
#define CHECK_CAMINO_HOSTIL 5
#define CHECK_CAMINO_NOVECINOS 6
/* Mediador */
#define CHECK_MEDIADOR_TERR 7
#define CHECK_MEDIADOR_COMUNIDAD 8
#define CHECK_MEDIADOR_CAMINOS 9
/* Pavimentacion */
#define CHECK_PAVIM_CANT_TERR 10
#define CHECK_PAVIM_DATOS_TERR 11
#define CHECK_PAVIM_MUCHOS_CAMINOS 12
#define CHECK_PAVIM_NO_CAMINO 13
#define CHECK_PAVIM_ARISTA 14

/* Retorna CHECK_OK si `sol' es un camino válido de largo `largo'
   desde `t1' a `t2' que no pasa por territorios de la comunidad `h'.
   Retorna un valor de error adecuado en otro caso. */
int check_camino (Mundo *m, int id1, int id2,
		  const char* h, int largo, Camino *sol);

/* Retorna CHECK_OK si `mediador' es un mediador válido entre las
   comunidades `c1' y `c2' en el mundo `m'. Retorna un valor de error
   adecuado en otro caso. */
int check_mediador (Mundo *m, const char *c1, const char *c2, int mediador);


/* Retorna CHECK_OK si `sol' es un mundo con los mismos territorios
   que `m', sin ciclos y tal que sus aristas estan en `m'. Retorna un
   valor de error adecuado en otro caso. */
int check_pavimentacion (Mundo *m, Mundo *sol);


#endif /* UTILS_H */