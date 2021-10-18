#include "Utility.h"


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

