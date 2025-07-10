#include "BotonMenu.h"
#include "Vector2D.h"

BotonMenu::BotonMenu(const CargadorParams* pParams) :
	SDLObjetoJuego(pParams) {
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
		if (Controles::instanciar()->getEstadoBotonMouse(IZQUIERDO)) {
			m_frameActual = CLICKEADO;
		}
	}
	else {
		m_frameActual = MOUSE_FUERA;
	}
}

void BotonMenu::limpiar() {
	SDLObjetoJuego::limpiar();
}
