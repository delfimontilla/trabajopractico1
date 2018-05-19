#include <stdio.h>


#ifndef ESTRUCTURAS__H
#define estructuras__H 1


typedef struct estado
{
	int *acumulador;/*posicion de memoria del acumulador*/
	int *contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    estado_t * estado;/*vector donde estan guardadas las palabras*/
    int opcode;
    int operando;

}estado_t;

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
status_t imprimir_ayuda();
status_t validar_argumentos (int argc , char *argv[], parametros_t *params, estado_t *estado, FILE * FENTRADA, FILE *FSALIDA);

status_t leer_archivo_txt(parametros_t *params, estado_t * estado,FILE *FENTRADA, FILE *FSALIDA);
status_t leer_archivo_bin(parametros_t *params, estado_t * estado, FILE *FENTRADA, FILE *FSALIDA);
status_t leer_teclado(parametros_t *params, estado_t * estado);

status_t imprimir_pantalla(parametros_t *params, estado_t *estado);
status_t imprimir_archivo_bin (parametros_t *params, estado_t * estado, FILE *FSALIDA);
status_t imprimir_archivo_txt(parametros_t *params, FILE *FSALIDA);
status_t cerrar_archivos(FILE *FENTRADA, FILE *FSALIDA);
status_t liberar_memoria(estado_t * estado);

status_t op_leer (parametros_t *params, estado_t * estado);
status_t op_escribir( parametros_t *params, estado_t * estado);
status_t op_cargar (parametros_t *params, estado_t * estado,);
status_t op_pcargar (parametros_t *params, estado_t * estado);
status_t op_guardar (parametros_t *params, estado_t * estado);
status_t op_pguardar (parametros_t *params, estado_t * estado);
status_t op_restar (parametros_t *params, estado_t * estado);
status_t op_dividir (parametros_t *params, estado_t * estado);
status_t op_multiplicar (parametros_t *params, estado_t * estado);
status_t op_sumar (parametros_t *params, estado_t * estado);
status_t op_jmp (parametros_t *params, estado_t * estado);
status_t op_djnz (parametros_t *params, estado_t * estado);

#endif