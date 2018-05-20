#include <stdio.h>
#include <stdlib.h>

typedef struct parametros
{
	int contador;
	int *palabras;
}parametros_t;

 int main(void)
{   parametros_t *params = NULL;

	int a=3;
	(*params).contador=a;

    params->palabras = (int *)calloc(5, sizeof (params->palabras));
    
	printf("%d",(*params).contador);
	return 0;
}