/* 4309187 4666259 4201206 */

#include "Estructura.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Campeonato;
struct Federacion;

struct AvlCampeonatos;
struct ColaFederaciones;

struct NodoHashCampeonatos;
struct NodoHashFederaciones;

typedef struct NodoHashDeportistas NodoHashFederados;

/** Datos **/
struct Pais{
    const char* nombrePais;
    Continente continente;
    const char* idioma;
    // estructura internas
    ColaFederaciones* c_federaciones;
    NodoHashFederaciones* hash_federaciones[F];
};

/** calendario de las inscripciones **/
struct NodoInscripcion {
    Campeonato* campeonato;
    Federacion* federacion;
};

struct ListaInscripciones {
    NodoInscripcion* inscripcion;
    ListaInscripciones* sig_inscripcion;
};
/** fin calendario de las inscripciones **/

struct Deportista{
    int codigoCOI;
    const char* nombreDeportista;
    const char* apellidoDeportista;
    int edadDeportista;
    ListaInscripciones*  calendario[12][31];
};

struct Federacion{
    const char* nombreFederacion;
    const char* dscFederacion;
    int diaCreacion;
    int mesCreacion;
    int anioCreacion;
    AvlCampeonatos* avl_campeonatos;
    NodoHashCampeonatos* hash_campeonatos[C];
    NodoHashFederados* hash_federados[D];
};

struct Campeonato {
    const char* nombreCampeonato;
    const char* dscCampeonato;
    int importancia;
};

/** Estructuras **/
struct AvlCampeonatos {
    Campeonato *campeonato;
    int fb;
    AvlCampeonatos *izq;
    AvlCampeonatos *der;
};

/** cola de federaciones */
struct NodoColaFederaciones {
    Federacion* federacion;
    NodoColaFederaciones* sig_federacion;
};

struct ColaFederaciones {
    NodoColaFederaciones* primero;
    NodoColaFederaciones* ultimo;
};

/** hash de paises **/
struct ListaPaises {
    Pais* pais;
    ListaPaises* sig_pais;
};

struct NodoHashPaises{
    ListaPaises* l_paises;
};
/** fin hash de paises **/

/** hash federaciones **/
struct ListaFederaciones{
    Federacion* federacion;
    ListaFederaciones * sig_federacion;
};

struct NodoHashFederaciones {
    ListaFederaciones* l_federaciones;

};
/** fin hash federaciones **/

/** hash campeonatos **/
struct ListaCampeonatos{
    Campeonato* campeonato;
    ListaCampeonatos* sig_campeonato;
};

struct NodoHashCampeonatos {
    ListaCampeonatos* l_campeonatos;
};
/** fin hash campeonatos **/

/** hash deportistas **/
struct ListaDeportistas{
    Deportista* deportista;
    ListaDeportistas* sig_deportista;
};

struct NodoHashDeportistas {
    ListaDeportistas* l_deportistas;
};
/** fin hash deportistas **/

struct Estructura {
    int cantPaises;
    NodoHashPaises* hash_paises[P];
    NodoHashDeportistas* hash_deportistas[P*D];
};

/****************************************/
/** Declaracion de funciones auxiliares */
/****************************************/

/** funciones para crear los datos **/
Pais* crearPais(const char* nombrePais, Continente continente, const char* idioma);
Deportista* crearDeportista(int codigoCOI, const char* nombreDeportista, const char* apellidoDeportista, int edadDeportista);
Federacion* crearFederacion(const char* nombreFederacion, const char* dscFederacion, int diaCreacion, int mesCreacion, int anioCreacion);
Campeonato* crearCampeonato(const char* nombreCampeonato, const char* dscCampeonato, int importancia);

/**funciones de insercion **/
void insertarHashCampeonatos(Campeonato* campeonato, NodoHashCampeonatos** hash_campeonatos);
void insertarHashDeportistas(Deportista* deportista, NodoHashDeportistas** hash_deportistas);
void insertarHashFederaciones(Federacion* federacion, NodoHashFederaciones** hash_federaciones);
void insertarHashFederados(Deportista* deportista, NodoHashFederados** hash_federados);
void insertarHashPaises(Pais* pais, NodoHashPaises** hash_paises);
void insertarAvlCampeonatos(Campeonato* campeonato, bool &aumento, AvlCampeonatos* &avl_campeonatos);
void insertarColaFederaciones(Federacion* federacion, Pais* pais);

