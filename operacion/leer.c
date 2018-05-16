status_t leer (int operando,parametros_t *params, int palabras[params->cant_palabras] )/*Lee una palabra por stdin a una posicion de memoria*/{
	long * AUX;
	fprintf(stdout, "%s\n", MSJ_INGRESO_PALABRA);
	if (fgets(AUX,MAX_LARGO_PALABRA,stdin)==NULL)
		return ST_ERROR_PALABRA_VACIA;/*la palabra ingresada es nula*/
	strcpy(palabras[operando], AUX);
	return ST_OK;
}
