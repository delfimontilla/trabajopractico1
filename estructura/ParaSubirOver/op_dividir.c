status_t op_dividir (estado_t * estado)/*divide al acumulador lo guardado en la posicion de memoria indcada*/{
	estado->acumulador /= estado->palabras[estado->operando];
	return ST_OK;
}