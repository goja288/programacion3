#include <stdio.h>
#include <string.h>
#include "Estructura.h"


/*
comandos:

altaPais
altaFederacion
altaCampeonatoFederacion
altaDeportista
imprimirFederaciones
inscribirDeportistaCampeonato
obtenerCantidadPaises
existeCampeonatoFederacion
imprimirFederados
imprimirCampeonatosDeportista
salir: termina
stress: carga datos y termina
destruir CANTIDAD : destruye lo que habia, hace un ciclo creando, haciendo altas y destruyendo y termina

*/


void leerParametro (char * param)
// consume espacios en blanco
// si el parametro esta encerrrado entre comillas lo almacena sin las comillas
{
    char c;
	scanf ("%*[ ]");
    c = (char) getchar ();
    if (c != '"') 
    {
		ungetc ((int) c, stdin);
        scanf ("%s", param);
    }
    else
    {
        int i = 0;
        while ((c = (char) getchar ()) != '"')
        {
            param [i] = c;
            i++;
        }
        param [i] = '\0';
    }

}


void 
dar_altas (Estructura * coi)
{
    char sufijo[5], nombreP [10], nombreF [10], nombreC [10];
    int i, j, k;
    for (i = 0; i < P; i++)
    {
        sprintf (sufijo, "%d", i);
        strcpy (nombreP,"pais");
        strcat (nombreP, sufijo);
        altaPais (nombreP, AMERICA, "espaniol", coi);
        for (j = 0; j < D; j++)
        {
			sprintf (sufijo, "%d", j);
			strcpy (nombreF,"ape");
			strcat (nombreF, sufijo);
            altaDeportista (nombreP, 10000 + i*D + j, "n", nombreF, 20 + j/10, coi);
        }
        for (j = 0; j < F; j++) // se asume que  F <= 122-48+1
        {
            strcpy (nombreF,"fede");
            nombreF [4] = 48+j;   // '0' -> 48
            nombreF [5] = 122-j;  // 'z' -> 122
            nombreF [6] = 0; 
            altaFederacion (nombreP, nombreF, "descrF", 1, 1, 1900 + j, coi);
            for (k = 0; k < C; k++) // se asume que  C <= 122-48+1
            {
                strcpy (nombreC,"camp");
                nombreC [4] = 48+k; 
                nombreC [5] = 122-k; 
                nombreC [6] = 0; 
                altaCampeonatoFederacion (nombreP, nombreF, nombreC, "descrC", k, coi);
				inscribirDeportistaCampeonato (nombreP, nombreF, nombreC, 10000+i*D + k, 1, 31, coi);
            }
        }
		
		for (j = 1; j <= 12; j++)
		{
			strcpy (nombreC,"camp");
			nombreC [4] = 48+j; 
			nombreC [5] = 122-j; 
			nombreC [6] = 0; 
			for (k = 1; k <= 28; k++)
			{
				strcpy (nombreF,"fede");
				nombreF [4] = 48+k; 
				nombreF [5] = 122-k;
				nombreF [6] = 0; 
				inscribirDeportistaCampeonato (nombreP, nombreF ,nombreC , 10000+(i+1)*D-1, j, k, coi);
			}	
        }
    }    
}





