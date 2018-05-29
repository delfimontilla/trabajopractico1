#ifndef STATUS__H
#define STATUS__H 1

#include <stdio.h>

typedef enum status
{
	ST_OK,
	ST_ERROR_PTR_NULO,
	ST_ERROR_CANT_ARG,
	ST_ERROR_FUERA_RANGO,
	ST_OK_NEG,
	ST_ERROR_PALABRA_VACIA,
	ST_ERROR_APERTURA_ARCHIVO,
	ST_ERROR_CANT_PALABRAS,
	ST_ERROR_NO_NUMERICO,
	ST_ERROR_NO_MEM,
	ST_SALIR
} status_t;

#endif