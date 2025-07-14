#pragma once
#ifndef __MaquinaEstadoJuego__
#define __MaquinaEstadoJuego__
#include "EstadoJuego.h"
#include <vector>

class MaquinaEstadoJuego
{
public:
	void pushEstado(EstadoJuego*);
	void cambiaEstado(EstadoJuego*);
	void popEstado();
	void actualizar();
	void renderizar();

private:
	std::vector<EstadoJuego*> m_estadoJuego;
};

#endif // !__MaquinaEstadoJuego__