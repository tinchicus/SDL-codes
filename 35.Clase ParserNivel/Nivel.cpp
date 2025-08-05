#include "Nivel.h"

Nivel::Nivel() {}
Nivel::~Nivel() {}

std::vector<ConjuntoPatron>* Nivel::getConjPatron() {
	return &m_conjPatrones;
}

std::vector<Capa*>* Nivel::getCapas() {
	return &m_capas;
}

void Nivel::renderizar() {
	for (int i = 0; i < m_capas.size(); i++)
		m_capas[i]->renderizar();
}

void Nivel::actualizar() {
	for (int i = 0; i < m_capas.size(); i++)
		m_capas[i]->actualizar();
}