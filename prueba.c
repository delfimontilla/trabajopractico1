#include <stdio.h>
#include <stdlib.h>

typedef struct parametros
{
	int *contador;
	int *palabras;
}parametros_t;

 int main(void)
{   parametros_t *params = NULL;

	int a=3;
	(*params).contador=&a;

	printf("%d",(params.palabras)->*(params.contador));
	return 0;
}