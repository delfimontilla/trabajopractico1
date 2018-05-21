status_t leer_archivo_bin(parametros_t *params, estado_t *estado, FILE *FENTRADA,FILE *FSALIDA){
 
	int i;
	int instruccion=0;


 	for(i=0; i<params->cant_palabras;i++){

    	if(fread(&instruccion,sizeof(int),MAX_LARGO_PALABRA,FENTRADA)!=MAX_LARGO_PALABRA){
    		liberar_memoria(estado);
    		cerrar_archivos(FENTRADA,FSALIDA);
    		return ST_ERROR_FUERA_RANGO;
    	}
    
 		if(instruccion==FIN)
 			return ST_OK;
 		if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 			return ST_ERROR_FUERA_RANGO;

 		estado->palabras[i]=instruccion;
 	
 	}
  
 	printf("%s\n",MSJ_CARGA_COMPLETA);
 	printf("%s\n",MSJ_COMIENZO_EJECUCION);
 
 	return ST_OK;
}