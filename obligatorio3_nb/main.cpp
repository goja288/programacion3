#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Estructura.h"

int main() {
    printf("TESTING Obligatorio 3 - 2011 - Programacion 3\n\n");
    Estructura* E = crearCOI ();
    bool fin = false;
    printf(">");
    while ( !fin ) {
        char entrada[255] = {0};
        // leo los datos de entrada
        int i = 0;
        char ce;
        while ( (( ce = getchar() ) != EOF) && (ce != '\n') ) {
                entrada[i] = ce;
                i++;
        }
        //printf("        entrada->%s\n",entrada);

        if (strcmp(entrada,"")!=0) { //control de ingreso vacio
            // divido los datos de entrada en comando y parametro
            char *comando = strtok( entrada, " ");
            char *param1  = strtok( NULL," ");
            char *param2  = strtok( NULL," ");
            char *param3  = strtok( NULL," ");
            char *param4  = strtok( NULL," ");
            char *param5  = strtok( NULL," ");
            char *param6  = strtok( NULL," ");

            /*      0 - help */
            if (strcmp (comando, "help") == 0) {
                printf("TODAVIA NO HACE NADA\n>");
                //fin = true;
            }
        /************************************************* AltaPais *************************************************/
            else if ((strcmp (comando, "altaPais") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL) {
                    if (strcmp (param2, "AMERICA"))
                        altaPais(param1, AMERICA, param3, E);
                    else if (strcmp (param2, "EUROPA"))
                        altaPais(param1, EUROPA, param3, E);
                    else if (strcmp (param2, "ASIA"))
                        altaPais(param1, ASIA, param3, E);
                    else if (strcmp (param2, "AFRICA"))
                        altaPais(param1, AFRICA, param3, E);
                    else if (strcmp (param2, "OCEANIA"))
                        altaPais(param1, OCEANIA, param3, E);
                    printf("Se dio de alta al Pais %s en el continente %s que tiene el idioma %s\n>",param1,param2,param3);
                }
                else {
                    printf("Falto ingresar alguno de los 3 parametros.\n>");
                }
            }
        /************************************************* AltaFederacion *************************************************/
            else if ((strcmp (comando, "altaFederacion") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL && param4!=NULL && param5!=NULL && param6!=NULL) {
                    altaFederacion(param1, param2, param3, atoi(param4), atoi(param5), atoi(param6), E);
                    printf("Se dio de alta a la Federacion %s en el pais %s, con la descripcion %s en la fecha %s/%s/%s\n>",param2,param1,param3,param4,param5,param6);
                }
                else {
                    printf("Falto ingresar alguno de los 6 parametros.\n>");
                }
            }
        /************************************************* AltaCampeonatoFederacion *************************************************/
            else if ((strcmp (comando, "altaCampeonatoFederacion") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL && param4!=NULL && param5!=NULL) {
                    altaCampeonatoFederacion(param1, param2, param3, param4, atoi(param5), E);
                    printf("Se dio de alta al Campeonato %s en la Federacion %s del pais %s, con la descripcion %s y la importancia%s\n>",param3,param2,param1,param4,param5);
                }
                else {
                    printf("Falto ingresar alguno de los 5 parametros.\n>");
                }
            }
        /************************************************* AltaDeportista *************************************************/
            else if ((strcmp (comando, "altaDeportista") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL && param4!=NULL && param5!=NULL) {
                    altaDeportista(param1, atoi(param2), param3, param4, atoi(param5), E);
                    printf("Se dio de alta al Deportista %s %s con el codigoCOI %s con la edad %s en el pais %s\n>",param3,param4,param2,param5,param1);
                }
                else {
                    printf("Falto ingresar alguno de los 5 parametros.\n>");
                }
            }
        /************************************************* ImprimirFederaciones *************************************************/
            else if ((strcmp (comando, "imprimirFederaciones") == 0)) {
                if (param1!=NULL) {
                    printf("Se imprimiran las federaciones del Pais %s:\n>",param1);
                    imprimirFederaciones(param1, E);
                    printf("\n>");
                }
                else {
                    printf("Falto ingresar el parametro.\n>");
                }
            }
        /************************************************* InscribirDeportistaCampeonato *************************************************/
            else if ((strcmp (comando, "inscribirDeportistaCampeonato") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL && param4!=NULL && param5!=NULL && param6!=NULL) {
                    inscribirDeportistaCampeonato(param1, param2, param3, atoi(param4), atoi(param5), atoi(param6), E);
                    printf("Se inscribio al Deportista de codigoCOI %s en el campeonato %s de la federacion %s y el pais %s en la fecha %s/%s\n>",param4,param3,param2,param1,param5,param6);
                }
                else {
                    printf("Falto ingresar alguno de los 6 parametros.\n>");
                }
            }
        /************************************************* ObtenerCantidadPaises *************************************************/
            else if ((strcmp (comando, "obtenerCantidadPaises") == 0)) {
                printf("Se obtendra la Cantidad de Paises que hay: %i\n>",obtenerCantidadPaises(E));
            }
        /************************************************* ExisteCampeonatoFederacion *************************************************/
            else if ((strcmp (comando, "existeCampeonatoFederacion") == 0)) {
                if (param1!=NULL && param2!=NULL && param3!=NULL) {
                    bool aux = existeCampeonatoFederacion(param1, param2, param3, E);
                    if (aux)
                        printf("EXISTE el Camepeonato %s de la Federacion %s del Pais %s\n>",param3,param2,param1);
                    else
                        printf("NO EXISTE el Camepeonato %s de la Federacion %s del Pais %s\n>",param3,param2,param1);
                }
                else {
                    printf("Falto ingresar alguno de los 3 parametros.\n>");
                }
            }
        /************************************************* ExisteCampeonatoFederacion *************************************************/
            else if ((strcmp (comando, "imprimirFederados") == 0)) {
                if (param1!=NULL && param2!=NULL) {
                    printf("Se imprimiran los federados de la Federacion %s del Pais %s:\n>",param2,param1);
                    imprimirFederados(param1, param2, E);
                    printf("\n>");
                }
                else {
                    printf("Falto ingresar alguno de los 2 parametros.\n>");
                }
            }
        /************************************************* ImprimirCampeonatosDeportista *************************************************/
            else if ((strcmp (comando, "imprimirCampeonatosDeportista") == 0)) {
                if (param1!=NULL) {
                    printf("Se imprimiran los campeonatos del Deportista con codigoCOI %s:\n>",param1);
                    imprimirCampeonatosDeportista(E, atoi(param1));
                    printf("\n>");
                }
                else {
                    printf("Falto ingresar el parametro.\n>");
                }
            }
        /************************************************* Salir *************************************************/
            else if (strcmp (comando, "salir") == 0)
                fin = true;
            else
                printf("Comando no reconocido.\n>");
        } // if de entrada vacia

    } //while
    destruirCOI (E);
    return 0;

} //principal
