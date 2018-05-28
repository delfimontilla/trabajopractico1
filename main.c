#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototipos.h"
#include "macros.h"
#include "simpletron.h"
#include "status.h"

#define LANG_ENGLISH /*elección del idioma del programa*/

#ifdef LANG_SPANISH
#include "LANG_SPANISH.h"

#elif LANG_ENGLISH
#include "LANG_ENGLISH.h"

#else 
#include LANG_SPANISH
#endif

int main(int argc, char *argv[])
{
	estado_t simpletron;
	estado_t *estado;

	parametros_t argumentos;
	parametros_t *params;
    status_t st;
    FILE *fentrada, *fsalida;
    
    params=NULL;
    estado=NULL;
    fentrada=NULL;
    fsalida=NULL;

    estado=&simpletron;
    params=&argumentos;


	if(argc==ARGC2_MAX){
		if((st=validar_ayuda(argc, argv))!=ST_OK){
			return EXIT_FAILURE;
		}
	}
    else {
    	if((st=validar_argumentos(argc, argv, params, estado, fentrada, fsalida))!=ST_OK){
    		return EXIT_FAILURE;
    	}
        estado->palabras = calloc(params->cant_palabras, sizeof(params->cant_palabras));
    	
    	if(estado->palabras==NULL){
    		fprintf(stderr, "%s:%s\n",MSJ_ERROR,MSJ_ERROR_NO_MEM );
    		return EXIT_FAILURE;
    	}
    	while(st!=ST_SALIR) st=operaciones(estado);
    	seleccionar_salida(argv,params,estado,fsalida);
    	liberar_memoria(estado);

        if(fentrada!=NULL)
    	 fclose(fentrada);
    	if(fsalida!=NULL)
	    fclose(fsalida);
    }
    return EXIT_SUCCESS;
}

status_t leer_archivo_bin(parametros_t *params, estado_t *estado, FILE *fentrada,FILE *fsalida)
 /*recibe los punteros: a la estructura de los argumentos para poder acceder al valor de cant_palabras (cantidad de instrucciones),
 a la estructura de estado para cargar las instrucciones en el vector palabras, o liberar la memoria en caso de error;
 al archivo de entrada para poder leer los datos,
 y al archivo de salida (para cerrar dos archivos en caso de error)*/
{
 
	int i;
	int instruccion;
	instruccion =0;
 	for(i=0; i<params->cant_palabras;i++){
    	if(fread(&instruccion,sizeof(int),MAX_LARGO_PALABRA,fentrada)!=MAX_LARGO_PALABRA){
    		liberar_memoria(estado);
    		fclose(fentrada);
    		return ST_ERROR_FUERA_RANGO;
    	}
 		if(instruccion==FIN)
 			return ST_OK;
 		if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 			return ST_ERROR_FUERA_RANGO;
 		estado->palabras[i]=instruccion;
 	}
 	printf("%s\n",MSJ_CARGA_COMPLETA);
 	printf("%s\n",MSJ_COMIENZO_EJECUCION);
 	return ST_OK;
}

status_t leer_teclado(parametros_t *params, estado_t *estado)
 /*recibe los punteros: a la estructura de los argumentos para poder acceder al valor de cant_palabras (cantidad de instrucciones) y
 a la estructura de estado para cargar las instrucciones en el vector palabras*/
{
 
 	int i;
 	char aux[MAX_LARGO_PALABRA];
 	long instruccion;
 	char *pc;
 	instruccion = 0;
 	printf("%s\n",MSJ_BIENVENIDA);
 	for(i=0; i<params->cant_palabras;i++){
 		printf("%2.i ? \n", i);
 	   if(fgets(aux,MAX_LARGO_PALABRA,stdin)==NULL){
 		liberar_memoria(estado);
    	return ST_ERROR_FUERA_RANGO;
	    }
	    instruccion = strtol(aux,&pc,10);
	    if(*pc!='\0'&& *pc!='\n')
			return ST_ERROR_NO_NUMERICO;
	 	if(instruccion==FIN)
	 		return ST_OK;
	 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
	 		return ST_ERROR_FUERA_RANGO;
	 	estado->palabras[i]=instruccion;
	 }
	 printf("%s\n",MSJ_CARGA_COMPLETA);
	 printf("%s\n",MSJ_COMIENZO_EJECUCION);	
	 return ST_OK;
}

