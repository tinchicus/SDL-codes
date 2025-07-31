#include "CapaPatron.h"

CapaPatron::CapaPatron(int tamPatron, 
	const std::vector<ConjuntoPatron> &conjuntos):
	m_tamPatron(tamPatron),m_conjuntos(conjuntos) {}

void CapaPatron::actualizar(){}
void CapaPatron::renderizar(){}
void CapaPatron::setIdPatron(const std::vector < std::vector<int>> &datos) {
	m_idPatron = datos;
}
void CapaPatron::setTamPatron(int tamPatron) {
	m_tamPatron = tamPatron;
}

ConjuntoPatron CapaPatron::getConjuntoPorId(int id) {}