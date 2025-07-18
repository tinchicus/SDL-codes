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
	if (!Elmanejador::instanciar()->cargar("assets/retomar.png",
		"botonretomar", Eljuego::instanciar()->getRenderer())) {
		return false;
	}
	if (!Elmanejador::instanciar()->cargar("assets/volver.png",
		"botonvolver", Eljuego::instanciar()->getRenderer())) {
		return false;
	}
	ObjetoJuego* boton1 = new BotonMenu(new CargadorParams(100, 100,
		400, 100, "botonvolver"), e_volverMenu);
	ObjetoJuego* boton2 = new BotonMenu(new CargadorParams(100, 300,
		400, 100, "botonretomar"), e_retomarJuego);
	m_objetosJuego.push_back(boton1);
	m_objetosJuego.push_back(boton2);

	OutputDebugStringA("Entrando en estado Pausa\n");
	return true;
}

bool EstadoPausa::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();
	m_objetosJuego.clear();
	Elmanejador::instanciar()->limpiaMapaTexturas("botonretomar");
	Elmanejador::instanciar()->limpiaMapaTexturas("botonvolver");
	Controles::instanciar()->limpiar();

	OutputDebugStringA("Saliendo del estado Pausa\n");
	return true;
}

std::string EstadoPausa::getIdEstado() const { return e_idpausa; }