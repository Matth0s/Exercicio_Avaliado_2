#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Aresta.h"

using namespace std;

class Aresta;
class Vertice;

/* Utilizada para juntar o Vertice vizinho com o grau da Aresta que os liga. */
struct Vizinho
{
	Vertice	*v;
	double	grau;

	Vizinho(Vertice *v, double grau) : v(v), grau(grau) {};
};

class Vertice
{
	private:
		string			_rotulo;
		vector<Aresta*>	_arestas;

	public:
		Vertice(void);
		Vertice(string rotulo);
		~Vertice(void);

		string	getRotulo(void) const;
		int		getTotalArestas(void) const;
		double	getCentralidade(void) const;
		void	addAresta(Aresta* aresta);
		void	removeAresta(Aresta* aresta);

		/* Retorna todos os Vertices vizinhos de Aresta. */
		vector<Vizinho>	getVizinhos(void);
};

#endif
