status_t imprimir_archivo_txt(parametros_t *params, estado_t *estado, FILE *FSALIDA){
	
	/******************** FALTA ALINEAR TODO A LA DERECHA CREO QUE ES CON EL MENOS VERIFICAR************/
	int i,k,l;

    fprintf(FSALIDA,"%s\n", MSJ_REGISTRO);
	fprintf(FSALIDA, "%25s: %6d\n",MSJ_ACUM, estado->acumulador );
	fprintf(FSALIDA, "%25s: %6d\n",MSJ_CONT_PROG, estado->contador_programa );
	fprintf(FSALIDA, "%25s: %6d\n",MSJ_INST, estado->palabras[estado->contador_programa] );
	
	estado->opcode = estado->palabras[estado->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	
	fprintf(FSALIDA, "%25s: %6d\n",MSJ_OPCODE, estado->opcode );
	fprintf(FSALIDA, "%25s: %6d\n",MSJ_OPERANDO, estado->operando );


	k=0;

	fprintf(FSALIDA,"    ");
	for (l = 0; l < 10; l++)
		fprintf(FSALIDA,"  %i   ",l) ;

	for ( i = 0; i < params->cant_palabras ; i++){ 
      if ((i%10)==0){
	  fprintf(FSALIDA,"\n%02i  ",k);
	  k+=10;
	  }
		  
      if(estado->palabras[i]<0)
		fprintf(FSALIDA,"%05i ",estado->palabras[i] );
	  else 
		fprintf(FSALIDA,"+%04i ",estado->palabras[i] );
	}
    
    fprintf(FSALIDA,"\n");
    
    return ST_OK;
}