#ifndef TERRITORIO_H
#define TERRITORIO_H

struct Territorio;

//***** Constructores *****//

Territorio* crearTerritorioVacio();
// Crea un nuevo territorio con nombre "" y comunidad ""


void asignarNombreTerritorio(Territorio* t, const char* nombre);
// Precondicion: El territorio t ya fue creado
// Precondicion: nombre != NULL
// Precondicion: nombre no contiene espacios
// Precondicion: El territorio t no tiene nombre asignado

void asignarComunidadTerritorio(Territorio* t, const char* comunidad);
// Precondicion: El territorio t ya fue creado
// Precondicion: comunidad != NULL
// Precondicion: comunidad no contiene espacios
// Precondicion: El territorio t no tiene comunidad asignada

Territorio* copiarTerritorio(Territorio* t);
// Devuelve una copia limpia del territorio t. (no comparte memoria)
// Precondicion: El territorio t ya fue creado


//***** Selectores *****//

char* obtenerNombreTerritorio(Territorio* t);
// Devuelve una copia del nombre del territorio t
// Precondicion: El territorio t ya fue creado

char* obtenerComunidadTerritorio(Territorio* t);
// Devuelve una copia de la comunidad del territorio t
// Precondicion: El territorio t ya fue creado

//***** Predicados *****//

bool esComunidadTerritorio(Territorio* t, const char* comunidad);
// Devuelve true si la comunidad es la que habita en el territorio t.
// Precondicion: comunidad != NULL
// Precondicion: comunidad no contiene espacios
// Precondicion: El territorio t no tiene comunidad asignada
// Precondicion: El territorio t ya fue creado


//***** Destructores *****//

void destruirTerritorio(Territorio* t);
// Libera la memoria asociada al Territorio t
// Precondicion: El territorio t ya fue creado

#endif /* TERRITORIO_H */
