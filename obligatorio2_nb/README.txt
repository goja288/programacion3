Comandos del main 


/**Mundo**/

QUE PIDA AL PRINCIPIO CANT DE TERROTORIOS Y DESPUES DEVUELVA CON LA FUNCION
CUANTOS SON 

0 - help

1 - hacerVecinos <territorio_m,terriorio_n>;<territorio_k,terriorio_l>
        /* hay que definir una dupla de territorios separados por coma por cada arista y
las duplas se separan por ; 
            Por ejemplo: si queremos que un vertice tenga 3 vecinos ingresamos
                hacerVecinos 1,2;1,3;1;4
                /* proxima version que imprima en pantalla las aristas que se van a intentar
crear*/

2 - cantidadVecinos <id_territorio>

3 - obtenerVecinos <id_territorio>

4 - sonVecinos <id_territorio_m> <id_territorio_n>

/**************/

/**Territorio**/

5 - crearTerritorio <nombre> <comunidad>
6 - obtenerNombre <id>
7 - obtenerComunidad <id>

8 - crearTerritorios
        /* crea los territorios y le asigna nombre: nombreK comunidad: comunidadK */
        /* proxima version tomar x comunidades menores a cant de territorios y hacer un random ahora
me embola */

9 - obtenerNombres
        /* devuelve todos los nombres de los territorios */
10 - obtenerComunidades
        /* devuelve todas las comunidades de los territorios */
 
/**************/

/**Estrategias**/

11 - caminoCorto <id_territorio_m> <id_territorio_n>

12 - pavimentar

13 - mediador <comunidad_m> <comunidad_n>

