#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Aresta.h"

using namespace std;

class Aresta;

class Vertice {

	private:
		string			_rotulo;
		vector<Aresta*>	_arestas;

	public:
		Vertice(void);
		Vertice(string rotulo);
		~Vertice(void);

		string	getRotulo(void) const;
		int		getTotalArestas(void) const;
		void	addAresta(Aresta* aresta);
		void	removeAresta(Aresta* aresta);

};

#endif
