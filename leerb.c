#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"


typedef int palabra_t;

typedef struct estado
{
    palabra_t acumulador;/*posicion de memoria del acumulador*/
    size_t contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    palabra_t *palabras;/*vector donde estan guardadas las palabras*/
    size_t opcode; /*el codigo de operacion, que especifica la operación a realizar*/
    size_t operando; /*represeta la dirección de memoria que contiene la palabra a la que se le aplica la operación*/
}simpletron_t; /*una estructura para almacenar el estado del Simpletron*/

int main()
{
    FILE *fp;
    simpletron_t simpletron;
    fp = fopen("salida.bin", "rb");


    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while( fread(&simpletron, sizeof(simpletron_t), 1, fp) == 1 )
    {
        printf("%s\n", MSJ_REGISTRO);
        printf("%25s: %6i\n",MSJ_ACUM, simpletron.acumulador );
        printf("%25s: %6lu\n",MSJ_CONT_PROG, simpletron.contador_programa );
        printf("%25s: %6i\n",MSJ_INST, simpletron.palabras[simpletron.contador_programa] );   
        printf("%25s: %6lu\n",MSJ_OPCODE, simpletron.opcode );
        printf("%25s: %6lu\n",MSJ_OPERANDO, simpletron.operando );

}
    fclose(fp);
    return 0;
}
