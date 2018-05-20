#include <stdio.h>


#ifndef ESTRUCTURAS__H
#define estructuras__H 1


typedef struct estado
{
	int *acumulador;/*posicion de memoria del acumulador*/
	int *contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    int *palabras;/*vector donde estan guardadas las palabras*/
    int opcode; /*el codigo de operacion, que especifica la operación a realizar*/
    int operando; /*represeta la dirección de memoria que contiene la palabra a la que se le aplica la operación*/

}estado_t; /*una estructura para almacenar el estado del Simpletron*/

typedef struct parametros
{
	int cant_palabras; /*la cantidad de palabras que han sido asignadas en memoria para las instrucciones*/
	char i;/*argumento que indica que el programa se leera del archivo pasado como opcion*/
	char ia;/*argumento que indica que el archivo de entrada se leera con el formato especificado como opcion*/
	char o;/*argumento que indica que el dump se hara en el archivo pasado como opcion*/
	char of;/*argumento que indica que el dump se hara en el formato especificado como opcion*/
}parametros_t; /*estructura con los argumentos que son pasados al momento de ejecucion*/

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
status_t validar_argumentos (int argc , char *argv[], parametros_t *params, estado_t * estado, FILE * FENTRADA, FILE *FSALIDA);

status_t leer_archivo_txt(parametros_t *params, estado_t * estado,FILE *FENTRADA, FILE *FSALIDA);
status_t leer_archivo_bin(parametros_t *params, estado_t * estado, FILE *FENTRADA, FILE *FSALIDA);
status_t leer_teclado(parametros_t *params, estado_t * estado);

status_t imprimir_pantalla(parametros_t *params, estado_t * estado);
status_t imprimir_archivo_bin (parametros_t *params, estado_t * estado, FILE *FSALIDA);
status_t imprimir_archivo_txt(parametros_t *params, FILE *FSALIDA);
status_t cerrar_archivos(FILE *FENTRADA, FILE *FSALIDA);
status_t liberar_memoria(estado_t * estado);

status_t op_leer (parametros_t *params, estado_t * estado);
status_t op_escribir( parametros_t *params, estado_t * estado);
status_t op_cargar (parametros_t *params, estado_t * estado);
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