/** funciones de busqueda **/
Campeonato* buscarHashCampeonatos(const char* nombreCampeonato,Federacion* federacion);
Deportista* buscarHashDeportistas(int codigoCOI, NodoHashDeportistas** hash_deportistas);
Federacion* buscarHashFederaciones(const char* nombreFederacion,Pais* pais);
Pais*       buscarHashPaises(const char* nombrePais,NodoHashPaises** hash_paises);

/** funciones de impresion **/
void imprimirFederados(Federacion* federacion);
void imprimirInscripciones(Deportista* deportista);
void imprimirFederacionesCola(Pais* pais);

/** funciones de destruccion **/
void destruirCampeonato(Campeonato* &campeonato);
void destruirDeportista(Deportista* &deportista);
void destruirFederacion(Federacion* &federacion);
void destruirPais(Pais* &pais);

void destruirListaCampeonatos(ListaCampeonatos* &l_campeonatos);
void destruirListaDeportistas(ListaDeportistas* &l_deportistas);
void destruirListaFederaciones(ListaFederaciones* &l_federaciones);
void destruirListaFederados(ListaDeportistas* &l_deportistas);
void destruirListaInscripciones(ListaInscripciones* &l_inscripciones);
void destruirListaPaises(ListaPaises* &l_paises);

void destruirAvlCampeonatos(AvlCampeonatos* &a);
void destruirColaFederaciones(ColaFederaciones* &c_federaciones);

void destruirNodoHashCampeonatos(NodoHashCampeonatos* &nodoHC);
void destruirNodoHashDeportistas(NodoHashDeportistas* &nodoHD);
void destruirNodoHashFederaciones(NodoHashFederaciones* &nodoHF);
void destruirNodoHashFederados(NodoHashFederados* &nodoHF);
void destruirNodoHashPaises(NodoHashPaises* &nodoHP);

/** TAD Avl **/
void rebalancearLL(AvlCampeonatos* &a);
void rebalancearRR(AvlCampeonatos* &a);
void rebalancearLR(AvlCampeonatos* &a);
void rebalancearRL(AvlCampeonatos* &a);

/** otras funciones **/
const char* IntToStr(int value);

/** FUNCIONES PARA DEBUGGEAR!!!!!!!!!!!! **/
/*void imprimirInOrder(AvlCampeonatos* &a);
// Función auxiliar para desplegar la lista de cada nodo
void desplegarHashLista(NodoHashPaises* lista);
// Despliega el hash
void desplegarHashPaises (Estructura* E);
*/
/*********************************************/
/** Fin declaracion de funciones auxiliares **/
/*********************************************/

/***********************************/
/** Implementacion de Estructuras **/
/***********************************/

Estructura*
crearCOI() {
    Estructura* estructura = new Estructura;
    estructura->cantPaises = 0;
	for (int i = 0; i < (P*D); i++){
        estructura->hash_deportistas[i] = NULL;
    }
    for (int i = 0; i < P; i++) {
        estructura->hash_paises[i] = NULL;
    }
    return (estructura);
}

void
altaPais(const char* nombrePais, Continente continente,const char* idioma,
                                                            Estructura* E) {
    // creo el pais
    Pais* pais_nuevo = crearPais(nombrePais,continente,idioma);
    // ingreso el pais en hash de paises
    insertarHashPaises(pais_nuevo,E->hash_paises);
    E->cantPaises++;
}

void
altaFederacion(const char* nombrePais, const char* nombreFederacion,
                    const char* dscFederacion,int diaCreacion,int mesCreacion,
                    int anioCreacion,Estructura* E) {
    // creo la federacion
    Federacion* federacion_nueva = crearFederacion(nombreFederacion,dscFederacion,diaCreacion,mesCreacion,anioCreacion);
    //busco el pais en el hash de paises
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // ingreso la federacion a la cola de federaciones del pais
    insertarColaFederaciones(federacion_nueva,pais);
    // ingreso la federacion al hash de federaciones del pais
    insertarHashFederaciones(federacion_nueva,pais->hash_federaciones);
}

void
altaCampeonatoFederacion ( const char* nombrePais,
                                const char* nombreFederacion,
                                const char* nombreCampeonato,
                                const char* dscCampeonato,
                                int importancia,
                                Estructura* E) {
    // creo el campeonato
    Campeonato* campeonato = crearCampeonato(nombreCampeonato,dscCampeonato,importancia);
    // busco el pais nombrePais dentro del hash de paises
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // busco la federacion nombreFederacion dentro del pais nombrePais
    Federacion* federacion = buscarHashFederaciones(nombreFederacion,pais);
    // ingreso al hash de campeonatos dentro de la federacion nombreFederacion
    insertarHashCampeonatos(campeonato,federacion->hash_campeonatos);
    // ingreso el campeonato al Avl de campeonatos dentro de la federacion
    bool aumento = false;
    insertarAvlCampeonatos(campeonato,aumento,federacion->avl_campeonatos);
}