status_t leer_archivo_txt(parametros_t *params, estado_t *estado,FILE *fentrada, FILE *fsalida)
 /*recibe los punteros: a la estructura de los argumentos para poder acceder al valor de cant_palabras (cantidad de instrucciones),
 a la estructura de estado para cargar las instrucciones en el vector palabras,
 al archivo de entrada para poder leer los datos,
 y al archivo de salida (para cerrar los dos archivos en caso de error)*/
{
	size_t i;
	char aux[MAX_LARGO_PALABRA];
	long instruccion;
	char *pc;
	instruccion = 0;

 	for(i=0; i<params->cant_palabras;i++){
	    if(fgets(aux,MAX_LARGO_PALABRA,fentrada)==NULL){
	    	liberar_memoria(estado);
	    	fclose(fentrada);
	    	return ST_ERROR_FUERA_RANGO;
	    }
	    instruccion = strtol(aux,&pc,10); 
	    if(*pc!='\0'&& *pc!='\n')
	    	return ST_ERROR_NO_NUMERICO;
	 /*validar que "     " no sea un 0*/ 
	 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
	 		return ST_ERROR_FUERA_RANGO;
	 	estado->palabras[i]=instruccion;
	 }
	 printf("%s\n",MSJ_CARGA_COMPLETA);
	 printf("%s\n",MSJ_COMIENZO_EJECUCION); 
	 return ST_OK;
}

