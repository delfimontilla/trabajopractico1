status_t op_pguardar (estado_t * estado)/*guarda en la posicion de memoria indicada por la palabra a la que apunta el operando lo que esta en el acumulador*/{
	estado->palabras[estado->palabras[estado->operando]] = estado->acumulador ;
	return ST_OK;
}