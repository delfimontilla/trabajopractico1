
/*COMO DEBERIA IMPLMENTARSE EN EL MAIN
int main (lo que sea){
	status_t st;
	while(st!=ST_SALIR) st=operaciones(&acumulador, palabras[cant_palabras],&contador_programa);
}


*/
status_t operaciones ( 
int * acumulador /*posicion de memoria del acumulador*/,
int  palabras[parametros_t->cant_palabras] /*vector donde estan guardadas las palabras*/
int * contador_programa /*cuenta el numero de paso y de memoria que se encuentra el programa*/)
/*Funcion que recibe las dos primeras posiciones de la posicion y decide que operacion correr*/
{
	int opcode;
	int operando;

	if (palabras<0){
		*contador_programa++;
		return ST_OK_NEG;
	}
	else{
		opcode = palabras[contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
		operando = palabras[contador_programa] - (opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
		switch (opcode){
			case (LEER):
				leer(operando, palabras[parametros_t->cant_palabras] );
				*contador_programa++;
				break;
			case (ESCRIBIR):
				escribir(operando, palabras[parametros_t->cant_palabras] );
				*contador_programa++;
				break;
			case (CARGAR):
				cargar(&acumulador, palabras[parametros_t->cant_palabras], operando );
				*contador_programa++;
				break;
			case (GUARDAR):
				guardar(&acumulador, palabras[parametros_t->cant_palabras],operando );
				*contador_programa++;
				break;
			case (PCARGAR):
				pcargar(operando);/*falta hacer, como se hace?*/
				*contador_programa++;
				break;
			case(PGUARDAR):
				pguardar(operando);/*falta hacer, como se hace?*/
				*contador_programa++;
				break;
			case(SUMAR):
				sumar(&acumulador, palabras[parametros_t->cant_palabras],operando );
				*contador_programa++;
				break;
			case(RESTAR):
				restar(&acumulador, palabras[parametros_t->cant_palabras],operando );
				*contador_programa++;
				break;
			case(DIVIDIR):
				dividir(&acumulador, palabras[parametros_t->cant_palabras],operando );
				*contador_programa++;
				break;
			case(MULTIPLICAR):
				multiplicar(&acumulador, palabras[parametros_t->cant_palabras],operando );
				*contador_programa++;
				break;
			case(JMP):
				jmp(acumulador,&contador_programa, operando);
				break;
			case(JMPNEG):
				if(acumulador<0)
					jmp(&acumulador,&contador_programa, operando);
				else
					contador_programa++;
				break;
			case(JMPZERO):
				if(acumulador=0)
					jmp(&acumulador,&contador_programa, operando);
				else
					contador_programa++;
				break;
			case(JNZ):
				if(acumulador!=0)
					jmp(&acumulador,&contador_programa, operando);
				else
					contador_programa++;
				break;
			case(DJNZ):
				djnz(&acumulador,&contador_programa, operando);
				break;
			case(HALT):
				salir = -1;
				break;
			default: 
				break;
		}
	}
	if (salir = -1){
		return ST_SALIR;
	}
	else{
		return ST_OK;
	}
}
