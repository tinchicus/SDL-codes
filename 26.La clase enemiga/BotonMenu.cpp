#include "BotonMenu.h"
#include "Vector2D.h"

BotonMenu::BotonMenu(const CargadorParams* pParams, void(*callback)()) :
	SDLObjetoJuego(pParams), m_callback(callback) {
	m_frameActual = MOUSE_FUERA;
}

void BotonMenu::dibujar() {
	SDLObjetoJuego::dibujar();
}

void BotonMenu::actualizar() {
	Vector2D* pPosMouse = Controles::instanciar()->getPosicionMouse();

	if (pPosMouse->getX() < (m_posicion.getX() + m_ancho)
		&& pPosMouse->getX() > m_posicion.getX()
		&& pPosMouse->getY() < (m_posicion.getY() + m_alto)
		&& pPosMouse->getY() > m_posicion.getY()) {
		m_frameActual = MOUSE_SOBRE;

		if (Controles::instanciar()->getEstadoBotonMouse(IZQUIERDO)
			&& m_bLiberado) {
			m_callback();
			m_bLiberado = false;
		}
		else if (!Controles::instanciar()->getEstadoBotonMouse(IZQUIERDO)) {
			m_bLiberado = true;
			m_frameActual = MOUSE_SOBRE;
		}
	}
	else {
		m_frameActual = MOUSE_FUERA;
	}
}

void BotonMenu::limpiar() {
	SDLObjetoJuego::limpiar();
}
