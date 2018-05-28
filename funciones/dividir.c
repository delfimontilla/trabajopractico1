status_t dividir (int acumulador, parametros_t *params, int palabras[params->cant_palabras], int operando)/*divide al acumulador lo guardado en la posicion de memoria indcada*/{
	acumulador /= palabras[operando];
	return ST_OK;
}
