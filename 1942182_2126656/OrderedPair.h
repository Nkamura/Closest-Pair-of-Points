/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: Ricardo Dutra da Silva
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
} OrderedPair;

double distance(OrderedPair* lhs, OrderedPair* rhs);

#endif
