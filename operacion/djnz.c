status_t djnz (int acumulador, int * contador_programa,  int operando)/*decrementa en 1 el acumulador y salta a la poscion deseada menos 1 en el caso que el acumulador sea distinto de 0*/{
	acumulador--;
	if (acumulador!=0){
		* contador_programa = operando-1;/*le resto uno para que cuando salgo del switch y le sume 1 quede donde quiero*/
	}
	return ST_OK;
}