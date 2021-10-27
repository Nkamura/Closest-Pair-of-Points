/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: 
 *
 */

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdlib.h>
#include <stdio.h>
#include "OrderedPair.h"

typedef struct PairTuple 
{
    OrderedPair* first_pair;
    OrderedPair* second_pair;
    double distance;
} PairTuple;

//Gathering the values and arranging
void merge(OrderedPair * p, int left, int med, int right);

//Merge sort 
void mergeSort(OrderedPair * p, int left, int right);


PairTuple compare(OrderedPair* arr, int size);

//Analyzes the possible cases (middle cases)
PairTuple stripClosest(OrderedPair* arr, int size, PairTuple current_min);

//Main function
PairTuple closestPair(OrderedPair* arr, int size);

#endif
