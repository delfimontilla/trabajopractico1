status_t op_leer (int operando, parametros_t *params, int *palabras)/*Lee una palabra por stdin a una posicion de memoria*/{
	long * AUX;

	printf("%s\n", MSJ_INGRESO_PALABRA);

	if (fgets(AUX,MAX_LARGO_PALABRA,stdin)==NULL)
		fprintf(stderr, "%s\n", );
		return ST_ERROR_PALABRA_VACIA;/*la palabra ingresada es nula*/
	
	palabras[operando] =
	
	return ST_OK;
}