void
altaDeportista (const char* paisDeportista,int codigoCOI,
                     const char* nombreDeportista,
                     const char* apellidoDeportista,int edadDeportista,
		     Estructura* E) {
    // creo al deportista
    Deportista* deportista = crearDeportista(codigoCOI,nombreDeportista,apellidoDeportista,edadDeportista);
    // ingreso al deportista al hash de deportistas (P*D)
    insertarHashDeportistas(deportista, E->hash_deportistas);
}

void
imprimirFederaciones(const char* nombrePais, Estructura* E) {
    // busco el pais nombrePais en el hash de paises
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // imprimo la cola de federaciones del pais nombrePais e imprimo las
    imprimirFederacionesCola(pais);
}

void
inscribirDeportistaCampeonato(const char* nombrePais,
				   const char* nombreFederacion,
				   const char* nombreCampeonato,
				   int codigoCOI,int mes,int dia,
                                   Estructura* E) {
    // busco al deportista en el hash de deportistas
    Deportista* deportista = buscarHashDeportistas(codigoCOI,E->hash_deportistas);
    // busco el pais nombrePais en el hash de paises
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // busco la federacion nombreFederacion dentro del pais nombre pais
    Federacion* federacion = buscarHashFederaciones(nombreFederacion,pais);
    // busco el campeonato en el hash de campeonatos dentro de la federacion
    // nombreFederacion
    Campeonato* campeonato = buscarHashCampeonatos(nombreCampeonato,federacion);
    // ingreso la inscripcion en el calendario dentro del deportista con
    // codigoCOI en la fecha int mes int dia
    NodoInscripcion* inscripcion = new NodoInscripcion;
    inscripcion->campeonato=campeonato;
    inscripcion->federacion=federacion;

    ListaInscripciones* l_aux_inscripciones = new ListaInscripciones;
    l_aux_inscripciones->inscripcion = inscripcion;
    l_aux_inscripciones->sig_inscripcion = deportista->calendario[mes-1][dia-1];
    deportista->calendario[mes-1][dia-1] = l_aux_inscripciones;
    // ingreso al deportista dentro del hash de federados de la federacion
    // nombreFederacion/
    insertarHashFederados(deportista,federacion->hash_federados);
}

int
obtenerCantidadPaises(Estructura* E) {

    return ( E->cantPaises );
}

bool
existeCampeonatoFederacion(const char* nombrePais,
                                const char* nombreFederacion,
 				const char* nombreCampeonato,
				Estructura* E) {
    // busco el pais nombrePais en el hash de paises
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // busco la federacion dentro del pais nombrePais
    Federacion* federacion = buscarHashFederaciones(nombreFederacion,pais);
    // busco en el hash de campeonatos dentro de la federacion

    return ( buscarHashCampeonatos(nombreCampeonato,federacion) != NULL );
}

void
imprimirFederados(const char* nombrePais, const char* nombreFederacion,
		       Estructura* E) {
    // buscar en el hash de paises el pais nombrePais
    Pais* pais = buscarHashPaises(nombrePais,E->hash_paises);
    // busco la federacion nombreFederacion dentro del pais nombrePais
    Federacion* federacion = buscarHashFederaciones(nombreFederacion,pais);
    // recorro el hash de federados dentro de la federacion
    imprimirFederados(federacion);
}

void
imprimirCampeonatosDeportista(Estructura* E, int codigoCOI) {
    // busco al deportista en el hash de deportistas
    Deportista* deportista = buscarHashDeportistas(codigoCOI,E->hash_deportistas);
    // recorro el calendario y voy imprimiendo la lista de inscripciones
    imprimirInscripciones(deportista);
}

void
destruirCOI(Estructura* E) {
	for (int p = 0; p < P; p++) {
        destruirNodoHashPaises(E->hash_paises[p]);
    }
    for (int pd = 0; pd < (P*D); pd++){
        destruirNodoHashDeportistas(E->hash_deportistas[pd]);
    }
    delete(E);
    E = NULL;
}

/***************************************/
/** Fin implementacion de Estructuras **/
/***************************************/

/********************************************/
/** Implementacion de funciones auxiliares **/
/********************************************/

