#include "EstadoJugar.h"
#include <Windows.h>

const std::string EstadoJugar::e_idjugar = "JUGAR";

void EstadoJugar::actualizar() {}

void EstadoJugar::renderizar() {}

bool EstadoJugar::enIngreso() {
	OutputDebugStringA("Ingresando al Estado de jugar\n");
	return true;
}

bool EstadoJugar::enSalida() {
	OutputDebugStringA("Saliendo del Estado de jugar\n");
	return true;
}

std::string EstadoJugar::getIdEstado() const { return e_idjugar; }