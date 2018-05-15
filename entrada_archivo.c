#include <stdio.h>

/* Procedimiento que cargará las instrucciones leídas de un archivo una a una en el vector palabras,
validando que sean un número entero de cuatro dígitos con signo.*/

status_t entrada_archivo(int palabras[cant_palabras],FILE f_entrada){
 size_t i;
 char aux[7];
 long instruccion=0;

 for(i=0; i<cant_palabras;i++){
    fgets(aux,7,f_entrada);
    instruccion=strtol(aux,10); 

    /*validar que "     " no sea un 0*/ 

 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 }

 
}

