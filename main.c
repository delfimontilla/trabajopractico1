#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototipos.h"
#include "constantes.h"
#include "simpletron.h"
#include "status.h"

#define LANG_ENGLISH /*elección del idioma del programa*/

#ifdef LANG_SPANISH
#include "LANG_SPANISH.h"

#elif defined (LANG_ENGLISH)
#include "LANG_ENGLISH.h"

#else 
#include "LANG_SPANISH.h"
#endif

int main(int argc, char *argv[])
{
	simpletron_t * simpletron;
	size_t cant_palabras;
    status_t st;
    FILE *fentrada, *fsalida;
    
   	cant_palabras=0;
    simpletron=NULL;
    fentrada=NULL;
    fsalida=NULL;

    	if((st=validar_argumentos(argc, argv, &argumentos, simpletron, fentrada, fsalida))!=ST_OK){
    		return EXIT_FAILURE;
    	}
        
		if((st=simpletron(&simpletron, cant_palabras, palabras))!=ST_OK){
			free(palabras);
			fprintf(stderr, "%s\n", errmsg[st]);
    		return EXIT_FAILURE;
    	}
    	while(st!=ST_SALIR) 
    		st=ejecutar_simpletron(simpletron);
    	
    	seleccionar_salida(argv,params,simpletron,fsalida);
    	
    	if((st=liberar_memoria(simpletron))!=ST_OK){
    		fprintf(stderr, "%s:%s\n", MSJ_ERROR, MSJ_ERROR_LIBERAR_MEM);
    		return EXIT_FAILURE;

        if(fentrada!=NULL)
    	    fclose(fentrada);
    	if(fsalida!=NULL)
	    	fclose(fsalida);
    }
    return EXIT_SUCCESS;
}

