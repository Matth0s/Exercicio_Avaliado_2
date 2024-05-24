#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>
#include <vector>
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo {

	private:
		vector<Vertice*>	_vertices;
		vector<Aresta*>		_arestas;

		/* Verifica se já existem Vertices com os rotulos parametros */
		vector<Vertice*>	_checarExistenciaVertices(string rotulo1,
														 string rotulo2);

		/* Verifica se existe alguma Aresta ligando os Vertices parametro */
		bool				_checarExistenciaAresta(Vertice *v1, Vertice *v2);

	public:
		Grafo(void);
		~Grafo(void);

		void	addAresta(string rotulo1, string rotulo2, string grau);
		void	exibirArestas(void);
		void	exibirVertices(void);

};

#endif
