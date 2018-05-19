#include <stdio.h>


#ifndef ESTRUCTURAS__H
#define estructuras__H 1


typedef struct parametros
{
	int cant_palabras;
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
	ST_ERROR_NO_NUMERICO,
	ST_SALIR
}status_t;

status_t validar_ayuda(int argc, char *argv[]);
status_t procesar_argumentos (int argc , char *argv[], parametros_t *params, FILE * FENTRADA, FILE *FSALIDA, int *palabras);
status_t entrada_archivo_txt(parametros_t *params, int palabras[params->cant_palabras],FILE *FENTRADA);
status_t entrada_archivo_bin(parametros_t *params, int palabras[params->cant_palabras], FILE *FENTRADA);
status_t entrada_pantalla(parametros_t *params, int palabras[params->cant_palabras]);
status_t vector_memoria(parametros_t *params, int palabras[params->cant_palabras]);

status_t leer (int operando,parametros_t *params, int palabras[params->cant_palabras]);
status_t escribir(int operando, parametros_t *params, int palabras[params->cant_palabras]);
status_t cargar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t pcargar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t guardar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t pguardar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t restar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t dividir (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t multiplicar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando);
status_t sumar (int acumulador, parametros_t *params, int palabras[params->cant_palabras] , int operando);
status_t jmp (int acumulador, int * contador_programa, int operando);
status_t djnz (int acumulador, int * contador_programa, int operando);

#endif