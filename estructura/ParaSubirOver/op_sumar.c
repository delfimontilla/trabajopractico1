status_t op_sumar(estado_t * estado)/*suma al acumulador lo guardado en la posicion de memoria indcada*/{
	estado->acumulador += estado->palabras[estado->operando];
	return ST_OK;
}