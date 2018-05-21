status_t op_djnz (estado_t * estado)/*decrementa en 1 el acumulador y salta a la poscion deseada en el caso que el acumulador sea distinto de 0*/{
	estado->acumulador--;
	if (estado->acumulador!=0){
		estado->contador_programa = estado->operando;
	}
	else
		estado->contador_programa++;
	return ST_OK;
}