#ifndef SIMPLETRON__H
#define SIMPLETRON__H 1

#include <stdio.h>

typedef int palabra_t;

typedef enum opcode
{

	OP_LEER = 10,
	OP_ESCRIBIR = 11,
	OP_CARGAR = 20,
	OP_GUARDAR = 21,
	OP_PCARGAR = 22,
	OP_PGUARDAR = 23,
	OP_SUMAR = 30,
	OP_RESTAR = 31,
	OP_DIVIDIR = 32,
	OP_MULTIPLICAR = 33,
	OP_JMP = 40,
	OP_JMPNEG = 41,
	OP_JMPZERO = 42,
	OP_JNZ = 43,
	OP_DJNZ = 44,
	OP_HALT = 45

}opcode_t;


typedef struct estado
{
	int acumulador;/*posicion de memoria del acumulador*/
	int contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    int *palabras;/*vector donde estan guardadas las palabras*/
    int opcode; /*el codigo de operacion, que especifica la operación a realizar*/
    int operando; /*represeta la dirección de memoria que contiene la palabra a la que se le aplica la operación*/

}simpletron_t; /*una estructura para almacenar el estado del Simpletron*/

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