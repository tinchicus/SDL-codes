#include "EstadoFinal.h"
#include <Windows.h>

const std::string EstadoFinal::e_idfinal = "GAMEOVER";

std::string EstadoFinal::getIdEstado() const {
	return e_idfinal;
}

void EstadoFinal::e_volverMenu() {
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoMenuPpal());
}

void EstadoFinal::e_reiniciar() {
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoJugar());
}

void EstadoFinal::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
}

void EstadoFinal::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoFinal::enIngreso() {
	if (!Elmanejador::instanciar()->cargar("assets/over.png",
		"gameover", Eljuego::instanciar()->getRenderer()))
		return false;

	if (!Elmanejador::instanciar()->cargar("assets/volver.png",
		"volvermenu", Eljuego::instanciar()->getRenderer()))
		return false;

	if (!Elmanejador::instanciar()->cargar("assets/reiniciar.png",
		"reiniciar", Eljuego::instanciar()->getRenderer()))
		return false;

	ObjetoJuego* textoGameOver = new GraficosAnimados(new CargadorParams(
		200, 100, 190, 30, "gameover", 2), 2);
	ObjetoJuego* boton1 = new BotonMenu(new CargadorParams(
		100, 170, 400, 100, "volvermenu"), e_volverMenu);
	ObjetoJuego* boton2 = new BotonMenu(new CargadorParams(
		100, 300, 400, 100, "reiniciar"), e_reiniciar);

	m_objetosJuego.push_back(textoGameOver);
	m_objetosJuego.push_back(boton1);
	m_objetosJuego.push_back(boton2);

	OutputDebugStringA("Entrando al estado Game Over\n");
	return true;
}

bool EstadoFinal::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();

	m_objetosJuego.clear();
	Elmanejador::instanciar()->limpiaMapaTexturas("gameover");
	Elmanejador::instanciar()->limpiaMapaTexturas("volvermenu");
	Elmanejador::instanciar()->limpiaMapaTexturas("reiniciar");

	OutputDebugStringA("Saliendo del Estado de Game Over\n");
	return true;
}