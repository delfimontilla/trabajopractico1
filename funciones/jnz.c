status_t jnz (int acumulador, int * contador_programa,  int operando)/*salta a la posicion de memeoria deseada menos 1 si el contador es distinto de 0*/{
	if (acumulador!=0){
		* contador_programa = operando-1;/*le resto uno para que cuando salgo del switch y le sume 1 quede donde quiero*/
	}
	return ST_OK;
}