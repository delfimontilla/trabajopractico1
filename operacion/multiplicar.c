status_t multiplicar (int acumulador, int  palabras[cant_palabras] , int operando)/*multiplica al acumulador lo guardado en la posicion de memoria indcada*/{
	acumulador *= palabras[operando];
	return ST_OK;
}