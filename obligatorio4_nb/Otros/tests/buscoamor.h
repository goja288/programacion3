/* Version 1.1 */

#ifndef BUSCOAMOR_H
#define BUSCOAMOR_H

enum ColorC {CASTANO, RUBIO, MOROCHO, ROJO};
enum ColorO {MARRON, VERDE, AZUL, NEGRO, GRIS};

struct Cliente{

	int E; //Edad

	//Atributos propios del cliente
	int P_A; //Apariencia
	int P_I; //Inteligencia
	int P_S; //Simpatia
	ColorC P_H; //Color de pelo
	ColorO P_O; //Color de ojos


	//Atributos de la persona buscada por el cliente
	int B_A; //Apariencia
	int B_I; //Inteligencia
	int B_S; //Simpatia
	ColorC B_H; //Color de pelo
	ColorO B_O; //Color de ojos
};


struct Pareja{
	Cliente* cliente1;
	Cliente* cliente2;
};



enum Criterio{CLASICO, OPUESTOS};


Pareja** formarParejas(Cliente** C1, int cantC1, Cliente** C2, int cantC2, 
	int& cantParejas, Criterio cr, bool cabalas, int M, int Lm1, int LM1, int Lm2, int LM2);
// C1 y C2 son conjuntos de clientes.
// cantC1 = |C1| , cantC2 = |C2|
// CantParejas indica la cantidad de parejas formadas que se retornan.
// Criterio indica si se desea usar el criterio clasico o el de los opuestos.
// cabalas indica si se van a flexibilizar las cabalas, en caso que sea "true", 
//    M es el valor de penalizacion.
// Lm1, LM1, Lm2, LM2 limites para la diferencia de edad permitida en una pareja
// Retorna: Las parejas formadas de clientes, donde cada cliente de las parejas es un alias a un cliente en C1 o en C2.



#endif /* BUSCOAMOR_H */


