status_t operaciones (estado_t * estado){
	int salir;
	if (estado->palabras[estado->contador_programa]<0){
		estado->contador_programa++;
		return ST_OK_NEG;
	}
	else{
		estado->opcode = estado->palabras[estado->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
		estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
		switch (estado->opcode){
			case (LEER):
				op_leer(estado);
				estado->contador_programa++;
				break;
			case (ESCRIBIR):
				op_escribir(estado);
				estado->contador_programa++;
				break;
			case (CARGAR):
				op_cargar(estado);
				estado->contador_programa++;
				break;
			case (GUARDAR):
				op_guardar(estado);
				estado->contador_programa++;
				break;
			case (PCARGAR):
				op_pcargar(estado);
				estado->contador_programa++;
				break;
			case(PGUARDAR):
				op_pguardar(estado);
				estado->contador_programa++;
				break;
			case(SUMAR):
				op_sumar(estado);
				estado->contador_programa++;
				break;
			case(RESTAR):
				op_restar(estado);
				estado->contador_programa++;
				break;
			case(DIVIDIR):
				op_dividir(estado);
				estado->contador_programa++;
				break;
			case(MULTIPLICAR):
				op_multiplicar(estado);
				estado->contador_programa++;
				break;
			case(JMP):
				op_jmp(estado);
				break;
			case(JMPNEG):
				if(estado->acumulador<0)
					op_jmp(estado);
				else
					estado->contador_programa++;
				break;
			case(JMPZERO):
				if(estado->acumulador==0)
					op_jmp(estado);
				else
					estado->contador_programa++;
				break;
			case(JNZ):
				if(estado->acumulador!=0)
					op_jmp(estado);
				else
					estado->contador_programa++;
				break;
			case(DJNZ):
				op_djnz(estado);
				break;
			case(HALT):
				salir = -1;
				break;
			default: 
				break;
		}
	}
	if (salir == -1){
		return ST_SALIR;
	}
	else{
		return ST_OK;
	}
}
