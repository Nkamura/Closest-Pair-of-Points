/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "OrderedPair.h"

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

	
	int numberOfLines = 0;
	float coordinatesX = 0, coordinatesY = 0;
	
	//numberOfLines receiving the first line of the .txt
	fscanf(file, "%d", &numberOfLines);
	printf("%d", numberOfLines);

	OrderedPair** pairs = (OrderedPair**)malloc(sizeof(OrderedPair*)*numberOfLines);

	double x, y;
	int i = 0 ;
	while(fscanf(file, "%lf %lf", &x, &y) != EOF)
	{
		pairs[i] = createOrderedPair(x, y);
		i++;
 	}
	
	for(i = 0; i < numberOfLines; i++)
		printf("x coord: %lf; y coord: %lf\n", pairs[i]->x_coord, pairs[i]->y_coord);

	// close the file
   	fclose(file);
}
