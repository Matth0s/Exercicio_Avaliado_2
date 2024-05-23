#include "Vertice.h"

using namespace std;

Vertice::Vertice(void)
 : _rotulo(""), _arestas() {}

Vertice::Vertice(string rotulo)
 : _rotulo(rotulo), _arestas() {}

Vertice::~Vertice(void)
{
	for (unsigned i = 0; i < _arestas.size(); i++) {
		_arestas.at(i)->removeVertice(this);
	}
}

string	Vertice::getRotulo(void) const {
	return (_rotulo);
}

int		Vertice::getTotalArestas(void) const {
	return (static_cast<int>(_arestas.size()));
}

void	Vertice::addAresta(Aresta* aresta)
{
	vector<Aresta*>::iterator	it;

	it = std::find(_arestas.begin(), _arestas.end(), aresta);
	if (it == _arestas.end()) {
		_arestas.push_back(aresta);
	}
}

void	Vertice::removeAresta(Aresta* aresta)
{
	vector<Aresta*>::iterator	it;

	it = std::find(_arestas.begin(), _arestas.end(), aresta);
	if (it != _arestas.end()) {
		_arestas.erase(it);
	}
}
