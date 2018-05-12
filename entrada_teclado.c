#define MSJ_BIENVENIDA "Bienvenide a le Simpletron! Por favor, ingrese su programa una instrucción (o dato) a la vez. 
Yo escribiré la ubicación y un signo de pregunta (?).
Luego usted ingrese la palabra para esa ubicación. 
Ingrese -99999 para finalizar."

/* Welcome to Simpletron !
Please enter your program one instruction (or data word) at a time. 
I will type the location number and a question mark (?). 
You then type the word for that location.
Type the sentinel -99999 to stop entering your program.*/



status_t entrada_pantalla(int *palabras[cant_palabras])

printf("%s\n","MSJ_BIENVENIDA");


