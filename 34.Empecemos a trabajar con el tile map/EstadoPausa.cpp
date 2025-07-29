#include "EstadoPausa.h"
#include <Windows.h>

const std::string EstadoPausa::e_idpausa = "PAUSA";

void EstadoPausa::e_volverMenu() {
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoMenuPpal());
}

void EstadoPausa::e_retomarJuego() {
	Eljuego::instanciar()->getEstadoMaquina()->popEstado();
}

void EstadoPausa::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
}

void EstadoPausa::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoPausa::enIngreso() {
	EstadoParser estadoParser;
	estadoParser.estadoParse("estados.xml", e_idpausa, &m_objetosJuego,
		&m_listaIdtexturas);
	m_callbacks.push_back(0);
	m_callbacks.push_back(e_retomarJuego);
	m_callbacks.push_back(e_volverMenu);
	setCallbacks(m_callbacks);

	OutputDebugStringA("Entrando en estado Pausa\n");
	return true;
}

bool EstadoPausa::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();
	m_objetosJuego.clear();
	for (int i = 0; i < m_listaIdtexturas.size(); i++) {
		Elmanejador::instanciar()->limpiaMapaTexturas(m_listaIdtexturas[i]);
	}
	Controles::instanciar()->limpiar();

	OutputDebugStringA("Saliendo del estado Pausa\n");
	return true;
}

void EstadoPausa::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_objetosJuego.size(); i++) {
		if (dynamic_cast<BotonMenu*>(m_objetosJuego[i])) {
			BotonMenu* pBoton = dynamic_cast<BotonMenu*>
				(m_objetosJuego[i]);
			pBoton->setCallback(callbacks[pBoton->getCallbackId()]);
		}
	}
}

std::string EstadoPausa::getIdEstado() const { return e_idpausa; }