#include <stdio.h>
#include <string.h>
#include "funciones.h"
//#include "funciones.c"

char matriz[4][9] = {"acfvdfgq","rfvtenjk","xszghiut","wsxcderv"};

char palabra[] = "sztd";




int main()
{
	int solucion[strlen(palabra)][2];
	int i, j;
	int len = strlen(palabra);
	busqueda_Recursiva_Horizontal_Derecha(matriz, palabra,0,0,0, solucion);
// El valor de los 3 ultimos param en esta llamada siempre ha de ser 0 para empezar por el principio
	busqueda_Recursiva_Vertical_Abajo(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Horizontal_Izquierda(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Vertical_Arriba(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Uno(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Dos(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Tres(matriz, palabra,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Cuatro(matriz, palabra,0,0,0,solucion);
	return 0;
}//end main



