#ifndef LANG_ENGLISH__H
#define LANG_ENGLISH__H 1

#include <stdio.h>



#define MSJ_ERROR "ERROR"
#define MSJ_ERROR_APERTURA_ARCHIVO "opening file"
#define MSJ_ERROR_PTR_NULO "null pointer"
#define MSJ_ERROR_CANT_ARG "number of arguments"
#define MSJ_ERROR_CANT_PALABRAS "number of words"
#define MSJ_ERROR_NO_MEM "out of memory"
#define MSJ_ERROR_PALABRA_NULA "the entered word is null"



#define MSJ_IMPRIMIR_PALABRA "Content of the position"
#define MSJ_INGRESO_PALABRA "Enter a word:"

#define MSJ_ACUM "accumulator"
#define MSJ_CONT_PROG "program counter"
#define MSJ_INST "instruction"
#define MSJ_OPCODE "opcode"
#define MSJ_OPERANDO "operand"


#define MSJ_BIENVENIDA "Welcome to Simpletron! Please enter your program one instruction (or data word) at a time. I will type the location number and a question mark (?). You then type the word for that location. Type the sentinel -99999 to stop entering your program."
#define MSJ_CARGA_COMPLETA "*** Program upload complete ***"
#define MSJ_COMIENZO_EJECUCION "*** Program execution starts ***"

#define MSJ_ARG_POSICIONALES "The arguments are positional. If you want input to be stdin you must enter 'entry stdin'; and in case you want output to be stdout, 'output stdout'."

#define MSJ_TITULO_ARG "Arg."
#define MSJ_TITULO_OPC "Option"
#define MSJ_TITULO_DESC "Description"

#define MSJ_AYUDA_ARG "-h" 
#define MSJ_AYUDA_OPC "doesn't have" 
#define MSJ_AYUDA_DESC "Shows help."

#define MSJ_MEMORIA_ARG "-m" 
#define MSJ_MEMORIA_OPC "N" 
#define MSJ_MEMORIA_DESC "Simpletron has a memory for N words. If no arguments is provided, by default it'll have 50 words."

#define MSJ_ENTRADA_ARG "-i" 
#define MSJ_ENTRADA_OPC "file" 
#define MSJ_ENTRADA_DESC "The program will be read from the file provided, otherwise, from stdin."

#define MSJ_ARCHIVO_ARG "-ia" 
#define MSJ_ARCHIVO_OPC_BIN "bin" 
#define MSJ_ARCHIVO_DESC_BIN "The input file will be understood as a binary sequence of integers that represent the words that make up the program."
#define MSJ_ARCHIVO_OPC_TXT "txt" 
#define MSJ_ARCHIVO_DESC_TXT "The input file will be interpreted as a sequence of numbers, each one in a single line"

#define MSJ_SALIDA_ARG "-o"
#define MSJ_SALIDA_OPC "archivo" 
#define MSJ_SALIDA_DESC "The dump will be done in the file provided, otherwise, the dump will be done by stdout."

#define MSJ_SALIDA_ARCH_ARG "-of" 

#define MSJ_SALIDA_ARCH_BIN_OPC "bin"
#define MSJ_SALIDA_ARCH_BIN_DESC "The dump will be done in binary saving every element of the Simpletron structure, in addition to the memory."
#define MSJ_SALIDA_ARCH_TXT_OPC "txt" 
#define MSJ_SALIDA_ARCH_TXT_DESC "The dump will be made in text format by printing the registers and the memory."

#define MSJ_ACLARACION_AYUDA "To enter these arguments must be placed in order. If you want to leave the field empty you must put '-'."

#define TAB_TITULO_OP "Operation"
#define TAB_TITULO_CODE "OpCode"
#define TAB_TITULO_DESC "Description"

#define TAB_ENT_SAL "Input/Output Op.:"
#define TAB_LEER_OP "READ" 
#define TAB_LEER_CODE "10" 
#define TAB_LEER_DESC "Reads a word from stdin to a position of memory"

#define TAB_ESCRIBIR_OP "WRITE"
#define TAB_ESCRIBIR_CODE "11"
#define TAB_ESCRIBIR_DESC "Prints by stdout a position of memory"

#define TAB_MOV "Movement Op.:"
#define TAB_CARGAR_OP "LOAD"
#define TAB_CARGAR_CODE "20" 
#define TAB_CARGAR_DESC "Loads a word from the memory to the accumulator"

#define TAB_GUARDAR_OP "SAVE" 
#define TAB_GUARDAR_CODE "21" 
#define TAB_GUARDAR_DESC "Saves a word from the accumulator to the memory"

#define TAB_PCARGAR_OP "PLOAD" 
#define TAB_PCARGAR_CODE "22" 
#define TAB_PCARGAR_DESC "Same as LOAD but the operand is pointer"

#define TAB_PGUARDAR_OP "PSAVE"
#define TAB_PGUARDAR_CODE "23"
#define TAB_PGUARDAR_DESC "Same a SAVE but the operand is pointer"

#define TAB_MATE "Arithmetic Op.:"
#define TAB_SUMAR_OP "ADDITION" 
#define TAB_SUMAR_CODE "30" 
#define TAB_SUMAR_DESC "Adds a word to the accumulator"

#define TAB_RESTAR_OP "SUBTRACTION" 
#define TAB_RESTAR_CODE "31"
#define TAB_RESTAR_DESC "Subtract a word to the accumulator"
 
#define TAB_DIVIDIR_OP "DIVIION" 
#define TAB_DIVIDIR_CODE "32" 
#define TAB_DIVIDIR_DESC "Divides the accumulator by the operand"

#define TAB_MULT_OP "MULTIPLY" 
#define TAB_MULT_CODE "33" 
#define TAB_MULT_DESC "Multiplies the accumulator by the operand"

#define TAB_CONTROL "Control Op.:"
#define TAB_JUMP_OP "JMP" 
#define TAB_JUMP_CODE "40" 
#define TAB_JUMP_DESC "Jumps to a memory location"

#define TAB_JMPNEG_OP "JMPNEG" 
#define TAB_JMPNEG_CODE "41" 
#define TAB_JMPNEG_DESC "Idem only if the accumulator is negative"

#define TAB_JMPZERO_OP "JMPZERO" 
#define TAB_JMPZERO_CODE "42" 
#define TAB_JMPZERO_DESC "Idem only if the accumulator is zero"

#define TAB_JNZ_OP "JNZ"
#define TAB_JNZ_CODE "43"
#define TAB_JNZ_DESC "Idem only if the accumulator is NOT zero"

#define TAB_DJNZ_OP "DJNZ" 
#define TAB_DJNZ_CODE "44"
#define TAB_DJNZ_DESC "Decreases the accumulator and jump if it is NOT zero"

#define TAB_FIN_OP "HALT" 
#define TAB_FIN_CODE "45" 
#define TAB_FIN_DESC "Finishes the program"

#define MSJ_REGISTRO "Registers:"

#endif
