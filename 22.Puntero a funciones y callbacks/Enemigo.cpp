#include "Enemigo.h"

Enemigo::Enemigo(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
}

void Enemigo::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Enemigo::actualizar() {
	m_posicion.setX(m_posicion.getX() + 1);
	m_posicion.setY(m_posicion.getY() + 1);
}

void Enemigo::limpiar() {}