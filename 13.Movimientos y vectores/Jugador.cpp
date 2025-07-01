#include "Jugador.h"

Jugador::Jugador(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
}

void Jugador::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Jugador::actualizar() {
	m_posicion.setX(m_posicion.getX() - 1);
}

void Jugador::limpiar() {}