#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>
#include "Vertice.h"

using namespace std;

class Vertice;

class Aresta {

	private:
		Vertice	*_left;
		Vertice	*_right;
		double	_grau;

	public:
		Aresta(Vertice *left, Vertice *right, double grau);
		~Aresta(void);

		Vertice*	getLeftVertice(void) const;
		Vertice*	getRightVertice(void) const;
		double		getGrau(void) const;
		void		removeVertice(Vertice *vertice);
};

#endif
