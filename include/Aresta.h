#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Vertice;

class Aresta
{
	private:
		Vertice	*_v1;
		Vertice	*_v2;
		double	_grau;

	public:
		Aresta(Vertice *v1, Vertice *v2, double grau);
		~Aresta(void);

		/* Retorna o Vertice que esta na outra ponta da Aresta de ligação. */
		Vertice*	getOutroVertice(Vertice *vertice) const;
		Vertice*	getVertice1(void) const;
		Vertice*	getVertice2(void) const;
		double		getGrau(void) const;

		void		removeVertice(Vertice *vertice);
};

#endif
