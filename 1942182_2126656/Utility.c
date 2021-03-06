/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: Ricardo Dutra da Silva
 *
 */

#include "Utility.h"
#include <float.h>
#include <math.h>

//Link útil: (calcula distância) https://www.calc-online.xyz/distancia-entre-dois-pontos

void merge(OrderedPair* p, int left, int med, int right){
	//analyzing from left to right in both of cases
	//creating aux arrays and vars
	int i, j, k;
	int l_limit = med - left + 1;
	int r_limit = right - med;

	OrderedPair* left_arr = (OrderedPair*)malloc(sizeof(OrderedPair)*(l_limit));
	OrderedPair* right_arr = (OrderedPair*)malloc(sizeof(OrderedPair)*(r_limit));
	
	for(i = 0; i < l_limit; i++)
		left_arr[i] = p[left + i];
	for(i = 0; i < r_limit; i++)
		right_arr[i] = p[med + 1 + i];

	i = 0;
	j = 0;
	k = left;

	while(i < l_limit && j < r_limit)
	{
		if(left_arr[i].x_coord < right_arr[j].x_coord)
		{
			p[k] = left_arr[i];
			i++;
		}
		else
		{
				p[k] = right_arr[j];
				j++;
		}
		k++;
	}

	while(i < l_limit)
	{
		p[k] = left_arr[i];
		i++;
		k++;
	}

	while(j < r_limit) 
	{
		p[k] = right_arr[j];
		j++;
		k++;
	}

	free(left_arr);
	free(right_arr);
}


void mergeSort(OrderedPair* p, int left, int right)
{
	if(left < right)
	{
		//half vector (left_med)(med+1_right)
		int med = (right + left) / 2;
		mergeSort(p, left, med);
		mergeSort(p, med + 1, right);
		merge(p, left, med, right); 
	}	
}

//same merge forY coordinate
void mergeY(OrderedPair* p, int left, int med, int right){
	//analyzing from left to right in both of cases
	//creating aux arrays and vars
	int i, j, k;
	int l_limit = med - left + 1;
	int r_limit = right - med;

	OrderedPair* left_arr = (OrderedPair*)malloc(sizeof(OrderedPair)*(l_limit));
	OrderedPair* right_arr = (OrderedPair*)malloc(sizeof(OrderedPair)*(r_limit));
	
	for(i = 0; i < l_limit; i++)
		left_arr[i] = p[left + i];
	for(i = 0; i < r_limit; i++)
		right_arr[i] = p[med + 1 + i];

	i = 0;
	j = 0;
	k = left;

	while(i < l_limit && j < r_limit)
	{
		if(left_arr[i].y_coord < right_arr[j].y_coord)
		{
			p[k] = left_arr[i];
			i++;
		}
		else
		{
			p[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while(i < l_limit)
	{
		p[k] = left_arr[i];
		i++;
		k++;
	}

	while(j < r_limit) 
	{
		p[k] = right_arr[j];
		j++;
		k++;
	}

	free(left_arr);
	free(right_arr);
}

void mergeSortY(OrderedPair* p, int left, int right)
{
	if(left < right)
	{
		//half vector (left_med)(med+1_right)
		int med = (right + left) / 2;
		mergeSortY(p, left, med);
		mergeSortY(p, med + 1, right);
		mergeY(p, left, med, right); 
	}	
}

PairTuple compare(OrderedPair* arr, int size) 
{
	double min = FLT_MAX;
	OrderedPair* l = NULL;
	OrderedPair* r = NULL;
	for(int i = 0; i < size; ++i)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(distance(&arr[i], &arr[j]) < min)
			{
				min = distance(&arr[i], &arr[j]);
				l = &arr[i];
				r = &arr[j];
			}
		}
	}
	
	//saving the closest one
	PairTuple tup;
	tup.distance = min;
	tup.first_pair = l;
	tup.second_pair = r;
	return tup;
}

PairTuple stripClosest(OrderedPair* arr, int size, PairTuple current_min)
{ 
	//sorting by Y coord
	mergeSortY(arr, 0, size - 1);

	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size && (arr[j].y_coord - arr[i].y_coord) < current_min.distance; ++j)
		{
			if(distance(&arr[i], &arr[j]) < current_min.distance)
			{
				current_min.distance = distance(&arr[i], &arr[j]);
				current_min.first_pair = &arr[i];
				current_min.second_pair = &arr[j];
			}
		}
	}

	return current_min;
}

PairTuple closestPair(OrderedPair* arr, int size) 
{
	if(size <= 3) return compare(arr, size);

	int mid = size/2;
	OrderedPair mid_pair = arr[mid];    

	//finding the closest pair; left and right
	PairTuple tup_l = closestPair(arr, mid);
	PairTuple tup_r = closestPair(arr + mid, size - mid);

	
	//getting the minimum (Left closest pair or Right closest pair)
	PairTuple tup_min;
	tup_min = tup_l.distance < tup_r.distance ? tup_l : tup_r;
	

	OrderedPair* aux = (OrderedPair*)malloc(sizeof(OrderedPair) * size);
	int j = 0;
	for(int i = 0; i < size; i++)
	{
		if(abs(arr[i].x_coord - mid_pair.x_coord) < tup_min.distance)
		{
			aux[j] = arr[i];
			j++;
		}
	}

	//returning the minimum between all the possibilities
	return stripClosest(aux, j, tup_min);
}
