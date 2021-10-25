/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: 
 *
 */

#include "Utility.h"
#include <float.h>
#include <math.h>

float getMin (float x, float y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}

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
	float min = FLT_MAX;
	OrderedPair* l = NULL;
	OrderedPair* r = NULL;
    for (int i = 0; i < size; ++i)
	{
        for (int j = i + 1; j < size; ++j)
		{
            if (distance(&arr[i], &arr[j]) < min)
			{
                min = distance(&arr[i], &arr[j]);
				l = &arr[i];
				r = &arr[j];
			}
		}
	}	
	PairTuple tup;
	tup.distance = min;
	tup.first_pair = l;
	tup.second_pair = r;
    return tup;
}

PairTuple stripClosest(OrderedPair* arr, int size, PairTuple current_min)
{
	mergeSortY(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
        for (int j = i+1; j < size && (arr[j].y_coord - arr[i].y_coord) < current_min.distance; ++j)
		{
            if (distance(&arr[i], &arr[j]) < current_min.distance)
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
	if (size <= 3)
        return compare(arr, size);

	int mid = size/2;
	OrderedPair mid_pair = arr[mid];

	PairTuple tup_l = closestPair(arr, mid);
	PairTuple tup_r = closestPair(arr + mid, size - mid);

	// float dist = getMin(tup_l.distance, tup_r.distance);
	PairTuple tup_min = tup_l.distance < tup_r.distance ? tup_r : tup_r;

	if(tup_min.distance == 0)
	{
		printf("%d, %d, %d\n\n", size, mid, size - mid);

		// printf("\n\n--------------\n\n");
		// printf("%f - ", tup_min.first_pair->x_coord);
		// printf("%f - ", tup_min.first_pair->y_coord);
		// printf("%f - ", tup_min.second_pair->x_coord);
		// printf("%f\nFIM\n", tup_min.second_pair->y_coord);
	}

	// return tup_min;

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


	return stripClosest(aux, size, tup_min);
}
