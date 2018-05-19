#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"
/*  procesar_argumentos es la funcion que valida los argumentos pasados por lineas de comando en la terminal, 
los parametros que se le pasan a esta funcion son los archivos de entrada y salida*/
status_t procesar_argumentos (int argc , char *argv[], parametros_t *params, FILE *FENTRADA, FILE *FSALIDA, int *palabras){
	
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