int main()
{

    char* nom_comando = new char[50];
    char* str1 = new char [50];
    char* str2 = new char [50];
    char* str3 = new char [50];
    char* str4 = new char [50];
    int int1, int2, int3;
    Continente cont;


    
    Estructura * micoi =  crearCOI();
    
    bool fin = false, stress = false, destruir = false;
    while(!fin)
    {
        scanf ("%s", nom_comando);

        if(strcmp(nom_comando, "altaPais") == 0)
        {
            leerParametro (str1);  // nombre 
            scanf ("%s", str3);  // continente
            leerParametro (str2);  // idioma
            if ( strcmp(str3, "AMERICA") == 0 )
                cont = AMERICA;
            else if ( strcmp(str3, "EUROPA") == 0 )
                cont = EUROPA;    
            else if ( strcmp(str3, "ASIA") == 0 )
                cont = ASIA;    
            else if ( strcmp(str3, "AFRICA") == 0 )
                cont = AFRICA;    
            else if ( strcmp(str3, "OCEANIA") == 0 )
                cont = OCEANIA;
            else
			    perror ("altaPais: continente no valido.");
            altaPais (str1, cont, str2, micoi);
        }
        else if(strcmp(nom_comando, "altaFederacion") == 0)
        {
            leerParametro (str1);  // pais 
            leerParametro (str2);  // federacion
            leerParametro (str3);  // descripcion
            scanf ("%d", &int1); // dia
			if (int1 < 1 || int1 > 31) perror ("altaFederacion: dia no valido.");
            scanf ("%d", &int2); // mes
			if (int2 < 1 || int2 > 12) perror ("altaFederacion: mes no valido.");
            scanf ("%d", &int3); // anio
            altaFederacion (str1, str2, str3, int1, int2, int3, micoi);
        }
        else if(strcmp(nom_comando, "altaCampeonatoFederacion") == 0)
        {
            leerParametro (str1);  // pais 
            leerParametro (str2);  // federacion
            leerParametro (str3);  // campeonato
            leerParametro (str4);  // descripcion
            scanf ("%d", &int1); // importancia
            altaCampeonatoFederacion(str1, str2, str3, str4, int1, micoi);
        }
        else if(strcmp(nom_comando, "altaDeportista") == 0)
        {
            leerParametro (str1);  // pais 
            scanf ("%d", &int1); // codigo
			if (int1 < 0) perror ("altaDeportista: codigo no valido.");
            leerParametro (str2);  // nombre
            leerParametro (str3);  // apellido
            scanf ("%d", &int2); // edad
			if (int2 < 0) perror ("altaDeportista: edad no valida.");
            altaDeportista (str1, int1, str2, str3, int2, micoi);
        }
        else if(strcmp(nom_comando, "imprimirFederaciones") == 0)
        {
            leerParametro (str1);  // pais 
            imprimirFederaciones (str1, micoi);
        }
        else if(strcmp(nom_comando, "inscribirDeportistaCampeonato") == 0)
        {
            leerParametro (str1);  // pais 
            leerParametro (str2);  // federacion
            leerParametro (str3);  // campeonato
            scanf ("%d", &int1); // codigo
			if (int1 < 0) perror ("inscribirDeportistaCampeonato: codigo no valido.");
            scanf ("%d", &int2); // mes
			if (int2 < 1 || int2 > 12) perror ("inscribirDeportistaCampeonato: mes no valido.");
            scanf ("%d", &int3); // dia
			if (int3 < 1 || int3 > 31) perror ("inscribirDeportistaCampeonato: dia no valido.");
            inscribirDeportistaCampeonato (str1, str2, str3, int1, int2, int3, micoi);
        }
        else if(strcmp(nom_comando, "obtenerCantidadPaises") == 0)
        {
            printf ("%d\n", obtenerCantidadPaises (micoi));
        }
        else if(strcmp(nom_comando, "existeCampeonatoFederacion") == 0)
        {
            leerParametro (str1);  // pais 
            leerParametro (str2);  // federacion
            leerParametro (str3);  // campeonato
            if (existeCampeonatoFederacion (str1, str2, str3, micoi))
                printf ("Existe\n");
            else
                printf ("No existe\n");
        }
        else if(strcmp(nom_comando, "imprimirFederados") == 0)
        {
            leerParametro (str1);  // pais 
            leerParametro (str2);  // federacion
            printf("---Federados---\n");
            imprimirFederados (str1, str2, micoi);
            printf("------\n");
        }
        else if(strcmp(nom_comando, "imprimirCampeonatosDeportista") == 0)
        {
            scanf ("%d", &int1); // codigo
            imprimirCampeonatosDeportista (micoi, int1);
        }
        else if(strcmp(nom_comando, "salir") == 0)
        {
            fin = true;
        }
        else if(strcmp(nom_comando, "stress") == 0)
        {
            fin = true;
            stress = true;
        }
        else if(strcmp(nom_comando, "destruir") == 0)
        {
            scanf ("%d", &int1); // cantidad de iteraciones
			if (int1 < 1) perror ("destruir: cantidad no valida.");
            fin = true;
            destruir = true;
        }
        else
        {
            scanf ("%*[^\n]");
        }
    }

    delete [] nom_comando;
    delete [] str1;
    delete [] str2;
    delete [] str3;
    delete [] str4;
    destruirCOI (micoi);

    
    if (stress)
    {
		char sufijo[5], nombreP [10], nombreF [10]; 
		int i, j;

		micoi =  crearCOI();
        dar_altas (micoi);

		for (i = 0; i < P; i++)
		{
			sprintf (sufijo, "%d", i);
			strcpy (nombreP,"pais");
			strcat (nombreP, sufijo);
			imprimirFederaciones (nombreP, micoi);
			
			imprimirCampeonatosDeportista (micoi, 10000 + (i+1)*D - 1);
			
			for (j = 0; j < F; j++)
			{
				strcpy (nombreF,"fede");
				nombreF [4] = 48+j; 
				nombreF [5] = 122-j; 
				nombreF [6] = 0; 
				printf("---Federados---\n");
				imprimirFederados (nombreP, nombreF, micoi);
				printf("------\n");
			}
			
		}
        destruirCOI (micoi);
    }
    
    if (destruir) 
    {
        int i;
        for (i =0; i < int1; i++)
        {
            micoi =  crearCOI();
            dar_altas (micoi);
            destruirCOI (micoi);
        }
        printf ("OK. Prueba terminada.\n");
    }
    
    return 0;
}