/** funciones para crear los datos **/
Pais*
crearPais (const char* nombrePais, Continente continente, const char* idioma) {
	Pais* pais = new Pais;
        char* nombre = new char[strlen(nombrePais)+1];
        strcpy(nombre, nombrePais);
	pais->nombrePais = nombre;
        pais->continente = continente;
        char* idiom = new char[strlen(idioma)+1];
	strcpy(idiom, idioma);
	pais->idioma = idiom;
        pais->c_federaciones = new ColaFederaciones;
        pais->c_federaciones->primero = NULL;
        pais->c_federaciones->ultimo  = NULL;
	for (int i=0; i<F; i++)
            pais->hash_federaciones[i] = NULL;

        return pais;
}

Deportista*
crearDeportista (int codigoCOI, const char* nombreDeportista, const char* apellidoDeportista, int edadDeportista) {
	Deportista* deportista = new Deportista;
	deportista->codigoCOI = codigoCOI;
        char* nombreD = new char[strlen(nombreDeportista)+1];
	strcpy(nombreD, nombreDeportista);
	deportista->nombreDeportista = nombreD;
	char* apellidoD = new char[strlen(apellidoDeportista)+1];
        strcpy(apellidoD, apellidoDeportista);
	deportista->apellidoDeportista = apellidoD;
	deportista->edadDeportista = edadDeportista;
	for (int i=0; i<12; i++) {
            for (int j=0; j<31; j++)
                deportista->calendario[i][j] = NULL;
	}

        return deportista;
}

Federacion*
crearFederacion (const char* nombreFederacion, const char* dscFederacion, int diaCreacion, int mesCreacion, int anioCreacion) {
	Federacion* federacion = new Federacion;
        char* nombreF = new char[strlen(nombreFederacion)+1];
        strcpy(nombreF, nombreFederacion);
	federacion->nombreFederacion = nombreF;
        char* dscF = new char[strlen(dscFederacion)+1];
        strcpy(dscF, dscFederacion);
	federacion->dscFederacion = dscF;
        federacion->diaCreacion = diaCreacion;
	federacion->mesCreacion = mesCreacion;
	federacion->anioCreacion = anioCreacion;
        federacion->avl_campeonatos = NULL;
	for (int i=0; i<C; i++)
            federacion->hash_campeonatos [i] = NULL;
        for (int i=0; i<D; i++)
        federacion->hash_federados [i] = NULL;
        
	return federacion;
}

Campeonato*
crearCampeonato (const char* nombreCampeonato,const char* dscCampeonato, int importancia)  {
	Campeonato* campeonato = new Campeonato;
	char* nombreC = new char[strlen(nombreCampeonato)+1];
	strcpy(nombreC, nombreCampeonato);
	campeonato->nombreCampeonato = nombreC;
	char* dscC = new char[strlen(dscCampeonato)+1];
        strcpy(dscC, dscCampeonato);
	campeonato->dscCampeonato = dscC;
	campeonato->importancia = importancia;

        return campeonato;
}

/** fin funciones para crear los datos **/

/** funciones de impresion **/
void
imprimirFederados(Federacion* federacion) {
    for (int i=0; i<D; i++) {
        if (federacion->hash_federados[i] != NULL) {
            ListaDeportistas* aux = federacion->hash_federados[i]->l_deportistas;
            while (aux != NULL) {
                Deportista* deportista = aux->deportista;
                printf ("%i - %s - %s - %i\n", deportista->codigoCOI, deportista->nombreDeportista, deportista->apellidoDeportista, deportista->edadDeportista);
                aux = aux->sig_deportista;
            }
        }
    }
}

void
imprimirInscripciones(Deportista* deportista) {
	for (int i=0; i<12; i++) {
            for (int j=0; j<31; j++) {
                ListaInscripciones*  aux = deportista->calendario [i][j];
                while (aux != NULL) {
                    NodoInscripcion* inscripcion = aux->inscripcion;
                    printf ("%s - %s - %s - %i\n", inscripcion->federacion->nombreFederacion, inscripcion->campeonato->nombreCampeonato, inscripcion->campeonato->dscCampeonato, inscripcion->campeonato->importancia);
                    aux = aux->sig_inscripcion;
                }
            }
    }
}

void
imprimirFederacionesCola(Pais* pais) {
	NodoColaFederaciones* aux = pais->c_federaciones->primero;
        while (aux != NULL) {
		printf ("%s - %s - %i/%i/%i\n", aux->federacion->nombreFederacion,
                    aux->federacion->dscFederacion, aux->federacion->diaCreacion,
                    aux->federacion->mesCreacion, aux->federacion->anioCreacion);
		aux = aux->sig_federacion;
	}
}

/** fin funciones de impresion **/

/** TAD Hash **/

