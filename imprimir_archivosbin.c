
status_t registro_archivo_txt (int * acumulador, parametros_t *params, int *palabras[params->cant_palabras],int * contador_programa, FILE *FSALIDA){
	
	int opcode, operando;
	
	fwrite(&acumulador, sizeof(int),1, FSALIDA);
	fwrite(&contador_programa, sizeof(int),1, FSALIDA );
	fwrite(&palabras[contador_programa], sizeof(int),1, FSALIDA);
	
	opcode = palabras[contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	operando = palabras[contador_programa] - (opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	
	fwrite(&opcode, sizeof(int),1, FSALIDA);
	fwrite(&operando, sizeof(int),1, FSALIDA);	

	fwrite(&palabras[params->cant_palabras], sizeof(int), params->cant_palabras, FSALIDA);
	
	return ST_OK;
}



