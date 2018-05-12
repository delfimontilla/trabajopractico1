#include <stdio.h>

#define MSJ_BIENVENIDA "Bienvenide a le Simpletron! Por favor, ingrese su programa una instrucción (o dato) a la vez. Yo escribiré la ubicación y un signo de pregunta (?).Luego usted ingrese la palabra para esa ubicación. Ingrese -99999 para finalizar."
/* "Welcome to Simpletron! Please enter your program one instruction (or data word) at a time. I will type the location number and a question mark (?). You then type the word for that location. Type the sentinel -99999 to stop entering your program."*/


#define FIN -99999
#define MIN_PALABRA -9999
#define MAX_PALABRA 9999
#define MSJ_CARGA_COMPLETA "*** Carga del programa completa ***"
#define MSJ_COMIENZO_EJECUCION "*** Comienza la ejecución del programa ***"

/* Procedimiento que,por stdin, cargará las instrucciones una a una en el vector palabras,
validando que sean un número entero de cuatro dígitos con signo.*/

status_t entrada_pantalla(int palabras[cant_palabras]){
 
 size_t i;
 char aux[7];
 long instruccion=0;

 printf("%s\n","MSJ_BIENVENIDA");

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