int
obtenerClave(const char *clave, int tamano)
{
	int largo = strlen(clave);
	int h     = 0;
	for (int indice = 0; indice < largo; ++indice) {
		h += clave[indice];
		h += (h<<10);
                h ^= (h>>6);
	}
	h += (h<<3);
	h ^= (h>>11);
	h += (h<<15);
	tamano--;
	h = (h % tamano);
	if (h<0) {
		tamano++;
		return (h + tamano);
	}
	else
		return h;
}

/** fin TAD Hash **/

/** funciones de insercion **/

void
insertarHashCampeonatos(Campeonato* campeonato, NodoHashCampeonatos** hash_campeonatos) {
    char* clave = new char[strlen(campeonato->nombreCampeonato)+1];
    strcpy(clave,campeonato->nombreCampeonato);
    int index = obtenerClave(clave, C);
    delete [] clave;
    if (hash_campeonatos[index] == NULL) {
        hash_campeonatos[index]                = new NodoHashCampeonatos;
        hash_campeonatos[index]->l_campeonatos = NULL;
    }

    ListaCampeonatos* celda                            = new ListaCampeonatos;
    celda->campeonato                                  = campeonato;
    celda->sig_campeonato                              = hash_campeonatos[index]->l_campeonatos;
    hash_campeonatos[index]->l_campeonatos = celda;
}

void
insertarHashDeportistas(Deportista* deportista, NodoHashDeportistas** hash_deportistas) {
    const char* clave = IntToStr(deportista->codigoCOI);
    int index               = obtenerClave(clave, P*D);
    delete [] clave;
    if (hash_deportistas[index] == NULL) {
        hash_deportistas[index]                = new NodoHashDeportistas;
        hash_deportistas[index]->l_deportistas = NULL;
    }
    ListaDeportistas* celda                = new ListaDeportistas;
    celda->deportista                      = deportista;
    celda->sig_deportista                  = hash_deportistas[index]->l_deportistas;
    hash_deportistas[index]->l_deportistas = celda;
}

void
insertarHashFederados(Deportista* deportista, NodoHashFederados** hash_federados) {
    const char* clave = IntToStr(deportista->codigoCOI);
    int index               = obtenerClave(clave, D);
    delete [] clave;
    if (hash_federados[index] == NULL) {
        hash_federados[index]                = new NodoHashFederados;
        hash_federados[index]->l_deportistas = NULL;
    }
    ListaDeportistas* aux   = hash_federados[index]->l_deportistas;
    bool              esFed = false;
    while((aux != NULL) && (!esFed)) {
        if(aux->deportista->codigoCOI == deportista->codigoCOI)
            esFed = true;
        aux = aux->sig_deportista;
    }
    if (!esFed) {
        ListaDeportistas* celda                          = new ListaDeportistas;
        celda->deportista                                = deportista;
        celda->sig_deportista                            = hash_federados[index]->l_deportistas;
        hash_federados[index]->l_deportistas = celda;
    }

};

void
insertarHashFederaciones(Federacion* federacion, NodoHashFederaciones** hash_federaciones) {
	int index = obtenerClave(federacion->nombreFederacion, F);
        if (hash_federaciones[index] == NULL) {
            hash_federaciones[index]                 = new NodoHashFederaciones;
            hash_federaciones[index]->l_federaciones = NULL;
        }
        ListaFederaciones* celda                       = new ListaFederaciones;
	celda->federacion                              = federacion;
	celda->sig_federacion                          = hash_federaciones[index]->l_federaciones;
        hash_federaciones[index]->l_federaciones = celda;
};

void
insertarHashPaises(Pais* pais, NodoHashPaises** hash_paises) {
    int index = obtenerClave(pais->nombrePais, P);
    if (hash_paises[index] == NULL ) {
		hash_paises[index] = new NodoHashPaises;
		hash_paises[index]->l_paises = NULL;
    }
    ListaPaises* celda           = new ListaPaises;
    celda->pais                  = pais;
    celda->sig_pais              = hash_paises[index]->l_paises;        
    hash_paises[index]->l_paises = celda;
}

