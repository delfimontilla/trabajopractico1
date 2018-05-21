status_t op_escribir(estado_t * estado)/*imprime por stdout el contenido de la posicion solicitada*/{
	fprintf(stdout, "%s %i : %i\n", MSJ_IMPRIMIR_PALABRA,estado->operando, estado->palabras[estado->operando]);
	return ST_OK;
}