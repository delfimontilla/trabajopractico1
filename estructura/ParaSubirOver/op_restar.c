status_t op_restar (estado_t * estado)/*resta al acumulador lo guardado en la posicion de memoria indcada*/{
	estado->acumulador -= estado->palabras[estado->operando];
	return ST_OK;
}