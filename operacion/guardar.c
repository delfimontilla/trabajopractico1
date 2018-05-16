status_t guardar (int acumulador, int  palabras[parametros_t->cant_palabras] , int operando)/*guarda en la posisicon de memoria indicada lo que esta en el acumulador*/{
	palabras[operando] = acumulador ;
	return ST_OK;
}
