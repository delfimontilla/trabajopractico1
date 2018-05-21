status_t op_leer (estado_t * estado)/*Lee una palabra por stdin a una posicion de memoria*/{
	int * AUX;
	AUX=NULL;
	printf("%s\n", MSJ_INGRESO_PALABRA);
	if (fgets((char*)AUX,MAX_LARGO_PALABRA,stdin)==NULL)
		fprintf(stderr, "%s\n", MSJ_ERROR_PALABRA_NULA );
		return ST_ERROR_PALABRA_VACIA; /*la palabra ingresada es nula*/	
	estado->palabras[estado->operando] = *AUX;	
	return ST_OK;
}