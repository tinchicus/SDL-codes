#include "SDLObjetoJuego.h"
#include "Juego.h"

SDLObjetoJuego::SDLObjetoJuego() : ObjetoJuego(){}

void SDLObjetoJuego::cargar(const CargadorParams* pParams) {
	m_posicion = Vector2D(pParams->getX(), pParams->getY());
	m_velocidad = Vector2D(0, 0);
	m_aceleracion = Vector2D(0, 0);
	m_ancho = pParams->getAncho();
	m_alto = pParams->getAlto();
	m_idTextura = pParams->getIdTextura();
	m_frameActual = 1;
	m_filaActual = 1;
	m_numFrames = pParams->getNumFrames();
}

void SDLObjetoJuego::dibujar() {
	/*ManejarTexturas::instanciar()->dibujar_frame(m_idTextura,
		m_posicion.getX(), m_posicion.getY(), m_ancho, m_alto,
		m_filaActual, m_frameActual, Eljuego::instanciar()->getRenderer());*/
	if (m_velocidad.getX() > 0){
		ManejarTexturas::instanciar()->dibujar_frame(m_idTextura,
			(Uint32)m_posicion.getX(),
			(Uint32)m_posicion.getY(),
			m_ancho, m_alto, m_filaActual, m_frameActual,
			Eljuego::instanciar()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else {
		ManejarTexturas::instanciar()->dibujar_frame(m_idTextura,
			(Uint32)m_posicion.getX(),
			(Uint32)m_posicion.getY(),
			m_ancho, m_alto, m_filaActual, m_frameActual,
			Eljuego::instanciar()->getRenderer());
	}
}

void SDLObjetoJuego::actualizar() {
	m_velocidad += m_aceleracion;
	m_posicion += m_velocidad;
}

Vector2D& SDLObjetoJuego::getPosicion() { return m_posicion; }
float SDLObjetoJuego::getAncho() { return m_ancho; }
float SDLObjetoJuego::getAlto() { return m_alto; }

void SDLObjetoJuego::limpiar() {}