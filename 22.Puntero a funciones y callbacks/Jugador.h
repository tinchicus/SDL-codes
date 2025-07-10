#pragma once
#ifndef __Jugador__
#define __Jugador__

#include "SDLObjetoJuego.h"
#include "CargadorParams.h"
#include "ManejarEntradas.h"

class Jugador : public SDLObjetoJuego
{
public:
	Jugador(const CargadorParams*);
	void dibujar();
	void actualizar();
	void limpiar();

private:
	void manejaEntrada();
};

#endif /* defined(__Jugador__)*/