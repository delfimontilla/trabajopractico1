status_t leer_archivo_txt(parametros_t *params, estado_t *estado,FILE *FENTRADA, FILE *FSALIDA){
 size_t i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 for(i=0; i<params->cant_palabras;i++){
    if(fgets(aux,MAX_LARGO_PALABRA,FENTRADA)==NULL){
    	liberar_memoria(estado);
    	cerrar_archivos(FENTRADA,FSALIDA);
    	return ST_ERROR_FUERA_RANGO;
    }
    instruccion= strtol(aux,&pc,10); 
    if(*pc!='\0'&& *pc!='\n')
    	return ST_ERROR_NO_NUMERICO;

    /*validar que "     " no sea un 0*/ 

 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	estado->palabras[i]=instruccion;
 }

 printf("%s\n",MSJ_CARGA_COMPLETA);
 printf("%s\n",MSJ_COMIENZO_EJECUCION); 

 return ST_OK;
}