status_t restar (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando)/*resta al acumulador lo guardado en la posicion de memoria indcada*/{
	acumulador -= palabras[operando];
	return ST_OK;
}
