status_t op_guardar (estado_t * estado)/*guarda en la posicion de memoria indicada lo que esta en el acumulador*/{
	estado->palabras[estado->operando] = estado->acumulador ;
	return ST_OK;
}