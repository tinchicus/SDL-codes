#include "EstadoMenuPpal.h"
#include <Windows.h>

const std::string EstadoMenuPpal::e_idmenu = "MENU";

std::string EstadoMenuPpal::getIdEstado() const {
	return e_idmenu;
}

void EstadoMenuPpal::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
}

void EstadoMenuPpal::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

void EstadoMenuPpal::e_menuParaJugar() {
	OutputDebugStringA("Boton de juego apretado\n");
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoJugar());
}

void EstadoMenuPpal::e_salirDelMenu() {
	OutputDebugStringA("Boton de salir apretado\n");
	Eljuego::instanciar()->limpiar();
}

bool EstadoMenuPpal::enIngreso() {
	EstadoParser estadoParser;
	estadoParser.estadoParse("estados.xml", e_idmenu, &m_objetosJuego,
		&m_listaIdtexturas);
	m_callbacks.push_back(0);
	m_callbacks.push_back(e_menuParaJugar);
	m_callbacks.push_back(e_salirDelMenu);
	setCallbacks(m_callbacks);
	OutputDebugStringA("Ingresando al estado Menu\n");
	return true;
}

bool EstadoMenuPpal::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();
	m_objetosJuego.clear();
	for (int i = 0; i < m_listaIdtexturas.size(); i++) {
		Elmanejador::instanciar()->limpiaMapaTexturas(m_listaIdtexturas[i]);
	}
	OutputDebugStringA("Saliendo del estado menu\n");
	return true;
}

void EstadoMenuPpal::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_objetosJuego.size(); i++) {
		if (dynamic_cast<BotonMenu*>(m_objetosJuego[i])) {
			BotonMenu* pBoton = dynamic_cast<BotonMenu*>
				(m_objetosJuego[i]);
			pBoton->setCallback(callbacks[pBoton->getCallbackId()]);
		}
	}
}