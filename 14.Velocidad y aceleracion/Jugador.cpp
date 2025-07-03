#include "Jugador.h"

Jugador::Jugador(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
}

void Jugador::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Jugador::actualizar() {
	m_frameActual = int(((SDL_GetTicks() / 100) % 6));
	m_aceleracion.setX(0.1f);
	SDLObjetoJuego::actualizar();
}

void Jugador::limpiar() {}