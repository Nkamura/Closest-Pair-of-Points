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
#include <time.h>


int main(int argc, char** argv) 
{
    if (argc != 2) 
	{
		printf("Wrong number of arguments! Please, provide input file name\n");
		exit(1);
	} 
	  /*********************/
	 /* .Txt Manipulation */
	/*********************/

	//Open the .txt file
	//Using fopen() function and "r" just to read
	FILE * file = fopen(argv[1], "r");
	
	if (file == NULL)
	{
		printf("Error: could not open file %s", argv[1]);
		return (1);
	}

	int numberOfcoordinates = 0;
	
	//numberOfLines receiving the first line of the .txt
	fscanf(file, "%d", &numberOfcoordinates);

	OrderedPair* pairs = (OrderedPair*)malloc(sizeof(OrderedPair)*numberOfcoordinates);

	double x, y;
	int i = 0;

	while(fscanf(file, "%lf %lf", &x, &y) != EOF)
	{
		pairs[i].x_coord = x;
		pairs[i].y_coord = y;
		i++;
 	}
	
	clock_t start, end;
	start = clock();
	//DIVIDE -> Recursion
	//By using Merge we can have T(nlogn)

	//arranging the X vector
	mergeSort(pairs, 0, numberOfcoordinates - 1);	
		
	PairTuple tup = closestPair(pairs, numberOfcoordinates);

	end = clock();

	double duration = (double) (end - start) / CLOCKS_PER_SEC;

	printf("%lf %lf %lf %lf %lf %lf", duration, tup.distance, tup.first_pair->x_coord, tup.first_pair->y_coord, tup.second_pair->x_coord, tup.second_pair->y_coord);


	// close the file
   	fclose(file);
}
