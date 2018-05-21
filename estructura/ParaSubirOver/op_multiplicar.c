status_t op_multiplicar (estado_t * estado)/*multiplica al acumulador lo guardado en la posicion de memoria indcada*/{
	estado->acumulador *= estado->palabras[estado->operando];
	return ST_OK;
}