void 
insertarAvlCampeonatos(Campeonato *campeonato, bool &aumento, AvlCampeonatos* &a) {
    if ( a == NULL ) {
            AvlCampeonatos *a_aux = new AvlCampeonatos;
            a_aux->fb = 0;
            a_aux->campeonato = campeonato;
            a_aux->izq = NULL;
            a_aux->der = NULL;
            a = a_aux;
            aumento = true;
    }
    else {
        if ( campeonato->importancia < a->campeonato->importancia ) {
            insertarAvlCampeonatos(campeonato,aumento,a->izq);
            if (aumento) {
                switch(a->fb) {
                    case -1: //antes de la ins. ALT(TL) < ALT(TR)
                        a->fb = 0;//No se produce desbalanceo
                        aumento = false;
                        break;
                    case 0: //antes de la ins. ALT(TL) = ALT(TR)
                        a->fb = 1;//mirar los ancestros
                        break;
                    case 1: //antes de la ins. ALT(TL) > ALT(TR)
                            //rebalanceo, el tipo es LL o LR
                        if (a->izq->fb == 1) // es LL
                            rebalancearLL(a);
                        else //es LR
                            rebalancearLR(a);
                        aumento = false;
                        break;
                }
            }
        }
        else {
            insertarAvlCampeonatos(campeonato,aumento,a->der);
            if (aumento) {
                switch(a->fb) {
                    case 1: //antes de la ins. ALT(TR) < ALT(TL)
                        a->fb = 0;//No se produce desbalanceo
                        aumento = false;
                        break;
                    case 0: //antes de la ins. ALT(TR) = ALT(TL)
                        a->fb = -1; // mirar los ancestros
                        break;
                    case -1: //antes de la ins. ALT(TR) > ALT(TL)
                            //rebalanceo, el tipo es RR o RL
                        if (a->der->fb == -1) // es RR
                            rebalancearRR(a);
                        else //es RL
                            rebalancearRL(a);
                        aumento = false;
                        break;
                }
            }
        }
    }
}

void
insertarColaFederaciones(Federacion* federacion, Pais* pais) {
	NodoColaFederaciones* celda  = new NodoColaFederaciones;
	celda->federacion            = federacion;
	celda->sig_federacion        = NULL;
	if (pais->c_federaciones->primero != NULL) {
		pais->c_federaciones->ultimo->sig_federacion = celda;
	}
	else {
		pais->c_federaciones->primero = celda;
	}
	pais->c_federaciones->ultimo = celda;
}

/** fin funciones de insercion **/

/** funciones de busqueda **/

Campeonato*
buscarHashCampeonatos(const char* nombreCampeonato, Federacion* federacion) {
    int index = obtenerClave(nombreCampeonato, C);
    if (federacion->hash_campeonatos[index] != NULL){
        ListaCampeonatos *lista = federacion->hash_campeonatos[index]->l_campeonatos;
        while((lista != NULL) && (strcmp(lista->campeonato->nombreCampeonato, nombreCampeonato) != 0)) {
            lista = lista->sig_campeonato;
        }
        if(lista != NULL) {
            return lista->campeonato;
        }
    }

    return NULL;
}

Deportista*
buscarHashDeportistas(int codigoCOI, NodoHashDeportistas** hash_deportistas) {
    const char* clave = IntToStr(codigoCOI);
    int index = obtenerClave(clave, P*D);
    delete [] clave;
    ListaDeportistas *lista = hash_deportistas[index]->l_deportistas;
    while(lista->deportista->codigoCOI != codigoCOI) {
        lista = lista->sig_deportista;
    }

    return lista->deportista;
}

Federacion*
buscarHashFederaciones(const char* nombreFederacion, Pais* pais) {
	int index = obtenerClave(nombreFederacion, F);
	ListaFederaciones *lista = pais->hash_federaciones[index]->l_federaciones;
	while(strcmp(lista->federacion->nombreFederacion, nombreFederacion) != 0) {
		lista = lista->sig_federacion;
	}

        return lista->federacion;
}

Pais*
buscarHashPaises(const char* nombrePais, NodoHashPaises** hash_paises) {
	int index = obtenerClave(nombrePais, P);
	ListaPaises *lista = hash_paises[index]->l_paises;
	while(strcmp(lista->pais->nombrePais, nombrePais) != 0) {
		lista = lista->sig_pais;
	};

        return lista->pais;
}

/** fin funciones de busqueda **/

/** funciones de destruccion **/

void 
destruirCampeonato(Campeonato* &campeonato) {
//[4] - destruyo el campeonato
    delete[] campeonato->nombreCampeonato;
    delete[] campeonato->dscCampeonato;
    campeonato->dscCampeonato = NULL;
    campeonato->nombreCampeonato = NULL;
    delete(campeonato);
    campeonato = NULL;
}

void 
destruirDeportista(Deportista* &deportista) {
//[12] - destruyo el deportista    
    delete[] deportista->nombreDeportista;
    delete[] deportista->apellidoDeportista;
    for (int fila=0; fila < 12; fila++ ) {
        for (int columna=0; columna < 31; columna++) {
            destruirListaInscripciones(deportista->calendario[fila][columna]);
        }
    }
    deportista->apellidoDeportista = NULL;
    deportista->nombreDeportista   = NULL;
    delete(deportista);
    deportista = NULL;
}

