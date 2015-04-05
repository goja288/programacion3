/* Version 0.1 */


#ifndef UTILS_H
#define UTILS_H

/* Si la solucion es valida imprime en la salida estandar la cantidad de parejas formadas y  el Q, 
en otro caso imprime que la solucion no es valida. */
void
controlar_solucion (Cliente** C1, int cantC1, Cliente** C2, int cantC2, 
					Pareja** parejas, int cant_parejas, Criterio cr, bool flexible,
					int M, int Lm1, int LM1, int Lm2, int LM2);


#endif /* UTILS_H */
