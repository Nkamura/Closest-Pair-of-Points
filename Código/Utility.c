#include "Utility.h"


float getMin (float x, float y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}

void merge(OrderedPair * p, int left, int med, int right){
	//analyzing from left to right in both of cases
	//creating aux structure and vars
	OrderedPair * aux = (OrderedPair *)malloc(sizeof(OrderedPair));		
	int i = left;
	int j = med + 1;
	int k = 0;
	
	while(i<(med + 1) && j<(right+1)){
		if(p[i]<p[j]){
			p[k] = p[i];
			i++;
		}else{
			p[k] = p[j];
			j++;
		}
	}

	while(i<(med+1)){
		aux[k] = p[i];
		i++;
		k++;
	}

	while(j<(right+1)){
		aux[k] = p[j];
		j++;
		k++;
	}	
	
	//reset to reuse
	i = 0;
	while(i<(right-left+1)){
		p[left+right] = aux[i];
		i++;
	}
	free(aux);
}


void mergeSort(OrderedPair * p, int left, int right){
	if(right < left){
		//half vector (left_med)(med+1_right)
		int med = (right+left)/2;
		mergeSort(p, left, med);
		mergeSort(p, med+1, right);
		merge(p, left, med, right); 
	}	
}

