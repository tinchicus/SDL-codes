#include "EstadoMenu.h"
#include <Windows.h>

const std::string EstadoMenu::e_idmenu = "MENU";

void EstadoMenu::actualizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->actualizar();
}

void EstadoMenu::renderizar() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->dibujar();
}

bool EstadoMenu::enIngreso() {
	if (!Elmanejador::instanciar()->cargar("assets/jugar.png", "botonJugar",
		Eljuego::instanciar()->getRenderer())) {
		return false;
	}
	if (!Elmanejador::instanciar()->cargar("assets/salir.png", "botonSalir",
		Eljuego::instanciar()->getRenderer())) {
		return false;
	}

	ObjetoJuego* boton1 = new BotonMenu(new CargadorParams(100, 100, 400, 100,
		"botonJugar"), e_menuParaJugar);
	ObjetoJuego* boton2 = new BotonMenu(new CargadorParams(100, 300, 400, 100,
		"botonSalir"), e_salirDelMenu);

	m_objetosJuego.push_back(boton1);
	m_objetosJuego.push_back(boton2);

	OutputDebugStringA("Ingresando al Estado del menu\n");
	return true;
}

bool EstadoMenu::enSalida() {
	for (int i = 0; i < m_objetosJuego.size(); i++)
		m_objetosJuego[i]->limpiar();

	m_objetosJuego.clear();
	Elmanejador::instanciar()->limpiaMapaTexturas("botonJugar");
	Elmanejador::instanciar()->limpiaMapaTexturas("botonSalir");

	OutputDebugStringA("Saliendo del Estado del menu\n");
	return true;
}

void EstadoMenu::e_menuParaJugar() {
	OutputDebugStringA("Boton de juego apretado\n");
	Eljuego::instanciar()->getEstadoMaquina()->
		cambiaEstado(new EstadoJugar());
}
void EstadoMenu::e_salirDelMenu() {
	OutputDebugStringA("Boton de salir apretado\n");
	Eljuego::instanciar()->limpiar();
}

std::string EstadoMenu::getIdEstado() const { return e_idmenu; }