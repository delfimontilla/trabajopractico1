
status_t registro ( 
int * acumulador /*posicion de memoria del acumulador*/,
parametros_t *params, int palabras[params->cant_palabras] /*vector donde estan guardadas las palabras*/
int * contador_programa /*cuenta el numero de paso y de memoria que se encuentra el programa*/){
	int opcode, operando;
	/*printf("%s: %i\n", MSJ_ACUM, acumulador );*/
	/******************** FALTA ALINEAR TODO A LA DERECHA CREO QUE ES CON EL MENOS VERIFICAR************/
	fprintf(stdin, "%-s: %-i\n",MSJ_ACUM, *acumulador );
	fprintf(stdin, "%-s: %-i\n",MSJ_CONT_PROG, *contador_programa );
	fprintf(stdin, "%-s: %-i\n",MSJ_INST, palabras[contador_programa] );
	opcode = palabras[contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	operando = palabras[contado
	r_programa] - (opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fprintf(stdin, "%-s: %-i\n",MSJ_OPCODE, opcode );
	fprintf(stdin, "%-s: %-i\n",MSJ_OPERANDO, operando );
	return ST_OK;
}



