#ifndef STATUS__H
#define STATUS__H 1

#include <stdio.h>

/*Se define un nuevo tipo enumerativo que se usará para conocer
el estado de las funciones y se declara un arreglo de char 
con los mensajes de los estados posibles*/

typedef enum
{
	ST_OK,
	ST_ERROR_PTR_NULO,
	ST_ERROR_CANT_ARG,
	ST_ERROR_FUERA_DE_RANGO,
	ST_ERROR_LECTURA,
	ST_ERROR_PALABRA_NEG,
	ST_ERROR_PALABRA_VACIA,
	ST_ERROR_APERTURA_ARCHIVO,
	ST_ERROR_ARG_INV,
	ST_ERROR_CANT_PALABRAS,
	ST_ERROR_NO_NUMERICO,
	ST_ERROR_NO_MEM,
	ST_ERROR_LIBERAR_MEM,
	ST_ERROR_NADA_QUE_CARGAR,
	ST_AYUDA,
	ST_SALIR
} status_t;

const char * errmsg[] = {
	MSJ_OK,
	MSJ_ERROR_PTR_NULO,
	MSJ_ERROR_CANT_ARG,
	MSJ_ERROR_FUERA_DE_RANGO,
	MSJ_ERROR_LECTURA,
	MSJ_ERROR_PALABRA_NEG,
	MSJ_ERROR_PALABRA_VACIA,
	MSJ_ERROR_APERTURA_ARCHIVO,
	MSJ_ERROR_ARG_INV,
	MSJ_ERROR_CANT_PALABRAS,
	MSJ_ERROR_NO_NUMERICO,
	MSJ_ERROR_NO_MEM,
	MSJ_ERROR_LIBERAR_MEM,
	MSJ_ERROR_NADA_QUE_CARGAR,
	MSJ_AYUDA,
	MSJ_SALIR
};

#endif