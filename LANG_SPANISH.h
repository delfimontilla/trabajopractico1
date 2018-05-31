#ifndef LANG_SPANISH__H
#define LANG_SPANISH__H 1

#include <stdio.h>


#define MSJ_ERROR "ERROR"
#define MSJ_ERROR_APERTURA_ARCHIVO "apertura de archivo"
#define MSJ_ERROR_PTR_NULO "puntero nulo"
#define MSJ_ERROR_CANT_ARG "cantidad de argumentos"
#define MSJ_ERROR_CANT_PALABRAS "cantidad de palabras"
#define MSJ_ERROR_NO_MEM "no hay memoria"
#define MSJ_ERROR_PALABRA_VACIA "la palabra ingresada es nula"
#define MSJ_ERROR_FUERA_DE_RANGO "se ha intentado acceder a una posición de memoria fuera de rango"
#define MSJ_ERROR_LIBERAR_MEM "error al liberar memoria"
#define MSJ_ERROR_LECTURA "lectura de archivo"
#define MSJ_ERROR_PALABRA_NEG "palabra negativa"
#define MSJ_ERROR_ARG_INV "argumento invalido"
#define MSJ_ERROR_NO_NUMERICO "no es un numero"
#define MSJ_ERROR_NADA_QUE_CARGAR "no hay nada que cargar"
#define MSJ_OK "OK"
#define MSJ_SALIR "Salir"

#define MSJ_IMPRIMIR_PALABRA "Contenido de la posicion"
#define MSJ_INGRESO_PALABRA "Ingrese una palabra:"

#define MSJ_ACUM "acumulador"
#define MSJ_CONT_PROG "contador del programa"
#define MSJ_INST "instruccion"
#define MSJ_OPCODE "opcode"
#define MSJ_OPERANDO "operando"


#define MSJ_BIENVENIDA "Bienvenide a le Simpletron! Por favor, ingrese su programa una instrucción (o dato) a la vez. Yo escribiré la ubicación y un signo de pregunta (?).Luego usted ingrese la palabra para esa ubicación. Ingrese -99999 para finalizar."

#define MSJ_CARGA_COMPLETA "*** Carga del programa completa ***"
#define MSJ_COMIENZO_EJECUCION "*** Comienza la ejecución del programa ***"



#define MSJ_ACLARACION_AYUDA "Para ingresar estos argumentos se deberán colocar en el orden mostrado a continuación. En caso de querer dejar el campo vacio se deberá colocar '-' . \n "

#define MSJ_TITULO_ARG "Arg.\t"
#define MSJ_TITULO_OPC "Opción\t"
#define MSJ_TITULO_DESC "Descripción\n"

#define MSJ_AYUDA_ARG "-h\t" 
#define MSJ_AYUDA_OPC "no posee\t" 
#define MSJ_AYUDA_DESC "Muestra una ayuda.\n"

#define MSJ_MEMORIA_ARG "-m\t" 
#define MSJ_MEMORIA_OPC "N\t" 
#define MSJ_MEMORIA_DESC "Simpletron tiene una memoria de N palabras. Si no se da el argumento, por omisión tendrá 50 palabras.\n"

#define MSJ_ENTRADA_ARG "-i\t" 
#define MSJ_ENTRADA_OPC "archivo\t" 
#define MSJ_ENTRADA_DESC "El programa se leerá del archivo pasado como opción, en caso contrario, de stdin.\n"

#define MSJ_ARCHIVO_ARG "-ia\t" 

#define MSJ_ARCHIVO_OPC_BIN "bin\t" 
#define MSJ_ARCHIVO_DESC_BIN "El archivo de entrada se entenderá como una secuencia binaria de enteros que representan las palabras que forman el programa.\n"

#define MSJ_ARCHIVO_OPC_TXT "txt\t" 
#define MSJ_ARCHIVO_DESC_TXT "El archivo de entrada se interpretará como secuencia de números, cada uno en una única línea\n"

#define MSJ_SALIDA_ARG "-o\t"
#define MSJ_SALIDA_OPC "archivo\t" 
#define MSJ_SALIDA_DESC "El dump se hará en el archivo pasado como opción, si no pasa el argumento, el volcado se hará por stdout.\n"

#define MSJ_SALIDA_ARCH_ARG "-of\t" 

