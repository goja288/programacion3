#include"ListaEnteros.h"
#include"Mundo.h"
#include"ColaEnteros.h"
#include"Estrategias.h"
#include"Territorio.h"
#include<stdio.h>

int imprimirMundo(Mundo* m,int tope)
{
	ListaEnteros* aux;
	for(int k=0; k<tope; k++)
	{
		printf("(( %d )||-->",k);
		aux=obtenerVecinosTerritorioMundo(m,k);
		while(!esVaciaListaEnteros(aux))
		{
			printf(">>>| %d  |>",primeroListaEnteros(aux));
			aux=restoListaEnteros(aux);
		}
		printf(">>NULL\n\n");
	}
        return 0;
}

void armar(Mundo* m ,int tope)
{
	for(int i=0; i<tope; i++)
	{
		for(int j=0; j<tope; j++)
		{
			if ( (i!=j) && (! sonVecinosMundo(m,i,j)) )
				hacerVecinosTerritorios(m,i,j);
		}
	}
}

void construirMundo(Mundo* m)
{
	asignarNombreTerritorio(obtenerTerritorioMundo(m,0),"Territorio_0");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,0), "Comunidad_0");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,1),"Territorio_1");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,1), "Comunidad_1");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,2),"Territorio_2");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,2), "Comunidad_2");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,3),"Territorio_3");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,3), "Comunidad_3");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,4),"Territorio_4");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,4), "Comunidad_4");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,5),"Territorio_5");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,5), "Comunidad_5");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,6),"Territorio_6");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,6), "Comunidad_6");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,7),"Territorio_7");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,7), "Comunidad_7");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,8),"Territorio_8");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,8), "Comunidad_8");
	
	/*asignarNombreTerritorio(obtenerTerritorioMundo(m,9),"Territorio_9");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,9), "Comunidad_9");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,10),"Territorio_10");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,10), "Comunidad_10");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,11),"Territorio_11");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,11), "Comunidad_11");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,12),"Territorio_12");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,12), "Comunidad_12");

	asignarNombreTerritorio(obtenerTerritorioMundo(m,13),"Territorio_13");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,13), "Comunidad_13");

	asignarNombreTerritorio(obtenerTerritorioMundo(m,14),"Territorio_14");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,14), "Comunidad_14");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,15),"Territorio_15");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,15), "Comunidad_15");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,16),"Territorio_16");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,16), "Comunidad_16");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,17),"Territorio_17");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,17), "Comunidad_17");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,18),"Territorio_18");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,18), "Comunidad_18");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,19),"Territorio_19");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,19), "Comunidad_19");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,20),"Territorio_20");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,20), "Comunidad_20");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,21),"Territorio_21");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,21), "Comunidad_21");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,22),"Territorio_22");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,22), "Comunidad_22");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,23),"Territorio_23");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,23), "Comunidad_23");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,24),"Territorio_24");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,24), "Comunidad_24");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,25),"Territorio_25");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,25), "Comunidad_25");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,26),"Territorio_26");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,26), "Comunidad_26");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,27),"Territorio_27");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,27), "Comunidad_27");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,28),"Territorio_28");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,28), "Comunidad_28");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,29),"Territorio_29");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,29), "Comunidad_29");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,30),"Territorio_30");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,30), "Comunidad_30");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,31),"Territorio_41");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,31), "Comunidad_41");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,32),"Territorio_42");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,32), "Comunidad_42");

	asignarNombreTerritorio(obtenerTerritorioMundo(m,33),"Territorio_43");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,33), "Comunidad_43");

	asignarNombreTerritorio(obtenerTerritorioMundo(m,34),"Territorio_44");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,34), "Comunidad_44");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,35),"Territorio_45");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,35), "Comunidad_45");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,36),"Territorio_46");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,36), "Comunidad_46");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,37),"Territorio_47");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,37), "Comunidad_47");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,38),"Territorio_48");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,38), "Comunidad_48");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,39),"Territorio_49");
	asignarNombreTerritorio(obtenerTerritorioMundo(m,39), "Comunidad_49");
	*/
}

