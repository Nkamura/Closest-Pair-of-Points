/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
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
	
	OrderedPair** pairs = (OrderedPair**)malloc(sizeof(OrderedPair*)*numberOfcoordinates);

	double x, y;
	int i = 0 ;
	while(fscanf(file, "%lf %lf", &x, &y) != EOF)
	{
		pairs[i] = createOrderedPair(x, y);
		i++;
 	}
	
	for(i = 0; i < numberOfcoordinates; i++)
		printf("x coord: %lf; y coord: %lf\n", pairs[i]->x_coord, pairs[i]->y_coord);

	

	//Main idea: Find the better pair of both sides and analyse the case were we can have one point in each side, then return the better one.	
	
	//DIVIDE -> Recursion
	//By using Merge we can have T(nlogn)
	//arranging the X vector
	
	//after arranging the X vector we can find the average(mediana): Knowing the lowest v[0]  and the higherv[numberOfCoordinates-1] value		

	






	// close the file
   	fclose(file);
}
