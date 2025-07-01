#include "Enemigo.h"

Enemigo::Enemigo(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
}

void Enemigo::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Enemigo::actualizar() {
	m_x += 1;
	m_frameActual = int(((SDL_GetTicks() / 100) % 6));
}

void Enemigo::limpiar() {}