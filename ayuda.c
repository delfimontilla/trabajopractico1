#include <stdio.h>


status_t ayuda(){

    printf("%s\n",MSJ_ARG_POSICIONALES);

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
