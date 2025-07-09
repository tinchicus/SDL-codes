#include "EstadoMenu.h"
#include <Windows.h>

const std::string EstadoMenu::e_idmenu = "MENU";

void EstadoMenu::actualizar() {}

void EstadoMenu::renderizar() {}

bool EstadoMenu::enIngreso() {
	OutputDebugStringA("Ingresando al Estado del menu\n");
	return true;
}

bool EstadoMenu::enSalida() {
	OutputDebugStringA("Saliendo del Estado del menu\n");
	return true;
}

std::string EstadoMenu::getIdEstado() const { return e_idmenu; }