/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
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
    float x_coord;
    float y_coord;
} OrderedPair;

float distance(OrderedPair* lhs, OrderedPair* rhs);

#endif
