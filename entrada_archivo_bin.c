#include <stdio.h>
#include <stdlib.h>

/* Procedimiento que,por un archivo binario, cargará las instrucciones una a una en el vector palabras,
validando que sean un número entero de cuatro dígitos con signo.*/
#include "LANG_SPANISH.h"

status_t entrada_archivo_bin(parametros_t *params, int palabras[params->cant_palabras], FILE *FENTRADA)
{
 
	int i;
	int instruccion=0;


 	for(i=0; i<params->cant_palabras;i++){

    	if(fread(&instruccion,sizeof(int),MAX_LARGO_PALABRA,FENTRADA)!=MAX_LARGO_PALABRA){
    		return ST_ERROR_FUERA_RANGO;
    	}
    
 		if(instruccion==FIN)
 			return ST_OK;
 		if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 			return ST_ERROR_FUERA_RANGO;

 		palabras[i]=instruccion;
 	
 	}
  
 	printf("%s\n",MSJ_CARGA_COMPLETA);
 	printf("%s\n",MSJ_COMIENZO_EJECUCION);
 
 	return ST_OK;
}