
status_t imp_memoria (parametros_t *params, int palabras[params->cant_palabras]){/*vector donde estan guardadas las palabras*/
	int i,j,k,l;
	k=0;
	for (int l = 0; l < 10; l++){
		printf(" %i ",l );
	}
	printf("\n");
	for ( i = 0; i < cant_palabras; i++){
		for ( j = 0; j < 10; j++){
			if(palabras[i]<0)
				printf("-%4i ",palabras[i] );
			else 
				printf("+%4i ",palabras[i] );
		}
	printf("\n");
	printf("%i\n",0 );
	k+=10;
	}
}