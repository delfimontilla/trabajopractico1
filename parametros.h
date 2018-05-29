#ifndef PARAMETROS__H
#define PARAMETROS__H 1

#include <stdio.h>

typedef struct parametros
{
	int cant_palabras; /*la cantidad de palabras que han sido asignadas en memoria para las instrucciones*/
	char i;/*argumento que indica que el programa se leera del archivo pasado como opcion*/
	const char * ia;/*argumento que indica que el archivo de entrada se leera con el formato especificado como opcion*/
	char o;/*argumento que indica que el dump se hara en el archivo pasado como opcion*/
	const char * oa;/*argumento que indica que el dump se hara en el formato especificado como opcion*/
}parametros_t; /*estructura con los argumentos que son pasados al momento de ejecucion*/

#endif