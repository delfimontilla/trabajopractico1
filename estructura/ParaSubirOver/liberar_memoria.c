status_t liberar_memoria(estado_t * estado)/*Recibe el puntero a las instrucciones para liberar la memoria pedida*/{
	free(estado);
	return ST_OK;
}