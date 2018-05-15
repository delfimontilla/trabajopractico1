#include <stdio.h>

/* Procedimiento que,por stdin, cargará las instrucciones una a una en el vector palabras,
validando que sean un número entero de cuatro dígitos con signo.*/

status_t entrada_pantalla(int palabras[cant_palabras]){
 
 size_t i;
 char aux[7];
 long instruccion=0;

 printf("%s\n",MSJ_BIENVENIDA);

 for(i=0; i<cant_palabras;i++){
 	printf("%2.lu ? \n", i);
    fgets(aux,7,stdin);
    instruccion=strtol(aux,10); 


 	if(instruccion==FIN)
 		return ST_OK;
 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 	
 }
  
 printf("%s\n",MSJ_CARGA_COMPLETA);
 printf("%s\n",MSJ_COMIENZO_EJECUCION);
 
}

