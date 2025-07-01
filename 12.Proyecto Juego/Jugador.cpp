#include "Jugador.h"

Jugador::Jugador(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
}

void Jugador::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Jugador::actualizar() {
	m_x -= 1;
	m_frameActual = int(((SDL_GetTicks() / 100) % 6));
}

void Jugador::limpiar() {}