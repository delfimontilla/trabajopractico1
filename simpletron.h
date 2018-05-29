#ifndef SIMPLETRON__H
#define SIMPLETRON__H 1

#include <stdio.h>
#include "status.h"

typedef enum 
{

	LEER = 10,
	ESCRIBIR = 11,
	CARGAR = 20,
	GUARDAR = 21,
	PCARGAR = 22,
	PGUARDAR = 23,
	SUMAR = 30,
	RESTAR = 31,
	DIVIDIR = 32,
	MULTIPLICAR = 33,
	JMP = 40,
	JMPNEG = 41,
	JMPZERO = 42,
	JNZ = 43,
	DJNZ = 44,
	HALT = 45

}opcode_t;


typedef struct estado
{
	int acumulador;/*posicion de memoria del acumulador*/
	int contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    int *palabras;/*vector donde estan guardadas las palabras*/
    int opcode; /*el codigo de operacion, que especifica la operación a realizar*/
    int operando; /*represeta la dirección de memoria que contiene la palabra a la que se le aplica la operación*/

}estado_t; /*una estructura para almacenar el estado del Simpletron*/

status_t ejecutar_simpletron (estado_t * estado);
status_t op_leer (estado_t * estado);
status_t op_escribir(estado_t * estado);
status_t op_cargar (estado_t * estado);
status_t op_pcargar (estado_t * estado);
status_t op_guardar (estado_t * estado);
status_t op_pguardar (estado_t * estado);
status_t op_restar (estado_t * estado);
status_t op_dividir (estado_t * estado);
status_t op_multiplicar (estado_t * estado);
status_t op_sumar (estado_t * estado);
status_t op_jmp (estado_t * estado);
status_t op_djnz (estado_t * estado);

#endif