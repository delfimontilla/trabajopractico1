#include <stdio.h>


#ifndef LANG_SPANISH__H
#define lang_spanish__H 1

#define ARGC_MAX 6
#define ARGC2_MAX 2
#define CANT_PALABRAS_DEFAULT 100
#define ARG_POS_CANT_PALABRAS 1
#define ARG_POS_FENTRADA1 2
#define ARG_POS_FENTRADA2 3 
#define ARG_POS_FSALIDA1 4
#define ARG_POS_FSALIDA2 5
#define ARG_POS_H 2

#define LEER 10
#define ESCRIBIR 11
#define CARGAR 20
#define GUARDAR 21
#define PCARGAR 22
#define PGUARDAR 23
#define SUMAR 30
#define RESTAR 31
#define DIVIDIR 32
#define MULTIPLICAR 33
#define JMP 40
#define JMPNEG 41
#define JMPZERO 42
#define JNZ 43
#define DJNZ 44
#define HALT 45
#define MSJ_IMPRIMIR_PALABRA "Contenido de la posicion"
#define MAX_LARGO_PALABRA 5 /*maxima cantidad caracteres en una palabra*/
#define MSJ_INGRESO_PALABRA "Ingrese una palabra:"

typedef struct parametros
{
	char cant_palabras;
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
