#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Vertice.h"
#include "Aresta.h"

using namespace std;

class Grafo
{
	private:
		vector<Vertice*>	_vertices;
		vector<Aresta*>		_arestas;

		/* Verifica se já existem Vertices com os rotulos parametros. */
		vector<Vertice*>	_checarExistenciaVertices(string rotulo1,
														 string rotulo2) const;

		/* Verifica se existe alguma Aresta ligando os Vertices parametro. */
		bool	_checarExistenciaAresta(Vertice *v1, Vertice *v2) const;

		/* Formatação padronizada para exibição do cabeçalho. */
		void	_exibirCabecalho(string texto) const;

		/* Formatação padronizada para exibição do rodapé. */
		void	_exibirRodape(void) const;

		/* Formatação para padronizar comportamento de metodos de exibição
		quando o Grafo não possui Verices. */
		void	_exibirGrafoVazio(void) const;

	public:
		Grafo(void);
		~Grafo(void);

		/* Adiciona novos Enlaces ao Grafo fazendo as tratativas e verificações
		adequadas antes da inserção. */
		void	addAresta(string rotulo1, string rotulo2, string grau);

		/* Exibe de maneira formatada as Arestas existentes no Grafo. */
		void	exibirArestas(void) const;

		/* Exibe de maneira formatada os Vertices existentes no Grafo. */
		void	exibirVertices(void) const;

		/* Exibe de maneira formatada os Vertices existentes no Grafo. */
		void	exibirDensidade(void) const;

		/* Exibe de maneira formatada o Vertice com maior centralidade de grau
		existente no Grafo. */
		void	exibirMaiorCentralidade(void) const;
};

#endif
