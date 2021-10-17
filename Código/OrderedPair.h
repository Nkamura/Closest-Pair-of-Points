/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

#ifndef _ORDEREDPAIR_H_
#define _ORDEREDPAIR_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct OrderedPair
{
    double x_coord;
    double y_coord;
}OrderedPair;

double getOrderedPairModule(OrderedPair* pair);

#endif

