status_t jmp (int acumulador, int * contador_programa, int operando)/*salta a la posicion de memoria indicada menos un valor*/{
	* contador_programa = operando;/*se resta porque al salir del switch */
	return ST_OK;
}