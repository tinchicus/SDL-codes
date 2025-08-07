#include "MaquinaEstadoJuego.h"

void MaquinaEstadoJuego::pushEstado(EstadoJuego* pEstado) {
	m_estadoJuego.push_back(pEstado);
	m_estadoJuego.back()->enIngreso();
}

void MaquinaEstadoJuego::popEstado() {
	if (!m_estadoJuego.empty()) {
		if (m_estadoJuego.back()->enSalida()) {
			delete m_estadoJuego.back();
			m_estadoJuego.pop_back();
		}
	}
}

void MaquinaEstadoJuego::cambiaEstado(EstadoJuego* pEstado) {
	if (!m_estadoJuego.empty()) {
		if (m_estadoJuego.back()->getIdEstado() ==
			pEstado->getIdEstado()) {
			return;
		}
		if (m_estadoJuego.back()->enSalida()) {
			delete m_estadoJuego.back();
			m_estadoJuego.pop_back();
		}
	}
	m_estadoJuego.push_back(pEstado);
	m_estadoJuego.back()->enIngreso();
}

void MaquinaEstadoJuego::actualizar()
{
	if (!m_estadoJuego.empty())
		m_estadoJuego.back()->actualizar();
}

void MaquinaEstadoJuego::renderizar()
{
	if (!m_estadoJuego.empty())
		m_estadoJuego.back()->renderizar();
}