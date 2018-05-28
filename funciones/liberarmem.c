#include <stdio.h>

status_t liberar_memoria(int *palabras)/*Recibe el puntero a las instrucciones para liberar la memoria pedida*/{
	
	free(palabras);
	return ST_OK;

}