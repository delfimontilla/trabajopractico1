status_t imprimir_archivos_txt(parametros_t *params, int * palabras[params->cant_palabras], FILE *FSALIDA,){
	
	registro_archivo_txt (acumulador, params, palabras[params->cant_palabras], contador_programa, FSALIDA);
    imprimir_memoria_archivo_txt(*params, palabras[params->cant_palabras], FSALIDA)

	return ST_OK;
}