#include <cstdlib>
#include <stdio.h>
#include "buscoamor.h"

const int cantCX            = 4;
const int cantCY            = 3;

int x_apariencia[cantCX]    = {9, 4, 2, 9};
int x_inteligencia[cantCX]  = {9, 9, 7, 3};
int x_simpatia[cantCX]      = {9, 5, 2, 3};
ColorC x_pelo[cantCX]       = {CASTANO, RUBIO, MOROCHO, ROJO};
ColorO x_ojos[cantCX]       = {MARRON, VERDE, AZUL, NEGRO};
int x_aparienciab[cantCX]   = {9, 4, 2, 9};
int x_inteligenciab[cantCX] = {9, 9, 7, 3};
int x_simpatiab[cantCX]     = {9, 5, 2, 3};
ColorC x_pelob[cantCX]      = {CASTANO, RUBIO, MOROCHO, ROJO};
ColorO x_ojosb[cantCX]      = {MARRON, VERDE, AZUL, NEGRO};

int y_apariencia[cantCY]    = {0, 2, 4};
int y_inteligencia[cantCY]  = {0, 7, 9};
int y_simpatia[cantCY]      = {0, 2, 5};
ColorC y_pelo[cantCY]       = {CASTANO, MOROCHO, RUBIO};
ColorO y_ojos[cantCY]       = {MARRON, AZUL, VERDE};
int y_aparienciab[cantCY]   = {0, 2, 4};
int y_inteligenciab[cantCY] = {0, 7, 9};
int y_simpatiab[cantCY]     = {0, 2, 5};
ColorC y_pelob[cantCY]      = {CASTANO, MOROCHO, RUBIO};
ColorO y_ojosb[cantCY]      = {MARRON, AZUL, VERDE};

void
imprimirParejas (Pareja** parejas, int cantParejas) {
    printf("\n Se formaron %i parejas: \n", cantParejas);
    for (int i = 0; i < cantParejas; i++) {
        printf("Pareja del cliente %i ---> %i \n", parejas[i]->cliente1->id, parejas[i]->cliente2->id);
    }
}

int
main () {
    Cliente** CX = new Cliente*[cantCX];
    for (int i=0; i < cantCX; i++) {
        Cliente* c = new Cliente;
        c->E = 30;
        c->id = i;
        c->P_A = x_apariencia[i];
        c->P_I = x_inteligencia[i];
        c->P_S = x_simpatia[i];
        c->P_H = x_pelo[i];
        c->P_O = x_ojos[i];
        c->B_A = x_aparienciab[i];
        c->B_I = x_inteligenciab[i];
        c->B_S = x_simpatiab[i];
        c->B_H = x_pelob[i];
        c->B_O = x_ojosb[i];
        CX[i] = c;
    }
    Cliente** CY = new Cliente*[cantCY];
    for (int i=0; i < cantCY; i++) {
        Cliente* c0 = new Cliente;
        c0->E = 30;
        c0->id = 10-i;
        c0->P_A = y_apariencia[i];
        c0->P_I = y_inteligencia[i];
        c0->P_S = y_simpatia[i];
        c0->P_H = y_pelo[i];
        c0->P_O = y_ojos[i];
        c0->B_A = y_aparienciab[i];
        c0->B_I = y_inteligenciab[i];
        c0->B_S = y_simpatiab[i];
        c0->B_H = y_pelob[i];
        c0->B_O = y_ojosb[i];
        CY[i] = c0;
    }
    
    int cantParejas   = 0;
    Criterio cr       = CLASICO;
    bool cabalas      = false;
    int  penalizacion = 5;
    int Lm1 = 2;
    int LM1 = 10;
    int Lm2 = 4;
    int LM2 = 6;
    Pareja** resultado = formarParejas(CY, cantCY, CX, cantCX, cantParejas, cr, cabalas, penalizacion, Lm1, LM1, Lm2, LM2);

    imprimirParejas(resultado,cantParejas);

    for (int i = 0; i < cantCX; i++) {
        Cliente* cliente;
        cliente = CX[i];
        //delete[] cliente->name; valgrind dijo q no!
        delete(cliente);
    }
    for (int i = 0; i < cantCY; i++) {
        Cliente* cliente;
        cliente = CY[i];
        //delete[] cliente->name; valgrind dijo q no!
        delete(cliente);
    }
    for (int i = 0; i < cantParejas; i++) {
        delete[] resultado[i];
    }
    delete[] resultado; // se borran parejas, pero no los clientes de adentro xq ya fueron eliminados
    delete[] CX;
    delete[] CY;
    return 0;
}

