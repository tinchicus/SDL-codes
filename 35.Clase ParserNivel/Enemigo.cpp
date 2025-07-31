#include "Enemigo.h"

ObjetoJuego* CreadorEnemigo::crearObjetoJuego() const {
	return new Enemigo();
}

Enemigo::Enemigo() : SDLObjetoJuego() {}

void Enemigo::cargar(const CargadorParams* pParams) {
	SDLObjetoJuego::cargar(pParams);
	m_velocidad.setY(2);
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