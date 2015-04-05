/* 4309187 4666259 4201206 */
/* Version 1.1 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "buscoamor.h"

struct Compatibilidad {
        int* indices;
        int  cantidad; //tope + 1
};

struct Solucion {
    Cliente** tupla;
    int sumaQ, cantParejas;
};

// funcion que devuelve true(1) si cumple la restricciones de las edades
// @param
// @return bool
bool
cumpleRestriccionEdad (Cliente* c1,Cliente* c2, int Lm1,int LM1, int Lm2, int LM2) {
    bool restriccion = 0;
    if ( (((c1->E)-Lm1) < (c2->E)) &&
         ((c2->E) < ((c1->E)+LM1)) &&
         (((c2->E)-Lm2) < (c1->E)) &&
         ((c1->E < ((c2->E)+LM2))) )
    {
        restriccion = 1;
    }

    return restriccion;

} // cumpleRestriccionEdad

bool
cumpleConCabalas (Cliente* c1, Cliente* c2) {
    if ( ((c1->B_H != c2->P_H) && (c1->B_O != c2->P_O))
         ||
         ((c2->B_H != c1->P_H) && (c2->B_O != c1->P_O)) )
    {
        return false;
    }
    return true;
}

// funcion para aplicar la penalizacion
// @param
// @return int
int
penalizarPareja (Cliente* c1, Cliente* c2,int Q, int M, Criterio cr) {

    int penalizacion = 0;
    if (!cumpleConCabalas(c1, c2)) {
        if (cr == OPUESTOS)
			penalizacion = -M;
		else
			penalizacion = M;
    }

    return (Q+penalizacion);

} // penalizarPareja

// funcion que calcula el indice Q entre 2 clientes
// @param
// @return int
int
obtenerQ (Cliente* c1, Cliente* c2, bool cabalas, int M, Criterio cr) {
    int D1 = abs((c1->B_A)-(c2->P_A)) + abs((c1->B_I)-(c2->P_I)) + abs((c1->B_S)-(c2->P_S));
    int D2 = abs((c2->B_A)-(c1->P_A)) + abs((c2->B_I)-(c1->P_I)) + abs((c2->B_S)-(c1->P_S));
    
    //printf ("El Q de %i con %i vale: %i\n\n", c1->id, c2->id, (D1+D2));
    int q = (D1 + D2);
    if (cabalas) {
        q = penalizarPareja(c1, c2, q, M, cr);
    }
    return q;
} //obtenerQ

Compatibilidad*
indicesCandidatos (Cliente* cliente1, bool* asignados, Cliente** C2, int cantC2,
                        bool cabalas, int Lm1, int LM1, int Lm2, int LM2) {
    int* indices = new int[cantC2 + 1]; //No hace falta inicializar porque usa tope
    int cantidad = 0;
    for (int j = 0; j < cantC2; j++) {
        if (asignados[j] == false) {         // AND Otros criterios de poda
            bool cumpleCabalas = true;
            if (!cabalas) {
                cumpleCabalas = cumpleConCabalas(cliente1, C2[j]);
            }
            if ((cumpleCabalas) && (cumpleRestriccionEdad(cliente1, C2[j], Lm1, LM1, Lm2, LM2))) {
                indices[cantidad] = j;
                cantidad++;
            }
        }
    }
    indices[cantidad] = cantC2;
    cantidad++;
    Compatibilidad* resultado = new Compatibilidad;
    resultado->indices  = indices;
    resultado->cantidad = cantidad;
    return resultado;
};

bool
esMejorSolucion(Solucion* s_actual, Solucion* s_posible, Criterio cr) {
    bool es_mejor = 0;
    if ( s_actual->cantParejas < s_posible->cantParejas ) { // mejoro la cantidad de parejas
        es_mejor = 1;
    }
    // me fijo en el Q
    else if ( (s_actual->cantParejas == s_posible->cantParejas) 
                &&
                (((cr == CLASICO) && (s_actual->sumaQ > s_posible->sumaQ)) 
                        ||
                ((cr == OPUESTOS) && (s_actual->sumaQ < s_posible->sumaQ))) ) 
    {
        es_mejor = 1;
    }
    
    return es_mejor;

} //esMejorSolucion

void
DFS (Solucion* solParcial, Cliente** C1, int cantC1, int posC1, bool* asignados,
                        Cliente** C2, int cantC2, Criterio cr, bool cabalas, int M,
                                        int Lm1, int LM1, int Lm2, int LM2, Solucion* &sol) {
    if (posC1 + 1 < cantC1) {
        int prox = posC1 + 1;
        Compatibilidad* candidatos = indicesCandidatos(C1[prox], asignados, C2, cantC2,cabalas, Lm1, LM1, Lm2, LM2);
                //imprimirCandidatos(candidatos, cantC2); //para debug
                //imprimirAsignados(asignados, cantC2); //para debug
        for (int j = 0; j < candidatos->cantidad; j++) {
            int posC2     = candidatos->indices[j];
            solParcial->tupla[prox]   = NULL;
            bool estaEnC2 = (posC2 < cantC2);
            if (estaEnC2) {
                solParcial->cantParejas++;
                solParcial->sumaQ       = solParcial->sumaQ + obtenerQ(C1[prox], C2[posC2], cabalas, M, cr);;
                solParcial->tupla[prox] = C2[posC2];
                asignados[posC2]        = true;
            }
            DFS(solParcial, C1, cantC1, prox, asignados, C2, cantC2, cr, cabalas, M, Lm1, LM1, Lm2, LM2, sol);
            if(estaEnC2) {
                solParcial->cantParejas--;
                solParcial->sumaQ = solParcial->sumaQ - obtenerQ(C1[prox], C2[posC2], cabalas, M, cr);
                asignados[posC2]  = false;
            }
        }
        delete[] candidatos->indices;
        delete(candidatos);
    }
    else {
        if (esMejorSolucion(sol,solParcial,cr)) {
                sol->cantParejas = solParcial->cantParejas;
                sol->sumaQ       = solParcial->sumaQ;
                for (int i = 0; i < cantC1; i++) {
                    sol->tupla[i] = solParcial->tupla[i];
                }
        }
    }
}

Pareja**
formarParejas (Cliente** C1, int cantC1, Cliente** C2, int cantC2, int& cantParejas,
                        Criterio cr, bool cabalas, int M, int Lm1, int LM1, int Lm2, int LM2) {
    bool* asignados = new bool[cantC2 + 1];
    for (int i = 0; i < cantC2 + 1; i++) {
        asignados[i] = false;
    };
    Solucion* solParcial    = new Solucion;
    solParcial->tupla       = new Cliente*[cantC1];
    solParcial->cantParejas = 0;
    solParcial->sumaQ       = 0;

    Solucion* sol           = new Solucion;
    sol->tupla              = new Cliente*[cantC1];
    sol->cantParejas        = 0;
    sol->sumaQ              = 0;

    DFS(solParcial, C1, cantC1, -1, asignados, C2, cantC2, cr, cabalas, M, Lm1, LM1, Lm2, LM2, sol);

    delete[] asignados;

    delete[] solParcial->tupla;
    delete(solParcial);

    Pareja** resultado = new Pareja*[sol->cantParejas];
    int cont = 0; 
    for (int i = 0; i < cantC1; i++) {
        if (sol->tupla[i] != NULL) {
            Pareja* pareja   = new Pareja;
            pareja->cliente1 = C1[i];
            pareja->cliente2 = sol->tupla[i];
            resultado[cont]  = pareja;
            cont++;
        }
    }
    cantParejas = sol->cantParejas;
    delete[] sol->tupla;
    delete(sol);
    return resultado;
}

