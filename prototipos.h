#ifndef PROTOTIPOS__H
#define PROTOTIPOS__H 1

#include <stdio.h>


status_t validar_ayuda(int argc, char *argv[]);
status_t imprimir_ayuda();
status_t validar_argumentos (int argc , char *argv[], parametros_t *params, estado_t * estado, FILE ** fentrada, FILE ** FSALIDA);

status_t leer_archivo_txt(parametros_t *params, estado_t * estado,FILE *fentrada, FILE *FSALIDA);
status_t leer_archivo_bin(parametros_t *params, estado_t * estado, FILE *fentrada, FILE *FSALIDA);
status_t leer_teclado(parametros_t *params, estado_t * estado);

status_t seleccionar_salida(char *argv[],parametros_t *params, estado_t *estado, FILE *FSALIDA);
status_t imprimir_pantalla(parametros_t *params, estado_t  * estado);
status_t imprimir_archivo_bin (parametros_t *params, estado_t * estado, FILE *FSALIDA);
status_t imprimir_archivo_txt(parametros_t *params, estado_t * estado, FILE *FSALIDA);
status_t liberar_memoria(estado_t *estado);


#endif