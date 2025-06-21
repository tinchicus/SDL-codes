#include "Jugador.h"

void Jugador::cargar(float x, float y, float ancho, float alto, 
	std::string idTextura) {
	ObjetoJuego::cargar(x, y, ancho, alto, idTextura);
}

void Jugador::dibujar(SDL_Renderer* pRenderer) {
	ObjetoJuego::dibujar(pRenderer);
}

void Jugador::actualizar() {
	m_x -= 1;
}

void Jugador::limpiar() {}