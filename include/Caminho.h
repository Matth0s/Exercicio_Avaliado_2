#ifndef CAMINHO_H
#define CAMINHO_H

#include <iostream>
#include <vector>
#include <limits>
#include "Vertice.h"

using namespace std;

struct Rota
{
	/* Vertice alvo da Rota. */
	Vertice	*destino;
	/* Ultimo Vertice passado antes de chegar ao destino. */
	Vertice *ultimo;
	/* Custo total desde o Vertice Origem e o Vertice Destino. */
	double	custo;
	/* Flag que indica se o caminho passou pelo algoritmo ou não. */
	bool	relaxado;

	Rota(Vertice *destino, Vertice *ultimo)	: destino(destino), ultimo(ultimo),
		custo(numeric_limits<double>::infinity()), relaxado(false) {};
	Rota(Rota *rota) : destino(rota->destino), ultimo(rota->ultimo),
		custo(rota->custo), relaxado(rota->relaxado) {};
};

class Caminho
{
	private:
		/* Ponto de onde todas as rotas vão sair. */
		Rota			*_origem;
		/* Vetor com todas as rotas do sistema. */
		vector<Rota*>	_rotas;
		/* Lista que sera utilizada de auxiliar no algoritmo de Dijkstra. */
		vector<Rota*>	_rotasParaChecar;

		/* Função que extrai do vetor parametro a rota com o menor custo. */
		Rota*	_getMenorRota(vector<Rota*> rotas);

		/* Dado o vertice destino, retorna a Rota correspondente. */
		Rota*	_buscarRotaByDestino(Vertice *destino);

		/* Metodo responsavel por realizar o algoritmo de Dijkstra. */
		void	_calcularRotaMaisCurta(void);

	public:
		Caminho(const vector<Vertice*> &vertices, Vertice *origem);
		~Caminho(void);

		/* Formata a exibição de todas as Rotas calculadas */
		void	exibirRotas(void) const;

		/* Retorna um vetor com uma copia de todas as Rotas calculadas */
		vector<Rota>	getRotas(void) const;
};

#endif
