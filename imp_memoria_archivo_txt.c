
status_t imp_memoria_archivo_txt (parametros_t *params, int palabras[params->cant_palabras], FILE *FSALIDA)/*Imprime la matriz con todas las instrucciones */{

	int i,k,l;
	k=0;

	fprintf(FSALIDA,"    ");
	for (l = 0; l < 10; l++)
		fprintf(FSALIDA,"  %i   ",l) ;


	for ( i = 0; i < cant_palabras ; i++){
      
      if ((i%10)==0){
	  fprintf(FSALIDA,"\n%02i  ",k);
	  k+=10;
	  }
		  
      if(palabras[i]<0)
		fprintf(FSALIDA,"%05i ",palabras[i] );
	  else 
		fprintf(FSALIDA,"+%04i ",palabras[i] );

	}
    fprintf(FSALIDA,"\n");
    
    return ST_OK;
}