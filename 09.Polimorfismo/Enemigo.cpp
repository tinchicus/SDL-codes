#include "Enemigo.h"

void Enemigo::cargar(float x, float y, float ancho, float alto,
	std::string idTextura) {
	ObjetoJuego::cargar(x, y, ancho, alto, idTextura);
}

void Enemigo::dibujar(SDL_Renderer* pRenderer) {
	ObjetoJuego::dibujar(pRenderer);
}

void Enemigo::actualizar() {
	m_x += 1;
	m_y += 1;
}

void Enemigo::limpiar() {}