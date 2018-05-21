status_t validar_argumentos (int argc , char *argv[], parametros_t *params, estado_t *estado, FILE * FENTRADA, FILE * FSALIDA){
	
	char *pc;
	if(!argv){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_PTR_NULO );
		return ST_ERROR_PTR_NULO;
	}

	if(argc>ARGC_MAX){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_ARG );
		return ST_ERROR_CANT_ARG;
	}

	if(argv[ARG_POS_CANT_PALABRAS]==NULL){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;
	}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_PALABRAS );
			return ST_ERROR_CANT_PALABRAS;
		}
	}

	if(argv[ARG_POS_FENTRADA2]!=NULL){
		if(strcmp(argv[ARG_POS_FENTRADA2],OPCION_TXT)){
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_txt(params, estado, FENTRADA, FSALIDA);
		}
		else if (strcmp(argv[ARG_POS_FENTRADA2],OPCION_BIN)){
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_bin(params, estado, FENTRADA, FSALIDA);
		}
	}
	
	else if(argv[ARG_POS_FENTRADA2]==NULL && argv[ARG_POS_FENTRADA1]!=NULL){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO);
		return ST_ERROR_APERTURA_ARCHIVO;
	}

	else
		leer_teclado(params,estado);

	
	
	if(argv[ARG_POS_FSALIDA2]!=NULL){
		if(strcmp(argv[ARG_POS_FENTRADA2],OPCION_TXT)){
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1],"wt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			imprimir_archivo_txt(params, estado, FSALIDA);
		}
		else if (strcmp(argv[ARG_POS_FENTRADA2],OPCION_BIN)){
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1 ],"wb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			imprimir_archivo_bin(params, estado, FSALIDA);
		}
	}
	else if(argv[ARG_POS_FSALIDA2]==NULL && argv[ARG_POS_FSALIDA1]!=NULL){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
			return ST_ERROR_APERTURA_ARCHIVO;
		}

	else 
		imprimir_pantalla(params,estado);

	return ST_OK;
}