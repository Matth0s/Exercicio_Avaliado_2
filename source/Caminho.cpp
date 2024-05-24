#include "Caminho.h"

Caminho::Caminho(const vector<Vertice*> &vertices, Vertice *origem)
: _origem(NULL), _rotas(), _rotasParaChecar()
{
	_origem = new Rota(origem, origem);
	_origem->custo = 0;
	_rotas.push_back(_origem);
	_rotasParaChecar.push_back(_origem);

	for (unsigned i = 0; i < vertices.size(); i++) {
		if (vertices.at(i) != origem) {
			_rotas.push_back(new Rota(vertices.at(i), origem));
		}
	}
	_calcularRotaMaisCurta();
}

Caminho::~Caminho(void)
{
	for (unsigned i = 0; i < _rotas.size(); i++) {
		delete _rotas.at(i);
		_rotas.at(i) = NULL;
	}
}

Rota*	Caminho::_getMenorRota(vector<Rota*> rotas)
{
	Rota	*rota = NULL;

	if (rotas.size()) {
		rota = rotas.at(0);
		for (unsigned i = 1; i < rotas.size(); i++) {
			if (rotas.at(i)->custo < rota->custo)	{
				rota = rotas.at(i);
			}
		}
	}
	return (rota);
}

Rota*	Caminho::_buscarRotaByDestino(Vertice *destino)
{
	for (unsigned i = 0; i < _rotas.size(); i++) {
		if (_rotas.at(i)->destino == destino) {
			return _rotas.at(i);
		}
	}
	return (NULL);
}

void	Caminho::_calcularRotaMaisCurta(void)
{
	while (_rotasParaChecar.size()) {

		Rota *rota = _getMenorRota(_rotasParaChecar);
		_rotasParaChecar.erase(
			find(_rotasParaChecar.begin(), _rotasParaChecar.end(), rota)
		);

		if (!rota->relaxado) {
			rota->relaxado = true;

			vector<Vizinho> vizinhos = rota->destino->getVizinhos();
			for (unsigned i = 0; i < vizinhos.size(); i++) {

				Rota *rotaVizinho = _buscarRotaByDestino(vizinhos.at(i).v);
				if (rotaVizinho->custo > rota->custo + vizinhos.at(i).grau) {
					rotaVizinho->ultimo = rota->destino;
					rotaVizinho->custo = rota->custo + vizinhos.at(i).grau;
					_rotasParaChecar.push_back(rotaVizinho);
				}
			}

		}
	}
}

void	Caminho::exibirRotas(void) const
{
	cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n";
	for (unsigned i = 0; i < _rotas.size(); i++) {
		cout << "| "
			 << _origem->destino->getRotulo()
			 << " -> ("
			 << _rotas.at(i)->ultimo->getRotulo()
			 << ") -> "
			 << _rotas.at(i)->destino->getRotulo()
			 << " :  "
			 << _rotas.at(i)->custo
			 << endl;
	}
	cout << "\\___________________________________________________________\n"
		 << endl;
}

vector<Rota>	Caminho::getRotas(void) const
{
	vector<Rota>	rotas;

	for (unsigned i = 0; i < _rotas.size(); i++) {
		rotas.push_back(Rota(_rotas.at(i)));
	}
	return (rotas);
}
