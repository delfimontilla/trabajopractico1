status_t pguardar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando)/*guarda en la posicion de memoria indicada por la palabra a la que apunta el operando lo que esta en el acumulador*/{
	 palabras[palabras[operando]] = acumulador ;
	return ST_OK;
}
