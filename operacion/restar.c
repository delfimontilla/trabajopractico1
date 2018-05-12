status_t restar (int acumulador, int  palabras[cant_palabras] , int operando)/*resta al acumulador lo guardado en la posicion de memoria indcada*/{
	acumulador -= palabras[operando];
	return ST_OK;
}