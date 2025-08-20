#include "CapaObjeto.h"

std::vector<ObjetoJuego*>* CapaObjeto::getObjetosJuego() {
	return &m_objetosJuego;
}

void CapaObjeto::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++) {
		m_objetosJuego[i]->actualizar();
	}
}

void CapaObjeto::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++) {
		m_objetosJuego[i]->dibujar();
	}
}