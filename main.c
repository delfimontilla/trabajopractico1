#include <stdio.h>
#include <stdlib.h>

#include "LANG_SPANISH.h"
#include "LANG_ENGLISH.h"
#include "estructuras_prototipos.h"


int main(int argc, char *argv[])
{
	int *acumulador;/*posicion de memoria del acumulador*/
	int *contador_programa;/*cuenta el numero de paso y de memoria que se encuentra el programa*/
    int *palabras;/*vector donde estan guardadas las palabras*/
    FILE *FENTRADA, *FSALIDA;
    status_t st;
	
	if(argc==ARGC2_MAX}){
		if((st=validacion_ayuda(argc, argv))!=ST_OK){
			return EXIT_FAILURE;
		}
	}

    else {
    	if(palabras = calloc(params->cant_palabras, sizeof (palabras))==NULL){
    		fprintf(stderr, "%s:%s\n",MSJ_ERROR,MSJ_ERROR_NO_MEM );
    		return EXIT_FAILURE;
    	}

    	if((st=validar_argumentos(argc, argv, params, FENTRADA, FSALIDA, palabras))!=ST_OK){
    		liberar_memoria(palabras);
    		return EXIT_FAILURE;
    	}

    	while(st!=ST_SALIR) st=operaciones(&acumulador, palabras[cant_palabras],&contador_programa);

    	liberar_memoria(palabras);
    	cerrar_archivos(FENTRADA,FSALIDA);
    }
    return EXIT_SUCCESS;
}

status_t leer_archivo_bin(parametros_t *params, int *palabras, FILE *FENTRADA){
 
	int i;
	int instruccion=0;


 	for(i=0; i<params->cant_palabras;i++){

    	if(fread(&instruccion,sizeof(int),MAX_LARGO_PALABRA,FENTRADA)!=MAX_LARGO_PALABRA){
    		liberar_memoria(palabras);
    		cerrar_archivos(FENTRADA,FSALIDA);
    		return ST_ERROR_FUERA_RANGO;
    	}
    
 		if(instruccion==FIN)
 			return ST_OK;
 		if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 			return ST_ERROR_FUERA_RANGO;

 		palabras[i]=instruccion;
 	
 	}
  
 	printf("%s\n",MSJ_CARGA_COMPLETA);
 	printf("%s\n",MSJ_COMIENZO_EJECUCION);
 
 	return ST_OK;
}

status_t leer_teclado(parametros_t *params, int *palabras){
 
 size_t i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 printf("%s\n",MSJ_BIENVENIDA);
 

 for(i=0; i<params->cant_palabras;i++){
 	printf("%2.i ? \n", i);
    if(fgets(aux,MAX_LARGO_PALABRA,stdin)==NULL){
    	liberar_memoria(palabras);
    	cerrar_archivos(FENTRADA,FSALIDA);
    	return ST_ERROR_FUERA_RANGO;
    }
    instruccion= strtol(aux,&pc,10);
    if(*pc!='\0'&& *pc!='\n')
    return ST_ERROR_NO_NUMERICO;


 	if(instruccion==FIN)
 		return ST_OK;
 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 	
 }
  
 printf("%s\n",MSJ_CARGA_COMPLETA);
 printf("%s\n",MSJ_COMIENZO_EJECUCION);
 	
 return ST_OK;
}

status_t leer_archivo_txt(parametros_t *params, int *palabras,FILE *FENTRADA){
 size_t i;
 char aux[MAX_LARGO_PALABRA];
 long instruccion=0;
 char *pc;

 for(i=0; i<params->cant_palabras;i++){
    if(fgets(aux,MAX_LARGO_PALABRA,FENTRADA)==NULL){
    	liberar_memoria(palabras);
    	cerrar_archivos(FENTRADA,FSALIDA);
    	return ST_ERROR_FUERA_RANGO;
    }
    instruccion= strtol(aux,&pc,10); 
    if(*pc!='\0'&& *pc!='\n')
    	return ST_ERROR_NO_NUMERICO;

    /*validar que "     " no sea un 0*/ 

 	if(instruccion<MIN_PALABRA||instruccion>MAX_PALABRA)
 		return ST_ERROR_FUERA_RANGO;

 	palabras[i]=instruccion;
 }

 printf("%s\n",MSJ_CARGA_COMPLETA);
 printf("%s\n",MSJ_COMIENZO_EJECUCION); 

 return ST_OK;
}

