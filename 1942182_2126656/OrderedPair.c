/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & Gustavo Brunholi Chierici (2126656)
 *	Professor: Ricardo Dutra da Silva
 *
 */

#include "OrderedPair.h"
#include <math.h>

double distance(OrderedPair* lhs, OrderedPair* rhs)
{
    return sqrt(pow((lhs->x_coord - rhs->x_coord), 2) + pow((lhs->y_coord - rhs->y_coord), 2));
}
