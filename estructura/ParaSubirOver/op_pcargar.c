status_t op_pcargar (estado_t * estado)/*Carga en el acumulador la posicion de memoria indicadapor la palabra a la que apunta el operando*/{
	estado->acumulador = estado->palabras[estado->palabras[estado->operando]];
	return ST_OK;
}