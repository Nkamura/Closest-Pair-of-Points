/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

#include "stdio.h"
#include "stdlib.h"


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






	// close the file
   	fclose(file);
}
