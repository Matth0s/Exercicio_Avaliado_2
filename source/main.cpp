/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 1                                                      */
/*                                                                            */
/*                        ____ Programa Principal ____                        */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

void exibirMenuPrincipal(void);
int	abrirArquivo(int argc, char *argv[], Grafo &g1);

int main(int argc, char *argv[])
{

	string	comando;
	string	origem;
	string	destino;
	Grafo	g1;

	if (abrirArquivo(argc, argv, g1)) {
		return (1);
	}

	cout << endl;
	cout << " * ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ *\n";
	cout << " |       Bem Vindo Programa Principal       |\n";
	cout << " |                                          |\n";
	cout << " |        utilize os codigos do Menu        |\n";
	cout << " |       para interacao com o sistema       |\n";
	cout << " * ________________________________________ *"
		 << endl
		 << endl;

	while (true) {

		exibirMenuPrincipal();
		cout << "# Insira o comando: ";
		getline(cin, comando);

		if (!comando.compare("1")) {
			g1.exibirVertices();

		} else if (!comando.compare("2")) {
			g1.exibirArestas();

		} else if (!comando.compare("3")) {
			g1.exibirDensidade();

		} else if (!comando.compare("4")) {
			g1.exibirMaiorCentralidade();

		} else if (!comando.compare("5")) {
			cout << "# Insira o Vertice de Origem: ";
			getline(cin, origem);
			cout << "# Insira o Destino: ";
			getline(cin, destino);
			g1.exibirCaminho(origem, destino);

		} else if (!comando.compare("6")) {
			g1.exibirMaiorCentralidadeProximade();

		} else if (!comando.compare("9")) {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|       Programa Encerrado       |\n";
			cout << "\\________________________________/\n"
				 << endl;
			break;

		} else {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|     Comando não encontrado     |\n";
			cout << "|         Tente novamente        |\n";
			cout << "\\________________________________/\n"
				 << endl;
		}

		cout << "Aperte Enter para continuar...";
		getline(cin, comando);
	}

	return (0);
}

void exibirMenuPrincipal(void)
{
	cout << endl;
	cout << "|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n";
	cout << "|    Digite o numero do comando desejado:    |\n";
	cout << "|                                            |\n";
	cout << "|    1 - Lista de Vertices                   |\n";
	cout << "|    2 - Lista de Enlaces                    |\n";
	cout << "|    3 - Densidade do Grafo                  |\n";
	cout << "|    4 - Maior Centralidade de Grau          |\n";
	cout << "|    5 - Calcular Menor Caminho              |\n";
	cout << "|    6 - Maior Centralidade de Proximidade   |\n";
	cout << "|                                            |\n";
	cout << "|    9 - Encerrar Programa                   |\n";
	cout << "|____________________________________________|"
		 << endl
		 << endl;
}

int	abrirArquivo(int argc, char *argv[], Grafo &g1)
{
	vector< vector<string> > dados;

	if (argc < 2) {
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "!    Programa iniciado sem indicacao para    !\n";
		cout << "!          arquivo contendo o Grafo          !\n";
		cout << "!        ! O Grafo permanecera vazio !       !\n";
		cout << "\\____________________________________________/\n"
			 << endl;
		return (0);
	}

	if (Utils::lerArquivoGrafo(argv[1], dados)) {
		cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
		cout << "|       Programa Encerrado       |\n";
		cout << "\\________________________________/\n"
				<< endl;
		return (1);
	}

	for (unsigned i = 0; i < dados.size(); i++) {
		g1.addAresta(dados.at(i).at(0), dados.at(i).at(1), dados.at(i).at(2));
	}
	return (0);
}
