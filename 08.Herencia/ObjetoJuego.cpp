#include "ObjetoJuego.h"

void ObjetoJuego::cargar(float x, float y, float ancho, float alto,
	std::string idTextura) {
	m_x = x;
	m_y = y;
	m_ancho = ancho;
	m_alto = alto;
	m_idTextura = idTextura;
	m_frameActual = 1;
	m_filaActual = 1;
}

void ObjetoJuego::dibujar(SDL_Renderer* pRenderer) {
	ManejarTexturas::instanciar()->dibujar_frame(m_idTextura, m_x, m_y,
		m_ancho, m_alto, m_filaActual, m_frameActual, pRenderer);
}

void ObjetoJuego::actualizar() {
	m_x += 1;
}

void ObjetoJuego::limpiar() {}
