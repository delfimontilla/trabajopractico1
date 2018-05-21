status_t imprimir_pantalla(parametros_t *params, estado_t * estado)
/*Recibe los punteros a las estructuras params y estado para imprimir los datos guardados
 en el acumulador, en el contador del programa, la ultima instruccion ejecutada, el ultimo opcode y operando, ademas de la memoria de todas las palabras*/{
	
	/******************** FALTA ALINEAR TODO A LA DERECHA CREO QUE ES CON EL MENOS VERIFICAR************/
    
    int i,k,l;

    printf("%s\n", MSJ_REGISTRO);
	printf("%25s: %6i\n",MSJ_ACUM, estado->acumulador );
	printf("%25s: %6i\n",MSJ_CONT_PROG, estado->contador_programa );
	printf("%25s: %6i\n",MSJ_INST, estado->palabras[estado->contador_programa] );
	
	estado->opcode = *(estado->palabras + estado->contador_programa) /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	
	printf("%25s: %6i\n",MSJ_OPCODE, estado->opcode );
	printf("%25s: %6i\n",MSJ_OPERANDO, estado->operando );

	
	k=0;

	printf("    ");
	for (l = 0; l < 10; l++)
		printf("  %i   ",l) ;


	for ( i = 0; i < params->cant_palabras ; i++){
      
      if ((i%10)==0){
	  printf("\n%02i  ",k);
	  k+=10;
	  }
		  
      if(estado->palabras[i]<0)
		printf("%05i ",estado->palabras[i] );
	  else 
		printf("+%04i ",estado->palabras[i] );

	}
    printf("\n");
    
    return ST_OK;
}