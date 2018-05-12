#define MSJ_TITULO_ARG "Arg."
#define MSJ_TITULO_OPC "Opción"
#define MSJ_TITULO_DESC "Descripción"

#define MSJ_AYUDA_ARG "-h" 
#define MSJ_AYUDA_OPC "no posee" 
#define MSJ_AYUDA_DES "Muestra una ayuda."

#define MSJ_MEMORIA_ARG "-m" 
#define MSJ_MEMORIA_OPC"N" 
#define MSJ_MEMORIA_DESC "Simpletron tiene una memoria de N palabras. Si no se da el
argumento, por omisión tendrá 50 palabras."

#define MSJ_ENTRADA_ARG "-i" 
#define MSJ_ENTRADA_OPC "archivo" 
#define MSJ_ENTRADA_DESC"El programa se leerá del archivo pasado como opción, en
caso contrario, de stdin."

#define MSJ_ARCHIVO_ARG "-ia" 

#define MSJ_ARCHIVO_OPC_BIN "bin" 
#define MSJ_ARCHIVO_DESC_BIN "El archivo de entrada se entenderá como una secuencia binaria
de enteros que representan las palabras que forman
el programa."

#define MSJ_ARCHIVO_OPC_TXT "txt" 
#define MSJ_ARCHIVO_DESC_TXT"El archivo de entrada se interpretará como secuencia de
números, cada uno en una única línea"

#define MSJ_SALIDA_ARG "-o"
#define MSJ_SALIDA_OPC_ "archivo" 
#define MSJ_SALIDA_DESCR "El dump se hará en el archivo pasado como opción, si no
pasa el argumento, el volcado se hará por stdout."

#define MSJ_SALIDA_ARCH_ARG "-of" 

#define MSJ_SALIDA_ARCH_BIN_OPC "bin"
#define MSJ_SALIDA_ARCH_BIN_DESC "El volcado se hará en binario guardando cada elemento de
la estructura del Simpletron, además de la memoria."

#define MSJ_SALIDA_ARCH_TXT_OPC "txt" 
#define MSJ_SALIDA_ARCH_TXT_DESC "El volcado se hará en formato de texto, como se muestra en
el ejemplo 4, imprimiendo los registros y la memoria."

Operación OpCode Descripción
Op. de Entrada/Salida:
LEER 10 Lee una palabra de stdin a una posición de memoria
ESCRIBIR 11 Imprime por stdout una posición de memoria
Op. de movimiento:
CARGAR 20 Carga una palabra de la memoria en el acumulador
GUARDAR 21 Guarda una palabra del acumulador a la memoria
PCARGAR 22 Idem CARGAR pero el operando es puntero
PGUARDAR 23 Idem GUARDAR pero el operando es puntero
Op. aritméticas:
SUMAR 30 Suma una palabra al acumulador
RESTAR 31 Resta una palabra al acumulador
DIVIDIR 32 Divide el acumulador por el operando
MULTIPLICAR 33 Multiplica el acumulador por el operando
Op. control:
JMP 40 Salta a una ubicación de memoria
JMPNEG 41 Idem sólo si el acumulador es negativo
JMPZERO 42 Idem sólo si el acumulador es cero
JNZ 43 Idem sólo si el acumulador NO es cero
DJNZ 44 Decrementa el acumulador y salta si NO es cero
HALT 45 Finaliza el programa



printf("%s   %s   %s\n",MSJ_TITULO_ARG, MSJ_TITULO_OPC, MSJ_TITULO_DESC);
printf("%s   %s   %s\n",MSJ_AYUDA_ARG, MSJ_AYUDA_OPC, MSJ_AYUDA_DESC);
printf("%s   %s   %s\n",MSJ_MEMORIA_ARG, MSJ_MEMORIA_OPC, MSJ_MEMORIA_DESC);
printf("%s   %s   %s\n",MSJ_ENTRADA_ARG, MSJ_ENTRADA_OPC, MSJ_ENTRADA_DESC);
printf("%s   %s   %s\n",MSJ_ARCHIVO_ARG, MSJ_ARCHIVO_OPC_BIN, MSJ_ARCHIVO_DESC_BIN);
printf("     %s   %s\n", MSJ_ARCHIVO_OPC_TXT,MSJ_ARCHIVO_DESC_TXT);
printf("%s   %s   %s\n",MSJ_SALIDA_ARG, MSJ_SALIDA_OPC, MSJ_SALIDA_DESC);
printf("%s   %s   %s\n",MSJ_SALIDA_ARCH_ARG, MSJ_SALIDA_ARCH_BIN_OPC, MSJ_SALIDA_ARCH_BIN_DESC);
printf("     %s   %s\n", MSJ_SALIDA_ARCH_TXT_OPC, MSJ_SALIDA_ARCH_TXT_DESC);

