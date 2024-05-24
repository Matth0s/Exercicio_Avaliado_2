#include "Grafo.h"

using namespace std;

Grafo::Grafo(void) : _vertices(), _arestas() {}

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
														string rotulo2) const
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

Aresta* Grafo::_checarExistenciaAresta(Vertice *v1, Vertice *v2) const
{
	for (unsigned i = 0; i < _arestas.size(); i++) {
		if ((_arestas.at(i)->getVertice1() == v1
				&& _arestas.at(i)->getVertice2() == v2)
			|| (_arestas.at(i)->getVertice1() == v2
				 && _arestas.at(i)->getVertice2() == v1))
		{
			return (_arestas.at(i));
		}
	}
	return (NULL);
}

void	Grafo::_exibirCabecalho(string texto) const
{
	cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨   "
		 << left << setw(15) << texto
		 << right << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n|\n";
}

void	Grafo::_exibirRodape(void) const
{
	cout << "\n\\___________________________________________________________\n"
		 << endl;
}

void	Grafo::_exibirGrafoVazio(void) const{

	_exibirCabecalho("GRAFO VAZIO");
	cout << "|";
	_exibirRodape();
}

void	Grafo::addAresta(string rotulo1, string rotulo2, string grau)
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
		if (grauConvertido <= 0) {
			throw invalid_argument("O grau da Aresta precisa ser maior que 0!");
		}

	} catch (...) {
		grauConvertido = 1;
		cerr << "Erro: valor " << grau << " não pode ser convertido"
			 << ", o valor 1.0 será utilizado" << endl;
	}

	aresta = new Aresta(vertices.at(0), vertices.at(1), grauConvertido);
	_arestas.push_back(aresta);
}

void	Grafo::exibirArestas(void) const
{
	if (!_vertices.size()) {
		_exibirGrafoVazio();
		return ;
	}

	_exibirCabecalho("ENLACES");
	for (unsigned i = 0; i < _arestas.size(); i++) {
		if (i % 4 == 0) {
			if (i != 0) {
				cout << endl;
			}
			cout << "| ";
		}
		cout << "("
			 << _arestas.at(i)->getVertice1()->getRotulo()
		 	 << " - "
		 	 << _arestas.at(i)->getVertice2()->getRotulo()
		 	 << ": "
		 	 << _arestas.at(i)->getGrau()
			 << ")   ";
	}
	_exibirRodape();
}

void	Grafo::exibirVertices(void) const
{
	if (!_vertices.size()) {
		_exibirGrafoVazio();
		return ;
	}

	_exibirCabecalho("VERTICES");
	for (unsigned i = 0; i < _vertices.size(); i++) {
		if (i % 10 == 0) {
			if (i != 0) {
				cout << endl;
			}
			cout << "| ";
		}
		cout << _vertices.at(i)->getRotulo();
		if (i != _vertices.size() - 1) {
			cout << " ,  ";
		}
	}
	_exibirRodape();
}

void	Grafo::exibirDensidade(void) const
{
	double	nArestas = _arestas.size();
	double	nVertices = _vertices.size();

	if (!_vertices.size()) {
		_exibirGrafoVazio();
		return ;
	}

	_exibirCabecalho("DENSIDADE");
	cout << "| A Densidade do Grafo é igual a: "
		 << (nArestas) / (nVertices * (nVertices - 1) / 2);
	_exibirRodape();
}

void	Grafo::exibirMaiorCentralidade(void) const
{
	Vertice	*vertice = NULL;

	if (!_vertices.size()) {
		_exibirGrafoVazio();
		return ;
	}

	vertice = _vertices.at(0);
	for (unsigned i = 0; i < _vertices.size(); i++) {
		if (_vertices.at(i)->getCentralidade() > vertice->getCentralidade()) {
			vertice = _vertices.at(i);
		}
	}

	_exibirCabecalho("CENTRALIDADE");
	cout << "| O vertice com maior centralidade de grau é: "
		 << vertice->getRotulo()
		 << endl;
	cout << "| Com grau total igual a : "
		 << vertice->getCentralidade();
	_exibirRodape();
}

void	Grafo::teste()
{
	Vertice	*vertice = _vertices.at(0);
	vector<Rota> rotas = Caminho(_vertices, vertice).getRotas();

	cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n";
	for (unsigned i = 0; i < rotas.size(); i++) {
		cout << "| "
			 << vertice->getRotulo()
			 << " -> ("
			 << rotas.at(i).ultimo->getRotulo()
			 << ") -> "
			 << rotas.at(i).destino->getRotulo()
			 << " :  "
			 << rotas.at(i).custo
			 << endl;
	}
	cout << "\\___________________________________________________________\n"
		 << endl;
}
