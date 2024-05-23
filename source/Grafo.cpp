#include "Grafo.h"

using namespace std;

Grafo::Grafo(void) {}

Grafo::Grafo(const Grafo &src)
{
	this->operator=(src);
}

Grafo::~Grafo(void) {}

Grafo &Grafo::operator=(const Grafo &rhs)
{
	if (this != &rhs) {
		// Codigo
	}
	return (*this);
}
