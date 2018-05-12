status_t jmpneg (int acumulador, int * contador_programa, int operando)/*salta a la posicion de memoria desada menos 1 si el acuumlador es negativo*/{
	if (acumulador<0){
		* contador_programa = operando-1;/*le resto uno para que cuando salgo del switch y le sume 1 quede donde quiero*/
	}
	return ST_OK;

}