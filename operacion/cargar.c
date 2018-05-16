status_t cargar (int acumulador, int  palabras[parametros_t->cant_palabras] , int operando)/*Carga en el acumulador la posicion de memoria indicada*/{
	acumulador = palabras[operando];
	return ST_OK;
}
