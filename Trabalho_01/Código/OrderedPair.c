/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "OrderedPair.h"

OrderedPair* createOrderedPair(double x, double y)
{
    OrderedPair* pair = (OrderedPair*)malloc(sizeof(OrderedPair));
    pair->x_coord = x;
    pair->y_coord = y;

    return pair;
}

double getOrderedPairModule(OrderedPair* pair)
{
    return sqrt(pow(pair->x_coord, 2) + pow(pair->y_coord, 2));
}