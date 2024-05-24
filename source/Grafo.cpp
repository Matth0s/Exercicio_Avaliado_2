#include "Grafo.h"

using namespace std;

Grafo::Grafo(void)
	: _vertices(), _arestas() {}

Grafo::~Grafo(void)
{
	for (unsigned i = 0; i < _arestas.size(); i++) {
		delete _arestas.at(i);
		_arestas.at(i) = NULL;
	}
	for (unsigned i = 0; i < _vertices.size(); i++) {
		delete _vertices.at(i);
		_vertices.at(i) = NULL;
	}
}

vector<Vertice *> Grafo::_checarExistenciaVertices(string rotulo1,
														string rotulo2)
{
	vector<Vertice *> vertices({NULL, NULL});

	for (unsigned i = 0; i < _vertices.size(); i++) {
		if (!_vertices.at(i)->getRotulo().compare(rotulo1)) {
			vertices.at(0) = _vertices.at(i);
		}
		if (!_vertices.at(i)->getRotulo().compare(rotulo2)) {
			vertices.at(1) = _vertices.at(i);
		}
	}
	return (vertices);
}

bool Grafo::_checarExistenciaAresta(Vertice *v1, Vertice *v2)
{
	for (unsigned i = 0; i < _arestas.size(); i++) {
		if ((_arestas.at(i)->getLeftVertice() == v1
				&& _arestas.at(i)->getRightVertice() == v2)
			|| (_arestas.at(i)->getLeftVertice() == v2
				 && _arestas.at(i)->getRightVertice() == v1))
		{
			return (true);
		}
	}
	return (false);
}

void Grafo::addAresta(string rotulo1, string rotulo2, string grau)
{
	vector<Vertice *> vertices;
	Aresta *aresta;
	double grauConvertido;

	vertices = _checarExistenciaVertices(rotulo1, rotulo2);
	// Se já existir uma Aresta que ligue os 2 Vertoces com rotulos parametro,
	// nenhuma alteração é realizada no grafo
	if (_checarExistenciaAresta(vertices.at(0), vertices.at(1))) {
		return;
	}

	// Caso os Vertices com rotulos parametro não existam, eles são criados e
	// adicionados ao vetor de Vertices
	if (!vertices.at(0)) {
		vertices.at(0) = new Vertice(rotulo1);
		_vertices.push_back(vertices.at(0));
	}
	if (!vertices.at(1)) {
		vertices.at(1) = new Vertice(rotulo2);
		_vertices.push_back(vertices.at(1));
	}

	// Tenta fazer a conversão do grau da Aresta para double, caso falhe, o
	// valor 1 será utilizado como padrão
	try {
		grauConvertido = stod(grau);
	} catch (...) {
		grauConvertido = 1;
		cerr << "Erro: valor " << grau << " não pode ser convertido"
			 << ", o valor 1.0 será utilizado" << endl;
	}

	aresta = new Aresta(vertices.at(0), vertices.at(1), grauConvertido);
	_arestas.push_back(aresta);
}

void Grafo::exibirArestas(void)
{
	for (unsigned i = 0; i < _arestas.size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << "("
			 << _arestas.at(i)->getLeftVertice()->getRotulo()
		 	 << " - "
		 	 << _arestas.at(i)->getRightVertice()->getRotulo()
		 	 << ": "
		 	 << _arestas.at(i)->getGrau()
			 << ")   ";
	}
	cout << endl;
}

void Grafo::exibirVertices(void)
{
	cout << "{ ";
	for (unsigned i = 0; i < _vertices.size(); i++) {
		if (i % 10 == 0 && i != 0) {
			cout << endl;
		}
		cout << _vertices.at(i)->getRotulo();
		if (i != _vertices.size() - 1) {
			cout << " ,  ";
		}
	}
	cout << " }";
	cout << endl;
}
