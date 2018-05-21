status_t op_jmp (estado_t * estado)/*salta a la posicion de memoria indicada menos un valor*/{
	estado->contador_programa = estado->operando;/*se resta porque al salir del switch */
	return ST_OK;
}