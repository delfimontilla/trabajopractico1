#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"
#include "estructuras.h"
/*  procesar_argumentos es la funcion que valida los argumentos pasados por lineas de comando en la terminal, 
los parametros que se le pasan a esta funcion son los archivos de entrada y salida*/



status_t procesar_argumentos (int argc , char *argv[], parametros_t *params, FILE * FENTRADA, FILE * FSALIDA, int *palabras){
	
	char *pc;
	if(!argv || !params){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_PTR_NULO );
		return ST_ERROR_PTR_NULO;
	}

	if(argc!=ARGC_MAX){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_ARG );
		return ST_ERROR_CANT_ARG;
	}

	if(argv[ARG_POS_CANT_PALABRAS]==NULL){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_PALABRAS );
			return ST_ERROR_CANT_PALABRAS;
		}
	}

	if(argv[ARG_POS_FENTRADA2]!=NULL){
		if(argv[ARG_POS_FENTRADA2]==OPCION_TXT){
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			entrada_archivo_txt(params, palabras, FENTRADA);
		}
		else{
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			entrada_archivo_bin(params, palabras, FENTRADA);
		}
	}
	
	else if(argv[ARG_POS_FENTRADA2]==NULL && argv[ARG_POS_FENTRADA1]!=NULL){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO);
		return ST_ERROR_APERTURA_ARCHIVO;
	}

	else
		entrada_teclado(palabras);

	
	
	if(argv[ARG_POS_FSALIDA2]!=NULL){
		if(argv[ARG_POS_FSALIDA2]==OPCION_TXT){
			
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
		else {
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
	}
	else if(argv[ARG_POS_FENTRADA2]==NULL && argv[ARG_POS_FSALIDA1]!=NULL){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
			return ST_ERROR_APERTURA_ARCHIVO;
		}

	else 
		salida_teclado(palabras);

	return ST_OK;
}

status_t ayuda1(int argc, char *argv[]){

	if(!argv){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_PTR_NULO );
		return ST_ERROR_PTR_NULO;
	}
	if(argc!=ARGC2_MAX){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_ARG );
		return ST_ERROR_CANT_ARG;
	}
	if(argv[ARG_POS_H]!=NULL){
		ayuda();
	}
	return ST_OK;	
}