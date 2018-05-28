
status_t registro_pantalla (int *acumulador,parametros_t *params, int *palabras[params->cant_palabras], int *contador_programa) /*Recibe el puntero al acumulador,  al contador del programa, 
para imprimir los datos guardados en el acumulador, en el contador del programa, la ultima instruccion ejecutada, el ultimo opcode y el ultimo operando*/{
	
	int opcode, operando;
	/******************** FALTA ALINEAR TODO A LA DERECHA CREO QUE ES CON EL MENOS VERIFICAR************/

    printf("%s\n", MSJ_REGISTRO);
	printf("%-s: %-i\n",MSJ_ACUM, *acumulador );
	printf("%-s: %-i\n",MSJ_CONT_PROG, *contador_programa );
	printf("%-s: %-i\n",MSJ_INST, palabras[contador_programa] );
	
	opcode = palabras[contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	operando = palabras[contador_programa] - (opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	
	printf("%-s: %-i\n",MSJ_OPCODE, opcode );
	printf("%-s: %-i\n",MSJ_OPERANDO, operando );
	return ST_OK;
}



