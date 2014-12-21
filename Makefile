funciones.o: funciones.h funciones.c
	gcc -c funciones.c
matriz_string: funciones.o 
	gcc funciones.o -o matriz_string
