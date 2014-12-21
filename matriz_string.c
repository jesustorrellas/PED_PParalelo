#include <stdio.h>
#include <string.h>
#include "funciones.h"
//#include "funciones.c"

char matriz[4][9] = {"acfvdfgq","rfvtenjk","xszghiut","wsxcderv"};

char palabra[] = "hmut";
//int len = strlen(palabra);

//int solucion[len][2];


int main()
{
	int solucion[strlen(palabra)][2];
	busqueda_Recursiva_Horizontal_Derecha(matriz, palabra,0,0,0, solucion);
// El valor de los 3 ultimos param en esta llamada siempre ha de ser 0 para empezar por el principio
	return 0;
}//end main



