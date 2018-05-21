status_t imprimir_archivo_bin (parametros_t *params, estado_t *estado, FILE *FSALIDA){
	
	
	fwrite(&estado->acumulador, sizeof(estado_t),1, FSALIDA);
	fwrite(&estado->contador_programa, sizeof(estado_t),1, FSALIDA );
	fwrite(&estado->palabras[estado->contador_programa], sizeof(estado_t),1, FSALIDA);
	
	estado->opcode = estado->palabras[estado->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	
	fwrite(&estado->opcode, sizeof(estado_t),1, FSALIDA);
	fwrite(&estado->operando, sizeof(estado_t),1, FSALIDA);	

	fwrite(&estado->palabras[params->cant_palabras], sizeof(int), params->cant_palabras, FSALIDA);
	
	return ST_OK;
}