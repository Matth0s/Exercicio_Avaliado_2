/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 2                                                      */
/*                                                                            */
/*                   ____ Programa Principal de Testes ____                   */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

int main (int argc, char *argv[])
{
	{
		cout << "____________________________\\\\_____________________________"
			 << endl
			 << endl;

		vector< vector<string> > dados;

		if (argc < 2) {
			cout << "É necessario um nome de arquivo como argumento!" <<endl;
			cout << "Programa Encerrado!" << endl;
			return (1);
		}

		if (Utils::lerArquivoGrafo(argv[1], dados)) {
			cout << "Programa Encerrado!" << endl;
			return (1);
		}

		for (unsigned i = 0; i < dados.size(); i++) {
			cout << "[  ";
			for (unsigned j = 0; j < dados[i].size(); j++) {
				cout << dados[i][j] << "  ";
			}
			cout << "]" << endl;
		}

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________\\\\_____________________________"
			 << endl
			 << endl;

		Vertice	ve1;
		Vertice	ve2("teste");
		Vertice	ve3(ve2);
		string	teste("teste");

		cout << ( ve1.getRotulo().empty() ? "✅" : "❌");
		cout << ( !teste.compare(ve2.getRotulo()) ? "✅" : "❌");
		cout << ( !teste.compare(ve3.getRotulo()) ? "✅" : "❌");
		cout << endl;

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________\\\\_____________________________"
			 << endl
			 << endl;

		Vertice	v1("A");
		Vertice	v2("B");

		cout << "   Antes Criação Aresta" << endl;
		cout << "v1: " << v1.getTotalArestas() << endl;
		cout << "v2: " << v2.getTotalArestas() << endl;

		Aresta*	a1 = new Aresta(&v1, &v2, 4);

		cout << "   Depois Criação Aresta" << endl;
		cout << a1->getLeftVertice()->getRotulo() << endl;
		cout << a1->getRightVertice()->getRotulo() << endl;
		cout << a1->getGrau() << endl;

		cout << "v1: " << v1.getTotalArestas() << endl;
		cout << "v2: " << v2.getTotalArestas() << endl;

		delete a1;

		cout << "   Delete Aresta" << endl;
		cout << "v1: " << v1.getTotalArestas() << endl;
		cout << "v2: " << v2.getTotalArestas() << endl;

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________\\\\_____________________________"
			 << endl
			 << endl;

		Vertice*	v1 = new Vertice("A");
		Vertice*	v2 = new Vertice("B");
		Aresta*		a1 = new Aresta(v1, v2, 4);


		cout << "   Antes Deleção Vertices" << endl;
		cout << "left: " << a1->getLeftVertice() << endl;
		cout << "right: " << a1->getRightVertice() << endl;

		delete v1;

		cout << "\n   Deleção Vertice Left" << endl;
		cout << "left: " << a1->getLeftVertice() << endl;
		cout << "right: " << a1->getRightVertice() << endl;

		delete v2;

		cout << "\n   Deleção Vertice Right" << endl;
		cout << "left: " << a1->getLeftVertice() << endl;
		cout << "right: " << a1->getRightVertice() << endl;

		delete a1;

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________\\\\_____________________________"
			 << endl
			 << endl;

		vector< vector<string> > dados;
		Grafo					g1;

		if (argc < 2) {
			cout << "É necessario um nome de arquivo como argumento!" <<endl;
			cout << "Programa Encerrado!" << endl;
			return (1);
		}

		if (Utils::lerArquivoGrafo(argv[1], dados)) {
			cout << "Programa Encerrado!" << endl;
			return (1);
		}

		for (unsigned i = 0; i < dados.size(); i++) {
			g1.addAresta(dados.at(i).at(0), dados.at(i).at(1), dados.at(i).at(2));
		}

		g1.exibirArestas();
		g1.exibirVertices();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	return (0);
}
