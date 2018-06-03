#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE  *prueba;
	int instr[12]={1009,1010,2009,3010,2111,111,4500,0000,0000,0000,0000,0000};

	prueba = fopen("pruebabin", "wb");
	fwrite(&instr, sizeof(int), 12, prueba);

	fclose(prueba);

	return 0;
}