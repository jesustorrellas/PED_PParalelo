#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include <mpi.h>
#include <stdlib.h>
//#include "funciones.c"

//char sopa[4][9] = {"acfvdfgq","rfvtenjk","xszghiut","wsxcderv"};

//char palabra[] = "sztd";
//char sopa_buffer[50];

//int palabras[4] = {145,536,234,698};
//char *palabras[4] = {"casa","perro","gato","ratita"};
//char palabras[] = {"casa\0perro\0gato\0ratita\0"};//El caracter \0 ocupa un unico caracter, e indica el final de un string.


int main(int argc, char *argv[])
{
//	int solucion[strlen(palabra)][2];
	char sopa[4][9] = {"acfvdfgq","rfvtenjk","xszghiut","wsxcderv"};
//	char palabras[] = {"fvdf\0perro\0qktv\0ratita\0"};//El caracter \0 ocupa un unico caracter, e indica el final de un string.
	char palabras[30]; //Buffer de palabras en forma de string, que se pasa a la funcion MPI_Scatterv
	int len_palabras;//Longitud del Buffer palabras[] que se pasa a la funcion MPI_Scatterv
	int rank, size;
//	int palabra_recibida;
	char palabra_recibida[20];//Palabra que recibe cada uno de los procesos para buscar en la sopa de letras
	int solucion[strlen(palabra_recibida)][2];
	int sendcounts[4];
	int displs[4];
//	int posicion_nulo[4];
//	int sendcounts2[4] = {33, 33, 33, 33};
//	int displs2[4] = {0, 0, 0, 0};
//	char sopa_buffer[50];
//	char matriz_array[33];
	int i;
	char palabra_ingresada[20];//Palabras ingresadas por el usuario
	int palabras_ingresadas;//Numero de palabras que desea ingresar el usuario
	char buffer_palabras[5][20];

//	busqueda_Recursiva_Horizontal_Derecha(matriz, palabra,0,0,0, solucion);
// El valor de los 3 ultimos param en esta llamada siempre ha de ser 0 para empezar por el principio
//	busqueda_Recursiva_Vertical_Abajo(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Horizontal_Izquierda(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Vertical_Arriba(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Diagonal_Uno(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Diagonal_Dos(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Diagonal_Tres(matriz, palabra,0,0,0,solucion);
//	busqueda_Recursiva_Diagonal_Cuatro(matriz, palabra,0,0,0,solucion);


	//Inicio de la aplicacion preguntando las palabras que queremos buscar


	/* Iniciamos el entorno MPI */
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

//	printf("Primera palabra: %s\n", palabras[1]);

	if (rank == 0){
		printf("Hay un total de %i procesos en la app\n", size);
		printf("Numero de palabras a buscar en la sopa de letras: \n");
		scanf("%i", &palabras_ingresadas);
		for(i = 0; i < palabras_ingresadas;i++){
			printf("Palabra numero %i a buscar\n",i);
			scanf("%20s", palabra_ingresada);
			strcpy(buffer_palabras[i], palabra_ingresada);
			sendcounts[i] = strlen(buffer_palabras[i]);
//			fgets(palabra_ingresada[i], sizeof(palabra_ingresada[i]),stdin);
		}
		//Creamos el vector de desplazamientos para repartir las palabras
		displs[0] = 0;
		for (i = 1; i < palabras_ingresadas;i++){
			displs[i] = sendcounts[i-1] + displs[i-1];
		}

		for(i = 0; i < palabras_ingresadas;i++){
			printf("Palabra ingresada numero %i: %s\n",i,buffer_palabras[i]);
			printf("Valor %i del vector sendcounts: %i\n", i, sendcounts[i]);
			printf("Valor %i del vector displs: %i\n",i,displs[i]);
		}
	//Empaquetamos la palabras introducidas por el usuario, en un buffer para enviarlo a los procesos
		strcpy(palabras,buffer_palabras[0]);
//		posicion_nulo[0] = sendcounts[0] + displs[0];
//		palabras[posicion_nulo[0]] = '\0';
//		palabras[strlen(buffer_palabras[0])] = '\0';
		for(i = 1; i < palabras_ingresadas;i++){
			strcat(palabras,buffer_palabras[i]);
//			posicion_nulo[i] = sendcounts[i] + displs[i] + i;
//			palabras[posicion_nulo[i]] = '\0';
		}

		printf("Palabras a buscar: %s\n", palabras);
		len_palabras = strlen(palabras);
		printf("Longitud de las palabras a buscar: %i\n",len_palabras);

		//Convertimos el array de strings que forma la sopa le letras, en un unico string para transmitirlo por MPI
//		for(i = 0; i < 4; i++){
//			strcat(sopa_buffer, sopa[i]);
//		}

//		printf("Matriz convertida en string: %s\n", sopa_buffer);
//		printf("Y ocupa: %d caracteres.", (int)strlen(sopa_buffer));

	}// fin if(rank == 0)

//	MPI_Scatter(palabras, 1, MPI_INT, &palabra_recibida, 1, MPI_INT, 0, MPI_COMM_WORLD);
//	MPI_Scatter(palabras[1], 4, MPI_CHAR, palabra_recibida, 4, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);//Para que no empiece ningun proceso antes de que el usuario facilite las palabras
	MPI_Scatterv(palabras, sendcounts, displs, MPI_CHAR, palabra_recibida, len_palabras, MPI_CHAR, 0, MPI_COMM_WORLD);//Paso individual de palabras
//	MPI_Scatterv(sendcounts,)
//	MPI_Scatterv(sopa_buffer, sendcounts2, displs2, MPI_CHAR, matriz_array, 33 , MPI_CHAR, 0, MPI_COMM_WORLD);//Paso sopa letras
	MPI_Barrier(MPI_COMM_WORLD);
//	palabra_recibida[strlen(palabra_recibida)-2] = '\0';


	printf("Mi rank es: %i y mi palabra recibida es: %s y tiene %i caracteres \n", rank, palabra_recibida,(int)strlen(palabra_recibida));

//	printf("Mi rank es: %i y he recibido mi sopa de letras: %s\n", rank, matriz_array);
//	printf("Mi rank es %i y puedo acceder a la sopa de letras %c\n", rank, sopa[3][3]);

// El valor de los 3 ultimos param en estas llamadas siempre han de ser 0 para empezar por el principio
	busqueda_Recursiva_Horizontal_Derecha(sopa, palabra_recibida,0,0,0, solucion);
	busqueda_Recursiva_Vertical_Abajo(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Horizontal_Izquierda(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Vertical_Arriba(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Uno(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Dos(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Tres(sopa, palabra_recibida,0,0,0,solucion);
	busqueda_Recursiva_Diagonal_Cuatro(sopa, palabra_recibida,0,0,0,solucion);


	/* Finalizacion del entorno MPI */
	MPI_Finalize();
	return 0;
}//end main



