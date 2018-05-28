#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"
/* Procedimiento que cargará las instrucciones leídas de un archivo una a una en el vector palabras,
validando que sean un número entero de cuatro dígitos con signo.*/

status_t entrada_archivo_txt(parametros_t *params, int palabras[params->cant_palabras],FILE *FENTRADA){
 size_t i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 for(i=0; i<params->cant_palabras;i++){
    if(fgets(aux,MAX_LARGO_PALABRA,FENTRADA)==NULL)
    	return ST_ERROR_FUERA_RANGO;
    instruccion= strtol(aux,&pc,10); 
    if(*pc!='\0'&& *pc!='\n')
    	return ST_ERROR_NO_NUMERICO;

    /*validar que "     " no sea un 0*/ 

 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 }

 printf("%s\n",MSJ_CARGA_COMPLETA);
 printf("%s\n",MSJ_COMIENZO_EJECUCION); 

 return ST_OK;
}

