status_t leer_teclado(parametros_t *params, estado_t *estado){
 
 int i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 printf("%s\n",MSJ_BIENVENIDA);
 

 for(i=0; i<params->cant_palabras;i++){
 	printf("%2.i ? \n", i);
    if(fgets(aux,MAX_LARGO_PALABRA,stdin)==NULL){
    	liberar_memoria(estado);
    	return ST_ERROR_FUERA_RANGO;
    }
    instruccion= strtol(aux,&pc,10);
    if(*pc!='\0'&& *pc!='\n')
    return ST_ERROR_NO_NUMERICO;


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
