#include "GraficosAnimados.h"

ObjetoJuego* CreadorGraficoAnimado::crearObjetoJuego() const {
	return new GraficosAnimados();
}

GraficosAnimados::GraficosAnimados() : SDLObjetoJuego() {}

void GraficosAnimados::cargar(const CargadorParams* pParams) {
	SDLObjetoJuego::cargar(pParams);
	m_velocAnim = pParams->getVelocAnim();
	m_numFrames = pParams->getNumFrames();
}

void GraficosAnimados::actualizar() {
	m_frameActual = int(((SDL_GetTicks() / (1000 / m_velocAnim)) % m_numFrames));
}