int main()
{

	Mundo*m=crearMundo(9);
	
	printf("ASIGNAR TERRITORIOS Y COMUNIDADES\n\n");
	
	construirMundo(m);
	
	for(int i=0; i<9; i++)
	{
		printf("Territorio%d: nombre-> %s | ",i,obtenerNombreTerritorio(obtenerTerritorioMundo(m,i)));
		printf("comunidad-> %s ||\n",obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i)));
	}
	printf("\nESTRUCTURA=>\n");
	
	imprimirMundo(m,9);
	
	printf("\nCREAR VECINOS\n\n");
	
	armar(m,9);
	
	imprimirMundo(m,9);
	
	printf("\nPAVIMENTAR\n\n");
	
	Mundo* m2=proyectoDePavimentacion(m);
	
	imprimirMundo(m2,9);
	
	destruirMundo(m2);
	destruirMundo(m);
		
	m=crearMundo(8);
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,0),"Territorio_0");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,0), "Comunidad_0");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,1),"Territorio_1");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,1), "Comunidad_1");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,2),"Territorio_2");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,2), "Comunidad_2");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,3),"Territorio_3");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,3), "Comunidad_3");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,4),"Territorio_4");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,4), "Comunidad_4");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,5),"Territorio_5");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,5), "Comunidad_5");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,6),"Territorio_6");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,6), "Comunidad_6");
	
	asignarNombreTerritorio(obtenerTerritorioMundo(m,7),"Territorio_7");
	asignarComunidadTerritorio(obtenerTerritorioMundo(m,7), "Comunidad_7");
	
	for(int i=0; i<8; i++)
	{
		printf("Territorio%d: nombre-> %s | ",i,obtenerNombreTerritorio(obtenerTerritorioMundo(m,i)));
		printf("comunidad-> %s ||\n",obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i)));
	}
	printf("\n");
	hacerVecinosTerritorios(m,0,1);
	hacerVecinosTerritorios(m,0,2);
	hacerVecinosTerritorios(m,0,3);
	hacerVecinosTerritorios(m,1,2);
	hacerVecinosTerritorios(m,1,4);
	hacerVecinosTerritorios(m,1,5);
	hacerVecinosTerritorios(m,2,5);
	hacerVecinosTerritorios(m,3,6);
	hacerVecinosTerritorios(m,3,7);
	hacerVecinosTerritorios(m,4,5);
	hacerVecinosTerritorios(m,6,7);
	
	printf("\n-----------------	ARBOL PARA PROBAR 	------------------\n");
	imprimirMundo(m,8);
	printf("\n-----------------                     ------------------\n");
	
	printf("\n------------------ CAMINO MAS CORTO --------------------\n");
	
	Camino* cam;
	for(int i=0; i<8 ;i++){
		for(int j=0; j<8 ;j++){
			for(int k=0; k<8 ; k++){
				if(i!=j){									//si todas las comunidades de i,j,k son distintas
					if(!esComunidadTerritorio(obtenerTerritorioMundo(m,i),obtenerComunidadTerritorio(obtenerTerritorioMundo(m,j)))){
						if(!esComunidadTerritorio(obtenerTerritorioMundo(m,i),obtenerComunidadTerritorio(obtenerTerritorioMundo(m,k)))){
							if(!esComunidadTerritorio(obtenerTerritorioMundo(m,j),obtenerComunidadTerritorio(obtenerTerritorioMundo(m,k)))){
								cam=caminoMasCorto(m,i,j,obtenerComunidadTerritorio(obtenerTerritorioMundo(m,k)));
								printf("caminoMasCorto(m,%d,%d,Comunidad_%d):\n",i,j,k);
								printf("	LARGO DEL CAMINO = %d\n		",cam->largo);
								if(cam->largo!=0){
									for(int k=0; k<cam->largo;k++)
									{	
										printf("| %d |",(cam->territorios)[k]);
									}		
								}
								else
									printf("NO HAY CAMINO\n");
									printf("\n\n");
								delete[] cam->territorios;
								delete cam;
							}
						}
					}
				}
			}
		}
	}
	
	printf("\n--------------------------------------------------------\n");
/*
	
	printf("\n\n---------- MEDIADOR ----------\n\n");
	printf("\n#####################\n");
	printf("el mediador entre 0 y 7 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_0","Comunidad_7"));
	printf("el mediador entre 0 y 6 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_0","Comunidad_6"));
	printf("el mediador entre 1 y 6 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_1","Comunidad_6"));
	printf("el mediador entre 2 y 6 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_2","Comunidad_6"));
	printf("el mediador entre 0 y 1 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_0","Comunidad_1"));//NO HAY
	printf("el mediador entre 6 y 4 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_6","Comunidad_4"));
	printf("el mediador entre 6 y 7 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_6","Comunidad_7"));
	printf("el mediador entre 3 y 4 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_3","Comunidad_4"));
	printf("el mediador entre 5 y 3 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_5","Comunidad_3"));
	printf("el mediador entre 1 y 5 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_1","Comunidad_5"));
	printf("el mediador entre 2 y 4 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_2","Comunidad_4"));	
	printf("el mediador entre 0 y 4 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_0","Comunidad_4"));
	printf("el mediador entre 3 y 1 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_3","Comunidad_1"));
	printf("el mediador entre 3 y 5 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_3","Comunidad_5"));
	printf("el mediador entre 3 y 2 es: ");
	printf("%d\n",territorioDelMediador(m,"Comunidad_3","Comunidad_2"));
*/
	
	int mediador;
	for(int i=0; i<8 ; i++){
		for(int j=0; j<8 ; j++){
			if(i!=j){
				printf("MEDIADOR ENTRE Comunidad_%d y Comunidad_%d: ",i,j);
				mediador= territorioDelMediador(m,obtenerComunidadTerritorio(obtenerTerritorioMundo(m,i)),obtenerComunidadTerritorio(obtenerTerritorioMundo(m,j)));
				if(mediador != -1)
					printf("%d\n",mediador);
				else
					printf("NO_HAY_MEDIADOR\n");
			}
		}
	}
	
	
	printf("\n#####################\n");
	


	return 0;
}

