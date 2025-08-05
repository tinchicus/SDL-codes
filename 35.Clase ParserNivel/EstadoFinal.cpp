#include "EstadoFinal.h"
#include <Windows.h>

const std::string EstadoFinal::e_idfinal = "GAMEOVER";

std::string EstadoFinal::getIdEstado() const {
	return e_idfinal;
}

void EstadoFinal::e_volverMenu() {
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoMenuPpal());
}

void EstadoFinal::e_reiniciar() {
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoJugar());
}

void EstadoFinal::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
}

void EstadoFinal::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoFinal::enIngreso() {
	EstadoParser estadoParser;
	estadoParser.estadoParse("estados.xml", e_idfinal, &m_objetosJuego,
		&m_listaIdtexturas);
	m_callbacks.push_back(0);
	m_callbacks.push_back(e_volverMenu);
	m_callbacks.push_back(e_reiniciar);
	setCallbacks(m_callbacks);

	OutputDebugStringA("Entrando al estado Game Over\n");
	return true;
}

bool EstadoFinal::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();

	m_objetosJuego.clear();
	for (int i = 0; i < m_listaIdtexturas.size(); i++) {
		Elmanejador::instanciar()->limpiaMapaTexturas(m_listaIdtexturas[i]);
	}

	OutputDebugStringA("Saliendo del Estado de Game Over\n");
	return true;
}

void EstadoFinal::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_objetosJuego.size(); i++) {
		if (dynamic_cast<BotonMenu*>(m_objetosJuego[i])) {
			BotonMenu* pBoton = dynamic_cast<BotonMenu*>
				(m_objetosJuego[i]);
			pBoton->setCallback(callbacks[pBoton->getCallbackId()]);
		}
	}
}