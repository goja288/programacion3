#ifndef ESTRUCTURA_H#define ESTRUCTURA_H#define P 100	/* Cantidad de paises */#define F 50	/* Cantidad de federaciones de un pais */#define C 20	/* Cantidad de campeonatos de una federacion */#define D 200	/* Cantidad de deportistas de un pais */struct Estructura;enum Continente {AMERICA, EUROPA, ASIA, AFRICA, OCEANIA};Estructura* crearCOI();//Crea la estructura de datos vacia.void altaPais(const char* nombrePais, Continente continente, 			  const char* idioma, Estructura* E);// Esta operacion debe realizarse en O(1) promedio.// Pre: nombrePais != NULL, continente != NULL, idioma!=NULL.// Pre: la estructura fue creada previamente.// Pre: el pais de nombre "nombrePais" no pertenece a la estructura E.void altaFederacion(const char* nombrePais, 					const char* nombreFederacion,					const char* dscFederacion, 					int diaCreacion,					int mesCreacion, 					int anioCreacion, 					Estructura* E);//Pre: nombrePais !=NULL, nombreFederacion!=NULL, dscFederacion!=NULL//Pre: diaCreacion, mesCreacion y anioCreacion forman una fecha valida//Pre: la estructura E fue creada previamente.//Pre: El pais de nombre nombrePais pertenece a la estructura E.//Pre: El pais de nombre nombrePais no tiene una federacion de nombre //     nombreFederacion al momento de agregar la nueva federacion.void altaCampeonatoFederacion (const char* nombrePais, 							   const char* nombreFederacion, 							   const char* nombreCampeonato, 							   const char* dscCampeonato, 							   int importancia, 							   Estructura* E);							  // Pre: nombrePais !=NULL, nombreFederacion!=NULL, nombreCampeonato!=NULL,// Pre: dscCampeonato !=NULL// Pre: la estructura E fue creada previamente// El pais de nombre nombrePais pertenece a la estructura E.// La federacion de nombre nombreFederacion del pais de nombre nombrePais // pertenece a la estructura E.// La federacion de nombre nombreFederacion del pais de nombre nombrePais// no tiene un campeonato registrado de nombre nombreCampeonato al momento de agregar el nuevo campeonato.void altaDeportista (const char* paisDeportista, 				     int codigoCOI,					 const char* nombreDeportista,					 const char* apellidoDeportista, 					 int edadDeportista, 					 Estructura* E);// Pre: paisDeportista!=NULL, nombreDeportista!=NULL,// Pre: apellidoDeportista!=NULL// Pre: la estructura E fue previamente creada.// Pre: No existe un deportista con codigo codigoCOI en la estructura E.// Pre: El pais de nombre paisDeportista pertenece a la estructura E.					 void imprimirFederaciones(const char* nombrePais, Estructura* E);	//Pre: nombrePais != NULL//Pre: la estructura E fue previamente creada.//Pre: El pais de nombre nombrePais pertenece a la estructura E.	void inscribirDeportistaCampeonato(const char* nombrePais, 								   const char* nombreFederacion, 								   const char* nombreCampeonato, 								   int codigoCOI,								   int mes,								   int dia,								   Estructura* E);//Pre: la estructura E fue previamente creada.// Pre: nombrePais!=NULL, nombreFederacion!=NULL, nombreCampeonato!=NULL// Pre: El pais de nombre nombrePais pertenece a la estructura E.// Pre: La federacion de nombre nombreFederacion del pais de nombre //      nombrePais pertenece a la estructura E.// Pre: Existe un campeonato de nombre nombreCampeonato en la federacion //      de nombre nombreFederacion del pais de nombre nombrePais.// Pre: El deportista de codigo codigoCOI no esta inscripto al campeonato //      de nombre nombreCampeonato de la federacion de nombre nombreFederacion //      del pais de nombre nombrePais para el dia dia del mes mes.		int obtenerCantidadPaises(Estructura* E);// Pre: la estructura E fue previamente creada.// Retorna la cantidad de paises ingresados.bool existeCampeonatoFederacion(const char* nombrePais,                                 const char* nombreFederacion, 								const char* nombreCampeonato,								Estructura* E);//Pre: nombrePais!=NULL, nombreFederacion!=NULL, nombreCampeonato!=NULL//Pre: la estructura E fue previamente creada//Pre: El pais de nombre nombrePais pertenece a la estructura E.//Pre: La federacion de nombre nombreFederacion del pais de nombre //     nombrePais pertenece a la estructura E.void imprimirFederados(const char* nombrePais,                        const char* nombreFederacion, 					   Estructura* E);//Pre: nombrePais!=NULL, nombreFederacion!=NULL//Pre: la estructura E fue previamente creada.//Pre: El pais de nombre nombrePais pertenece a la estructura E.//Pre: La federacion de nombre nombreFederacion del pais de nombre //     nombrePais pertenece a la estructura E.void imprimirCampeonatosDeportista(Estructura* E, int codigoCOI);//Pre: la estructura E fue previamente creada.//Pre: Existe un deportista con codigo codigoCOI en la estructura E.void destruirCOI(Estructura* E);//Pre: La estructura E fue previamente creada.//Destruye la estructura, liberando por completo la memoria asignada.#endif /* ESTRUCTURA_H */