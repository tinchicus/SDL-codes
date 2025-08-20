#include "Jugador.h"

ObjetoJuego* CreadorJugador::crearObjetoJuego() const {
	return new Jugador();
}

Jugador::Jugador() : SDLObjetoJuego() {}

void Jugador::cargar(const CargadorParams* pParams) {
	SDLObjetoJuego::cargar(pParams);
}

void Jugador::dibujar() {
	SDLObjetoJuego::dibujar();
}

void Jugador::actualizar() {
	m_velocidad.setX(0);
	m_velocidad.setY(0);
	manejaEntrada();
	m_frameActual = int(((SDL_GetTicks() / 100) % 6));
	SDLObjetoJuego::actualizar();
}

void Jugador::limpiar() {}

void Jugador::manejaEntrada(){
	Vector2D* destino = Controles::instanciar()->getPosicionMouse();
	m_velocidad = *destino - m_posicion;
	m_velocidad /= 50;
}