status_t validar_argumentos (int argc , char *argv[], parametros_t *params, FILE * FENTRADA, FILE * FSALIDA, int *palabras){
	
	char *pc;
	if(!argv || !params){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_PTR_NULO );
		return ST_ERROR_PTR_NULO;
	}

	if(argc!=ARGC_MAX){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_ARG );
		return ST_ERROR_CANT_ARG;
	}

	if(argv[ARG_POS_CANT_PALABRAS]==NULL){
		params->cant_palabras=CANT_PALABRAS_DEFAULT;}
	else {
		params->cant_palabras = strtol(argv[ARG_POS_CANT_PALABRAS], &pc, 10);
		if(params->cant_palabras<0 || (*pc!='\0' && *pc!='\n') || params->cant_palabras>100){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_CANT_PALABRAS );
			return ST_ERROR_CANT_PALABRAS;
		}
	}

	if(argv[ARG_POS_FENTRADA2]!=NULL){
		if(argv[ARG_POS_FENTRADA2]==OPCION_TXT){
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_txt(params, palabras, FENTRADA);
		}
		else if (argv[ARG_POS_FENTRADA2]==OPCION_BIN){
			if((FENTRADA=fopen(argv[ARG_POS_FENTRADA1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
			leer_archivo_bin(params, palabras, FENTRADA);
		}
	}
	
	else if(argv[ARG_POS_FENTRADA2]==NULL && argv[ARG_POS_FENTRADA1]!=NULL){
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO);
		return ST_ERROR_APERTURA_ARCHIVO;
	}

	else
		leer_teclado(palabras);

	
	
	if(argv[ARG_POS_FSALIDA2]!=NULL){
		if(argv[ARG_POS_FSALIDA2]==OPCION_TXT){
			
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1],"rt"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
		else {
			if((FSALIDA=fopen(argv[ARG_POS_FSALIDA1],"rb"))==NULL){
				fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
				return ST_ERROR_APERTURA_ARCHIVO;
			}
		}
	}
	else if(argv[ARG_POS_FSALIDA2]==NULL && argv[ARG_POS_FSALIDA1]!=NULL){
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_ERROR_APERTURA_ARCHIVO );
			return ST_ERROR_APERTURA_ARCHIVO;
		}

	else 
		imprimir_pantalla(palabras);

	return ST_OK;
}

status_t ayuda(){

	printf("%s   %s   %s\n",MSJ_TITULO_ARG, MSJ_TITULO_OPC, MSJ_TITULO_DESC);
	printf("%s   %s   %s\n",MSJ_AYUDA_ARG, MSJ_AYUDA_OPC, MSJ_AYUDA_DESC);
	printf("%s   %s   %s\n",MSJ_MEMORIA_ARG, MSJ_MEMORIA_OPC, MSJ_MEMORIA_DESC);
	printf("%s   %s   %s\n",MSJ_ENTRADA_ARG, MSJ_ENTRADA_OPC, MSJ_ENTRADA_DESC);
	printf("%s   %s   %s\n",MSJ_ARCHIVO_ARG, MSJ_ARCHIVO_OPC_BIN, MSJ_ARCHIVO_DESC_BIN);
	printf("     %s   %s\n",MSJ_ARCHIVO_OPC_TXT,MSJ_ARCHIVO_DESC_TXT);
	printf("%s   %s   %s\n",MSJ_SALIDA_ARG, MSJ_SALIDA_OPC, MSJ_SALIDA_DESC);
	printf("%s   %s   %s\n",MSJ_SALIDA_ARCH_ARG, MSJ_SALIDA_ARCH_BIN_OPC, MSJ_SALIDA_ARCH_BIN_DESC);
	printf("     %s   %s\n",MSJ_SALIDA_ARCH_TXT_OPC, MSJ_SALIDA_ARCH_TXT_DESC);

	printf("%s   %s   %s\n",TAB_TITULO_OP,TAB_TITULO_CODE,TAB_TITULO_DESC);
	printf("%s\n",TAB_ENT_SAL);
	printf("%s   %s   %s\n",TAB_LEER_OP,TAB_LEER_CODE,TAB_LEER_DESC);
	printf("%s   %s   %s\n",TAB_ESCRIBIR_OP,TAB_ESCRIBIR_CODE,TAB_ESCRIBIR_DESC);
	printf("%s\n",TAB_MOV);
	printf("%s   %s   %s\n",TAB_CARGAR_OP,TAB_CARGAR_CODE,TAB_CARGAR_DESC);
	printf("%s   %s   %s\n",TAB_GUARDAR_OP,TAB_GUARDAR_CODE,TAB_GUARDAR_DESC);
	printf("%s   %s   %s\n",TAB_PCARGAR_OP,TAB_PCARGAR_CODE,TAB_PCARGAR_DESC);
	printf("%s   %s   %s\n",TAB_PGUARDAR_OP,TAB_PGUARDAR_CODE,TAB_PGUARDAR_DESC);
	printf("%s\n",TAB_MATE);
	printf("%s   %s   %s\n",TAB_SUMAR_OP,TAB_SUMAR_CODE,TAB_SUMAR_DESC);
	printf("%s   %s   %s\n",TAB_RESTAR_OP,TAB_RESTAR_CODE, TAB_RESTAR_DESC);
	printf("%s   %s   %s\n",TAB_DIVIDIR_OP,TAB_DIVIDIR_CODE,TAB_DIVIDIR_DESC);
	printf("%s   %s   %s\n",TAB_MULT_OP,TAB_MULT_CODE,TAB_MULT_DESC);
	printf("%s\n",TAB_CONTROL);
	printf("%s   %s   %s\n",TAB_JUMP_OP, TAB_JUMP_CODE,TAB_JUMP_DESC);
	printf("%s   %s   %s\n",TAB_JMPNEG_OP, TAB_JMPNEG_CODE,TAB_JMPNEG_DESC);
	printf("%s   %s   %s\n",TAB_JMPZERO_OP, TAB_JMPZERO_CODE,TAB_JMPZERO_DESC);
	printf("%s   %s   %s\n",TAB_JNZ_OP,TAB_JNZ_CODE,TAB_JNZ_DESC);
	printf("%s   %s   %s\n",TAB_DJNZ_OP,TAB_DJNZ_CODE,TAB_DJNZ_DESC);
	printf("%s   %s   %s\n",TAB_FIN_OP,TAB_FIN_CODE,TAB_FIN_DESC);

	return ST_OK;
}

status_t validacion_ayuda(int argc, char *argv[]){

	if(!argv){
		return ST_ERROR_PTR_NULO;
	}
	if(argc!=ARGC2_MAX){
		return ST_ERROR_CANT_ARG;
	}
	if(argv[ARG_POS_H]!=NULL){
		ayuda();
	}	
}

status_t imprimir_pantalla(parametros_t *params, int * palabras, int *acumulador, int *contador_programa){
	
	imprimir_registro_pantalla(acumulador,params,palabras[params->cant_palabras],contador_programa);
	imprimir_memoria_pantalla(params, palabras[params->cant_palabras]);
	
}

status_t imprimir_memoria_pantalla (parametros_t *params, int palabras)/*Imprime la matriz con todas las instrucciones que se encuentran en palabras */{

	int i,k,l;
	k=0;

	printf("    ");
	for (l = 0; l < 10; l++)
		printf("  %i   ",l) ;


	for ( i = 0; i < params->cant_palabras ; i++){
      
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