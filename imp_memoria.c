/*Imprime por  */
status_t imp_memoria (parametros_t *params, int palabras[params->cant_palabras]){

	int i,k,l;
	k=0;

	printf("    ");
	for (l = 0; l < 10; l++)
		printf("  %i   ",l) ;


	for ( i = 0; i < cant_palabras ; i++){
      
      if ((i%10)==0){
	  printf("\n%02i  ",k);
	  k+=10;
	  }
		  
      if(palabras[i]<0)
		printf("%05i ",palabras[i] );
	  else 
		printf("+%04i ",palabras[i] );

	}
    printf("\n");


}