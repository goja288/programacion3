/* 4309187 4666259 4201206 */
#include "Territorio.h"
#include <string.h>

const int maxLenght = 0x100;

struct Territorio {
   char name[maxLenght];
   char community[maxLenght];
};

Territorio*
crearTerritorioVacio() {
    Territorio *terr = new Territorio;
    strcpy(terr->name, "");
    strcpy(terr->community, "");
    return terr;
};

void
asignarNombreTerritorio(Territorio* t, const char* nombre) {
    strcpy(t->name, nombre);
};

void
asignarComunidadTerritorio(Territorio* t, const char* comunidad) {
    strcpy(t->community, comunidad);
};

Territorio*
copiarTerritorio(Territorio* t) {
    Territorio *terr = new Territorio;
    strcpy(terr->name,      t->name);
    strcpy(terr->community, t->community);
    return terr;
};

char*
obtenerNombreTerritorio(Territorio* t) {
    char* auxName = new char[maxLenght];
    strcpy(auxName, t->name);
    return auxName;
};

char*
obtenerComunidadTerritorio(Territorio* t) {
    char*  auxCommunity = new char[maxLenght];
    strcpy(auxCommunity, t->community);
    return auxCommunity;
};

bool
esComunidadTerritorio(Territorio* t, const char* comunidad) {
    return (strcmp(t->community, comunidad) == 0);
};

void
destruirTerritorio(Territorio* t) {
    delete(t);
};
