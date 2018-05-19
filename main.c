#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"
#include "LANG_ENGLISH.h"
#include "estructuras.h"


int main(int argc, char *argv[])
{
	int *acumulador, *contador_programa;
    int *palabras;
    FILE *FENTRADA, *FSALIDA;
    status_t st;
	

    procesar_argumentos(argc, argv, params, FENTRADA, FSALIDA, palabras);

    if(palabras = calloc(params->cant_palabras, sizeof (palabras))==NULL){
    	fprintf(stderr, "%s:%s\n",MSJ_ERROR,MSJ_ERROR_NO_MEM );
    	return EXIT_FAILURE;
    }	



    while(st!=ST_SALIR) st=operaciones(&acumulador, palabras[cant_palabras],&contador_programa);

    liberar_memoria(palabras);
    cerrar_archivos(FENTRADA,FSALIDA);

    return EXIT_SUCCESS;
}

status_t entrada_archivo_bin(parametros_t *params, int palabras[params->cant_palabras], FILE *FENTRADA){
 
	int i;
	int instruccion=0;

 	printf("%s\n",MSJ_BIENVENIDA);
 

 	for(i=0; i<params->cant_palabras;i++){
 		printf("%2.i ? \n", i);
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

status_t entrada_pantalla(parametros_t *params, int palabras[params->cant_palabras]){
 
 size_t i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 printf("%s\n",MSJ_BIENVENIDA);
 

 for(i=0; i<params->cant_palabras;i++){
 	printf("%2.i ? \n", i);
    if(fgets(aux,MAX_LARGO_PALABRA,stdin)==NULL)
    	return ST_ERROR_FUERA_RANGO;
    instruccion= strtol(aux,&pc,10);
    if(*pc!='\0'&& *pc!='\n')
    return ST_ERROR_NO_NUMERICO;


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

status_t procesar_argumentos (int argc , char *argv[], parametros_t *params, FILE ** FENTRADA, FILE **FSALIDA, int *palabras){
	
	char *pc;
	if(!argv || !params){
		return ST_ERROR_PTR_NULO;
	}

	if(argc!=ARGC_MAX){
		return ST_ERROR_CANT_ARG;
	}

	if(argv[ARG_POS_FENTRADA2]!=NULL){/*Falta preguntar si es un archivo de texto o binario*/
		if((*FENTRADA=fopen(argv[ARG_POS_FENTRADA2],"rt"))==NULL){
			return ST_ERROR_APERTURA_ARCHIVO;
		}
		if((*FENTRADA=fopen(argv[ARG_POS_FENTRADA2],"rb"))==NULL){/*Puedo usar el mismo nombre para los archivos si decido si es binario o texto?*/
			return ST_ERROR_APERTURA_ARCHIVO;
		}
	}
	else if(argv[ARG_POS_FENTRADA1]!=NULL){
		if((*FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rt"))==NULL){
			return ST_ERROR_APERTURA_ARCHIVO;
		}
	}

	else 
		entrada_teclado(&palabras);

	if(argv[ARG_POS_CANT_PALABRAS]==NULL){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
		return ST_ERROR_CANT_PALABRAS;
		}
	}
	
	
	if(argv[ARG_POS_FENTRADA2]!=NULL){/*Falta preguntar si es un archivo de texto o binario*/
		if((*FSALIDA=fopen(argv[ARG_POS_FSALIDA2],"rt"))==NULL){
			return ST_ERROR_APERTURA_ARCHIVO;
		}
		if((*FENTRADA=fopen(argv[ARG_POS_FSALIDA2],"rb"))==NULL){
			return ST_ERROR_APERTURA_ARCHIVO;
		}
	}
	else if(argv[ARG_POS_FENTRADA1]!=NULL){
		if((*FENTRADA=fopen(argv[ARG_POS_FSALIDA1],"rt"))==NULL){
			return ST_ERROR_APERTURA_ARCHIVO;
		}
	}

	else 
		salida_teclado(palabras);

	return ST_OK;
}

status_t ayuda1(int argc, char *argv[]){

	if(!argv){
		return ST_ERROR_PTR_NULO;
	}
	if(argc!=ARGC2_MAX){
		return ST_ERROR_CANT_ARG;
	}
	if(argv[ARG_POS_H]!=NULL){
		ayuda();
	}	
}

status_t ayuda(){

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

	return ST_OK;
}

status_t registro ( int * acumulador,parametros_t *params ,int  palabras[params->cant_palabras], int * contador_programa){
	int opcode, operando;
	/*printf("%s: %i\n", MSJ_ACUM, acumulador );*/
	/******************** FALTA ALINEAR TODO A LA DERECHA CREO QUE ES CON EL MENOS VERIFICAR************/
	fprintf(stdin, "%-s: %-i\n",MSJ_ACUM, *acumulador );
	fprintf(stdin, "%-s: %-i\n",MSJ_CONT_PROG, *contador_programa );
	fprintf(stdin, "%-s: %-i\n",MSJ_INST, palabras[contador_programa] );
	opcode = palabras[contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	operando = palabras[contado
	r_programa] - (opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fprintf(stdin, "%-s: %-i\n",MSJ_OPCODE, opcode );
	fprintf(stdin, "%-s: %-i\n",MSJ_OPERANDO, operando );
	return ST_OK;
}

status_t imp_memoria (parametros_t *params ,int  palabras[params->cant_palabras]){
	/*COPIAR LA NUEVA VERSION*/
}