#define MSJ_SALIDA_ARCH_BIN_OPC "bin\t"
#define MSJ_SALIDA_ARCH_BIN_DESC "El volcado se hará en binario guardando cada elemento de la estructura del Simpletron, además de la memoria.\n"

#define MSJ_SALIDA_ARCH_TXT_OPC "txt\t" 
#define MSJ_SALIDA_ARCH_TXT_DESC "El volcado se hará en formato de texto imprimiendo los registros y la memoria.\n"

#define TAB_TITULO_OP "Operación\t"
#define TAB_TITULO_CODE "OpCode\t"
#define TAB_TITULO_DESC "Descripción\n"

#define TAB_ENT_SAL "Op. de Entrada/Salida:\n"

#define TAB_LEER_OP "LEER\t\t" 
#define TAB_LEER_CODE "10\t" 
#define TAB_LEER_DESC "Lee una palabra de stdin a una posición de memoria\n"

#define TAB_ESCRIBIR_OP "ESCRIBIR\t"
#define TAB_ESCRIBIR_CODE "11\t"
#define TAB_ESCRIBIR_DESC "Imprime por stdout una posición de memoria\n"

#define TAB_MOV "Op. de movimiento:\n"

#define TAB_CARGAR_OP "CARGAR\t\t"
#define TAB_CARGAR_CODE "20\t" 
#define TAB_CARGAR_DESC "Carga una palabra de la memoria en el acumulador\n"

#define TAB_GUARDAR_OP "GUARDAR\t\t" 
#define TAB_GUARDAR_CODE "21\t" 
#define TAB_GUARDAR_DESC "Guarda una palabra del acumulador a la memoria\n"

#define TAB_PCARGAR_OP "PCARGAR\t\t" 
#define TAB_PCARGAR_CODE "22\t" 
#define TAB_PCARGAR_DESC "Idem CARGAR pero el operando es puntero\n"

#define TAB_PGUARDAR_OP "PGUARDAR\t\t"
#define TAB_PGUARDAR_CODE "23\t"
#define TAB_PGUARDAR_DESC "Idem GUARDAR pero el operando es puntero\n"

#define TAB_MATE "Op. aritméticas:\n"
#define TAB_SUMAR_OP "SUMAR\t\t" 
#define TAB_SUMAR_CODE "30\t" 
#define TAB_SUMAR_DESC "Suma una palabra al acumulador\n"

#define TAB_RESTAR_OP "RESTAR\t\t" 
#define TAB_RESTAR_CODE "31\t"
#define TAB_RESTAR_DESC "Resta una palabra al acumulador\n"
 
#define TAB_DIVIDIR_OP "DIVIDIR\t\t" 
#define TAB_DIVIDIR_CODE "32\t" 
#define TAB_DIVIDIR_DESC "Divide el acumulador por el operando\n"

#define TAB_MULT_OP "MULTIPLICAR\t" 
#define TAB_MULT_CODE "33\t" 
#define TAB_MULT_DESC "Multiplica el acumulador por el operando\n"

#define TAB_CONTROL "Op. control:\n"
#define TAB_JUMP_OP "JMP\t\t" 
#define TAB_JUMP_CODE "40\t" 
#define TAB_JUMP_DESC "Salta a una ubicación de memoria\n"

#define TAB_JMPNEG_OP "JMPNEG\t\t" 
#define TAB_JMPNEG_CODE "41\t" 
#define TAB_JMPNEG_DESC "Idem sólo si el acumulador es negativo\n"

#define TAB_JMPZERO_OP "JMPZERO\t\t" 
#define TAB_JMPZERO_CODE "42\t" 
#define TAB_JMPZERO_DESC "Idem sólo si el acumulador es cero\n"

#define TAB_JNZ_OP "JNZ\t\t"
#define TAB_JNZ_CODE "43\t"
#define TAB_JNZ_DESC "Idem sólo si el acumulador NO es cero\n"

#define TAB_DJNZ_OP "DJNZ\t\t" 
#define TAB_DJNZ_CODE "44\t"
#define TAB_DJNZ_DESC "Decrementa el acumulador y salta si NO es cero\n"

#define TAB_FIN_OP "HALT\t\t" 
#define TAB_FIN_CODE "45\t" 
#define TAB_FIN_DESC "Finaliza el programa\n"

#define MSJ_REGISTRO "Registros:"

#endif