status_t validar_argumentos (int argc , char *argv[], parametros_t *params, estado_t *estado, FILE * fentrada, FILE * fsalida)
 /*recibe arc y argv para realizar las validacione correspondientes a su cantidad y contenido;
 además recibe los punteros: a la estructura de los argumentos para poder cargar el valor a cant_palabras (cantidad de instrucciones),
 a la estructura de estado para después ser pasada a la funcion de lectura correspondiente,
 al archivo de entrada para poder leer los datos,
 y al archivo de salida para poder escribir los datos*/
{
	char *pc=NULL;
	if(!argv){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_PTR_NULO );
		return ST_ERROR_PTR_NULO;
	}

	if(ARGC_MAX!=argc){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_ARG );
		return ST_ERROR_CANT_ARG;
	}

	if(argv[ARG_POS_CANT_PALABRAS]==NULL){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;
	}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_PALABRAS );
			return ST_ERROR_CANT_PALABRAS;
		}
	}
	if(argv[ARG_POS_fentrada2]!=NULL){
		if(strcmp(argv[ARG_POS_fentrada2],OPCION_TXT)){
			if((fentrada=fopen(argv[ARG_POS_fentrada1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO);
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_txt(params, estado, fentrada, fsalida);
		}
		else if (strcmp(argv[ARG_POS_fentrada2],OPCION_BIN)){
			if((fentrada=fopen(argv[ARG_POS_fentrada1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_bin(params, estado, fentrada, fsalida);
		}
	}
	else if(argv[ARG_POS_fentrada2]==NULL && argv[ARG_POS_fentrada1]!=NULL){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO);
		return ST_ERROR_APERTURA_ARCHIVO;
	}
	else if(strcmp(argv[ARG_POS_fentrada2],OPCION_STDIN)){
		leer_teclado(params,estado);
	}	

	if(argv[ARG_POS_fsalida2]!=NULL){
		if(strcmp(argv[ARG_POS_fentrada2],OPCION_TXT)){
			if((fsalida=fopen(argv[ARG_POS_fsalida1],"wt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
	            fclose(fsalida);
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
		else if (strcmp(argv[ARG_POS_fentrada2],OPCION_BIN)){
			if((fsalida=fopen(argv[ARG_POS_fsalida1 ],"wb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
			    fclose(fsalida);
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
	}
	else if(argv[ARG_POS_fsalida2]==NULL && argv[ARG_POS_fsalida1]!=NULL){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
			return ST_ERROR_APERTURA_ARCHIVO;
		}

	return ST_OK;
}

status_t validar_ayuda(int argc, char *argv[])
 /*recibe arc y argv para verificar si el usuario ejecuto el programa con el argumento de ayuda 
 para que fuese impresa la información correspondiente*/
{

	if(!argv){
		return ST_ERROR_PTR_NULO;
	}
	if(argc!=ARGC2_MAX){
		return ST_ERROR_CANT_ARG;
	}
	if(argv[ARG_POS_H]!=NULL){
		imprimir_ayuda();
	}	

	return ST_OK;
}

status_t imprimir_ayuda()
 /*Imprime la información de ayuda: tabla del orden de los argumentos y
 tabla de las operaciones validas*/
{

	printf("%s\n", MSJ_ACLARACION_AYUDA );

	printf("%s     %s     %s\n",MSJ_TITULO_ARG, MSJ_TITULO_OPC, MSJ_TITULO_DESC);
	printf("%s     %s     %s\n",MSJ_AYUDA_ARG, MSJ_AYUDA_OPC, MSJ_AYUDA_DESC);
	printf("%s     %s     %s\n",MSJ_MEMORIA_ARG, MSJ_MEMORIA_OPC, MSJ_MEMORIA_DESC);
	printf("%s     %s     %s\n",MSJ_ENTRADA_ARG, MSJ_ENTRADA_OPC, MSJ_ENTRADA_DESC);
	printf("%s     %s     %s\n",MSJ_ARCHIVO_ARG, MSJ_ARCHIVO_OPC_BIN, MSJ_ARCHIVO_DESC_BIN);
	printf("       %s     %s\n",MSJ_ARCHIVO_OPC_TXT,MSJ_ARCHIVO_DESC_TXT);
	printf("%s     %s     %s\n",MSJ_SALIDA_ARG, MSJ_SALIDA_OPC, MSJ_SALIDA_DESC);
	printf("%s     %s     %s\n",MSJ_SALIDA_ARCH_ARG, MSJ_SALIDA_ARCH_BIN_OPC, MSJ_SALIDA_ARCH_BIN_DESC);
	printf("       %s     %s\n",MSJ_SALIDA_ARCH_TXT_OPC, MSJ_SALIDA_ARCH_TXT_DESC);

	printf("%s     %s     %s\n",TAB_TITULO_OP,TAB_TITULO_CODE,TAB_TITULO_DESC);
	printf("%s\n",TAB_ENT_SAL);
	printf("%s     %s     %s\n",TAB_LEER_OP,TAB_LEER_CODE,TAB_LEER_DESC);
	printf("%s     %s     %s\n",TAB_ESCRIBIR_OP,TAB_ESCRIBIR_CODE,TAB_ESCRIBIR_DESC);
	printf("%s\n",TAB_MOV);
	printf("%s     %s     %s\n",TAB_CARGAR_OP,TAB_CARGAR_CODE,TAB_CARGAR_DESC);
	printf("%s     %s     %s\n",TAB_GUARDAR_OP,TAB_GUARDAR_CODE,TAB_GUARDAR_DESC);
	printf("%s     %s     %s\n",TAB_PCARGAR_OP,TAB_PCARGAR_CODE,TAB_PCARGAR_DESC);
	printf("%s     %s     %s\n",TAB_PGUARDAR_OP,TAB_PGUARDAR_CODE,TAB_PGUARDAR_DESC);
	printf("%s\n",TAB_MATE);
	printf("%s     %s     %s\n",TAB_SUMAR_OP,TAB_SUMAR_CODE,TAB_SUMAR_DESC);
	printf("%s     %s     %s\n",TAB_RESTAR_OP,TAB_RESTAR_CODE, TAB_RESTAR_DESC);
	printf("%s     %s     %s\n",TAB_DIVIDIR_OP,TAB_DIVIDIR_CODE,TAB_DIVIDIR_DESC);
	printf("%s     %s     %s\n",TAB_MULT_OP,TAB_MULT_CODE,TAB_MULT_DESC);
	printf("%s\n",TAB_CONTROL);
	printf("%s     %s     %s\n",TAB_JUMP_OP, TAB_JUMP_CODE,TAB_JUMP_DESC);
	printf("%s     %s     %s\n",TAB_JMPNEG_OP, TAB_JMPNEG_CODE,TAB_JMPNEG_DESC);
	printf("%s     %s     %s\n",TAB_JMPZERO_OP, TAB_JMPZERO_CODE,TAB_JMPZERO_DESC);
	printf("%s     %s     %s\n",TAB_JNZ_OP,TAB_JNZ_CODE,TAB_JNZ_DESC);
	printf("%s     %s     %s\n",TAB_DJNZ_OP,TAB_DJNZ_CODE,TAB_DJNZ_DESC);
	printf("%s     %s     %s\n",TAB_FIN_OP,TAB_FIN_CODE,TAB_FIN_DESC);

	return ST_OK;
}


status_t seleccionar_salida(char *argv[],parametros_t *params, estado_t *estado, FILE *fsalida)
 /*recibe argv para verficar cual es el formato del archivo de salida o si se hara por stdout;
 además recibe el puntero a la estructura de argumentos, de estado y al archivo de salida para poder pasarselos
 a las funciones que se encargaran de imprimir en el formato correspondiente.*/
{

	if(strcmp(argv[ARG_POS_fentrada2],OPCION_TXT)){
		imprimir_archivo_txt(params, estado, fsalida);
	}
	else if (strcmp(argv[ARG_POS_fentrada2],OPCION_BIN)){
		imprimir_archivo_bin(params, estado, fsalida);
	}

    else if(strcmp(argv[ARG_POS_fentrada2],OPCION_TXT)){
    	imprimir_pantalla(params,estado);
    }

    return ST_OK;
}


status_t imprimir_pantalla(parametros_t *params, estado_t * estado)
 /*Recibe los punteros a la estructura de argumentos y a la de estado para imprimir los datos guardados
 en el acumulador, en el contador del programa, la ultima instruccion ejecutada, 
 el ultimo opcode y operando, además de la memoria de todas las palabras, en forma de matriz*/
{
	int i,k,l;

    printf("%s\n", MSJ_REGISTRO);
	printf("%25s: %6i\n",MSJ_ACUM, estado->acumulador );
	printf("%25s: %6i\n",MSJ_CONT_PROG, estado->contador_programa );
	printf("%25s: %6i\n",MSJ_INST, estado->palabras[estado->contador_programa] );	
	estado->opcode = *(estado->palabras + estado->contador_programa) /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	printf("%25s: %6i\n",MSJ_OPCODE, estado->opcode );
	printf("%25s: %6i\n",MSJ_OPERANDO, estado->operando );
	printf("    ");
	for (l = 0; l < 10; l++)
		printf("  %i   ",l) ;
	for ( i = 0; i < params->cant_palabras ; i++){
      if ((i%10)==0){
		  printf("\n%02i  ",i);
	  }	  
		printf("%+04i ",estado->palabras[i] );
	}
    printf("\n");
    return ST_OK;
}

status_t imprimir_archivo_txt(parametros_t *params, estado_t *estado, FILE *fsalida)
 /*Recibe el puntero del archivo de salida, los punteros a la estructura de argumentos y 
 a la de estado para imprimir los datos guardados en el acumulador, en el contador del programa, 
 la ultima instruccion ejecutada, el ultimo opcode y operando, 
 además de la memoria de todas las palabras, en forma de matriz*/
{
	int i,k,l;
    fprintf(fsalida,"%s\n", MSJ_REGISTRO);
	fprintf(fsalida, "%25s: %6d\n",MSJ_ACUM, estado->acumulador );
	fprintf(fsalida, "%25s: %6d\n",MSJ_CONT_PROG, estado->contador_programa );
	fprintf(fsalida, "%25s: %6d\n",MSJ_INST, estado->palabras[estado->contador_programa] );
	estado->opcode = estado->palabras[estado->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fprintf(fsalida, "%25s: %6d\n",MSJ_OPCODE, estado->opcode );
	fprintf(fsalida, "%25s: %6d\n",MSJ_OPERANDO, estado->operando );
	fprintf(fsalida,"    ");
	for (l = 0; l < 10; l++)
		fprintf(fsalida,"  %i   ",l) ;
	for ( i = 0; i < params->cant_palabras ; i++){ 
      if ((i%10)==0){
		  fprintf(fsalida,"\n%02i  ",i);
	  }		  
		fprintf(fsalida,"%+04i ",estado->palabras[i] );
	}
    fprintf(fsalida,"\n");
    return ST_OK;
}

status_t imprimir_archivo_bin (parametros_t *params, estado_t *estado, FILE *fsalida)
 /*Recibe el puntero del archivo de salida, los punteros a la estructura de argumentos y 
 a la de estado para imprimir los datos guardados en el acumulador, en el contador del programa, 
 la ultima instruccion ejecutada, el ultimo opcode y operando, además de la memoria de todas las palabras.*/
{
	
	fwrite(&estado->acumulador, sizeof(estado_t),1, fsalida);
	fwrite(&estado->contador_programa, sizeof(estado_t),1, fsalida );
	fwrite(&estado->palabras[estado->contador_programa], sizeof(estado_t),1, fsalida);
	estado->opcode = estado->palabras[estado->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	estado->operando = estado->palabras[estado->contador_programa] - (estado->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fwrite(&estado->opcode, sizeof(estado_t),1, fsalida);
	fwrite(&estado->operando, sizeof(estado_t),1, fsalida);	
	fwrite(estado->palabras, sizeof(int), params->cant_palabras, fsalida);
	return ST_OK;
}


status_t liberar_memoria(estado_t * estado) /*LA ESTRUCTURA RECIBIDA DEBERIA SER INTEGRAMENTE EN MEM DINAMICA*/
/*Recibe el puntero a la estructura de estado para liberar la memoria pedida*/
{	
	if (estado!=NULL)
		free(estado->palabras);

	estado->palabras=NULL;
	return ST_OK;
}

status_t operaciones (estado_t * estado)
/*Recibe el puntero a la estructura de estado para hacer un análisis de las instrucciones que se encuentran
en el vector palabras, y después se llama a una función que realiza la operación necesaria.*/
{
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

status_t op_leer (estado_t * estado)
 /*Lee una palabra por stdin a una posicion de memoria que está indicada por el operando (miembro de la estructura estado)*/
{
	int * lectura;
	int numero;
	char * pc;


	pc=NULL;
	lectura=NULL;

	printf("%s\n", MSJ_INGRESO_PALABRA);

	if (fgets((char*)lectura,MAX_LARGO_PALABRA,stdin)==NULL)
		fprintf(stderr, "%s\n", MSJ_ERROR_PALABRA_NULA );
		return ST_ERROR_PALABRA_VACIA; /*la palabra ingresada es nula*/	

	numero = strtol(lectura,&pc,10);
	
	if(*pc!='\0'&& *pc!='\n')
	    	return ST_ERROR_NO_NUMERICO; 
	    /*validar que "     " no sea un 0*/ 
	
	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
	 		return ST_ERROR_FUERA_RANGO;

	estado->palabras[estado->operando] = numero;	
	return ST_OK;
}

status_t op_escribir(estado_t * estado)
 /*imprime por stdout el contenido de la posicion del operando (miembro de la estructura estado)*/
{
	fprintf(stdout, "%s %i : %i\n", MSJ_IMPRIMIR_PALABRA,estado->operando, estado->palabras[estado->operando]);
	return ST_OK;
}

status_t op_cargar (estado_t * estado)
/*Carga en el acumulador (miembro de la estructura estado) la posicion de memoria indicada 
por el operando(miembro de la estructura estado)*/
{
	if(estado->operando > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}
	estado->acumulador = estado->palabras[estado->operando];
	return ST_OK;
}


status_t op_pcargar (estado_t * estado)
 /*Carga en el acumulador (miembro de la estructura estado) la posicion de memoria indicada 
 por la palabra a la que apunta el operando(miembro de la estructura estado)*/
{
	if(estado->operando > params->cant_palabras  || estado->palabras[estado->operando] > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	estado->acumulador = estado->palabras[estado->palabras[estado->operando]];
	return ST_OK;
}

status_t op_guardar (estado_t * estado)
 /*guarda en la posicion de memoria indicada por el operando(miembro de la estructura estado)
  lo que está en el acumulador(miembro de la estructura estado)*/
{
	if(estado->operando > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	estado->palabras[estado->operando] = estado->acumulador ;
	return ST_OK;
}

status_t op_pguardar (estado_t * estado)
 /*guarda en la posicion de memoria indicada por la palabra a la que apunta el operando (miembro de la estructura estado) 
 lo que esta en el acumulador(miembro de la estructura estado)*/
{
	if(estado->operando > params->cant_palabras || estado->palabras[estado->operando] > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	estado->palabras[estado->palabras[estado->operando]] = estado->acumulador ;
	return ST_OK;
}


status_t op_restar (estado_t * estado)
 /*resta al acumulador (miembro de la estructura estado) lo guardado en la posicion de memoria indcada 
 por el operando(miembro de la estructura estado)*/
{
	estado->acumulador -= estado->palabras[estado->operando];
	return ST_OK;
}

status_t op_dividir (estado_t * estado)
 /*divide al acumulador (miembro de la estructura estado) por lo guardado en la posicion de memoria indicada
  por el operando(miembro de la estructura estado)*/{
	estado->acumulador /= estado->palabras[estado->operando];
	return ST_OK;
}

status_t op_multiplicar (estado_t * estado)
 /*multiplica al acumulador (miembro de la estructura estado)lo guardado en la posicion de memoria indicada por el operando(miembro de la estructura estado)*/
{
	estado->acumulador *= estado->palabras[estado->operando];
	return ST_OK;
}

status_t op_sumar(estado_t * estado)
 /*suma al acumulador (miembro de la estructura estado) lo guardado en la posicion de memoria indcada 
 por el operando(miembro de la estructura estado)*/
{
	estado->acumulador += estado->palabras[estado->operando];
	return ST_OK;
}

status_t op_jmp (estado_t * estado)
/*salta a la posicion de memoria indicada por el operando(miembro de la estructura estado) menos un valor*/
{
	estado->contador_programa = estado->operando;
	return ST_OK;
}

status_t op_djnz (estado_t * estado)
 /*decrementa en 1 el acumulador (miembro de la estructura estado) y salta a la posicion indicada 
 por el operando (miembro de la estructura estado) en el caso que el acumulador sea distinto de 0*/
{
	estado->acumulador--;
	if (estado->acumulador!=0){
		estado->contador_programa = estado->operando;
	}
	else
		estado->contador_programa++;
	return ST_OK;
}
