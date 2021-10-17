/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

#include "OrderedPair.h"

double getOrderedPairModule(OrderedPair* pair)
{
    return sqrt(pow(pair->x_coord, 2) + pow(pair->y_coord, 2));
}