status_t validar_argumentos (int argc , char *argv[],size_t *cant_palabras,  simpletron_t *simpletron, FILE ** fentrada, FILE ** fsalida)
 /*recibe arc y argv para realizar las validacione correspondientes a su cantidad y contenido;
 además recibe los punteros: a la estructura de los argumentos para poder cargar el valor a cant_palabras (cantidad de instrucciones),
 a la estructura de simpletron para después ser pasada a la funcion de lectura correspondiente,
 al archivo de entrada para poder leer los datos,
 y al archivo de salida para poder escribir los datos*/
{
	char *pc=NULL;
		
	if(!argv){
		return ST_ERROR_PTR_NULO;
	}

	if(argc==ARGC_MIN){

		if((strcmp(argv[ARG_POS_H],ARG_H))==0){
			imprimir_ayuda();
			return ST_OK;
		}
	}

	if(argc!=ARGC_MAX){
		return ST_ERROR_CANT_ARG;
	}

	if((strcmp(argv[ARG_POS_CANT_PALABRAS],ARG_VALIDO))==0){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;
	}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
			return ST_ERROR_CANT_PALABRAS;
		}
	}
	if((strcmp(argv[ARG_POS_FENTRADA_TIPO],ARG_VALIDO))!=0){
		if((strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_TXT))==0){
			if((*fentrada=fopen(argv[ARG_POS_FENTRADA_NOMBRE],"rt"))==NULL){
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
		else if ((strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_BIN))==0){
			if((*fentrada=fopen(argv[ARG_POS_FENTRADA_NOMBRE],"rb"))==NULL){
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
	}
	else if((strcmp(argv[ARG_POS_FENTRADA_TIPO],ARG_VALIDO))==0 && (strcmp(argv[ARG_POS_FENTRADA_NOMBRE],ARG_VALIDO))!=0){
		return ST_ERROR_APERTURA_ARCHIVO;
	}

	if((strcmp(argv[ARG_POS_FSALIDA_TIPO],ARG_VALIDO))!=0){
		if((strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_TXT))==0){
			if((*fsalida=fopen(argv[ARG_POS_FSALIDA_NOMBRE],"wt"))==NULL){
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
		else if ((strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_BIN))==0){
			if((*fsalida=fopen(argv[ARG_POS_FSALIDA_NOMBRE ],"wb"))==NULL){  
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
	
	else if((strcmp(argv[ARG_POS_FSALIDA_TIPO],ARG_VALIDO))==0 && (strcmp(argv[ARG_POS_FSALIDA_NOMBRE],ARG_VALIDO))!=0){
			return ST_ERROR_APERTURA_ARCHIVO;
		}

	return ST_OK;
}
}


status_t simpletron (simpletron_t **simpletron, size_t cant_palabras, palabra_t * palabras){

	if (!simpletron||!argumentos)
		return ST_ERROR_PTR_NULO;

	if(!cant_palabras)
		return ST_ERROR_NADA_QUE_CARGAR;

	if((*simpletron = (simpletron_t **) calloc((sizeof(simpletron_t), 1)))==NULL){
		return ST_ERROR_NO_MEM;
	}
	
	if(((*simpletron)->palabras = (palabra_t *) malloc(cant_palabras*(sizeof(palabra_t))))==NULL){
		free(*simpletron);
		*simpletron=NULL;
		return ST_ERROR_NO_MEM;
	}

	memcpy ((*simpletron)->palabras, palabras, cant_palabras*sizeof(palabra_t));

	return ST_OK;
}

status_t leer_archivo_bin (simpletron_t *simpletron, FILE *fentrada)
 /*recibe los punteros: a la estructura de los argumentos para poder acceder al valor de cant_palabras (cantidad de instrucciones),
 a la estructura de simpletron para cargar las instrucciones en el vector palabras, o liberar la memoria en caso de error;
 al archivo de entrada para poder leer los datos,
 y al archivo de salida (para cerrar dos archivos en caso de error)*/
{
	int i;
	int instruccion;

	instruccion =0;
 	for(i=0; i<params->cant_palabras;i++){
    	if(fread(&instruccion,sizeof(int),MAX_LARGO_INGRESO,fentrada)!=MAX_LARGO_INGRESO){
    		liberar_memoria(simpletron);
    		return ST_ERROR_FUERA_RANGO;
    	}

 		
 		if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 			return ST_ERROR_FUERA_RANGO;
 		
 		simpletron->palabras[i]=instruccion;
 	}

 	return ST_OK;
}

status_t leer_archivo_txt(parametros_t *params, simpletron_t *simpletron,FILE *fentrada, FILE *fsalida)
 /*recibe los punteros: a la estructura de los argumentos para poder acceder al valor de cant_palabras (cantidad de instrucciones),
 a la estructura de simpletron para cargar las instrucciones en el vector palabras y 
 al archivo de entrada para poder */
{
	size_t i;
	char aux[MAX_LARGO_INGRESO];
	long instruccion;
	char *pc;
	instruccion = 0;

 	for(i=0; i<params->cant_palabras;i++){
	    if(fgets(aux,MAX_LARGO_INGRESO,fentrada)==NULL){
	    	liberar_memoria(simpletron);
	    	return ST_ERROR_FUERA_RANGO;
	    }

	    instruccion = strtol(aux,&pc,10); 
	    
	    if(*pc!='\0'&& *pc!='\n')
	    	return ST_ERROR_NO_NUMERICO;
	 /*validar que "     " no sea un 0*/ 
	 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
	 		return ST_ERROR_FUERA_RANGO;
	 	
	 	simpletron->palabras[i]=instruccion;
	 }

	 printf("%s\n",MSJ_CARGA_COMPLETA);
	 printf("%s\n",MSJ_COMIENZO_EJECUCION); 
	 
	 return ST_OK;

{
 	

 	printf("%s\n",MSJ_BIENVENIDA);

 	for(i=0; i<params->cant_palabras;i++){
 		
 		printf("%2.i ? \n", i);
 	    
 	    if(fgets(aux,MAX_LARGO_INGRESO,stdin)==NULL){
 			liberar_memoria(simpletron);
    		return ST_ERROR_FUERA_RANGO;
	    }
	    
	    instruccion = strtol(aux,&pc,10);
	    
	    if(*pc!='\0'&& *pc!='\n')
			return ST_ERROR_NO_NUMERICO;
	 	
	 	if(instruccion==FIN)
	 		return ST_OK;
	 	
	 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA){
	 		liberar_memoria(simpletron);
	 		return ST_ERROR_FUERA_RANGO;
	 	}

	 	simpletron->palabras[i]=instruccion;
	 }

	 printf("%s\n",MSJ_CARGA_COMPLETA);
	 printf("%s\n",MSJ_COMIENZO_EJECUCION);	

	 return ST_OK;
}





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


status_t seleccionar_salida(char *argv[],parametros_t *params, simpletron_t *simpletron, FILE *fsalida)
 /*recibe argv para verficar cual es el formato del archivo de salida o si se hara por stdout;
 además recibe el puntero a la estructura de argumentos, de simpletron y al archivo de salida para poder pasarselos
 a las funciones que se encargaran de imprimir en el formato correspondiente.*/
{

	if(strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_TXT)){
		imprimir_archivo_txt(params, simpletron, fsalida);
	}
	else if (strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_BIN)){
		imprimir_archivo_bin(params, simpletron, fsalida);
	}

    else if(strcmp(argv[ARG_POS_FENTRADA_TIPO],OPCION_TXT)){
    	imprimir_pantalla(params,simpletron);
    }

    return ST_OK;
}


status_t imprimir_pantalla(parametros_t *params, simpletron_t * simpletron)
 /*Recibe los punteros a la estructura de argumentos y a la de simpletron para imprimir los datos guardados
 en el acumulador, en el contador del programa, la ultima instruccion ejecutada, 
 el ultimo opcode y operando, además de la memoria de todas las palabras, en forma de matriz*/
{
	int i,k,l;

    printf("%s\n", MSJ_REGISTRO);
	printf("%25s: %6i\n",MSJ_ACUM, simpletron->acumulador );
	printf("%25s: %6i\n",MSJ_CONT_PROG, simpletron->contador_programa );
	printf("%25s: %6i\n",MSJ_INST, simpletron->palabras[simpletron->contador_programa] );	
	simpletron->opcode = *(simpletron->palabras + simpletron->contador_programa) /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	simpletron->operando = simpletron->palabras[simpletron->contador_programa] - (simpletron->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	printf("%25s: %6i\n",MSJ_OPCODE, simpletron->opcode );
	printf("%25s: %6i\n",MSJ_OPERANDO, simpletron->operando );
	printf("    ");
	for (l = 0; l < 10; l++)
		printf("  %i   ",l) ;
	for ( i = 0; i < params->cant_palabras ; i++){
      if ((i%10)==0){
		  printf("\n%02i  ",i);
	  }	  
		printf("%+04i ",simpletron->palabras[i] );
	}
    printf("\n");
    return ST_OK;
}

status_t imprimir_archivo_txt(parametros_t *params, simpletron_t *simpletron, FILE *fsalida)
 /*Recibe el puntero del archivo de salida, los punteros a la estructura de argumentos y 
 a la de simpletron para imprimir los datos guardados en el acumulador, en el contador del programa, 
 la ultima instruccion ejecutada, el ultimo opcode y operando, 
 además de la memoria de todas las palabras, en forma de matriz*/
{
	int i,k,l;
    fprintf(fsalida,"%s\n", MSJ_REGISTRO);
	fprintf(fsalida, "%25s: %6d\n",MSJ_ACUM, simpletron->acumulador );
	fprintf(fsalida, "%25s: %6d\n",MSJ_CONT_PROG, simpletron->contador_programa );
	fprintf(fsalida, "%25s: %6d\n",MSJ_INST, simpletron->palabras[simpletron->contador_programa] );
	simpletron->opcode = simpletron->palabras[simpletron->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	simpletron->operando = simpletron->palabras[simpletron->contador_programa] - (simpletron->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fprintf(fsalida, "%25s: %6d\n",MSJ_OPCODE, simpletron->opcode );
	fprintf(fsalida, "%25s: %6d\n",MSJ_OPERANDO, simpletron->operando );
	fprintf(fsalida,"    ");
	for (l = 0; l < 10; l++)
		fprintf(fsalida,"  %i   ",l) ;
	for ( i = 0; i < params->cant_palabras ; i++){ 
      if ((i%10)==0){
		  fprintf(fsalida,"\n%02i  ",i);
	  }		  
		fprintf(fsalida,"%+04i ",simpletron->palabras[i] );
	}
    fprintf(fsalida,"\n");
    return ST_OK;
}

status_t imprimir_archivo_bin (parametros_t *params, simpletron_t *simpletron, FILE *fsalida)
 /*Recibe el puntero del archivo de salida, los punteros a la estructura de argumentos y 
 a la de simpletron para imprimir los datos guardados en el acumulador, en el contador del programa, 
 la ultima instruccion ejecutada, el ultimo opcode y operando, además de la memoria de todas las palabras.*/
{
	
	fwrite(&simpletron->acumulador, sizeof(simpletron_t),1, fsalida);
	fwrite(&simpletron->contador_programa, sizeof(simpletron_t),1, fsalida );
	fwrite(&simpletron->palabras[simpletron->contador_programa], sizeof(simpletron_t),1, fsalida);
	simpletron->opcode = simpletron->palabras[simpletron->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
	simpletron->operando = simpletron->palabras[simpletron->contador_programa] - (simpletron->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
	fwrite(&simpletron->opcode, sizeof(simpletron_t),1, fsalida);
	fwrite(&simpletron->operando, sizeof(simpletron_t),1, fsalida);	
	fwrite(simpletron->palabras, sizeof(int), params->cant_palabras, fsalida);
	return ST_OK;
}


status_t liberar_memoria(simpletron_t * simpletron) /*LA ESTRUCTURA RECIBIDA DEBERIA SER INTEGRAMENTE EN MEM DINAMICA*/
/*Recibe el puntero a la estructura de simpletron para liberar la memoria pedida*/
{	
	if (simpletron!=NULL)
		free(simpletron->palabras);

	simpletron->palabras=NULL;
	return ST_OK;
}

status_t ejecutar_simpletron (simpletron_t * simpletron)
/*Recibe el puntero a la estructura de simpletron para hacer un análisis de las instrucciones que se encuentran
en el vector palabras, y después se llama a una función que realiza la operación necesaria.*/
{
	int salir;

	if (simpletron->palabras[simpletron->contador_programa]<0){
		return ST_ERROR_PALABRA_NEG;
	}
	else{
		simpletron->opcode = simpletron->palabras[simpletron->contador_programa] /100;/*divido por 100 entonces como es un int borra los numeros despues de la coma y me queda el entero que quiero (ejemplo, si llega 2598 me queda 25.98 pero se guarda 25)*/
		simpletron->operando = simpletron->palabras[simpletron->contador_programa] - (simpletron->opcode*100);/*necesito los ultimos dos entonces al multiplicar opcode por 100 tengo 2500 del ejemplo entonces 2598-2500 da 98 que son los ultimos dos digitos que necesito*/
		switch (simpletron->opcode){
			case (LEER):
				op_leer(simpletron);
				simpletron->contador_programa++;
				break;
			case (ESCRIBIR):
				op_escribir(simpletron);
				simpletron->contador_programa++;
				break;
			case (CARGAR):
				op_cargar(simpletron);
				simpletron->contador_programa++;
				break;
			case (GUARDAR):
				op_guardar(simpletron);
				simpletron->contador_programa++;
				break;
			case (PCARGAR):
				op_pcargar(simpletron);
				simpletron->contador_programa++;
				break;
			case(PGUARDAR):
				op_pguardar(simpletron);
				simpletron->contador_programa++;
				break;
			case(SUMAR):
				op_sumar(simpletron);
				simpletron->contador_programa++;
				break;
			case(RESTAR):
				op_restar(simpletron);
				simpletron->contador_programa++;
				break;
			case(DIVIDIR):
				op_dividir(simpletron);
				simpletron->contador_programa++;
				break;
			case(MULTIPLICAR):
				op_multiplicar(simpletron);
				simpletron->contador_programa++;
				break;
			case(JMP):
				op_jmp(simpletron);
				break;
			case(JMPNEG):
				if(simpletron->acumulador<0)
					op_jmp(simpletron);
				else
					simpletron->contador_programa++;
				break;
			case(JMPZERO):
				if(simpletron->acumulador==0)
					op_jmp(simpletron);
				else
					simpletron->contador_programa++;
				break;
			case(JNZ):
				if(simpletron->acumulador!=0)
					op_jmp(simpletron);
				else
					simpletron->contador_programa++;
				break;
			case(DJNZ):
				op_djnz(simpletron);
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

status_t op_leer (simpletron_t * simpletron)
 /*Lee una palabra por stdin a una posicion de memoria que está indicada por el operando (miembro de la estructura simpletron)*/
{
	int * lectura;
	int numero;
	char * pc;


	pc=NULL;
	lectura=NULL;

	printf("%s\n", MSJ_INGRESO_PALABRA);

	if (fgets((char*)lectura,MAX_LARGO_INGRESO,stdin)==NULL)
		fprintf(stderr, "%s\n", MSJ_ERROR_PALABRA_NULA );
		return ST_ERROR_PALABRA_VACIA; /*la palabra ingresada es nula*/	


	numero = strtol(lectura,&pc,10);
	
	if(*pc!='\0'&& *pc!='\n')
	    	return ST_ERROR_NO_NUMERICO; 
	    /*validar que "     " no sea un 0*/ 
	
	if(numero<MIN_PALABRA||numero>MAX_PALABRA)
	 		return ST_ERROR_FUERA_RANGO;

	simpletron->palabras[simpletron->operando] = numero;	
	return ST_OK;
}

status_t op_escribir(simpletron_t * simpletron)
 /*imprime por stdout el contenido de la posicion del operando (miembro de la estructura simpletron)*/
{
	fprintf(stdout, "%s %i : %i\n", MSJ_IMPRIMIR_PALABRA,simpletron->operando, simpletron->palabras[simpletron->operando]);
	return ST_OK;
}

status_t op_cargar (simpletron_t * simpletron)
/*Carga en el acumulador (miembro de la estructura simpletron) la posicion de memoria indicada 
por el operando(miembro de la estructura simpletron)*/
{
	if(simpletron->operando > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}
	simpletron->acumulador = simpletron->palabras[simpletron->operando];
	return ST_OK;
}


status_t op_pcargar (simpletron_t * simpletron)
 /*Carga en el acumulador (miembro de la estructura simpletron) la posicion de memoria indicada 
 por la palabra a la que apunta el operando(miembro de la estructura simpletron)*/
{
	if(simpletron->operando > params->cant_palabras  || simpletron->palabras[simpletron->operando] > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	simpletron->acumulador = simpletron->palabras[simpletron->palabras[simpletron->operando]];
	return ST_OK;
}

status_t op_guardar (simpletron_t * simpletron)
 /*guarda en la posicion de memoria indicada por el operando(miembro de la estructura simpletron)
  lo que está en el acumulador(miembro de la estructura simpletron)*/
{
	if(simpletron->operando > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	simpletron->palabras[simpletron->operando] = simpletron->acumulador ;
	return ST_OK;
}

status_t op_pguardar (simpletron_t * simpletron)
 /*guarda en la posicion de memoria indicada por la palabra a la que apunta el operando (miembro de la estructura simpletron) 
 lo que esta en el acumulador(miembro de la estructura simpletron)*/
{
	if(simpletron->operando > params->cant_palabras || simpletron->palabras[simpletron->operando] > params->cant_palabras){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_FUERA_DE_RANGO);
		return ST_ERROR_FUERA_RANGO;
	}

	simpletron->palabras[simpletron->palabras[simpletron->operando]] = simpletron->acumulador ;
	return ST_OK;
}


status_t op_restar (simpletron_t * simpletron)
 /*resta al acumulador (miembro de la estructura simpletron) lo guardado en la posicion de memoria indcada 
 por el operando(miembro de la estructura simpletron)*/
{
	simpletron->acumulador -= simpletron->palabras[simpletron->operando];
	return ST_OK;
}

status_t op_dividir (simpletron_t * simpletron)
 /*divide al acumulador (miembro de la estructura simpletron) por lo guardado en la posicion de memoria indicada
  por el operando(miembro de la estructura simpletron)*/{
	simpletron->acumulador /= simpletron->palabras[simpletron->operando];
	return ST_OK;
}

status_t op_multiplicar (simpletron_t * simpletron)
 /*multiplica al acumulador (miembro de la estructura simpletron)lo guardado en la posicion de memoria indicada por el operando(miembro de la estructura simpletron)*/
{
	simpletron->acumulador *= simpletron->palabras[simpletron->operando];
	return ST_OK;
}

status_t op_sumar(simpletron_t * simpletron)
 /*suma al acumulador (miembro de la estructura simpletron) lo guardado en la posicion de memoria indcada 
 por el operando(miembro de la estructura simpletron)*/
{
	simpletron->acumulador += simpletron->palabras[simpletron->operando];
	return ST_OK;
}

status_t op_jmp (simpletron_t * simpletron)
/*salta a la posicion de memoria indicada por el operando(miembro de la estructura simpletron) menos un valor*/
{
	simpletron->contador_programa = simpletron->operando;
	return ST_OK;
}

status_t op_djnz (simpletron_t * simpletron)
 /*decrementa en 1 el acumulador (miembro de la estructura simpletron) y salta a la posicion indicada 
 por el operando (miembro de la estructura simpletron) en el caso que el acumulador sea distinto de 0*/
{
	simpletron->acumulador--;
	if (simpletron->acumulador!=0){
		simpletron->contador_programa = simpletron->operando;
	}
	else
		simpletron->contador_programa++;
	return ST_OK;
}