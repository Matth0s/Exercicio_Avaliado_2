#include "Aresta.h"

using namespace std;

Aresta::Aresta(Vertice *left, Vertice *right, double grau = 1)
 : _left(left), _right(right), _grau(grau)
{
	_left->addAresta(this);
	_right->addAresta(this);
}

Aresta::~Aresta(void)
{
	if (_left) {
		_left->removeAresta(this);
	}
	if (_right) {
		_right->removeAresta(this);
	}
}

Vertice*	Aresta::getLeftVertice(void) const {
	return (_left);
}

Vertice*	Aresta::getRightVertice(void) const {
	return (_right);
}

double		Aresta::getGrau(void) const {
	return (_grau);
}

void	Aresta::removeVertice(Vertice *vertice)
{
	if (_left == vertice) {
		_left = NULL;
	} else if (_right == vertice) {
		_right = NULL;
	}
}
