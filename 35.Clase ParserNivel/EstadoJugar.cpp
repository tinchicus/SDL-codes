#include "EstadoJugar.h"
#include <Windows.h>

const std::string EstadoJugar::e_idjugar = "JUGAR";

void EstadoJugar::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
	if (Controles::instanciar()->teclaPresionada(SDL_SCANCODE_ESCAPE))
		Eljuego::instanciar()->getEstadoMaquina()->
		pushEstado(new EstadoPausa());
	if (chekaColision(dynamic_cast<SDLObjetoJuego*>(m_objetosJuego[0]),
		dynamic_cast<SDLObjetoJuego*>(m_objetosJuego[1]))) {
		Eljuego::instanciar()->getEstadoMaquina()->
			pushEstado(new EstadoFinal());
	}
}

void EstadoJugar::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoJugar::enIngreso() {
	EstadoParser estadoParser;
	estadoParser.estadoParse("estados.xml", e_idjugar, &m_objetosJuego, 
		&m_listaIdtexturas);

	OutputDebugStringA("Ingresando al Estado de jugar\n");
	return true;
}

bool EstadoJugar::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();

	for (int i = 0; i < m_listaIdtexturas.size(); i++) {
		Elmanejador::instanciar()->limpiaMapaTexturas(m_listaIdtexturas[i]);
	}

	OutputDebugStringA("Saliendo del Estado de jugar\n");
	return true;
}

bool EstadoJugar::chekaColision(SDLObjetoJuego* p1, SDLObjetoJuego* p2) {
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;
	leftA = p1->getPosicion().getX();
	rightA = p1->getPosicion().getX() + p1->getAncho();
	topA = p1->getPosicion().getY();
	bottomA = p1->getPosicion().getY() + p1->getAlto();
	leftB = p2->getPosicion().getX();
	rightB = p2->getPosicion().getX() + p2->getAncho();
	topB = p2->getPosicion().getY();
	bottomB = p2->getPosicion().getY() + p2->getAlto();
	if (bottomA <= topB) return false;
	if (topA >= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	return true;
}

std::string EstadoJugar::getIdEstado() const { return e_idjugar; }