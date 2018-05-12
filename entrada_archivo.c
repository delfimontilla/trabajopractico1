#include <stdio.h>

#define MIN_PALABRA -9999
#define MAX_PALABRA 9999


status_t entrada_archivo(int palabras[cant_palabras],FILE f_entrada){
 size_t i;
 char aux[7];
 long instruccion=0;

 for(i=0; i<cant_palabras;i++){
    fgets(aux,7,f_entrada);
    instruccion=strtol(aux,10); 


 	if(instruccion==FIN)
 		return ST_OK;
 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 }
 
}

