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

int main ( int argc, char *argv[] ) {

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

		// try {
		// 	double peso = std::stod(temp.at(2));
		// 	if (peso <= 0)
		// 		throw std::invalid_argument("Número negativo não é permitido.");
		// 	std::cout << "O número convertido é: " << peso << std::endl;
		// } catch (const std::invalid_argument& e) {
		// 	std::cerr << "Erro: argumento inválido - " << e.what() << std::endl;
		// } catch (const std::out_of_range& e) {
		// 	std::cerr << "Erro: valor fora do intervalo - " << e.what() << std::endl;
		// }

	return (0);
}
