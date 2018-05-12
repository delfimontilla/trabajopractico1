#include <stdio.h>


#ifndef LANG_ENGLISH__H
#define lang_english__H 1

typedef struct parametros
{
	char m;
	char i;
	char ia;
	char o;
	char of;
}parametros_t;

typedef enum 
{
	ST_OK,
	ST_ERROR_PTR_NULO,
	ST_ERROR_CANT_ARG,
	ST_ERROR_PALABRA_VACIA,
	ST_ERROR_FUERA_RANGO,
	ST_OK_NEG,
	ST_ERROR_APERTURA_ARCHIVO,
	ST_ERROR_CANT_PALABRAS,
	ST_SALIR
}status_t;

status_t ayuda1(int argc, char *argv[]);
status_t procesar_argumentos (int argc , char *argv[], parametros_t *params, FILE ** FENTRADA, FILE **FSALIDA, int *palabras);


#endif