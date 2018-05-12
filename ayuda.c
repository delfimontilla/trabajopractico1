#include <stdio.h>

#define MSJ_TITULO_ARG "Arg."
#define MSJ_TITULO_OPC "Opción"
#define MSJ_TITULO_DESC "Descripción"

#define MSJ_AYUDA_ARG "-h" 
#define MSJ_AYUDA_OPC "no posee" 
#define MSJ_AYUDA_DESC "Muestra una ayuda."

#define MSJ_MEMORIA_ARG "-m" 
#define MSJ_MEMORIA_OPC "N" 
#define MSJ_MEMORIA_DESC "Simpletron tiene una memoria de N palabras. Si no se da el argumento, por omisión tendrá 50 palabras."

#define MSJ_ENTRADA_ARG "-i" 
#define MSJ_ENTRADA_OPC "archivo" 
#define MSJ_ENTRADA_DESC "El programa se leerá del archivo pasado como opción, en caso contrario, de stdin."

#define MSJ_ARCHIVO_ARG "-ia" 

#define MSJ_ARCHIVO_OPC_BIN "bin" 
#define MSJ_ARCHIVO_DESC_BIN "El archivo de entrada se entenderá como una secuencia binaria de enteros que representan las palabras que forman el programa."

#define MSJ_ARCHIVO_OPC_TXT "txt" 
#define MSJ_ARCHIVO_DESC_TXT "El archivo de entrada se interpretará como secuencia de números, cada uno en una única línea"

#define MSJ_SALIDA_ARG "-o"
#define MSJ_SALIDA_OPC "archivo" 
#define MSJ_SALIDA_DESC "El dump se hará en el archivo pasado como opción, si no pasa el argumento, el volcado se hará por stdout."

#define MSJ_SALIDA_ARCH_ARG "-of" 

#define MSJ_SALIDA_ARCH_BIN_OPC "bin"
#define MSJ_SALIDA_ARCH_BIN_DESC "El volcado se hará en binario guardando cada elemento de la estructura del Simpletron, además de la memoria."

#define MSJ_SALIDA_ARCH_TXT_OPC "txt" 
#define MSJ_SALIDA_ARCH_TXT_DESC "El volcado se hará en formato de texto, como se muestra en el ejemplo 4, imprimiendo los registros y la memoria."

#define TAB_TITULO_OP "Operación"
#define TAB_TITULO_CODE "OpCode"
#define TAB_TITULO_DESC "Descripción"

#define TAB_ENT_SAL "Op. de Entrada/Salida:"
#define TAB_LEER_OP "LEER" 
#define TAB_LEER_CODE "10" 
#define TAB_LEER_DESC "Lee una palabra de stdin a una posición de memoria"
#define TAB_ESCRIBIR_OP "ESCRIBIR"
#define TAB_ESCRIBIR_CODE "11"
#define TAB_ESCRIBIR_DESC "Imprime por stdout una posición de memoria"

#define TAB_MOV "Op. de movimiento:"
#define TAB_CARGAR_OP "CARGAR"
#define TAB_CARGAR_CODE "20" 
#define TAB_CARGAR_DESC "Carga una palabra de la memoria en el acumulador"

#define TAB_GUARDAR_OP "GUARDAR" 
#define TAB_GUARDAR_CODE "21" 
#define TAB_GUARDAR_DESC "Guarda una palabra del acumulador a la memoria"

#define TAB_PCARGAR_OP "PCARGAR" 
#define TAB_PCARGAR_CODE "22" 
#define TAB_PCARGAR_DESC "Idem CARGAR pero el operando es puntero"

#define TAB_PGUARDAR_OP "PGUARDAR"
#define TAB_PGUARDAR_CODE "23"
#define TAB_PGUARDAR_DESC "Idem GUARDAR pero el operando es puntero"

#define TAB_MATE "Op. aritméticas:"
#define TAB_SUMAR_OP "SUMAR" 
#define TAB_SUMAR_CODE "30" 
#define TAB_SUMAR_DESC "Suma una palabra al acumulador"

#define TAB_RESTAR_OP "RESTAR" 
#define TAB_RESTAR_CODE "31"
#define TAB_RESTAR_DESC "Resta una palabra al acumulador"
 
#define TAB_DIVIDIR_OP "DIVIDIR" 
#define TAB_DIVIDIR_CODE "32" 
#define TAB_DIVIDIR_DESC "Divide el acumulador por el operando"

#define TAB_MULT_OP "MULTIPLICAR" 
#define TAB_MULT_CODE "33" 
#define TAB_MULT_DESC "Multiplica el acumulador por el operando"

#define TAB_CONTROL "Op. control:"
#define TAB_JUMP_OP "JMP" 
#define TAB_JUMP_CODE "40" 
#define TAB_JUMP_DESC "Salta a una ubicación de memoria"

