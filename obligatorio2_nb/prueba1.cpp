#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

Mundo* crear_mundo ();

/* Definicion del mundo */
#define CANT_TERRITORIOS 7
char nombres[CANT_TERRITORIOS][3]     = {"t0", "t1", "t2", "t3", "t4", "t5", "t6"};
char comunidades[CANT_TERRITORIOS][3] = {"c1", "c2", "c2", "c3", "c2", "c1", "c4"};
/* Vecinos de cada territorio. CADA ARISTA DEBE ESTAR UNA VEZ SOLA. */
int vecinos[CANT_TERRITORIOS][CANT_TERRITORIOS] =
//  0  1  2  3  4  5  6
  {{0, 1, 1, 1, 0, 0, 0},  // 0
   {0, 0, 0, 0, 0, 1, 0},  // 1
   {0, 0, 0, 0, 1, 0, 0},  // 2
   {0, 0, 0, 0, 0, 1, 0},  // 3
   {0, 0, 0, 0, 0, 1, 0},  // 4
   {0, 0, 0, 0, 0, 0, 1},  // 5
   {0, 0, 0, 0, 0, 0, 0}}; // 6

/* Camino mas corto */
#define T1 0			/* Territorio origen */
#define T2 5			/* Territorio destino */
#define HOSTIL "c3"		/* Comunidad hostil */
#define LARGO_CAMINO 3          /* Largo del camino más corto entre T1 y T2 */

/* Mediador */
#define COMUNIDAD1 "c2"
#define COMUNIDAD2 "c4"
#define HAY_MEDIADOR 1

int
main (int argc, char *argv[])
{
  int res;
  Mundo *m = crear_mundo ();

  printf ("Calculando camino mas corto...");
  Camino *c = caminoMasCorto (m, T1, T2, HOSTIL);

  res = check_camino (m, T1, T2, HOSTIL, LARGO_CAMINO, c);
  if (res == CHECK_OK)
    printf ("OK\n");
  else
    printf ("ERROR\n(%s)\n", STR_ERRORS[res]);

  delete [] c->territorios;
  delete c;

  printf ("Calculando mediador...");
  int mediador = territorioDelMediador(m, COMUNIDAD1, COMUNIDAD2);
  res = check_mediador (m, COMUNIDAD1, COMUNIDAD2, mediador);
  if (! HAY_MEDIADOR && mediador == NO_HAY_TERRITORIO_MEDIADOR)
    printf ("OK\n");
  else if (res == CHECK_OK)
    printf ("OK\n");
  else
    printf ("ERROR\n(%s)\n", STR_ERRORS[res]);

  printf ("Calculando proyecto de pavimentacion...");
  Mundo *pavimentado = proyectoDePavimentacion (m);
  if (check_pavimentacion (m, pavimentado) == CHECK_OK)
    printf ("OK\n");
  else
    printf ("ERROR!\n");

  destruirMundo (m);
  destruirMundo (pavimentado);

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

