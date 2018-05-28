status_t cargar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando)/*Carga en el acumulador la posicion de memoria indicada*/{
	acumulador = palabras[operando];
	return ST_OK;
}
