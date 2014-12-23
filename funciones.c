// La primera llamada a esta funcion debe ser: busquedaRecursiva(palabraBuscada, 0, 0, 0)

#include <stdio.h>
#include <string.h>

#include "funciones.h"

/*
Parametros:
	- char matriz[][] -> sopa de letras
	Ejemplo: agh,rtc,dkl
	- char word[] -> palabra que buscamos en la sopa de letras
	- posicion -> posicion que indica el caracter dentro de la palabra que buscamos en la sopa de letras
	Ejemplo: word[] = "ten"
		 si buscamos la 't', posicion = 0
		 si buscamos la 'e', posicion = 1
		 si buscamos la 'n', posicion = 2
	- fila -> coordenada de fila de la sopa de letras, en la que comenzar la busqueda
	- columna -> coordenada de columna de la sopa de letras, en la que comenzar la busqueda
	- solucion[][2] -> array de dos dimensiones:
		el primer indice hace referencia a la letra i-esima de la palabra a buscar almacenada en word[]
		el segundo indice (0,1) hace referencia a los dos elementos del array solucion e indica la coordenada de la letra en la sopa
	Ejemplo: si buscamos en la matriz[][] la palabra rtc, solucion tendra los valores:
		solucion[0][0] -> 1		solucion[0][1] -> 0
		solucion[1][0] -> 1		solucion[1][1] -> 1
		solucion[2][0] -> 1		solucion[2][1] -> 2
		
*/
void busqueda_Recursiva_Horizontal_Derecha(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);	

	if (posicion == len){
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[posicion][0] = i;
					solucion[posicion][1] = j;
					busqueda_Recursiva_Horizontal_Derecha(matriz, word, posicion+1, i, j+1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

void busqueda_Recursiva_Vertical_Abajo(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);
	
	if (posicion == len){
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[posicion][0] = i;
					solucion[posicion][1] = j;
					busqueda_Recursiva_Vertical_Abajo(matriz, word, posicion+1, i+1, j, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					//Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

void busqueda_Recursiva_Horizontal_Izquierda(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[len-1-posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[len-1-posicion][0] = i;
					solucion[len-1-posicion][1] = j;
					busqueda_Recursiva_Horizontal_Izquierda(matriz, word, posicion+1, i, j+1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

void busqueda_Recursiva_Vertical_Arriba(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[len-1-posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[len-1-posicion][0] = i;
					solucion[len-1-posicion][1] = j;
					busqueda_Recursiva_Vertical_Arriba(matriz, word, posicion+1, i+1, j, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

//De Izquierda a Derecha y de arriba hacia abajo
void busqueda_Recursiva_Diagonal_Uno(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[posicion][0] = i;
					solucion[posicion][1] = j;
					busqueda_Recursiva_Diagonal_Uno(matriz, word, posicion+1, i+1, j+1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

//De abajo a arriba y de derecha a izquierda
void busqueda_Recursiva_Diagonal_Dos(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){		
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[len-1-posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[len-1-posicion][0] = i;
					solucion[len-1-posicion][1] = j;
					busqueda_Recursiva_Diagonal_Dos(matriz, word, posicion+1, i+1, j+1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

//De arriba a abajo y de derecha a izquierda
void busqueda_Recursiva_Diagonal_Tres(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){		
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[posicion][0] = i;
					solucion[posicion][1] = j;
					busqueda_Recursiva_Diagonal_Tres(matriz, word, posicion+1, i+1, j-1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

//De izquierda a derecha y de abajo a arriba
void busqueda_Recursiva_Diagonal_Cuatro(char matriz[][9], char word[], int posicion, int fila, int columna, int solucion[][2])
{
	int i, j;
	int len = strlen(word);

	if (posicion == len){		
		printf("Posiciones de las letras de la solucion en la sopa:\n");
		for(i = 0; i < len; i++){
			printf("La letra %c en la posicion [%i - %i]\n", word[i], solucion[i][0], solucion[i][1]);
		}
		return;
	}
	if (posicion < len){
		for(i = fila; i < 4; i++){
			for (j = columna; j < 9; j++ ){
				if(matriz[i][j] == word[len-1-posicion]){//Como comparamos caracteres y no strings, no utilizamos la funcion strcmp()
					solucion[len-1-posicion][0] = i;
					solucion[len-1-posicion][1] = j;
					busqueda_Recursiva_Diagonal_Cuatro(matriz, word, posicion+1, i+1, j-1, solucion);
	//Con este return, cancelamos el recorrido completo de la matriz por cada llamada recursiva, aun despues de haber encontrado una letra
					return;
				}else{
					// Anular cualquier valor guardado como posible solucion
					posicion = 0;
				}
			}
			printf("\n");
		}


	}//fin del if
}//fin funcion

