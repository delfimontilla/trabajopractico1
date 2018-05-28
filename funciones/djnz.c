status_t djnz (int acumulador, int * contador_programa,  int operando)/*decrementa en 1 el acumulador y salta a la poscion deseada en el caso que el acumulador sea distinto de 0*/{
	acumulador--;
	if (acumulador!=0){
		* contador_programa = operando;
	}
	else
		*contador_programa++;
	return ST_OK;
}
