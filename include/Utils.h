#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Grafo.h"
#include "Aresta.h"
#include "Vertice.h"

using namespace std;

class Utils
{
	public:
		/* Verifica se a string é composta somente de caracteres numericos ou
		'.' (para decimais). */
		static bool				numeroInvalido(string numero);

		/* Converte uma linha do arquivo em um vetor de string com 3 elementos. */
		static vector<string>	linhaToVector(ifstream &file, bool txt);

		/* Realiza a leitura do arquivo indicado, valida e extrai os dados. */
		static int				lerArquivoGrafo(string nomeArquivo,
											vector< vector<string> > &dados);
};

#endif