void 
destruirFederacion(Federacion* &federacion) {
//[6] - destruyo la federacion    
    delete [] federacion->nombreFederacion;
    delete [] federacion->dscFederacion;
    for (int d = 0; d < D; d++ ) {
        destruirNodoHashFederados(federacion->hash_federados[d]);
    }
    destruirAvlCampeonatos(federacion->avl_campeonatos);
    for (int c = 0; c < C; c++ ) {
        destruirNodoHashCampeonatos(federacion->hash_campeonatos[c]);
    }
    federacion->dscFederacion = NULL;
    federacion->nombreFederacion = NULL;
    delete(federacion);
    federacion = NULL;

}

void 
destruirPais(Pais* &pais) {
//[8] - destruyo el pais 
    delete [] pais->nombrePais;
    delete [] pais->idioma;
    destruirColaFederaciones(pais->c_federaciones);
	for (int f = 0; f < F; f++) {
        destruirNodoHashFederaciones(pais->hash_federaciones[f]);
    }
    pais->nombrePais        = NULL;
    pais->idioma            = NULL;
    delete(pais);
    pais = NULL;
}

void 
destruirListaCampeonatos(ListaCampeonatos* &l_campeonatos) {
    if ( l_campeonatos != NULL ) {
        destruirListaCampeonatos(l_campeonatos->sig_campeonato);
        destruirCampeonato(l_campeonatos->campeonato);
        delete(l_campeonatos);
        l_campeonatos = NULL;
    }
}

void 
destruirListaDeportistas(ListaDeportistas* &l_deportistas) {
    if ( l_deportistas != NULL ) {
        destruirListaDeportistas(l_deportistas->sig_deportista);
        destruirDeportista(l_deportistas->deportista);
        delete(l_deportistas);
        l_deportistas = NULL;
    }
}

void 
destruirListaFederaciones(ListaFederaciones* &l_federaciones) {
    if ( l_federaciones != NULL ) {
        destruirListaFederaciones(l_federaciones->sig_federacion);
        destruirFederacion(l_federaciones->federacion);
        delete(l_federaciones);
        l_federaciones = NULL;
    }
}

void 
destruirListaFederados(ListaDeportistas* &l_deportistas) {
// no destruyo el deportista aca lo hago en el hash de deportistas P*D
    if ( l_deportistas != NULL ) {
        destruirListaDeportistas(l_deportistas->sig_deportista);
        delete(l_deportistas);
        l_deportistas = NULL;
    }
}

void 
destruirListaInscripciones(ListaInscripciones* &l_inscripciones) {
//[10] 
    if ( l_inscripciones != NULL ) {
        destruirListaInscripciones(l_inscripciones->sig_inscripcion);
        l_inscripciones->inscripcion->campeonato  = NULL;
        l_inscripciones->inscripcion ->federacion = NULL;
        delete(l_inscripciones->inscripcion);
        delete(l_inscripciones);
        l_inscripciones = NULL;
    }
}

void 
destruirListaPaises(ListaPaises* &l_paises) {
    if ( l_paises != NULL ) {
        destruirListaPaises(l_paises->sig_pais);
        destruirPais(l_paises->pais);
        delete(l_paises);
        l_paises = NULL;
    }
}

void
destruirAvlCampeonatos (AvlCampeonatos* &a) {
//[3]- destruye el avl SIN borrar los campeonatos     
    if (a != NULL) {
        destruirAvlCampeonatos(a->der);
        destruirAvlCampeonatos(a->izq);
        delete(a);
        a = NULL;
    }
}

void 
destruirColaFederaciones(ColaFederaciones* &c_federaciones) {
//[1] - las federaciones se destruyen desde el hash de fed
    while ( c_federaciones->primero != NULL ) {
       if (c_federaciones->primero->sig_federacion == NULL) {
           delete (c_federaciones->primero);
           c_federaciones->primero = NULL;
       }
       else {
           NodoColaFederaciones* aBorrar = c_federaciones->primero;
           c_federaciones->primero = c_federaciones->primero->sig_federacion;
           delete(aBorrar);
       }
    }
    c_federaciones->ultimo = NULL;
    delete (c_federaciones);
    c_federaciones = NULL;
}

void 
destruirNodoHashCampeonatos(NodoHashCampeonatos* &nodoHC) {
//[5] destruyo el hash y los campeonatos que contiene    
    if ( nodoHC != NULL ){
        destruirListaCampeonatos(nodoHC->l_campeonatos);
        delete nodoHC;
        nodoHC = NULL;
    }
}

