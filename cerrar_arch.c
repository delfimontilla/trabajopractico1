#include <stdio.h>

status_t cerrar_archivos(FILE *FENTRADA, FILE *FSALIDA)/*Recibe los punteros a los archivos de entrada y salida para cerrarlos*/{

	fclose(FENTRADA);
	fclose(FSALIDA);
	return ST_OK;
}