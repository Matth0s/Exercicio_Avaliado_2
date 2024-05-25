#include "Utils.h"

bool Utils::numeroInvalido(string numero)
{
	for (unsigned i = 0; i < numero.size(); i++) {
		if (!isdigit(numero[i]) && numero[i] != '.') {
			return true;
		}
	}
	return false;
}

vector<string> Utils::linhaToVector(ifstream &file, bool txt)
{
	vector<string> temp;
	stringstream buffer;
	string linha;
	string palavra;

	// Extrau uma linha inteira do arquivo
	getline(file, linha);
	buffer << linha;

	if (txt) {
		// Extrai as palavras do buffer usando whitespaces como delimitador
		while (buffer >> palavra) {
			temp.push_back(palavra);
		}
	} else {
		// Extrai as palavra do buffer usando ',' como delimitador
		while (getline(buffer, palavra, ',')) {
			temp.push_back(palavra);
		}
	}

	return (temp);
}

int Utils::lerArquivoGrafo(string nomeArquivo, vector< vector<string> > &dados)
{
	ifstream	file;
	bool		isTxt;

	if (nomeArquivo.size() < 4
		|| (nomeArquivo.compare(nomeArquivo.size() - 4, 4, ".txt")
			&& nomeArquivo.compare(nomeArquivo.size() - 4, 4, ".csv"))
	) {
		cout << "\nExtensão do Arquivo Invalida: " << nomeArquivo << endl;
		return (1);
	}

	file.open(nomeArquivo.c_str(), ifstream::in);
	if (!file.is_open()) {
		cout << "\nFalha ao Abrir o Arquivo: " << nomeArquivo << endl;
		return (1);
	}
	isTxt = !nomeArquivo.compare(nomeArquivo.size() - 4, 4, ".txt");
	for (unsigned i = 1; file.good(); i++) {
		vector<string> temp = linhaToVector(file, isTxt);

		// Significa que foi lida uma linha vazia
		if (!temp.size()) {
			continue;
		}

		// São permitidos 3 parametros por linha, 2 rotulos e 1 peso
		if (temp.size() != 3) {
			cout << "\nlinha " << i << ": Quantidade Invalida de Parametros: "
				 << temp.size() << endl;
			return (1);
		}

		// Garante que o terceiro parametro seja totalmente numero e positivo
		if (Utils::numeroInvalido(temp.at(2))) {
			cout << "\nlinha " << i << ": Valor do Peso de Aresta Invalido: "
				 << temp.at(2) << endl;
			return (1);
		}

		dados.push_back(temp);
	}
	return (0);
}
