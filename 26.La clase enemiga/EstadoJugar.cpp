#include "EstadoJugar.h"
#include <Windows.h>

const std::string EstadoJugar::e_idjugar = "JUGAR";

void EstadoJugar::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_ESCAPE))
		Eljuego::instanciar()->getEstadoMaquina()->
		pushEstado(new EstadoPausa());
}

void EstadoJugar::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoJugar::enIngreso() {
	if (!Elmanejador::instanciar()->cargar("assets/helicoptero.png",
		"helicoptero", Eljuego::instanciar()->getRenderer())) {
		return false;
	}
	if (!Elmanejador::instanciar()->cargar("assets/helicoptero2.png",
		"helicotero", Eljuego::instanciar()->getRenderer())) {
		return false;
	}
	ObjetoJuego* jugador = new Jugador(new CargadorParams(
		500, 100, 128, 55, "helicoptero"));
	ObjetoJuego* enemigo = new Enemigo(new CargadorParams(
		100, 100, 128, 55, "helicotero"));

	m_objetosJuego.push_back(jugador);
	m_objetosJuego.push_back(enemigo);

	OutputDebugStringA("Ingresando al Estado de jugar\n");
	return true;
}

bool EstadoJugar::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();

	m_objetosJuego.clear();
	Elmanejador::instanciar()->limpiaMapaTexturas("helicoptero");

	OutputDebugStringA("Saliendo del Estado de jugar\n");
	return true;
}

std::string EstadoJugar::getIdEstado() const { return e_idjugar; }