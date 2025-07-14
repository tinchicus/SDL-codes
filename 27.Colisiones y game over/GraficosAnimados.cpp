#include "GraficosAnimados.h"

GraficosAnimados::GraficosAnimados(const CargadorParams* pParams,
	int velocAnim) : SDLObjetoJuego(pParams), m_velocAnim(velocAnim) {
	m_numFrames = pParams->getNumFrames();
}

void GraficosAnimados::actualizar() {
	m_frameActual = int(((SDL_GetTicks() / (1000 / m_velocAnim)) % m_numFrames));
}