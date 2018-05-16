status_t escribir(int operando, int  palabras[parametros_t->cant_palabras] )/*imprime por stdout el contenido de la posicion solicitada*/{
	fprintf(stdout, "%s %i : %i\n", MSJ_IMPRIMIR_PALABRA,operando, palabras[operando]);
	return ST_OK;
}
