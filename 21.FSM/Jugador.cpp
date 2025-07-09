#include "Jugador.h"

Jugador::Jugador(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
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

void Jugador::manejaEntrada()
{
	Vector2D* v = Controles::instanciar()->getPosicionMouse();
	m_velocidad = (*v - m_posicion);

	if (Controles::instanciar()->joysticksIniciados()) {
		if (Controles::instanciar()->valorX(0, 1) > 0 ||
			Controles::instanciar()->valorX(0, 1) < 0) {
			m_velocidad.setX(1 * Controles::instanciar()->
				valorX(0, 1));
		}

		if (Controles::instanciar()->valorY(0, 1) > 0 ||
			Controles::instanciar()->valorY(0, 1) < 0) {
			m_velocidad.setY(1 * Controles::instanciar()->
				valorY(0, 1));
		}

		if (Controles::instanciar()->valorX(0, 2) > 0 ||
			Controles::instanciar()->valorX(0, 2) < 0) {
			m_velocidad.setX(1 * Controles::instanciar()->
				valorX(0, 2));
		}

		if (Controles::instanciar()->valorY(0, 2) > 0 ||
			Controles::instanciar()->valorY(0, 2) < 0) {
			m_velocidad.setY(1 * Controles::instanciar()->
				valorY(0, 2));
		}

		if (Controles::instanciar()->getEstadoBoton(0, 1))
			m_velocidad.setX(1);
	}

	if (Controles::instanciar()->getEstadoBotonMouse(DERECHO))
		m_velocidad.setX(1);

	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_RIGHT)) {
		m_velocidad.setX(2);
	}
	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_LEFT)) {
		m_velocidad.setX(-2);
	}
	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_DOWN)) {
		m_velocidad.setY(2);
	}
	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_UP)) {
		m_velocidad.setY(-2);
	}

}