#define TAB_JMPNEG_OP "JMPNEG" 
#define TAB_JMPNEG_CODE "41" 
#define TAB_JMPNEG_DESC "Idem sólo si el acumulador es negativo"

#define TAB_JMPZERO_OP "JMPZERO" 
#define TAB_JMPZERO_CODE "42" 
#define TAB_JMPZERO_DESC "Idem sólo si el acumulador es cero"

#define TAB_JNZ_OP "JNZ"
#define TAB_JNZ_CODE "43"
#define TAB_JNZ_DESC "Idem sólo si el acumulador NO es cero"

#define TAB_DJNZ_OP "DJNZ" 
#define TAB_DJNZ_CODE "44"
#define TAB_DJNZ_DESC "Decrementa el acumulador y salta si NO es cero"

#define TAB_FIN_OP "HALT" 
#define TAB_FIN_CODE "45" 
#define TAB_FIN_DESC "Finaliza el programa"

void ayuda(){

printf("%s   %s   %s\n",MSJ_TITULO_ARG, MSJ_TITULO_OPC, MSJ_TITULO_DESC);
printf("%s   %s   %s\n",MSJ_AYUDA_ARG, MSJ_AYUDA_OPC, MSJ_AYUDA_DESC);
printf("%s   %s   %s\n",MSJ_MEMORIA_ARG, MSJ_MEMORIA_OPC, MSJ_MEMORIA_DESC);
printf("%s   %s   %s\n",MSJ_ENTRADA_ARG, MSJ_ENTRADA_OPC, MSJ_ENTRADA_DESC);
printf("%s   %s   %s\n",MSJ_ARCHIVO_ARG, MSJ_ARCHIVO_OPC_BIN, MSJ_ARCHIVO_DESC_BIN);
printf("     %s   %s\n",MSJ_ARCHIVO_OPC_TXT,MSJ_ARCHIVO_DESC_TXT);
printf("%s   %s   %s\n",MSJ_SALIDA_ARG, MSJ_SALIDA_OPC, MSJ_SALIDA_DESC);
printf("%s   %s   %s\n",MSJ_SALIDA_ARCH_ARG, MSJ_SALIDA_ARCH_BIN_OPC, MSJ_SALIDA_ARCH_BIN_DESC);
printf("     %s   %s\n",MSJ_SALIDA_ARCH_TXT_OPC, MSJ_SALIDA_ARCH_TXT_DESC);

printf("%s   %s   %s\n",TAB_TITULO_OP,TAB_TITULO_CODE,TAB_TITULO_DESC);
printf("%s\n",TAB_ENT_SAL);
printf("%s   %s   %s\n",TAB_LEER_OP,TAB_LEER_CODE,TAB_LEER_DESC);
printf("%s   %s   %s\n",TAB_ESCRIBIR_OP,TAB_ESCRIBIR_CODE,TAB_ESCRIBIR_DESC);
printf("%s\n",TAB_MOV);
printf("%s   %s   %s\n",TAB_CARGAR_OP,TAB_CARGAR_CODE,TAB_CARGAR_DESC);
printf("%s   %s   %s\n",TAB_GUARDAR_OP,TAB_GUARDAR_CODE,TAB_GUARDAR_DESC);
printf("%s   %s   %s\n",TAB_PCARGAR_OP,TAB_PCARGAR_CODE,TAB_PCARGAR_DESC);
printf("%s   %s   %s\n",TAB_PGUARDAR_OP,TAB_PGUARDAR_CODE,TAB_PGUARDAR_DESC);
printf("%s\n",TAB_MATE);
printf("%s   %s   %s\n",TAB_SUMAR_OP,TAB_SUMAR_CODE,TAB_SUMAR_DESC);
printf("%s   %s   %s\n",TAB_RESTAR_OP,TAB_RESTAR_CODE, TAB_RESTAR_DESC);
printf("%s   %s   %s\n",TAB_DIVIDIR_OP,TAB_DIVIDIR_CODE,TAB_DIVIDIR_DESC);
printf("%s   %s   %s\n",TAB_MULT_OP,TAB_MULT_CODE,TAB_MULT_DESC);
printf("%s\n",TAB_CONTROL);
printf("%s   %s   %s\n",TAB_JUMP_OP, TAB_JUMP_CODE,TAB_JUMP_DESC);
printf("%s   %s   %s\n",TAB_JMPNEG_OP, TAB_JMPNEG_CODE,TAB_JMPNEG_DESC);
printf("%s   %s   %s\n",TAB_JMPZERO_OP, TAB_JMPZERO_CODE,TAB_JMPZERO_DESC);
printf("%s   %s   %s\n",TAB_JNZ_OP,TAB_JNZ_CODE,TAB_JNZ_DESC);
printf("%s   %s   %s\n",TAB_DJNZ_OP,TAB_DJNZ_CODE,TAB_DJNZ_DESC);
printf("%s   %s   %s\n",TAB_FIN_OP,TAB_FIN_CODE,TAB_FIN_DESC);


}
