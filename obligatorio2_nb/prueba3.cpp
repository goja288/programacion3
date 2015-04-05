#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

Mundo* crear_mundo ();

/* Definicion del mundo */
#define CANT_TERRITORIOS 8
char nombres[CANT_TERRITORIOS][3]     = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"};
char comunidades[CANT_TERRITORIOS][3] = {"c1", "c2", "c1", "c3", "c3", "c2", "c4", "c4"};
/* Vecinos de cada territorio. CADA ARISTA DEBE ESTAR UNA VEZ SOLA. */
int vecinos[CANT_TERRITORIOS][CANT_TERRITORIOS] =
//  0  1  2  3  4  5  6  7
  {{0, 1, 0, 0, 0, 0, 0, 0},  // 0
   {0, 0, 0, 1, 1, 0, 0, 0},  // 1
   {0, 0, 0, 1, 0, 0, 0, 0},  // 2
   {0, 0, 0, 0, 0, 0, 0, 0},  // 3
   {0, 0, 0, 0, 0, 1, 0, 1},  // 4
   {0, 0, 0, 0, 0, 0, 1, 0},  // 5
   {0, 0, 0, 0, 0, 0, 0, 1},  // 6
   {0, 0, 0, 0, 0, 0, 0, 0}}; // 7

int
main (int argc, char *argv[])
{
  Mundo *m = crear_mundo ();
  int mediador, res;

  printf ("Calculando mediador 1...");
  mediador = territorioDelMediador (m, "c1", "c4");
  res = check_mediador (m, "c1", "c4", mediador);
  if (res == CHECK_OK)
    printf ("OK\n");
  else
    printf ("ERROR\n(%s)\n", STR_ERRORS[res]);

  printf ("Calculando mediador 2...");
  mediador = territorioDelMediador (m, "c4", "c2");
  if (mediador == NO_HAY_TERRITORIO_MEDIADOR)
    printf ("OK\n");
  else
    printf ("ERROR\n");

  printf ("Calculando mediador 3...");
  mediador = territorioDelMediador (m, "c1", "c3");
  if (mediador == NO_HAY_TERRITORIO_MEDIADOR)
    printf ("OK\n");
  else
    printf ("ERROR!\n");

  hacerVecinosTerritorios (m, 0, 6);
  printf ("Calculando mediador 4...");
  mediador = territorioDelMediador (m, "c1", "c4");
  if (mediador == NO_HAY_TERRITORIO_MEDIADOR)
    printf ("OK\n");
  else
    printf ("ERROR!\n");

  destruirMundo (m);

  /* c1 - c2 - c3 - c2 - c1 */
  Territorio *t;
  
  m = crearMundo (5);
  t = obtenerTerritorioMundo (m, 0);
  asignarNombreTerritorio (t, "t0");
  asignarComunidadTerritorio (t, "c1");
  t = obtenerTerritorioMundo (m, 1);
  asignarNombreTerritorio (t, "t1");
  asignarComunidadTerritorio (t, "c2");
  t = obtenerTerritorioMundo (m, 2);
  asignarNombreTerritorio (t, "t2");
  asignarComunidadTerritorio (t, "c3");
  t = obtenerTerritorioMundo (m, 3);
  asignarNombreTerritorio (t, "t3");
  asignarComunidadTerritorio (t, "c2");
  t = obtenerTerritorioMundo (m, 4);
  asignarNombreTerritorio (t, "t4");
  asignarComunidadTerritorio (t, "c1");
  
  hacerVecinosTerritorios (m, 0, 1);
  hacerVecinosTerritorios (m, 1, 2);
  hacerVecinosTerritorios (m, 2, 3);
  hacerVecinosTerritorios (m, 3, 4);

  printf ("Calculando mediador 5...");
  mediador = territorioDelMediador (m, "c1", "c3");
  if (mediador == NO_HAY_TERRITORIO_MEDIADOR)
    printf ("OK\n");
  else
    printf ("ERROR!\n");
  
  destruirMundo (m);
  return 0;
}


Mundo *
crear_mundo ()
{
  int i, j;
  Mundo *m = crearMundo (CANT_TERRITORIOS);

  for (i = 0; i < CANT_TERRITORIOS; i++)
    {
      Territorio *t = obtenerTerritorioMundo (m, i);
      asignarNombreTerritorio (t, nombres[i]);
      asignarComunidadTerritorio (t, comunidades[i]);

      for (j = 0; j < CANT_TERRITORIOS; j++)
	if (vecinos[i][j])
	  hacerVecinosTerritorios (m, i, j);
    }

  return m;
}

