#include "Vertice.h"

using namespace std;

Vertice::Vertice(void)
 : _rotulo(""), _arestas() {}

Vertice::Vertice(string rotulo)
 : _rotulo(rotulo), _arestas() {}

Vertice::~Vertice(void)
{
	// Desvincula o vertice de todas as Arestas
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

double	Vertice::getCentralidade(void) const
{
	double centralidade = 0;

	for (unsigned i = 0; i < _arestas.size(); i++) {
		centralidade += _arestas.at(i)->getGrau();
	}
	return (centralidade);
}

void	Vertice::addAresta(Aresta* aresta)
{
	vector<Aresta*>::iterator	it;

	// Antes de adicionar, verifica se a Aresta parametro já esta na lista
	it = std::find(_arestas.begin(), _arestas.end(), aresta);
	if (it == _arestas.end()) {
		_arestas.push_back(aresta);
	}
}

void	Vertice::removeAresta(Aresta* aresta)
{
	vector<Aresta*>::iterator	it;

	// Antes de remover, verifica se a Aresta parametro existe na lista
	it = std::find(_arestas.begin(), _arestas.end(), aresta);
	if (it != _arestas.end()) {
		_arestas.erase(it);
	}
}
