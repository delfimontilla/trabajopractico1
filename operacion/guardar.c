status_t guardar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando)/*guarda en la posicion de memoria indicada lo que esta en el acumulador*/{
	palabras[operando] = acumulador ;
	return ST_OK;
}
