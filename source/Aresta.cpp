#include "Aresta.h"

Aresta::Aresta(Vertice *v1, Vertice *v2, double grau = 1)
 : _v1(v1), _v2(v2), _grau(grau)
{
	_v1->addAresta(this);
	_v2->addAresta(this);
}

Aresta::~Aresta(void)
{
	// Retira a referencia cruzada existente com os Vertices
	if (_v1) {
		_v1->removeAresta(this);
	}
	if (_v2) {
		_v2->removeAresta(this);
	}
}

Vertice*	Aresta::getOutroVertice(Vertice *vertice) const
{
	if (_v1 == vertice) {
		return (_v2);
	} else if (_v2 == vertice) {
		return (_v1);
	}
	return (NULL);
}

Vertice*	Aresta::getVertice1(void) const {
	return (_v1);
}

Vertice*	Aresta::getVertice2(void) const {
	return (_v2);
}

double		Aresta::getGrau(void) const {
	return (_grau);
}

void	Aresta::removeVertice(Vertice *vertice)
{
	if (_v1 == vertice) {
		_v1 = NULL;
	} else if (_v2 == vertice) {
		_v2 = NULL;
	}
}
