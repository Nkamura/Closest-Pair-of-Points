/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "OrderedPair.h"
#include "Utility.h"


int main(){
	
	  /*********************/
	 /* .Txt Manipulation */
	/*********************/

	//Open the .txt file
	//Using fopen() function and "r" just to read
	FILE * file = fopen("input.txt", "r");
	
	if (file == NULL)
	{
		printf("Error: could not open file %s", "input.txt");
		return (1);
	}

	
	int numberOfcoordinates = 0;
	
	//numberOfLines receiving the first line of the .txt
	fscanf(file, "%d", &numberOfcoordinates);
	printf("%d", numberOfcoordinates);
	
	OrderedPair* pairs = (OrderedPair*)malloc(sizeof(OrderedPair)*numberOfcoordinates);

	float x, y;
	int i = 0;

	while(fscanf(file, "%f %f", &x, &y) != EOF)
	{
		pairs[i].x_coord = x;
		pairs[i].y_coord = y;
		i++;
 	}
	
	 for(i = 0; i < numberOfcoordinates; i++)
	{
		printf("\t%d\t",i);
	 	printf("x coord: %f; y coord: %f\n", pairs[i].x_coord, pairs[i].y_coord);
	}
	printf("\n_____________________________________________________________________________\n");
	
	//DIVIDE -> Recursion
	//By using Merge we can have T(nlogn)

	//arranging the X vector
	mergeSort(pairs, 0, numberOfcoordinates - 1);	
		
	for(i = 0; i < numberOfcoordinates; i++)
	 	printf("x coord: %f; y coord: %f\n", pairs[i].x_coord, pairs[i].y_coord);

	printf("\n\n\n\n");
	PairTuple tup = closestPair(pairs, numberOfcoordinates);

	printf("%f\n", tup.first_pair->x_coord);

	printf("%f %f %f %f %f", tup.distance, tup.first_pair->x_coord, tup.first_pair->y_coord, tup.second_pair->x_coord, tup.second_pair->y_coord);


	// close the file
   	fclose(file);
}
