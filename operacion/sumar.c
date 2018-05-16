status_t sumar (int acumulador, int  palabras[parametros_t->cant_palabras] , int operando)/*suma al acumulador lo guardado en la posicion de memoria indcada*/{
	acumulador += palabras[operando];
	return ST_OK;
}