void 
destruirNodoHashDeportistas(NodoHashDeportistas* &nodoHD) {
//[13] - destruyo TODO lo relativo a los deportistas    
    if ( nodoHD != NULL ){
        destruirListaDeportistas(nodoHD->l_deportistas);
        delete nodoHD;
        nodoHD = NULL;
    }
}

void 
destruirNodoHashFederaciones(NodoHashFederaciones* &nodoHF){
//[7] - destruyo TODO lo relativo a las federaciones     
    if ( nodoHF != NULL ){
        destruirListaFederaciones(nodoHF->l_federaciones);
        delete nodoHF;
        nodoHF = NULL;
    }
}

void 
destruirNodoHashFederados(NodoHashFederados* &nodoHF) {
//[2] - destruyo el hash SIN destruir los deportistas 
    if ( nodoHF != NULL ){
        destruirListaFederados(nodoHF->l_deportistas);
        delete nodoHF;
        nodoHF = NULL;
    }
}

void 
destruirNodoHashPaises(NodoHashPaises* &nodoHP) {
//[9] - destruyo TODO lo relativo a los paises    
    if ( nodoHP != NULL ){
        destruirListaPaises(nodoHP->l_paises);
        delete nodoHP;
        nodoHP = NULL;
    }
}

/** fin de funciones de destruccion **/

/** TAD Avl **/

void 
rebalancearLL(AvlCampeonatos* &a) {
    AvlCampeonatos *a_aux = a;
    a = a->izq;
    a_aux->izq= a->der;
    a->der = a_aux;
    a->fb = 0;
    a->der->fb = 0;
}

void 
rebalancearRR(AvlCampeonatos* &a) {
    AvlCampeonatos* a_aux = a;
    a = a->der;
    a_aux->der = a->izq;
    a->izq = a_aux;
    a->fb = 0;
    a->izq->fb = 0;
}

void 
rebalancearLR(AvlCampeonatos* &a) {
    rebalancearRR(a->izq);
    rebalancearLL(a);
}

void 
rebalancearRL(AvlCampeonatos* &a) {
    rebalancearLL(a->der);
    rebalancearRR(a);
}

/** fin TAD Avl*/

/** otras funciones **/
char
DigitToChar(int digit) {
        switch(digit) {
            case 0: return '0';
            case 1: return '1';
            case 2: return '2';
            case 3: return '3';
            case 4: return '4';
            case 5: return '5';
            case 6: return '6';
            case 7: return '7';
            case 8: return '8';
            case 9: return '9';
            default: return '-';
        }
}

const char*
IntToStr(int value) {
    char* inverted = new char[15];
    for (int i = 0; i < 15; i++) {
        inverted[i] = 0;
    }
    int count         = 0;
    int oldAux        = value;
    int aux           = value / 10;
    int digit         = oldAux - (aux * 10);
    inverted[count]   = DigitToChar(digit);
    while (aux >= 1) {
        inverted[count] = DigitToChar(digit);
        count++;
        oldAux       = aux;
        aux          = aux / 10;
        digit        = oldAux - (aux * 10);
    }
    inverted[count]  = DigitToChar(digit);

    return inverted;
}

/** fin de otras funciones **/

/** FUNCIONES PARA DEBUGGEAR!!!!!!!!!!!! **/
/*void
imprimirInOrder(AvlCampeonatos* &a) {
    if ( a != NULL ) {
        imprimirInOrder(a->izq);
        printf("imp: %i | nom: %s | dsc: %s \n",a->campeonato->importancia,a->campeonato->nombreCampeonato,a->campeonato->dscCampeonato);
        
    }
}*/
// Función auxiliar para desplegar la lista de cada nodo
/*void desplegarHashLista(NodoHashPaises* lista) {
    NodoHashPaises* recorrer;
    recorrer = lista;
    while (recorrer->l_paises != NULL) {
        printf("--->%s,", recorrer->l_paises->pais->nombrePais);
        recorrer->l_paises = recorrer->l_paises->sig_pais;
    }
}*/

// Despliega el hash
/*void desplegarHashPaises (Estructura* E) {
    NodoHashPaises** hash = E->hash_paises;
	for (int i = 0; i < P; i++) {
        if (hash[i] == NULL) {
            printf("%i - NULL ",i);
        }
        else {
            desplegarHashLista(hash[i]);
        }
        printf("\n");
    }
}*/

/** FIN FUNCIONES PARA DEBUGGEAR!!!!!!!!!!!! **/

/************************************************/
/** fin implementacion de funciones auxiliares **/
/************************************************/
