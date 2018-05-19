status_t imprimir_archivos_txt(parametros_t *params, FILE *FSALIDA, int * palabras[params->cant_palabras]){
	
	registro_archivo (acumulador, params, palabras[params->cant_palabras], contador_programa);
	return ST_OK;
}