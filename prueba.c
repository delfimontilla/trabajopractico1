#include <stdio.h>
#include <stdlib.h>

typedef struct parametros
{
	int contador;
	int *palabras;
}parametros_t;

 int main(void)
{   parametros_t *params;
	int a=3;
	params->contador=a;

    params->palabras = calloc(5, sizeof (params->palabras));
    
	printf("%i",params->contador);
	return 0;
}