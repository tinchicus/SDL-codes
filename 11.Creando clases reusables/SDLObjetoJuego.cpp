#include "SDLObjetoJuego.h"
#include "Juego.h"

SDLObjetoJuego::SDLObjetoJuego(const CargadorParams* pParams) :
	ObjetoJuego(pParams) {
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_ancho = pParams->getAncho();
	m_alto = pParams->getAlto();
	m_idTextura = pParams->getIdTextura();
	m_frameActual = 1;
	m_filaActual = 1;
}

void SDLObjetoJuego::dibujar() {
	ManejarTexturas::instanciar()->dibujar_frame(m_idTextura,
		m_x, m_y, m_ancho, m_alto, m_filaActual, m_frameActual,
		Eljuego::instanciar()->getRenderer());
}

void SDLObjetoJuego::actualizar() {}

void SDLObjetoJuego::limpiar() {}