#include "Enemigo.h"

Enemigo::Enemigo(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
	m_velocidad.setY(2);
	m_velocidad.setX(0.001f);
}

void Enemigo::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Enemigo::actualizar() {
	m_frameActual = int(((SDL_GetTicks() / 100) % 6));
	if (m_posicion.getY() < 0)
		m_velocidad.setY(2);
	else if (m_posicion.getY() > 480)
		m_velocidad.setY(-2);
	SDLObjetoJuego::actualizar();
}

void Enemigo::limpiar() {}