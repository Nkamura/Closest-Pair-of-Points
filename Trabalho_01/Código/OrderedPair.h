/*
 * 	Análise e Projeto de Algoritmos
 *	Autores: Gustavo Riodi Nakamura (1942182) & 
 *	Professor: 
 *
 */

typedef struct OrderedPair
{
    double x_coord;
    double y_coord;
} OrderedPair;

OrderedPair* createOrderedPair(double x, double y);

double getOrderedPairModule(OrderedPair* pair);