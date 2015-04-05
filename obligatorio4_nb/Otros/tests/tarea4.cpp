#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buscoamor.h"
#include "utils.h"


char *
cabello2str (ColorC c)
{
	if (c == CASTANO)
		return (char *) "CASTANO";
	else if (c == RUBIO)
		return (char*) "RUBIO";
	else if (c == MOROCHO)
		return (char*) "MOROCHO";
	else
		return (char*) "ROJO";
}

char *
ojos2str (ColorO c)
{
	if (c == MARRON)
		return (char*) "MARRON";
	else if (c == VERDE)
		return (char*) "VERDE";
	else if (c == AZUL)
		return (char*) "AZUL";
	else if (c == NEGRO)
		return (char*) "NEGRO";
	else
		return (char*) "GRIS";
}


void
imprimir_parejas (Pareja **parejas, int cant_parejas)
{
	for (int i = 0; i < cant_parejas; i++)
		printf ( "%d %d %d %d %s %s %d %d %d %s %s - %d %d %d %d %s %s %d %d %d %s %s\n",
			parejas[i]->cliente1->E, parejas[i]->cliente1->P_A, parejas[i]->cliente1->P_I, parejas[i]->cliente1->P_S, 
			cabello2str (parejas[i]->cliente1->P_H), ojos2str (parejas[i]->cliente1->P_O), 
			parejas[i]->cliente1->B_A, parejas[i]->cliente1->B_I, parejas[i]->cliente1->B_S,
			cabello2str (parejas[i]->cliente1->B_H), ojos2str (parejas[i]->cliente1->B_O), 
			parejas[i]->cliente2->E, parejas[i]->cliente2->P_A, parejas[i]->cliente2->P_I, parejas[i]->cliente2->P_S,
			cabello2str (parejas[i]->cliente2->P_H), ojos2str (parejas[i]->cliente2->P_O),
			parejas[i]->cliente2->B_A, parejas[i]->cliente2->B_I, parejas[i]->cliente2->B_S,
			cabello2str (parejas[i]->cliente2->B_H), ojos2str (parejas[i]->cliente2->B_O)); 
}




ColorC
str2cabello (char * param)
{
	ColorC result;
	if (strcmp ("CASTANO", param) == 0)
		result = CASTANO;
	else if (strcmp ("RUBIO", param) == 0)
		result = RUBIO;
	else if (strcmp ("MOROCHO", param) == 0)
		result = MOROCHO;
	else if (strcmp ("ROJO", param) == 0)
		result = ROJO;
	else 
		printf ("Cabello no valido. \n"); 
	return result;
}


ColorO
str2ojos (char * param)
{
	ColorO result;
	if (strcmp ("MARRON", param) == 0)
		result = MARRON;
	else if (strcmp ("VERDE", param) == 0)
		result = VERDE;
	else if (strcmp ("AZUL", param) == 0)
		result = AZUL;
	else if (strcmp ("NEGRO", param) == 0)
		result = NEGRO;
	else if (strcmp ("GRIS", param) == 0)
		result = GRIS;
	else 
		printf ("Ojos no valido. \n");
	return result;
}



/* Retorna true si el atributo de tipo Apariencia, Inteligencia o Simpatia esta entre 1 y 10 , 
 y false  en caso contrario. */  
bool ais_valido (int atributo)
{
	return (atributo >=0) && (atributo <= 10); 
}

void leer_cliente (Cliente & c)
{
	char str_param [10];

	scanf ("%d", &c.E);
	if (c.E < 0) printf ("Edad no valida\n");

	scanf ("%d", &c.P_A);
	if (! ais_valido (c.P_A)) printf ("Apariencia no valida\n");
	scanf ("%d", &c.P_I);
	if (! ais_valido (c.P_I)) printf ("Inteligencia no valida\n");
	scanf ("%d", &c.P_S);
	if (! ais_valido (c.P_S)) printf ("Simpatia no valida\n");
	scanf ("%s", str_param);
	c.P_H = str2cabello (str_param);
	scanf ("%s", str_param);
	c.P_O = str2ojos (str_param);
	
	scanf ("%d", &c.B_A);
	if (! ais_valido (c.B_A)) printf ("Apariencia no valida\n");
	scanf ("%d", &c.B_I);
	if (! ais_valido (c.B_I)) printf ("Inteligencia no valida\n");
	scanf ("%d", &c.B_S);
	if (! ais_valido (c.B_S)) printf ("Simpatia no valida\n");
	scanf ("%s", str_param);
	c.B_H = str2cabello (str_param);
	scanf ("%s", str_param);
	c.B_O = str2ojos (str_param);
}










int
main ()
{

	char str_param [10];

	int cant1, cant2;
	Criterio cr;
	bool cabalas;
	int M;
	int Lm1, LM1, Lm2, LM2;
	
	scanf ("%d", &cant1);
	scanf ("%d", &cant2);
	scanf ("%s", str_param);
	if ( strcmp ("CLASICO", str_param ) == 0 )
		cr = CLASICO;
	else if ( strcmp ("OPUESTOS", str_param ) == 0 )
		cr = OPUESTOS;
	else
		printf ("Criterio no valido.\n");
	
	scanf ("%s", str_param);
	if ( strcmp ("false", str_param ) == 0 )
		cabalas = false;
	else if ( strcmp ("true", str_param ) == 0 )
		cabalas = true;
	else
		printf ("Cabala no valida.\n");

	scanf ("%d", &M);
	if (M < 0) printf ("Penalizacion no valida.\n");
	scanf ("%d", &Lm1);
	if (Lm1 < 0) printf ("Limite no valido.\n");
	scanf ("%d", &LM1);
	if (LM1 < 0) printf ("Limite no valido.\n");
	scanf ("%d", &Lm2);
	if (Lm2 < 0) printf ("Limite no valido.\n");
	scanf ("%d", &LM2);
	if (LM2 < 0) printf ("Limite no valido.\n");

	Cliente **C1 = (Cliente**) malloc (sizeof (Cliente*) * cant1);
	Cliente **C2 = (Cliente**) malloc (sizeof (Cliente*) * cant2);
	
	int i;
	for (i = 0; i < cant1; i++)
	{
		C1[i] = (Cliente*) malloc (sizeof (Cliente));
		leer_cliente (*C1[i]);
	}
	for (i = 0; i < cant2; i++)
	{
		C2[i] = (Cliente*) malloc (sizeof (Cliente));
		leer_cliente (*C2[i]);
	}
	
	int cant_parejas = 0;
	
	Pareja** parejas =
	formarParejas(C1, cant1, C2, cant2, cant_parejas, cr, cabalas,
		M,  Lm1, LM1, Lm2, LM2);

//	imprimir_parejas (parejas, cant_parejas);

	
	controlar_solucion (C1, cant1, C2, cant2,
		parejas, cant_parejas, cr, cabalas,
		M,  Lm1, LM1, Lm2, LM2);
	
	
}
