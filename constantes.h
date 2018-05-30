#ifndef CONSTANTES__H
#define CONSTANTES__H 1

#include <stdio.h>


#define ARGC_MAX 6
#define ARGC_MIN 2
#define MAX_LARGO_INGRESO 5
#define CANT_PALABRAS_DEFAULT 50
#define ARG_POS_CANT_PALABRAS 1
#define ARG_POS_FENTRADA_NOMBRE 2
#define ARG_POS_FENTRADA_TIPO 3 
#define ARG_POS_FSALIDA_NOMBRE 4
#define ARG_POS_FSALIDA_TIPO 5
#define ARG_POS_H 1
#define MIN_CANT_PALABRA 1
#define MAX_CANT_PALABRA 100
#define MAX_CADENA 100
#define OPCION_TXT "txt"
#define OPCION_BIN "bin"
#define OPCION_STDIN "stdin"
#define OPCION_STDOUT "stdout"
#define ARG_H "h"

#define FIN -99999
#define MIN_PALABRA -9999
#define MAX_PALABRA 9999

#define TABULACION "\t"
#define SALTO "\n"
#define PREGUNTA "?"

#define ARG_VALIDO_DEFAULT '-'
#define ARG_VALIDO "-"

#define TXT_AYUDA1 \
		MSJ_ACLARACION_AYUDA \
		SALTO \
		MSJ_TITULO_ARG \
		MSJ_TITULO_OPC \
		MSJ_TITULO_DESC \
		MSJ_AYUDA_ARG \
		MSJ_AYUDA_OPC \
		MSJ_AYUDA_DESC \
		MSJ_MEMORIA_ARG \
		MSJ_MEMORIA_OPC \
		MSJ_MEMORIA_DESC \

#define TXT_AYUDA2 \
		MSJ_ENTRADA_ARG \
		MSJ_ENTRADA_OPC \
		MSJ_ENTRADA_DESC \
		MSJ_ARCHIVO_ARG \
		MSJ_ARCHIVO_OPC_BIN \
		MSJ_ARCHIVO_DESC_BIN \
		TABULACION \
		MSJ_ARCHIVO_OPC_TXT \
		MSJ_ARCHIVO_DESC_TXT \

#define TXT_AYUDA3 \
		MSJ_SALIDA_ARG \
		MSJ_SALIDA_OPC \
		MSJ_SALIDA_DESC \
		MSJ_SALIDA_ARCH_ARG \
		MSJ_SALIDA_ARCH_BIN_OPC \
		MSJ_SALIDA_ARCH_BIN_DESC \
		TABULACION \
		MSJ_SALIDA_ARCH_TXT_OPC \
		MSJ_SALIDA_ARCH_TXT_DESC \
		
#define TXT_AYUDA4 \
		TAB_TITULO_OP \
		TAB_TITULO_CODE \
		TAB_TITULO_DESC \
		TAB_ENT_SAL \
		TAB_LEER_OP \
		TAB_LEER_CODE \
		TAB_LEER_DESC \
		TAB_ESCRIBIR_OP \
		TAB_ESCRIBIR_CODE \
		TAB_ESCRIBIR_DESC \
		TAB_MOV \

#define TXT_AYUDA5 \
		TAB_CARGAR_OP \
		TAB_CARGAR_CODE \
		TAB_CARGAR_DESC \
		TAB_GUARDAR_OP \
		TAB_GUARDAR_CODE \
		TAB_GUARDAR_DESC \
		TAB_PCARGAR_OP \
		TAB_PCARGAR_CODE \
		TAB_PCARGAR_DESC \
		TAB_PGUARDAR_OP \
		TAB_PGUARDAR_CODE \
		TAB_PGUARDAR_DESC \
		TAB_MATE \
		TAB_SUMAR_OP \
		TAB_SUMAR_CODE \
		TAB_SUMAR_DESC \
		TAB_RESTAR_OP \
		TAB_RESTAR_CODE \
		TAB_RESTAR_DESC \
		TAB_DIVIDIR_OP \
		TAB_DIVIDIR_CODE \
		TAB_DIVIDIR_DESC \
	
#define TXT_AYUDA6 \
		TAB_MULT_OP \
		TAB_MULT_CODE \
		TAB_MULT_DESC \
		TAB_CONTROL \
		TAB_JUMP_OP \
		TAB_JUMP_CODE \
		TAB_JUMP_DESC \
		TAB_JMPNEG_OP \
		TAB_JMPNEG_CODE \
		TAB_JMPNEG_DESC \
		TAB_JMPZERO_OP \
		TAB_JMPZERO_CODE \
		TAB_JMPZERO_DESC \
		TAB_JNZ_OP \
		TAB_JNZ_CODE \
		TAB_JNZ_DESC \
		TAB_DJNZ_OP \
		TAB_DJNZ_CODE \
		TAB_DJNZ_DESC \
		TAB_FIN_OP \
		TAB_FIN_CODE \
		TAB_FIN_DESC \

#endif

